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

#include "../cub3D.h"

void	init_mapvalidator_struct(t_mlx *mlx)
{
	mlx->mapvars.no = NULL;
	mlx->mapvars.so = NULL;
	mlx->mapvars.we = NULL;
	mlx->mapvars.ea = NULL;
	mlx->mapvars.f = NULL;
	mlx->mapvars.c = NULL;
	mlx->mapvars.ft = NULL;
	mlx->mapvars.ct = NULL;
}

//mlx->start_time = get_timestamp();//cambiar esto
void	init_mlx_object(t_mlx *mlx)
{
	mlx->fov = 60;
	mlx->tile_size = 64;
	mlx->frames = 0;
	mlx->backgroundx = 0;
	mlx->gun.animation = 0;
	mlx->gun.sp_time = 0;
	mlx->gun.sp_index = 0;
}

void	init_player(t_mlx *mlx)
{
	get_player_starting_map_data(mlx);
	mlx->hero.height = 32;
}

void	init_game_data(t_mlx *mlx)
{
	init_mlx_object(mlx);
	init_player(mlx);
}

void	init_game_images(t_mlx *mlx)
{
	mlx->img = malloc(sizeof(t_img) * 10);
	if (!mlx->img)
	{
		free_map_memory(mlx);
		free(mlx->hero.img);
		perror(NULL);
		exit(errno);
	}
	load_walls_images(mlx);
	load_image(&mlx->img[4], "imgs/BW_background.xpm", mlx);
	load_image(&mlx->img[5], "imgs/64x64xpm/CSTX0562.xpm", mlx);
	load_image(&mlx->img[6], "imgs/weapons/DEAGA0.xpm", mlx);
	load_image(&mlx->img[7], "imgs/64x64xpm/DOOR.xpm", mlx);
	draw_backgroud(mlx);
	load_minimap_image(mlx);
	load_weapon_images(mlx);
}
