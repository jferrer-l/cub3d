/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/07/15 06:45:41 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_raycast_vars(t_mlx *mlx)
{
	mlx->ray.count = -1;
	mlx->time = 0;
	mlx->old_time = 0;
	mlx->fov = 66;
	mlx->ray.planex = 0.0;
	mlx->ray.planey = 0.66;
	mlx->hero.vector_view.x = 1;
	mlx->hero.vector_view.y = 0;
}

void	ray_set_sidedist(t_mlx *mlx)
{
	if (mlx->ray.raydirx < 0)
	{
		mlx->ray.stepx = -1;
		mlx->ray.sidedistx = (mlx->hero.pos.x - mlx->ray.map_x)
			* mlx->ray.deltadistx;
	}
	else
	{
		mlx->ray.stepx = 1;
		mlx->ray.sidedistx = (mlx->ray.map_x + 1.0 - mlx->hero.pos.x)
			* mlx->ray.deltadistx;
	}
	if (mlx->ray.raydiry < 0)
	{
		mlx->ray.stepy = -1;
		mlx->ray.sidedisty = (mlx->hero.pos.y - mlx->ray.map_y)
			* mlx->ray.deltadisty;
	}
	else
	{
		mlx->ray.stepy = 1;
		mlx->ray.sidedisty = (mlx->ray.map_y + 1.0 - mlx->hero.pos.y)
			* mlx->ray.deltadisty;
	}
}

void	ray_advance_until_hit(t_mlx *mlx)
{
	static int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (mlx->ray.sidedistx < mlx->ray.sidedisty)
		{
			mlx->ray.sidedistx += mlx->ray.deltadistx;
			mlx->ray.map_x += mlx->ray.stepx;
			mlx->ray.side = 0;
			if (mlx->ray.stepx < 0)
				mlx->ray.side = 1;
		}
		else
		{
			mlx->ray.sidedisty += mlx->ray.deltadisty;
			mlx->ray.map_y += mlx->ray.stepy;
			mlx->ray.side = 2;
			if (mlx->ray.stepy < 0)
				mlx->ray.side = 3;
		}
		if (mlx->map[mlx->ray.map_x][mlx->ray.map_y] == '1')
			hit = 1;
	}
}

void	ray_draw_line(int x, t_mlx *mlx)
{
	static t_cords	start_p;
	static t_cords	end_p;
	static int		line_height;
	static double	wall_x;

	line_height = (int)((WIN_HEIGHT) / mlx->ray.walldistance);
	start_p.y = -line_height / 2 + WIN_HEIGHT / 2;
	end_p.y = line_height / 2 + WIN_HEIGHT / 2;
	start_p.x = x;
	end_p.x = x;
	if (mlx->ray.side == 0 || mlx->ray.side == 1)
		wall_x = mlx->hero.pos.y + mlx->ray.walldistance * mlx->ray.raydiry;
	else
		wall_x = mlx->hero.pos.x + mlx->ray.walldistance * mlx->ray.raydirx;
	wall_x -= floor(wall_x);
	draw_line(mlx, start_p, end_p, (int [2]){64.0 * wall_x, mlx->ray.side});
}
