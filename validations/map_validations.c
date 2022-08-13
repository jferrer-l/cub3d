/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marza-ga <marza-ga-@student.42barcelo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/03/04 22:17:00 by marza-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	check_map_valid_height_and_width(char *map_info, t_mlx *mlx)
{
	if (map_lines_height(map_info) < 3)
	{
		free(map_info);
		write(2, "Error: Map height is not valid\n", 31);
		free_map_textures_vars(mlx);
		mlx_destroy(mlx->mlx_ptr);
		check_leaks();
		exit(-1);
	}
	if (map_lines_width(map_info) < 3)
	{
		free(map_info);
		write(2, "Error: Map width is not valid\n", 31);
		free_map_textures_vars(mlx);
		mlx_destroy(mlx->mlx_ptr);
		check_leaks();
		exit(-1);
	}
}

void	check_map_is_rectangular(char *map_info, t_mlx *mlx)
{
	int	count_y;
	int	count_x;
	int	count;

	count = 0;
	count_y = 0;
	count_x = 0;
	while (count_y < mlx->map_height)
	{
		while (map_info[count] != '\n' && map_info[count] != '\0')
		{
			count++;
			count_x++;
		}
		if (count_x != mlx->map_width)
		{
			free(map_info);
			write(2, "Error\nMap is not rectangular", 28);
			exit(-1);
		}
		count++;
		count_x = 0;
		count_y++;
	}
}

void	check_map_valid_chars(char *map_info, t_mlx *mlx)
{
	int	count;

	count = 0;
	while (map_info[count] != '\0')
	{
		if (map_info[count] == '0' || map_info[count] == '1'
			|| map_info[count] == 'N' || map_info[count] == 'S'
			|| map_info[count] == 'W' || map_info[count] == 'E'
			|| map_info[count] == '\n' || map_info[count] == ' ')
		{
			count++;
		}
		else
		{
			free(map_info);
			write(2, "Error: Invalid characters in map\n", 34);
			free_map_textures_vars(mlx);
			mlx_destroy(mlx->mlx_ptr);
			check_leaks();
			exit(-1);
		}
	}
}

void	check_map_needed_chars(char *map_info, t_mlx *mlx)
{
	int	count;
	int	count_p;

	count = 0;
	count_p = 0;
	while (map_info[count++] != '\0')
	{
		if (map_info[count - 1] == 'N' || map_info[count - 1] == 'S'
			|| map_info[count - 1] == 'E' || map_info[count - 1] == 'W')
			count_p++;
	}
	if (count_p != 1)
	{
		free(map_info);
		write(2, "Error:\nInvalid number of players", 33);
		free_map_textures_vars(mlx);
		mlx_destroy(mlx->mlx_ptr);
		check_leaks();
		exit(-1);
	}
}
