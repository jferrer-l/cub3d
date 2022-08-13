/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:24:33 by jferrer-          #+#    #+#             */
/*   Updated: 2022/07/18 13:24:33 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_mapvalidator_struct(t_mlx *mlx)
{
	mlx->mapvars.no = NULL;
	mlx->mapvars.so = NULL;
	mlx->mapvars.we = NULL;
	mlx->mapvars.ea = NULL;
	mlx->mapvars.f = NULL;
	mlx->mapvars.c = NULL;
	mlx->mapvars.ft = NULL;
	mlx->mapvars.ct = NULL;
}
