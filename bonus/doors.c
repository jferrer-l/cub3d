/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                             :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: marza-ga <marza-ga-@student.42barcelo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/03/04 22:17:00 by marza-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	close_door_when_ready(t_mlx *mlx, t_door *door)
{
	if (door->x == (int)mlx->hero.pos.x)
		if (door->y == (int)mlx->hero.pos.y)
			return ;
	door->sp_time++;
	if (door->sp_time == 40)
	{
		mlx->map[door->x][door->y] = 'D';
		door->state = 0;
		door->sp_time = 0;
	}
}

void	render_doors(t_mlx *mlx)
{
	int	index;

	index = 0;
	while (index < mlx->num_doors)
	{
		if (mlx->doors[index].state == 1)
			close_door_when_ready(mlx, &mlx->doors[index]);
		index++;
	}
}

t_door	*get_door_whit_cords(t_mlx *mlx, int x, int y)
{
	int	index;

	index = 0;
	while (index < mlx->num_doors)
	{
		if (mlx->doors[index].x == x)
			if (mlx->doors[index].y == y)
				return (&mlx->doors[index]);
		index++;
	}
	return (NULL);
}

void	open_door(t_mlx *mlx, int x, int y)
{
	t_door	*door;

	mlx->map[x][y] = '0';
	door = get_door_whit_cords(mlx, x, y);
	door->state = 1;
}
