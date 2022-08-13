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

/*
◦ The map must be closed/surrounded by walls, if not the program must return 
  an error.
◦ Map must have at least one exit, one collectible, and one starting position.
◦ You don’t need to check if there’s a valid path in the map.
◦ The map must be rectangular.
◦ You must be able to parse any kind of map, as long as it respects the rules 
  of the map.

If any misconfiguration of any kind is encountered in the file, the program must
exit properly and return "Error\n" followed by an explicit error message of your
choice.
*/

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

void	check_map_valid_chars(char *map_info, t_mlx *mlx)
{
	int	count;

	count = 0;
	while (map_info[count] != '\0')
	{
		if (map_info[count] == '0' || map_info[count] == '1'
			|| map_info[count] == 'N' || map_info[count] == 'S'
			|| map_info[count] == 'W' || map_info[count] == 'E'
			|| map_info[count] == '\n' || map_info[count] == 'D'
			|| map_info[count] == ' ')
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
		write(2, "Error: Invalid number of players\n", 33);
		free_map_textures_vars(mlx);
		mlx_destroy(mlx->mlx_ptr);
		check_leaks();
		exit(-1);
	}
}
