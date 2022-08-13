/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallocs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/07/15 07:44:37 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	clean_mlx_imgs_ptrs(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img[0].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img[1].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img[2].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img[3].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img[4].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img[5].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img[6].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_fire[0].img_ptr);
}

void	clean_mlx_window(t_mlx *mlx)
{
	mlx_clear_window (mlx->mlx_ptr, mlx->win);
	mlx_destroy_window (mlx->mlx_ptr, mlx->win);
}

void	clean_mlx_garbage(t_mlx *mlx)
{
	clean_mlx_imgs_ptrs(mlx);
	clean_mlx_window(mlx);
}
