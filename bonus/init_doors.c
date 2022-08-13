/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_doors.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: marza-ga <marza-ga-@student.42barcelo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/03/04 22:17:00 by marza-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init_door_object_data(t_door *door, int x, int y)
{
	door->x = x;
	door->y = y;
	door->state = 0;
	door->sp_index = 0;
	door->sp_time = 0;
}

void	init_doors_malloc(t_mlx *mlx)
{
	if (!mlx->num_doors)
	{
		mlx->doors = NULL;
		return ;
	}
	mlx->doors = malloc(sizeof(t_door) * (mlx->num_doors));
	if (!mlx->doors)
	{
		write(2, "Error: malloc fails creating door array\n", 41);
		free_map_textures_vars(mlx);
		free_map_memory(mlx);
		mlx_destroy(mlx->mlx_ptr);
		check_leaks();
		exit(-1);
	}
}

void	fill_doors_arrays(t_mlx *mlx)
{
	int	x;
	int	y;
	int	index;

	x = 0;
	y = 0;
	index = 0;
	while (y < mlx->map_height)
	{
		while (x < mlx->map_width)
		{
			if (mlx->map[x][y] == 'D')
			{
				init_door_object_data(&mlx->doors[index], x, y);
				index++;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	count_doors_in_map(t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx->num_doors = 0;
	while (y < mlx->map_height)
	{
		while (x < mlx->map_width)
		{
			if (mlx->map[x][y] == 'D')
				mlx->num_doors++;
			x++;
		}
		x = 0;
		y++;
	}
}

void	init_doors(t_mlx *mlx)
{
	count_doors_in_map(mlx);
	init_doors_malloc(mlx);
	fill_doors_arrays(mlx);
}
