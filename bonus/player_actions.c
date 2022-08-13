/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marza-ga <marza-ga-@student.42barcelo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/03/04 22:17:00 by marza-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	player_action_recharge(t_mlx *mlx)
{
	if (mlx->gun.animation != 2)
	{
		mlx->gun.sp_index = 0;
		mlx->gun.sp_time = 0;
		mlx->gun.animation = 2;
	}
}

void	player_action_shot(t_mlx *mlx)
{
	if (mlx->gun.animation != 2)
	{
		mlx->gun.sp_index = 0;
		mlx->gun.sp_time = 0;
		mlx->gun.animation = 1;
	}
}

void	player_action_use(t_mlx *mlx)
{
	int	x;
	int	y;

	x = (int)mlx->hero.pos.x;
	y = (int)mlx->hero.pos.y;
	if (mlx->map[x - 1][y] == 'D')
		open_door(mlx, x - 1, y);
	if (mlx->map[x - 1][y + 1] == 'D')
		open_door(mlx, x - 1, y + 1);
	if (mlx->map[x][y + 1] == 'D')
		open_door(mlx, x, y + 1);
	if (mlx->map[x + 1][y + 1] == 'D')
		open_door(mlx, x + 1, y + 1);
	if (mlx->map[x + 1][y] == 'D')
		open_door(mlx, x + 1, y);
	if (mlx->map[x - 1][y - 1] == 'D')
		open_door(mlx, x - 1, y - 1);
	if (mlx->map[x][y - 1] == 'D')
		open_door(mlx, x, y - 1);
	if (mlx->map[x + 1][y - 1] == 'D')
		open_door(mlx, x + 1, y - 1);
}
