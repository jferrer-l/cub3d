/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marza-ga <marza-ga-@student.42barcelo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/03/04 22:17:00 by marza-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_player_starting_angle2(t_mlx *mlx, char angle_char)
{
	if (angle_char == 'E')
	{
		mlx->hero.vector_view.x = 1;
		mlx->hero.vector_view.y = 0;
		mlx->hero.angle_view = 0;
		mlx->ray.planex = 0.0;
		mlx->ray.planey = 0.66;
	}
	else if (angle_char == 'W')
	{
		mlx->hero.vector_view.x = -1;
		mlx->hero.vector_view.y = 0;
		mlx->hero.angle_view = 180;
		mlx->ray.planex = 0.0;
		mlx->ray.planey = -0.66;
	}
}

void	get_player_starting_angle(t_mlx *mlx, char angle_char)
{
	if (angle_char == 'S')
	{
		mlx->hero.vector_view.x = 0;
		mlx->hero.vector_view.y = 1;
		mlx->hero.angle_view = 90;
		mlx->ray.planex = -0.66;
		mlx->ray.planey = 0.0;
	}
	else if (angle_char == 'N')
	{
		mlx->hero.vector_view.x = 0;
		mlx->hero.vector_view.y = -1;
		mlx->hero.angle_view = 270;
		mlx->ray.planex = 0.66;
		mlx->ray.planey = 0.0;
	}
	else
		get_player_starting_angle2(mlx, angle_char);
}

void	get_player_starting_map_data(t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < mlx->map_height)
	{
		while (x < mlx->map_width)
		{
			if (mlx->map[x][y] == 'N' || mlx->map[x][y] == 'E'
				|| mlx->map[x][y] == 'W' || mlx->map[x][y] == 'S')
			{
				mlx->hero.pos.x = x + 0.5;
				mlx->hero.pos.y = y + 0.5;
				get_player_starting_angle(mlx, mlx->map[x][y]);
				return ;
			}
			x++;
		}
		y++;
		x = 0;
	}
}
