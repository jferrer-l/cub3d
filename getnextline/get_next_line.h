/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marza-ga <marza-ga-@student.42barcelo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/02/04 22:17:00 by marza-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include	<stdlib.h>
# include	<unistd.h>
# include	<stdio.h>
# include	<errno.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 	42
# endif

char	*get_next_line(int fd);
char	*get_the_line(char *info_storage);
char	*read_in_chunks(char *info_storage, int fd);
char	*clean_line_in_info_storage(char *info_storage);
size_t	ft_strjoin_getsize_including_if_no_string(char *s);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
int		check_err_and_free_s1_if_need(void *ptr, char*s1);
#endif
