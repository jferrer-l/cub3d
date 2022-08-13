/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_animations.c                                    :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: marza-ga <marza-ga-@student.42barcelo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/03/04 22:17:00 by marza-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	gun_recharge_sprites_animation(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
		mlx->gun.img_reload[mlx->gun.sp_index].img_ptr, 193, 240);
	mlx->gun.sp_time++;
	if (mlx->gun.sp_time == 3)
	{
		mlx->gun.sp_index++;
		mlx->gun.sp_time = 0;
	}
	if (mlx->gun.sp_index == 26)
	{
		mlx->gun.sp_index = 0;
		mlx->gun.sp_time = 0;
		mlx->gun.animation = 0;
	}
}

void	render_gun(t_mlx *mlx)
{
	if (!mlx->gun.animation)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
			mlx->gun.img_fire[0].img_ptr, 193, 240);
		return ;
	}
	if (mlx->gun.animation == 1)
	{
		gun_fire_sprites_animation(mlx);
	}
	else if (mlx->gun.animation == 2)
	{
		gun_recharge_sprites_animation(mlx);
	}
}

void	gun_fire_sprites_animation(t_mlx *mlx)
{
	if (mlx->gun.sp_index == 1 || mlx->gun.sp_index == 2)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
			mlx->gun.img_fire[mlx->gun.sp_index].img_ptr, 117, 160);
	else
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
			mlx->gun.img_fire[mlx->gun.sp_index].img_ptr, 193, 240);
	mlx->gun.sp_time++;
	if (mlx->gun.sp_time == 3)
	{
		mlx->gun.sp_index++;
		mlx->gun.sp_time = 0;
	}
	if (mlx->gun.sp_index == 11)
	{
		mlx->gun.sp_index = 0;
		mlx->gun.sp_time = 0;
		mlx->gun.animation = 0;
	}
}
