/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mov.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 06:21:38 by jferrer-          #+#    #+#             */
/*   Updated: 2022/07/15 06:34:51 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	check_and_move2(t_mlx *mlx, double dirx, double diry)
{
	if (mlx->map[(int)(mlx->hero.pos.x + dirx * MOVSPEED)][(int)
		(mlx->hero.pos.y + diry * MOVSPEED + 0.16)] == '1')
	{
		mlx->hero.pos.x += dirx * MOVSPEED * fabs(sin(dirx * M_PI_2));
		mlx->hero.pos.y = (int)(mlx->hero.pos.y + 1) - 0.15;
	}
	else if (mlx->map[(int)(mlx->hero.pos.x + dirx * MOVSPEED)][(int)
		(mlx->hero.pos.y + diry * MOVSPEED - 0.16)] == '1')
	{
		mlx->hero.pos.x += dirx * MOVSPEED * fabs(sin(dirx * M_PI_2));
		mlx->hero.pos.y = (int)(mlx->hero.pos.y) + 0.15;
	}
}

static void	check_and_move1(t_mlx *mlx, int key)
{
	double	dirx;
	double	diry;

	update_route(mlx, key, &dirx, &diry);
	if (mlx->map[(int)(mlx->hero.pos.x + dirx * MOVSPEED + 0.16)][(int)
		(mlx->hero.pos.y + diry * MOVSPEED)] == '1')
	{
		mlx->hero.pos.y += diry * MOVSPEED * fabs(sin(diry * M_PI_2));
		mlx->hero.pos.x = (int)(mlx->hero.pos.x + 1) - 0.15;
	}
	else if (mlx->map[(int)(mlx->hero.pos.x + dirx * MOVSPEED - 0.16)][(int)
		(mlx->hero.pos.y + diry * MOVSPEED)] == '1')
	{
		mlx->hero.pos.y += diry * MOVSPEED * fabs(sin(diry * M_PI_2));
		mlx->hero.pos.x = (int)(mlx->hero.pos.x) + 0.15;
	}
	else
		check_and_move2(mlx, dirx, diry);
}

static int	condition2(t_mlx *mlx, int value, double dirx, double diry)
{
	if (((value == 1 && mlx->map[(int)(mlx->hero.pos.x + dirx * MOVSPEED)]
			[(int)(mlx->hero.pos.y + diry * MOVSPEED)] != '1' && mlx->map
		[(int)(mlx->hero.pos.x + dirx * MOVSPEED + 0.15)][(int)
		(mlx->hero.pos.y + diry * MOVSPEED)] != '1' && mlx->map[(int)
		(mlx->hero.pos.x + dirx * MOVSPEED - 0.15)][(int)(mlx->hero.pos.y
		+ diry * MOVSPEED)] != '1') || (value == 2 && mlx->map[(int)
		(mlx->hero.pos.x + dirx * MOVSPEED)][(int)(mlx->hero.pos.y + diry
		* MOVSPEED)] != '1' && mlx->map[(int)(mlx->hero.pos.x + dirx
		* MOVSPEED)][(int)(mlx->hero.pos.y + diry * MOVSPEED + 0.15)] != '1'
		&& mlx->map[(int)(mlx->hero.pos.x + dirx * MOVSPEED)][(int)
		(mlx->hero.pos.y + diry * MOVSPEED - 0.15)] != '1')) && !(mlx->map[(int)
		(mlx->hero.pos.x + copysign(0.5, dirx))][(int)mlx->hero.pos.y] == '1'
		&& mlx->map[(int)mlx->hero.pos.x][(int)(mlx->hero.pos.y
		+ copysign(0.5, dirx))] == '1'))
	{
		mlx->hero.pos.x += dirx * MOVSPEED;
		mlx->hero.pos.y += diry * MOVSPEED;
		return (1);
	}
	return (0);
}

static int	condition1(t_mlx *mlx, int value, double dirx, double diry)
{
	if (value == 0 && mlx->map[(int)(mlx->hero.pos.x + dirx * MOVSPEED + 0.15)]
	[(int)(mlx->hero.pos.y + diry * MOVSPEED)] != '1' && mlx->map[(int)
	(mlx->hero.pos.x + dirx * MOVSPEED - 0.15)][(int)(mlx->hero.pos.y + diry
	* MOVSPEED)] != '1' && mlx->map[(int)(mlx->hero.pos.x + dirx * MOVSPEED)]
	[(int)(mlx->hero.pos.y + diry * MOVSPEED + 0.15)] != '1' && mlx->map[(int)
	(mlx->hero.pos.x + dirx * MOVSPEED)][(int)(mlx->hero.pos.y + diry * MOVSPEED
	- 0.15)] != '1')
	{
		mlx->hero.pos.x += dirx * MOVSPEED;
		mlx->hero.pos.y += diry * MOVSPEED;
		return (1);
	}
	return (0);
}

void	input_is_key_move(t_mlx *mlx, int value, int key)
{
	double	dirx;
	double	diry;

	value = update_route(mlx, key, &dirx, &diry);
	if (mlx->map[(int)(mlx->hero.pos.x)][(int)(mlx->hero.pos.y
	+ copysign(0.34, diry))] == '1' && mlx->map[(int)(mlx->hero.pos.x
	+ copysign(0.34, dirx))][(int)(mlx->hero.pos.y)] == '1')
		;
	else if (condition1(mlx, value, dirx, diry) == 0 && value == 0)
		check_and_move1(mlx, key);
	else if (condition2(mlx, value, dirx, diry))
		;
	else if (value == 1 && mlx->map[(int)(mlx->hero.pos.x)][(int)
	(mlx->hero.pos.y + diry * MOVSPEED + copysign(0.15, diry))] != '1')
		mlx->hero.pos.y += diry * MOVSPEED * fabs(sin(diry * M_PI_2));
	else if (value == 1 && mlx->map[(int)(mlx->hero.pos.x + dirx * MOVSPEED
			+ copysign(0.15, dirx))][(int)(mlx->hero.pos.y)] != '1')
		mlx->hero.pos.x += dirx * MOVSPEED * fabs(sin(dirx * M_PI_2));
	else if (value == 2 && mlx->map[(int)(mlx->hero.pos.x + dirx * MOVSPEED
			+ copysign(0.15, dirx))][(int)(mlx->hero.pos.y)] != '1')
		mlx->hero.pos.x += dirx * MOVSPEED * fabs(sin(dirx * M_PI_2));
	else if (value == 2 && mlx->map[(int)(mlx->hero.pos.x)][(int)
	(mlx->hero.pos.y + diry * MOVSPEED + copysign(0.15, diry))] != '1')
		mlx->hero.pos.y += diry * MOVSPEED * fabs(sin(diry * M_PI_2));
}
