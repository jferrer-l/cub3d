/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/07/15 07:41:02 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	exit_error_get_map_name(int err_num, t_mlx *mlx)
{
	if (err_num == 1)
		write(2, "Error: Wrong number of arguments\n", 34);
	if (err_num == 2)
		write(2, "Error: Invalid map name\n", 25);
	if (err_num == 3)
		write(2, "Error: Wrong map extention\n", 28);
	mlx_destroy(mlx->mlx_ptr);
	check_leaks();
	exit (-1);
}

void	exit_error_in_map_vars(int err_num, t_mlx *mlx)
{
	if (err_num == 4)
		write(2, "Invalid file extention", 23);
	if (err_num == 5)
		write(2, "Invalid file route", 19);
	if (err_num == 6)
		write(2, "Invalid rgb code", 19);
	free(mlx->doors);
	free_map_memory(mlx);
	free_map_textures_vars(mlx);
	mlx_destroy(mlx->mlx_ptr);
	check_leaks();
	exit (-1);
}

void	exit_error_cant_open_map(t_mlx *mlx)
{
	perror("Error");
	free(mlx->doors);
	mlx_destroy(mlx->mlx_ptr);
	check_leaks();
	exit(errno);
}

void	exit_error_load_extra_images(t_mlx *mlx, int img_num)
{
	img_num--;
	while (img_num >= 0)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img[img_num].img_ptr);
		img_num--;
	}
	free_map_memory(mlx);
	free(mlx->doors);
	free_map_textures_vars(mlx);
	mlx_destroy(mlx->mlx_ptr);
	free(mlx->img);
	check_leaks();
	exit (-1);
}

void	exit_error_load_walls_images(t_mlx *mlx, int img_num)
{
	img_num--;
	while (img_num >= 4)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img[img_num].img_ptr);
		img_num--;
	}
	free_map_memory(mlx);
	free(mlx->doors);
	free_map_textures_vars(mlx);
	mlx_destroy(mlx->mlx_ptr);
	free(mlx->img);
	check_leaks();
	exit (-1);
}
