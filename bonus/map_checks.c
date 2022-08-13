/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:40:41 by jferrer-          #+#    #+#             */
/*   Updated: 2022/07/15 13:40:42 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static int	check_extension(char *str, t_mlx *mlx)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i < 4)
	{
		free_map_memory(mlx);
		free_map_textures_vars(mlx);
		free(mlx->doors);
		mlx_destroy(mlx->mlx_ptr);
		write(2, "Error: Invalid image name\n", 27);
		check_leaks();
		exit(-1);
	}
	if (str[i - 1] == 'm' && str[i - 2] == 'p'
		&& str[i - 3] == 'x' && str[i - 4] == '.')
		return (0);
	return (1);
}

static int	check_route(char *str)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	if (str[0] == '/')
		return (1);
	while (str[++i])
		if (i > 1 && str[i] == '/' && str[i - 1] == '.' && str[i - 2] == '.')
			return (1);
	return (0);
}

static int	get_color(char	*str, int aux, int rgb)
{
	int	i;
	int	index;
	int	numc;

	i = -1;
	while (str[++i])
		numc = 0;
	index = 1;
	while (--i >= 0)
	{
		if (str[i] >= '0' && str[i] <= '9' && index < 101
			&& (str[i] != '2' || str[i + 1] != '5' || str[i + 2] != '6'))
		{
			rgb += (str[i] - '0') * index * aux / 256;
			index *= 10;
		}
		else if (str[i] != ',' || ++numc > 2 || rgb >= aux)
			return (-1);
		else
			aux *= 256;
		if (str[i] == ',')
			index = 1;
	}
	return ((rgb & 0xFF0000) | (rgb & 0x00FF00) | (rgb & 0x0000FF));
}

void	check_map(t_mlx *mlx)
{
	int	i;

	i = 0;
	i += check_extension(mlx->mapvars.no, mlx);
	i += check_extension(mlx->mapvars.so, mlx);
	i += check_extension(mlx->mapvars.we, mlx);
	i += check_extension(mlx->mapvars.ea, mlx);
	if (i > 0)
		exit_error_in_map_vars(4, mlx);
	i += check_route(mlx->mapvars.no);
	i += check_route(mlx->mapvars.so);
	i += check_route(mlx->mapvars.we);
	i += check_route(mlx->mapvars.ea);
	if (i > 0)
		exit_error_in_map_vars(5, mlx);
	mlx->mapvars.floor = get_color(mlx->mapvars.f, 256, 0);
	mlx->mapvars.ceiling = get_color(mlx->mapvars.c, 256, 0);
	if (mlx->mapvars.floor == -1 || mlx->mapvars.ceiling == -1)
		exit_error_in_map_vars(6, mlx);
}
