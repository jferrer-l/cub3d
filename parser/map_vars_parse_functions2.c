/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_vars_parse_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marza-ga <marza-ga-@student.42barcelo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/03/04 22:17:00 by marza-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	parse_var_ft(char *map_info, int index, t_mlx *mlx)
{
	index += 2;
	if (map_info[index] != ' ')
		return (0);
	while (map_info[index] && map_info[index] == ' ')
		index++;
	if (map_info[index] == '\n' || map_info[index] == '\0')
		return (0);
	while (map_info[index] != '\n' && map_info[index] != '\0'
		&& map_info[index] != ' ')
	{
		mlx->mapvars.ft = ft_strjoin_char(mlx->mapvars.ft, map_info[index]);
		index++;
	}
	if (map_info[index] == '\n' || map_info[index] == '\0')
		return (index);
	return (0);
}

int	parse_var_ct(char *map_info, int index, t_mlx *mlx)
{
	index += 2;
	if (map_info[index] != ' ')
		return (0);
	while (map_info[index] && map_info[index] == ' ')
		index++;
	if (map_info[index] == '\n' || map_info[index] == '\0')
		return (0);
	while (map_info[index] != '\n' && map_info[index] != '\0'
		&& map_info[index] != ' ')
	{
		mlx->mapvars.ct = ft_strjoin_char(mlx->mapvars.ct, map_info[index]);
		index++;
	}
	if (map_info[index] == '\n' || map_info[index] == '\0')
		return (index);
	return (0);
}

int	parse_var_f(char *map_info, int index, t_mlx *mlx)
{
	index += 1;
	if (map_info[index] != ' ')
		return (0);
	while (map_info[index] && map_info[index] == ' ')
		index++;
	if (map_info[index] == '\n' || map_info[index] == '\0')
		return (0);
	while (map_info[index] != '\n' && map_info[index] != '\0'
		&& map_info[index] != ' ')
	{
		mlx->mapvars.f = ft_strjoin_char(mlx->mapvars.f, map_info[index]);
		index++;
	}
	if (map_info[index] == '\n' || map_info[index] == '\0')
		return (index);
	return (0);
}

int	parse_var_c(char *map_info, int index, t_mlx *mlx)
{
	index += 1;
	if (map_info[index] != ' ')
		return (0);
	while (map_info[index] && map_info[index] == ' ')
		index++;
	if (map_info[index] == '\n' || map_info[index] == '\0')
		return (0);
	while (map_info[index] != '\n' && map_info[index] != '\0'
		&& map_info[index] != ' ')
	{
		mlx->mapvars.c = ft_strjoin_char(mlx->mapvars.c, map_info[index]);
		index++;
	}
	if (map_info[index] == '\n' || map_info[index] == '\0')
		return (index);
	return (0);
}
