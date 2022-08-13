/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_vars_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marza-ga <marza-ga-@student.42barcelo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/03/04 22:17:00 by marza-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	check_have_all_map_vars(char *map_info, t_mlx *mlx)
{
	if (!mlx->mapvars.no || !mlx->mapvars.so || !mlx->mapvars.we
		|| !mlx->mapvars.ea || !mlx->mapvars.f || !mlx->mapvars.c)
	{
		free(map_info);
		write(2, "Error: Not found some mapvars in map file\n", 42);
		free_map_textures_vars(mlx);
		mlx_destroy(mlx->mlx_ptr);
		check_leaks();
		exit(-1);
	}
}

int	parse_map_var(char *map_info, int index, int type, t_mlx *mlx)
{
	int	result;

	result = 0;
	if (type == 1)
		result = parse_var_no(map_info, index, mlx);
	if (type == 2)
		result = parse_var_so(map_info, index, mlx);
	if (type == 3)
		result = parse_var_we(map_info, index, mlx);
	if (type == 4)
		result = parse_var_ea(map_info, index, mlx);
	if (type == 5)
		result = parse_var_ft(map_info, index, mlx);
	if (type == 6)
		result = parse_var_ct(map_info, index, mlx);
	if (type == 7)
		result = parse_var_f(map_info, index, mlx);
	if (type == 8)
		result = parse_var_c(map_info, index, mlx);
	return (result);
}

int	check_line_type(char *map_info, int index)
{
	if (map_info[index] == 'N' && map_info[index + 1] == 'O')
		return (1);
	if (map_info[index] == 'S' && map_info[index + 1] == 'O')
		return (2);
	if (map_info[index] == 'W' && map_info[index + 1] == 'E')
		return (3);
	if (map_info[index] == 'E' && map_info[index + 1] == 'A')
		return (4);
	if (map_info[index] == 'F' && map_info[index + 1] == 'T')
		return (5);
	if (map_info[index] == 'C' && map_info[index + 1] == 'T')
		return (6);
	if (map_info[index] == 'F')
		return (7);
	if (map_info[index] == 'C')
		return (8);
	return (0);
}

int	parse_map_vars(char *map_info, t_mlx *mlx)
{
	int	index;
	int	lstart;
	int	l_lenght;

	index = 0;
	lstart = 0;
	l_lenght = 0;
	init_mapvalidator_struct(mlx);
	while (map_info[index])
	{
		while (is_empty_line(map_info, index))
			index = advance_empty_line(map_info, index);
		lstart = index;
		if (parse_map_var(map_info, index,
				check_line_type(map_info, index), mlx))
			;
		else
			return (lstart);
		index += get_line_lenght(map_info, index);
		index++;
	}
	return (0);
}
