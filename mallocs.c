/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallocs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/07/15 07:44:37 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	create_map_x_malloc(t_mlx *mlx, char *map_info)
{
	mlx->map = (char **)malloc(sizeof(char *) * (mlx->map_width + 1));
	if (!mlx->map)
	{
		free(map_info);
		free_map_textures_vars(mlx);
		mlx_destroy(mlx->mlx_ptr);
		perror(NULL);
		exit(errno);
	}
}

char	*create_map_y_malloc(t_mlx *mlx, int count, char *map_info)
{
	char	*temp;

	temp = (char *)malloc(sizeof(char) * (mlx->map_height + 1));
	if (!temp)
	{
		count--;
		while (count >= 0)
		{
			free(mlx->map[count]);
			count--;
		}
		free(mlx->map);
		free(map_info);
		free_map_textures_vars(mlx);
		mlx_destroy(mlx->mlx_ptr);
		perror(NULL);
		exit(errno);
	}
	return (temp);
}
