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

int	parse_var_no(char *map_info, int index, t_mlx *mlx)
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
		mlx->mapvars.no = ft_strjoin_char(mlx->mapvars.no, map_info[index]);
		index++;
	}
	if (map_info[index] == '\n' || map_info[index] == '\0')
		return (index);
	return (0);
}

int	parse_var_so(char *map_info, int index, t_mlx *mlx)
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
		mlx->mapvars.so = ft_strjoin_char(mlx->mapvars.so, map_info[index]);
		index++;
	}
	if (map_info[index] == '\n' || map_info[index] == '\0')
		return (index);
	return (0);
}

int	parse_var_we(char *map_info, int index, t_mlx *mlx)
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
		mlx->mapvars.we = ft_strjoin_char(mlx->mapvars.we, map_info[index]);
		index++;
	}
	if (map_info[index] == '\n' || map_info[index] == '\0')
		return (index);
	return (0);
}

int	parse_var_ea(char *map_info, int index, t_mlx *mlx)
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
		mlx->mapvars.ea = ft_strjoin_char(mlx->mapvars.ea, map_info[index]);
		index++;
	}
	if (map_info[index] == '\n' || map_info[index] == '\0')
		return (index);
	return (0);
}
