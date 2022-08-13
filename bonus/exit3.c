/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marza-ga <marza-ga-@student.42barcelo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/03/04 22:17:00 by marza-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	exit_not_map_info(char *map_info, t_mlx *mlx)
{
	write(2, "Error: Map file content is invalid\n", 35);
	free(map_info);
	mlx_destroy(mlx->mlx_ptr);
	check_leaks();
	exit(-1);
}
