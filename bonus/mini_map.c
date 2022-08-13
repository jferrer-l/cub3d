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

void	draw_minimap_image_whit_laoded_map(t_mlx *mlx)
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
	while (count_y < mlx->map_height)
	{
		while (count_x < mlx->map_width)
		{
			if (mlx->map[count_x][count_y] == '1')
				draw_in_minimap_img_px_in_size(count2, count_y,
					0xCC00FF00, mlx);
			count2 += mlx->minimap.px_size;
			count_x++;
		}
		count2 = (mlx->minimap.img.width * count_y * 3);
		count_y++;
		count_x = 0;
	}
}

void	load_minimap_image(t_mlx *mlx)
{
	mlx->minimap.px_size = 4;
	mlx->minimap.img.width = mlx->map_width * mlx->minimap.px_size;
	mlx->minimap.img.height = mlx->map_height * mlx->minimap.px_size;
	mlx->minimap.pos.x = 20;
	mlx->minimap.pos.y = 370;
	mlx->minimap.width = 190;
	mlx->minimap.height = 90;
	mlx->minimap.img.img_ptr = mlx_new_image(mlx->mlx_ptr,
			mlx->minimap.img.width, mlx->minimap.img.height);
	if (mlx->minimap.img.img_ptr == NULL)
	{
		write(2, "Error cargando imgs ptr para minimapa!\n", 39);
		return ;
	}
	mlx->minimap.img.data = (int *)mlx_get_data_addr(mlx->minimap.img.img_ptr,
			&mlx->minimap.img.bpp, &mlx->minimap.img.size_l,
			&mlx->minimap.img.endian);
	if (mlx->minimap.img.data == NULL)
	{
		write(2, "Error cargando dataimgs ptr para minimapa!\n", 43);
		return ;
	}
	load_image(&mlx->minimap.background, "imgs/frame_minimap.xpm", mlx);
	draw_minimap_image_color_background(mlx);
	draw_minimap_image_whit_laoded_map(mlx);
}

void	init_draw_minimap_to_screen_vars(t_mlx *mlx, t_minimap *mm)
{
	mm->start_y = mlx->hero.pos.y * mlx->minimap.px_size;
	mm->start_x = mlx->hero.pos.x * mlx->minimap.px_size;
	mm->count_x = 0;
	mm->count_y = 0;
	mm->start_print_x = mlx->minimap.pos.x
		+ mlx->minimap.width / 2 - mm->start_x;
	mm->start_print_y = mlx->minimap.pos.y
		+ mlx->minimap.height / 2 - mm->start_y + mlx->minimap.px_size - 1;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
		mlx->minimap.background.img_ptr, mlx->minimap.pos.x - 10,
		mlx->minimap.pos.y - 10);
}

void	draw_minimap_to_screen(t_mlx *mlx)
{
	unsigned long	color;
	t_minimap		mm;

	init_draw_minimap_to_screen_vars(mlx, &mm);
	while (mm.count_y < mlx->minimap.img.height)
	{
		while (mm.count_x < mlx->minimap.img.width && mm.start_print_x
			+ mm.count_x < mlx->minimap.width + mlx->minimap.pos.x
			&& mm.start_print_y + mm.count_y < mlx->minimap.pos.y
			+ mlx->minimap.height)
		{	
			if (mm.start_print_x + mm.count_x > mlx->minimap.pos.x
				&& mm.start_print_y + mm.count_y > mlx->minimap.pos.y)
			{
				color = mlx->minimap.img.data[mm.count_x
					+ mlx->minimap.img.width * mm.count_y];
				mlx_pixel_put(mlx->mlx_ptr, mlx->win, mm.start_print_x
					+ mm.count_x, mm.start_print_y + mm.count_y, color);
			}
			mm.count_x++;
		}
		mm.count_x = 0;
		mm.count_y++;
	}
	draw_player_in_minimap(mlx);
}
