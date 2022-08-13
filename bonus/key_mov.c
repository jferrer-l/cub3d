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

static int	condition2(t_mlx *mlx, int value, t_move *mv)
{
	if ((walkable(mv->start_x + copysign(0.5, mv->dirx), mv->start_y, mlx)
			&& walkable(mv->start_x, mv->start_y + copysign(0.5, mv->dirx),
				mlx)))
	{
		if (value == 1 && walkable(mv->new_pos_x, mv->new_pos_y, mlx)
			&& walkable(mv->new_pos_x + 0.15, mv->new_pos_y, mlx)
			&& walkable(mv->new_pos_x - 0.15, mv->new_pos_y, mlx))
		{
			mlx->hero.pos.x = mv->new_pos_x;
			mlx->hero.pos.y = mv->new_pos_y;
			return (1);
		}
		else if (value == 2 && walkable(mv->new_pos_x, mv->new_pos_y, mlx)
			&& walkable(mv->new_pos_x, mv->new_pos_y + 0.15, mlx)
			&& walkable(mv->new_pos_x, mv->new_pos_y - 0.15, mlx))
		{
			mlx->hero.pos.x = mv->new_pos_x;
			mlx->hero.pos.y = mv->new_pos_y;
			return (1);
		}
	}
	return (0);
}

static int	condition1(t_mlx *mlx, int value, t_move *mv)
{
	if (value == 0)
	{
		if (walkable(mv->new_pos_x + 0.15, mv->new_pos_y, mlx)
			&& walkable(mv->new_pos_x - 0.15, mv->new_pos_y, mlx)
			&& walkable(mv->new_pos_x, mv->new_pos_y + 0.15, mlx)
			&& walkable(mv->new_pos_x, mv->new_pos_y - 0.15, mlx)
		)
		{
			mlx->hero.pos.x = mv->new_pos_x;
			mlx->hero.pos.y = mv->new_pos_y;
			return (1);
		}
	}
	return (0);
}

void	input_is_key_move2(t_mlx *mlx, int value, t_move mv)
{
	if (value == 1)
	{
		if (walkable(mv.start_x, mv.new_pos_y + copysign(0.15, mv.diry), mlx))
			mlx->hero.pos.y += mv.move_vector_y * fabs(sin(mv.diry * M_PI_2));
		else if (walkable(mv.new_pos_x + copysign(0.15, mv.dirx),
				mv.start_y, mlx))
			mlx->hero.pos.x += mv.move_vector_x * fabs(sin(mv.dirx * M_PI_2));
	}
	else if (value == 2)
	{
		if (walkable(mv.new_pos_x + copysign(0.15, mv.dirx), mv.start_y, mlx))
			mlx->hero.pos.x += mv.move_vector_x * fabs(sin(mv.dirx * M_PI_2));
		else if (walkable(mv.start_x, mv.new_pos_y + copysign(0.15, mv.diry),
				mlx))
			mlx->hero.pos.y += mv.move_vector_y * fabs(sin(mv.diry * M_PI_2));
	}
}

void	input_is_key_move(t_mlx *mlx, int value, int key)
{
	t_move	mv;

	value = update_route(mlx, key, &mv.dirx, &mv.diry);
	calculate_move_vars(mlx, &mv);
	if (!walkable(mv.start_x, mv.start_y + copysign(0.34, mv.diry), mlx)
		&& !walkable(mv.start_x + copysign(0.34, mv.dirx), mv.start_y, mlx))
		return ;
	else if (condition1(mlx, value, &mv) == 0 && value == 0)
		check_and_move(mlx, &mv);
	else if (condition2(mlx, value, &mv))
		return ;
	else
		input_is_key_move2(mlx, value, mv);
}
