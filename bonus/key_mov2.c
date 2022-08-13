/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marza-ga <marza-ga-@student.42barcelo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/03/04 22:17:00 by marza-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	check_and_move2(t_mlx *mlx, t_move *mv)
{
	if (!walkable(mv->new_pos_x, mv->new_pos_y + 0.16, mlx))
	{
		mlx->hero.pos.x += mv->move_vector_x * fabs(sin(mv->dirx * M_PI_2));
		mlx->hero.pos.y = (int)(mlx->hero.pos.y + 1) - 0.15;
	}
	else if (!walkable(mv->new_pos_x, mv->new_pos_y - 0.16, mlx))
	{
		mlx->hero.pos.x += mv->move_vector_x * fabs(sin(mv->dirx * M_PI_2));
		mlx->hero.pos.y = (int)(mlx->hero.pos.y) + 0.15;
	}
}

void	check_and_move(t_mlx *mlx, t_move *mv)
{
	if (!walkable(mv->new_pos_x + 0.16, mv->new_pos_y, mlx))
	{
		mlx->hero.pos.y += mv->move_vector_y * fabs(sin(mv->diry * M_PI_2));
		mlx->hero.pos.x = (int)(mlx->hero.pos.x + 1) - 0.15;
	}
	else if (!walkable(mv->new_pos_x - 0.16, mv->new_pos_y, mlx))
	{
		mlx->hero.pos.y += mv->move_vector_y * fabs(sin(mv->diry * M_PI_2));
		mlx->hero.pos.x = (int)(mlx->hero.pos.x) + 0.15;
	}
	else
		check_and_move2(mlx, mv);
}

void	calculate_move_vars(t_mlx *mlx, t_move *mv)
{
	mv->start_x = mlx->hero.pos.x;
	mv->start_y = mlx->hero.pos.y;
	mv->move_vector_y = mv->diry * MOVSPEED;
	mv->move_vector_x = mv->dirx * MOVSPEED;
	mv->new_pos_x = mlx->hero.pos.x + mv->dirx * MOVSPEED;
	mv->new_pos_y = mlx->hero.pos.y + mv->diry * MOVSPEED;
}

int	walkable(int x, int y, t_mlx *mlx)
{
	if (mlx->map[x][y] == '1')
		return (0);
	if (mlx->map[x][y] == 'D')
		return (0);
	return (1);
}
