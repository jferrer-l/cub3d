/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_gun_imgs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marza-ga <marza-ga-@student.42barcelo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/03/04 22:17:00 by marza-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	load_weapon_sprites_reload(t_mlx *mlx)
{
	load_image(&mlx->gun.img_reload[0], "imgs/gun/recharge/DEARA0.xpm", mlx);
	load_image(&mlx->gun.img_reload[1], "imgs/gun/recharge/DEARB0.xpm", mlx);
	load_image(&mlx->gun.img_reload[2], "imgs/gun/recharge/DEARC0.xpm", mlx);
	load_image(&mlx->gun.img_reload[3], "imgs/gun/recharge/DEARD0.xpm", mlx);
	load_image(&mlx->gun.img_reload[4], "imgs/gun/recharge/DEARE0.xpm", mlx);
	load_image(&mlx->gun.img_reload[5], "imgs/gun/recharge/DEARF0.xpm", mlx);
	load_image(&mlx->gun.img_reload[6], "imgs/gun/recharge/DEARG0.xpm", mlx);
	load_image(&mlx->gun.img_reload[7], "imgs/gun/recharge/DEARH0.xpm", mlx);
	load_image(&mlx->gun.img_reload[8], "imgs/gun/recharge/DEARI0.xpm", mlx);
	load_image(&mlx->gun.img_reload[9], "imgs/gun/recharge/DEARJ0.xpm", mlx);
	load_image(&mlx->gun.img_reload[10], "imgs/gun/recharge/DEARK0.xpm", mlx);
	load_image(&mlx->gun.img_reload[11], "imgs/gun/recharge/DEARL0.xpm", mlx);
	load_image(&mlx->gun.img_reload[12], "imgs/gun/recharge/DEARM0.xpm", mlx);
}

void	load_weapon_sprites_reload2(t_mlx *mlx)
{
	load_image(&mlx->gun.img_reload[13], "imgs/gun/recharge/DEARN0.xpm", mlx);
	load_image(&mlx->gun.img_reload[14], "imgs/gun/recharge/DEARO0.xpm", mlx);
	load_image(&mlx->gun.img_reload[15], "imgs/gun/recharge/DEARP0.xpm", mlx);
	load_image(&mlx->gun.img_reload[16], "imgs/gun/recharge/DEARQ0.xpm", mlx);
	load_image(&mlx->gun.img_reload[17], "imgs/gun/recharge/DEARR0.xpm", mlx);
	load_image(&mlx->gun.img_reload[18], "imgs/gun/recharge/DEARS0.xpm", mlx);
	load_image(&mlx->gun.img_reload[19], "imgs/gun/recharge/DEART0.xpm", mlx);
	load_image(&mlx->gun.img_reload[20], "imgs/gun/recharge/DEARU0.xpm", mlx);
	load_image(&mlx->gun.img_reload[21], "imgs/gun/recharge/DEARV0.xpm", mlx);
	load_image(&mlx->gun.img_reload[22], "imgs/gun/recharge/DEARW0.xpm", mlx);
	load_image(&mlx->gun.img_reload[23], "imgs/gun/recharge/DEARX0.xpm", mlx);
	load_image(&mlx->gun.img_reload[24], "imgs/gun/recharge/DEARY0.xpm", mlx);
	load_image(&mlx->gun.img_reload[25], "imgs/gun/recharge/DEARZ0.xpm", mlx);
}

void	load_weapon_sprites_fire(t_mlx *mlx)
{
	load_image(&mlx->gun.img_fire[0], "imgs/gun/fire/DEAGA0.xpm", mlx);
	load_image(&mlx->gun.img_fire[1], "imgs/gun/fire/DEAGB0.xpm", mlx);
	load_image(&mlx->gun.img_fire[2], "imgs/gun/fire/DEAGC0.xpm", mlx);
	load_image(&mlx->gun.img_fire[3], "imgs/gun/fire/DEAGD0.xpm", mlx);
	load_image(&mlx->gun.img_fire[4], "imgs/gun/fire/DEAGE0.xpm", mlx);
	load_image(&mlx->gun.img_fire[5], "imgs/gun/fire/DEAGF0.xpm", mlx);
	load_image(&mlx->gun.img_fire[6], "imgs/gun/fire/DEAGG0.xpm", mlx);
	load_image(&mlx->gun.img_fire[7], "imgs/gun/fire/DEAGH0.xpm", mlx);
	load_image(&mlx->gun.img_fire[8], "imgs/gun/fire/DEAGI0.xpm", mlx);
	load_image(&mlx->gun.img_fire[9], "imgs/gun/fire/DEAGJ0.xpm", mlx);
	load_image(&mlx->gun.img_fire[10], "imgs/gun/fire/DEAGK0.xpm", mlx);
}

void	load_weapon_images(t_mlx *mlx)
{
	load_weapon_sprites_fire(mlx);
	load_weapon_sprites_reload(mlx);
	load_weapon_sprites_reload2(mlx);
}
