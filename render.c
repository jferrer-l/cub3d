/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:49:42 by jferrer-          #+#    #+#             */
/*   Updated: 2022/07/15 13:49:51 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate_mouse(t_mlx *mlx, int diff)
{
	double	dirx;
	double	diry;
	double	olddirx;
	double	oldplanex;
	double	i;

	dirx = mlx->hero.vector_view.x;
	diry = mlx->hero.vector_view.y;
	olddirx = dirx;
	oldplanex = mlx->ray.planex;
	i = diff * 0.0025;
	mlx->hero.vector_view.x = dirx * cos(i) - diry * sin(i);
	mlx->hero.vector_view.y = olddirx * sin(i) + diry * cos(i);
	mlx->ray.planex = mlx->ray.planex * cos(i) - mlx->ray.planey * sin(i);
	mlx->ray.planey = oldplanex * sin(i) + mlx->ray.planey * cos(i);
	mlx->backgroundx += diff * 0.1;
}

void	update_mouse_pos(t_mlx *mlx)
{
	static int	px = WIN_WIDTH / 2;
	int			x;
	int			y;

	mlx_mouse_get_pos(mlx->win, &x, &y);
	if (x < 0 || x > 2200)
	{
		mlx_mouse_move(mlx->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
		x = WIN_WIDTH / 2;
		px = x;
	}
	if (x)
		rotate_mouse(mlx, x - px);
	px = x;
}

int	render(t_mlx *mlx)
{
	errno = 0;
	update_mouse_pos(mlx);
	draw_sky_background(mlx);
	raycast(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
		mlx->gun.img_fire[0].img_ptr, 193, 240);
	draw_cross_fire(mlx);
	return (1);
}

int	load_image(t_img *slot, char *img_name, t_mlx *mlx)
{
	slot->img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			img_name, &slot->width, &slot->height);
	if (slot->img_ptr == NULL)
	{
		write(2, "Error: de mlx cargando imgs ptr\n", 33);
		return (0);
	}
	slot->data = (int *)mlx_get_data_addr(slot->img_ptr,
			&slot->bpp, &slot->size_l, &slot->endian);
	if (slot->data == NULL)
	{
		mlx_destroy_image(mlx->mlx_ptr, slot->img_ptr);
		free(slot->img_ptr);
		write(2, "Error: de mlx cargando dataimgs ptr\n", 37);
		return (0);
	}
	return (1);
}

int	load_walls_images(t_mlx *mlx)
{
	if (!load_image(&mlx->img[0], mlx->mapvars.no, mlx))
		exit_error_load_walls_images(mlx, 0);
	if (!load_image(&mlx->img[1], mlx->mapvars.so, mlx))
		exit_error_load_walls_images(mlx, 1);
	if (!load_image(&mlx->img[2], mlx->mapvars.we, mlx))
		exit_error_load_walls_images(mlx, 2);
	if (!load_image(&mlx->img[3], mlx->mapvars.ea, mlx))
		exit_error_load_walls_images(mlx, 3);
	return (1);
}
