/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marza-ga <marza-ga-@student.42barcelo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/03/04 22:17:00 by marza-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	draw_minimap_image_color_background(t_mlx *mlx)
{
	int		start_x;
	int		start_y;
	int		count_y;
	int		count_x;
	int		count2;

	count2 = 0;
	count_x = 0;
	count_y = 0;
	start_x = 0;
	start_y = 0;
	while (count_y < mlx->minimap.img.height)
	{
		while (count_x < mlx->minimap.img.width)
		{
			mlx->minimap.img.data[count2] = 0x191919;
			count2++;
			count_x++;
		}
		count_x = 0;
		count2 = (mlx->minimap.img.width * count_y);
		count_y++;
	}
}

void	draw_in_minimap_img_px_in_size(int x, int y, unsigned long color,
			t_mlx *mlx)
{
	mlx->minimap.img.data[x + mlx->minimap.img.width * y] = color;
	mlx->minimap.img.data[x + 1 + mlx->minimap.img.width * y] = color;
	mlx->minimap.img.data[x + 2 + mlx->minimap.img.width * y] = color;
	mlx->minimap.img.data[x + mlx->minimap.img.width * (y + 1)] = color;
	mlx->minimap.img.data[x + mlx->minimap.img.width * (y + 2)] = color;
	mlx->minimap.img.data[x + 1 + mlx->minimap.img.width * (y + 1)] = color;
	mlx->minimap.img.data[x + 1 + mlx->minimap.img.width * (y + 2)] = color;
	mlx->minimap.img.data[x + 2 + mlx->minimap.img.width * (y + 1)] = color;
	mlx->minimap.img.data[x + 2 + mlx->minimap.img.width * (y + 2)] = color;
}

void	draw_player_in_minimap(t_mlx *mlx)
{
	static unsigned long	color = 0xFF0000;
	int						x;
	int						y;

	x = mlx->minimap.pos.x + mlx->minimap.width / 2;
	y = mlx->minimap.pos.y + mlx->minimap.height / 2;
	mlx_pixel_put(mlx->mlx_ptr, mlx->win, x, y, color);
	mlx_pixel_put(mlx->mlx_ptr, mlx->win, x + 1, y, color);
	mlx_pixel_put(mlx->mlx_ptr, mlx->win, x, y + 1, color);
	mlx_pixel_put(mlx->mlx_ptr, mlx->win, x + 1, y + 1, color);
}
