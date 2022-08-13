/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/07/15 07:41:52 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_prepare_s1(char *s1)
{
	s1 = (char *)malloc(1 * sizeof(char));
	if (!s1)
		return (NULL);
	s1[0] = '\0';
	return (s1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	size_t	count;
	char	*ptr;

	if (!s1)
	{
		s1 = ft_strjoin_prepare_s1(s1);
		if (!s1)
			return (NULL);
	}
	count = 0;
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strjoin_getsize_including_if_no_string(s2);
	ptr = malloc(sizeof(char) * (size_s1 + size_s2 +1));
	if (check_err_and_free_s1_if_need(ptr, s1))
		return (NULL);
	while (count++ < size_s1)
		ptr[count -1] = s1[count -1];
	count = 0;
	while (count++ < size_s2)
		ptr[size_s1 + count -1] = s2[count -1];
	ptr[size_s1 + count -1] = '\0';
	free(s1);
	return (ptr);
}

size_t	ft_strjoin_getsize_including_if_no_string(char *s)
{
	size_t	size;

	if (s)
		size = ft_strlen(s);
	else
		size = 0;
	return (size);
}

size_t	ft_strlen(char *s)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

char	*ft_strchr(char *s, int c)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
	{
		if (s[count] == (char)c)
			return ((char *)&s[count]);
		count++;
	}
	if ((char)c == '\0')
		return ((char *)&s[count]);
	return (NULL);
}
