/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_routes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 05:56:12 by jferrer-          #+#    #+#             */
/*   Updated: 2022/07/15 06:20:47 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static int	check_route_up_down(t_mlx *mlx, int index)
{
	double	vx;
	double	vy;
	double	px;
	double	py;

	px = mlx->hero.pos.x;
	py = mlx->hero.pos.y;
	vx = mlx->hero.vector_view.x * index;
	vy = mlx->hero.vector_view.y * index;
	if ((int)(py + vy * MOVSPEED) != (int)py)
		return (1);
	else if ((int)(px + vx * MOVSPEED) != (int)px)
		return (2);
	return (0);
}

static int	check_route_right(t_mlx *mlx)
{
	double	vx;
	double	vy;
	double	px;
	double	py;

	px = mlx->hero.pos.x;
	py = mlx->hero.pos.y;
	vx = mlx->hero.vector_view.x;
	vy = mlx->hero.vector_view.y;
	update_direction_right(&vx, &vy, 0.0);
	if ((int)(py + vy * MOVSPEED) != (int)py)
		return (1);
	else if ((int)(px + vx * MOVSPEED) != (int)px)
		return (2);
	return (0);
}

static int	check_route_left(t_mlx *mlx)
{
	double	vx;
	double	vy;
	double	px;
	double	py;

	px = mlx->hero.pos.x;
	py = mlx->hero.pos.y;
	vx = mlx->hero.vector_view.x;
	vy = mlx->hero.vector_view.y;
	update_direction_left(&vx, &vy, 0.0);
	if ((int)(py + vy * MOVSPEED) != (int)py)
		return (1);
	else if ((int)(px + vx * MOVSPEED) != (int)px)
		return (2);
	return (0);
}

int	update_route(t_mlx *mlx, int key, double *dirx, double *diry)
{
	int	value;

	value = 0;
	*dirx = mlx->hero.vector_view.x;
	*diry = mlx->hero.vector_view.y;
	if (key == KEY_UP)
		value = check_route_up_down(mlx, 1);
	else if (key == KEY_DOWN)
	{
		*dirx *= -1;
		*diry *= -1;
		value = check_route_up_down(mlx, -1);
	}
	else if (key == KEY_RIGHT)
	{
		update_direction_left(dirx, diry, 0.0);
		value = check_route_left(mlx);
	}
	else if (key == KEY_LEFT)
	{
		update_direction_right(dirx, diry, 0.0);
		value = check_route_right(mlx);
	}
	return (value);
}

void	move_if_needed(t_mlx *mlx)
{
	if (mlx->map[(int)(mlx->hero.pos.x + 0.149)][(int)(mlx->hero.pos.y)] == '1')
		mlx->hero.pos.x = (int)(mlx->hero.pos.x) + 0.85;
	if (mlx->map[(int)(mlx->hero.pos.x + 0.149)][(int)(mlx->hero.pos.y)] == '1')
		mlx->hero.pos.x = (int)(mlx->hero.pos.x) + 0.85;
	if (mlx->map[(int)(mlx->hero.pos.x - 0.149)][(int)(mlx->hero.pos.y)] == '1')
		mlx->hero.pos.x = (int)(mlx->hero.pos.x) + 0.15;
	if (mlx->map[(int)(mlx->hero.pos.x)][(int)(mlx->hero.pos.y + 0.149)] == '1')
		mlx->hero.pos.y = (int)(mlx->hero.pos.y) + 0.85;
	if (mlx->map[(int)(mlx->hero.pos.x)][(int)(mlx->hero.pos.y - 0.149)] == '1')
		mlx->hero.pos.y = (int)(mlx->hero.pos.y) + 0.15;
}
