/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marza-ga <marza-ga-@student.42barcelo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/03/04 22:17:00 by marza-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char	*ft_strjoin_char(char *s1, char c)
{
	int		i;
	char	*string;

	i = 0;
	if (!s1 || s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char) * (1));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	string = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (!string)
		return (0);
	while (s1[i] != '\0')
	{
		string[i] = s1[i];
		i++;
	}
	free(s1);
	string[i] = c;
	string[i + 1] = '\0';
	return (string);
}

int	get_line_lenght(char *map_info, int index)
{
	int	count;

	count = 0;
	while (map_info[index] && map_info[index] != '\n')
	{
		index++;
		count++;
	}
	return (count);
}

int	is_empty_line(char *map_info, int index)
{
	while (map_info[index] && map_info[index] != '\n')
	{
		if (map_info[index] != ' ')
			return (0);
		index++;
	}
	return (1);
}

int	advance_empty_line(char *map_info, int index)
{
	while (map_info[index] && map_info[index] != '\n')
		index++;
	if (map_info[index] == '\n')
		index++;
	return (index);
}

int	advance_empty_spaces(char *map_info, int index)
{
	while (map_info[index] && map_info[index] != '\n' && map_info[index] != ' ')
		index++;
	return (index);
}
