/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/07/15 07:38:41 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int		is_empty_line(char *map_info, int index);
char	*ft_strjoin_char(char *s1, char c);
int		advance_empty_line(char *map_info, int index);

void	fill_map_matrix(t_mlx *mlx, char *map_info)
{
	int		count2;
	int		count_y;
	int		count_x;

	count2 = 0;
	count_x = 0;
	count_y = 0;
	while (map_info[count2])
	{
		if (map_info[count2] != '\n')
			mlx->map[count_x++][count_y] = map_info[count2];
		else
		{
			while (count_x < mlx->map_width)
				mlx->map[count_x++][count_y] = ' ';
			count_y++;
			count_x = 0;
		}
		count2++;
	}
	free(map_info);
}

char	*construct_map_info_whit_only_map(char
	*map_info, int index, t_mlx *mlx)
{
	char	*new_map_info;

	new_map_info = NULL;
	while (is_empty_line(map_info, index))
		index = advance_empty_line(map_info, index);
	while (map_info[index])
	{
		new_map_info = ft_strjoin_char(new_map_info, map_info[index]);
		if (!new_map_info)
		{
			free(map_info);
			write(2, "Error: Cannot allocate memory\n", 31);
			free_map_textures_vars(mlx);
			mlx_destroy(mlx->mlx_ptr);
			check_leaks();
			exit(-1);
		}
		index++;
	}
	free(map_info);
	return (new_map_info);
}

char	**parse_initial_map(t_mlx *mlx)
{
	char	*map_info;
	int		index;

	map_info = get_initial_map_info(mlx->map_name, mlx);
	index = parse_map_vars(map_info, mlx);
	check_have_all_map_vars(map_info, mlx);
	map_info = construct_map_info_whit_only_map(map_info, index, mlx);
	mlx->map_height = map_lines_height(map_info);
	mlx->map_width = map_lines_width(map_info);
	check_map_valid_height_and_width(map_info, mlx);
	check_map_valid_chars(map_info, mlx);
	check_map_needed_chars(map_info, mlx);
	create_map_x_malloc(mlx, map_info);
	mlx->map[mlx->map_width] = NULL;
	index = -1;
	while (++index <= mlx->map_width)
	{
		mlx->map[index] = create_map_y_malloc(mlx, index, map_info);
		mlx->map[index][mlx->map_height] = '\0';
	}
	fill_map_matrix(mlx, map_info);
	check_map_surronded_by_walls(mlx);
	return (mlx->map);
}
