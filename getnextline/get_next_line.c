/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marza-ga <marza-ga-@student.42barcelo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/02/04 22:17:00 by marza-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_err_and_free_s1_if_need(void *ptr, char *s1)
{
	if (!ptr)
	{
		free(s1);
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*info_storage;
	char		*return_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if ((info_storage && !ft_strchr(info_storage, '\n')) || !info_storage)
		info_storage = read_in_chunks(info_storage, fd);
	if (info_storage == NULL)
		return (NULL);
	return_line = get_the_line(info_storage);
	if (return_line == NULL)
	{
		free(info_storage);
		return (NULL);
	}
	info_storage = clean_line_in_info_storage(info_storage);
	return (return_line);
}

char	*read_in_chunks(char *info_storage, int fd)
{
	int		num_readed_bytes;
	char	*buffer;

	errno = 0;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	num_readed_bytes = 1;
	while (num_readed_bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		num_readed_bytes = read(fd, buffer, BUFFER_SIZE);
		if (num_readed_bytes > 0)
		{
			buffer[num_readed_bytes] = '\0';
			info_storage = ft_strjoin(info_storage, buffer);
		}
	}
	free(buffer);
	if (num_readed_bytes == -1)
	{
		free(info_storage);
		return (NULL);
	}
	return (info_storage);
}

char	*get_the_line(char *info_storage)
{
	char	*return_line;
	int		count;

	count = 0;
	if (!info_storage[count])
		return (NULL);
	return_line = malloc((ft_strlen(info_storage) + 1) * sizeof(char));
	if (!return_line)
		return (NULL);
	while (info_storage[count] != '\n' && info_storage[count] != '\0')
	{
		return_line[count] = info_storage[count];
		count++;
	}
	if (info_storage[count] == '\n')
	{
		return_line[count] = info_storage[count];
		count++;
	}
	return_line[count] = '\0';
	return (return_line);
}

char	*clean_line_in_info_storage(char *info_storage)
{
	size_t	count;
	size_t	count2;
	char	*cln_storage;

	count = 0;
	count2 = 0;
	while (info_storage[count] && info_storage[count] != '\n')
		count++;
	if (!info_storage[count])
	{
		free(info_storage);
		return (NULL);
	}
	cln_storage = malloc(sizeof(char) * (ft_strlen(info_storage) - count + 1));
	if (!cln_storage)
		return (NULL);
	count++;
	while (info_storage[count])
		cln_storage[count2++] = info_storage[count++];
	cln_storage[count2] = '\0';
	free(info_storage);
	return (cln_storage);
}
