/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus_extras.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marza-ga <marza-ga-@student.42barcelo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/03/04 22:17:00 by marza-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	free_img_sprites_reload2(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_reload[14].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_reload[15].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_reload[16].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_reload[17].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_reload[18].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_reload[19].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_reload[20].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_reload[21].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_reload[22].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_reload[23].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_reload[24].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_reload[25].img_ptr);
}

void	free_img_sprites_reload(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_reload[0].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_reload[1].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_reload[2].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_reload[3].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_reload[4].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_reload[5].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_reload[6].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_reload[7].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_reload[8].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_reload[9].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_reload[10].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_reload[11].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_reload[12].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_reload[13].img_ptr);
}

void	free_img_sprites_fire(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_fire[1].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_fire[2].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_fire[3].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_fire[4].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_fire[5].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_fire[6].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_fire[7].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_fire[8].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_fire[9].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->gun.img_fire[10].img_ptr);
}

void	free_img_sprites_others(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img[7].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->minimap.background.img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->minimap.img.img_ptr);
}

void	clean_bonus_extra_imgs(t_mlx *mlx)
{
	free_img_sprites_reload(mlx);
	free_img_sprites_reload2(mlx);
	free_img_sprites_fire(mlx);
	free_img_sprites_others(mlx);
	free(mlx->doors);
}
