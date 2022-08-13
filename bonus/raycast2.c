/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:46:52 by jferrer-          #+#    #+#             */
/*   Updated: 2022/07/18 13:46:53 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ray_launch_new(int x, t_mlx *mlx)
{
	static double	camera_x;
	static double	w = (double)WIN_WIDTH;

	camera_x = 2 * x / w - 1;
	mlx->ray.raydirx = mlx->hero.vector_view.x + mlx->ray.planex * camera_x;
	mlx->ray.raydiry = mlx->hero.vector_view.y + mlx->ray.planey * camera_x;
	mlx->ray.deltadistx = fabs(1 / mlx->ray.raydirx);
	mlx->ray.deltadisty = fabs(1 / mlx->ray.raydiry);
	mlx->ray.map_x = (int)mlx->hero.pos.x;
	mlx->ray.map_y = (int)mlx->hero.pos.y;
	ray_set_sidedist(mlx);
	ray_advance_until_hit(mlx);
	if (mlx->ray.side == 0 || mlx->ray.side == 1
		|| mlx->ray.side == 5 || mlx->ray.side == 6)
		mlx->ray.walldistance = (mlx->ray.sidedistx - mlx->ray.deltadistx);
	else
		mlx->ray.walldistance = (mlx->ray.sidedisty - mlx->ray.deltadisty);
	ray_draw_line(x, mlx);
}

//calcualte_fps(mlx);
void	raycast(t_mlx *mlx)
{
	static int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		ray_launch_new(x, mlx);
		x++;
	}
	mlx->frames++;
}

void	draw_sky_background(t_mlx *mlx)
{
	if (mlx->backgroundx > mlx->img[4].width)
		mlx->backgroundx -= mlx->img[4].width;
	else if (mlx->backgroundx < 0 && mlx->backgroundx > -mlx->img[4].width)
		mlx->backgroundx += mlx->img[4].width;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
		mlx->img[4].img_ptr, mlx->backgroundx, 0);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
		mlx->img[4].img_ptr, mlx->backgroundx - mlx->img[4].width, 0);
}
