/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/07/15 10:27:49 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	open_map(char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	return (fd);
}

int	map_lines_height(char *map_info)
{
	int	rows;
	int	count;
	int	line_width;

	rows = 0;
	count = 0;
	line_width = 0;
	while (map_info[count])
	{
		if (map_info[count] == '\n')
		{
			rows++;
			line_width = 0;
		}
		else
			line_width++;
		count++;
	}
	if (map_info[count] == '\0' && line_width > 0)
		rows++;
	return (rows);
}

char	*get_initial_map_info(char *map_name, t_mlx *mlx)
{
	char	*map_info;
	char	*line;
	int		fd;
	int		end_read;

	end_read = 0;
	map_info = NULL;
	errno = 0;
	fd = open_map(map_name);
	if (fd < 0)
		exit_error_cant_open_map(mlx);
	while (!end_read)
	{
		line = get_next_line(fd);
		if (!line)
			end_read = 1;
		else
			map_info = ft_strjoin(map_info, line);
		free(line);
	}
	close(fd);
	if (!map_info)
		exit_not_map_info(map_info, mlx);
	return (map_info);
}

int	map_lines_width(char *map_info)
{
	int	linecount;
	int	current_line;
	int	count;

	linecount = 0;
	current_line = 0;
	count = 0;
	while (map_info[count] != '\0')
	{
		while (map_info[count] != '\0' && map_info[count] != '\n')
		{
			current_line++;
			count++;
		}
		if (current_line > linecount)
			linecount = current_line;
		current_line = 0;
		if (map_info[count] != '\0')
			count++;
	}
	return (linecount);
}
