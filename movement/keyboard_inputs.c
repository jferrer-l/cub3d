/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_inputs2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/07/15 06:27:02 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	update_direction_right(double	*dirx, double *diry, double temp)
{
	if (*dirx > 0 && *diry >= 0)
	{
		temp = *diry;
		*diry = *dirx * -1;
		*dirx = temp;
	}
	else if (*dirx > 0 && *diry < 0)
	{
		temp = *dirx;
		*dirx = *diry;
		*diry = temp * -1;
	}
	else if (*diry > 0 && *dirx <= 0)
	{
		temp = *dirx;
		*dirx = *diry;
		*diry = temp * -1;
	}
	else if (*diry < 0 && *dirx < 0)
	{
		temp = *diry;
		*diry = *dirx * -1;
		*dirx = temp;
	}
}

void	update_direction_left(double *dirx, double *diry, double temp)
{
	if (*dirx > 0 && *diry >= 0)
	{
		temp = *diry;
		*diry = *dirx;
		*dirx = temp * -1;
	}
	else if (*dirx > 0 && *diry < 0)
	{
		temp = *dirx;
		*dirx = *diry * -1;
		*diry = temp;
	}
	else if (*diry > 0 && *dirx <= 0)
	{
		temp = *dirx;
		*dirx = *diry * -1;
		*diry = temp;
	}
	else if (*diry < 0 && *dirx < 0)
	{
		temp = *diry;
		*diry = *dirx;
		*dirx = temp * -1;
	}
}

void	input_is_key_rotate_right(t_mlx *mlx, double planex, double planey)
{
	double	dirx;
	double	diry;
	double	olddirx;
	double	oldplanex;

	dirx = mlx->hero.vector_view.x;
	diry = mlx->hero.vector_view.y;
	olddirx = dirx;
	oldplanex = planex;
	mlx->hero.vector_view.x = dirx * cos(ROTSPEED) - diry * sin(ROTSPEED);
	mlx->hero.vector_view.y = olddirx * sin(ROTSPEED) + diry * cos(ROTSPEED);
	mlx->ray.planex = planex * cos(ROTSPEED) - planey * sin(ROTSPEED);
	mlx->ray.planey = oldplanex * sin(ROTSPEED) + planey * cos(ROTSPEED);
	mlx->backgroundx -= 10;
}

void	input_is_key_rotate_left(t_mlx *mlx, double planex, double planey)
{
	double	dirx;
	double	diry;
	double	olddirx;
	double	oldplanex;

	dirx = mlx->hero.vector_view.x;
	diry = mlx->hero.vector_view.y;
	olddirx = dirx;
	oldplanex = planex;
	mlx->hero.vector_view.x = dirx * cos(-ROTSPEED) - diry * sin(-ROTSPEED);
	mlx->hero.vector_view.y = olddirx * sin(-ROTSPEED) + diry * cos(-ROTSPEED);
	mlx->ray.planex = planex * cos(-ROTSPEED) - planey * sin(-ROTSPEED);
	mlx->ray.planey = oldplanex * sin(-ROTSPEED) + planey * cos(-ROTSPEED);
	mlx->backgroundx += 10;
}

int	input(int key, t_mlx *mlx)
{
	if (key == ESC)
		exit_game(mlx);
	else if (key == KEY_UP || key == KEY_DOWN
		|| key == KEY_LEFT || key == KEY_RIGHT)
	{
		input_is_key_move(mlx, 1, key);
		move_if_needed(mlx);
	}
	else if (key == KEY_ROTLEFT)
		input_is_key_rotate_left(mlx, mlx->ray.planex, mlx->ray.planey);
	else if (key == KEY_ROTRIGHT)
		input_is_key_rotate_right(mlx, mlx->ray.planex, mlx->ray.planey);
	return (1);
}
