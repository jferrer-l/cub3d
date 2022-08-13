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

#include "../cub3D.h"

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
	render_gun(mlx);
	draw_cross_fire(mlx);
	draw_minimap_to_screen(mlx);
	render_doors(mlx);
	return (1);
}

int	load_image(t_img *slot, char *img_name, t_mlx *mlx)
{
	slot->img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			img_name, &slot->width, &slot->height);
	if (slot->img_ptr == NULL)
	{
		printf("Error cargando imgs ptr para %s!\n", img_name);
		return (0);
	}
	slot->data = (int *)mlx_get_data_addr(slot->img_ptr,
			&slot->bpp, &slot->size_l, &slot->endian);
	if (slot->data == NULL)
	{
		printf("Error cargando dataimgs ptr para %s!\n", img_name);
		return (0);
	}
	return (1);
}

int	load_walls_images(t_mlx *mlx)
{
	if (!load_image(&mlx->img[0], mlx->mapvars.no, mlx))
		return (0);
	if (!load_image(&mlx->img[1], mlx->mapvars.so, mlx))
		return (0);
	if (!load_image(&mlx->img[2], mlx->mapvars.we, mlx))
		return (0);
	if (!load_image(&mlx->img[3], mlx->mapvars.ea, mlx))
		return (0);
	return (1);
}
