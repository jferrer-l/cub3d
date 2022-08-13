/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:46:01 by jferrer-          #+#    #+#             */
/*   Updated: 2022/07/15 13:46:02 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_cross_fire(t_mlx *mlx)
{
	int	pixels;

	pixels = 11;
	while (pixels)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win, 320, 246 - pixels, 0xcc0000);
		--pixels;
	}
	pixels = 11;
	while (pixels)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win, 326 - pixels, 240, 0xcc0000);
		--pixels;
	}
}

void	draw_weapon(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
		mlx->img[6].img_ptr, 193, 240);
	draw_cross_fire(mlx);
}

int	draw_backgroud(t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 100;
	while (x < ((mlx->img[4].width * mlx->img[4].height) / 2))
	{
		mlx->img[4].data[x] = (mlx->mapvars.ceiling)
			& (0xFFFFFF + mlx->img[4].data[x]);
		x++;
	}
	x = (mlx->img[4].width * mlx->img[4].height) / 2;
	while (x < (mlx->img[4].width * mlx->img[4].height))
	{
		mlx->img[4].data[x] = mlx->mapvars.floor;
		x++;
	}
	return (1);
}

void	draw_line(t_mlx *mlx, t_cords start_p, t_cords end_p, int ps[2])
{
	double	count;
	double	increment;
	double	pixindex;
	double	prevpixindex;
	int		pixels;

	pixels = end_p.y - start_p.y;
	increment = 64 / (double)pixels;
	pixindex = 0.0;
	prevpixindex = 0.0;
	count = ps[0];
	if (ps[1] > 4)
		ps[1] = 7;
	while (pixels && start_p.y < 480)
	{
		if (++start_p.y >= 0 && start_p.y < 480)
			mlx_pixel_put(mlx->mlx_ptr, mlx->win,
				start_p.x, start_p.y, mlx->img[ps[1]].data[(int)count]);
		--pixels;
		if ((int)prevpixindex < (int)pixindex)
			count += 64 * ((int)pixindex - (int)prevpixindex);
		prevpixindex = pixindex;
		pixindex += increment;
	}
}
