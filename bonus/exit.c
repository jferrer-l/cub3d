/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/07/15 07:41:02 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	exit_game(t_mlx *mlx)
{
	free_memory_and_exit(mlx);
	return (0);
}

int	free_map_memory(t_mlx *mlx)
{
	int	count;

	count = 0;
	while (count <= mlx->map_width)
	{
		free(mlx->map[count]);
		count++;
	}
	free(mlx->map);
	return (0);
}

void	free_map_textures_vars(t_mlx *mlx)
{
	if (mlx->mapvars.no)
		free(mlx->mapvars.no);
	if (mlx->mapvars.so)
		free(mlx->mapvars.so);
	if (mlx->mapvars.we)
		free(mlx->mapvars.we);
	if (mlx->mapvars.ea)
		free(mlx->mapvars.ea);
	if (mlx->mapvars.ft)
		free(mlx->mapvars.ft);
	if (mlx->mapvars.ct)
		free(mlx->mapvars.ct);
	if (mlx->mapvars.f)
		free(mlx->mapvars.f);
	if (mlx->mapvars.c)
		free(mlx->mapvars.c);
}

void	free_general_images_memory(t_mlx *mlx)
{
	free(mlx->img);
	free(mlx->hero.img);
}

void	free_memory_and_exit(t_mlx *mlx)
{
	free_map_memory(mlx);
	clean_mlx_garbage(mlx);
	free_map_textures_vars(mlx);
	free_general_images_memory(mlx);
	clean_bonus_extra_imgs(mlx);
	mlx_destroy(mlx->mlx_ptr);
	check_leaks();
	exit(0);
}
