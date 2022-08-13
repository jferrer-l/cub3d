/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marza-ga <marza-ga-@student.42barcelo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:00:00 by marza-ga          #+#    #+#             */
/*   Updated: 2021/11/05 12:00:00 by marza-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
/*
double	get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);//hay que quitar esto
	return ((tv.tv_sec % 1000) + ((double)tv.tv_usec / 1000000));
}

void	calcualte_fps(t_mlx *game)
{
	char			str[4];
	int				time;
	int				count;
	static double	previouse = 0;

	game->time = get_timestamp();
	time = 1.0 / (game->time - previouse);
	previouse = game->time;
	count = 0;
	if (time / 100)
		str[count++] = '0' + time / 100;
	if (time / 10)
		str[count++] = '0' + (time % 100) / 10;
	if (time / 1)
		str[count++] = '0' + time % 10;
	str[count] = '\0';
	mlx_string_put(game->mlx_ptr, game->win, 20, 20, 0xFFFF00, "FPS:");
	mlx_string_put(game->mlx_ptr, game->win, 49, 20, 0xFFFF00, str);
}
*/
