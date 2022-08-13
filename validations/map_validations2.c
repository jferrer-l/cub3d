/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:28:40 by jferrer-          #+#    #+#             */
/*   Updated: 2022/07/15 15:28:42 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	check_map_surronded_by_walls(t_mlx *mlx)
{
	if (!map_is_surrounded_be_walls(mlx))
	{
		write(2, "Error: map not surrounded be walls\n", 35);
		free_map_memory(mlx);
		free_map_textures_vars(mlx);
		mlx_destroy(mlx->mlx_ptr);
		check_leaks();
		exit(-1);
	}
}

int	map_is_surrounded_be_walls(t_mlx *mlx)
{
	int		count_y;
	int		count_x;

	count_x = -1;
	while (++count_x < mlx->map_width)
	{
		count_y = -1;
		while (++count_y < mlx->map_height)
		{
			if (mlx->map[count_x][count_y] != '1'
				&& mlx->map[count_x][count_y] != ' ')
			{
				if (count_y == mlx->map_height - 1 || count_y == 0
					|| count_x == mlx->map_width - 1 || count_x == 0
					|| mlx->map[count_x + 1][count_y] == ' '
					|| mlx->map[count_x - 1][count_y] == ' '
					|| mlx->map[count_x + 1][count_y + 1] == ' '
					|| mlx->map[count_x - 1][count_y + 1] == ' '
					|| mlx->map[count_x + 1][count_y - 1] == ' '
					|| mlx->map[count_x - 1][count_y - 1] == ' ')
					return (0);
			}
		}
	}
	return (1);
}
