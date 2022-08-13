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

#include "cub3D.h"

//mlx->start_time = get_timestamp();
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

int	load_extra_images(t_mlx *mlx)
{
	if (!load_image(&mlx->img[4], "imgs/BW_background.xpm", mlx))
		exit_error_load_extra_images(mlx, 4);
	if (!load_image(&mlx->img[5], "imgs/64x64xpm/CSTX0562.xpm", mlx))
		exit_error_load_extra_images(mlx, 5);
	if (!load_image(&mlx->img[6], "imgs/weapons/DEAGA0.xpm", mlx))
		exit_error_load_extra_images(mlx, 6);
	if (!load_image(&mlx->gun.img_fire[0], "imgs/gun/fire/DEAGA0.xpm", mlx))
		exit_error_load_extra_images(mlx, 7);
	return (1);
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
	load_extra_images(mlx);
	draw_backgroud(mlx);
}
