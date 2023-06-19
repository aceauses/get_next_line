/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:45:36 by aceauses          #+#    #+#             */
/*   Updated: 2023/06/09 11:28:39 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPENMAX
#  define OPENMAX 10240
# endif

# include	<unistd.h>
# include	<string.h>
# include	<stdio.h>
# include	<fcntl.h>
# include	<stdlib.h>

char		*get_next_line(int fd);

void		*ft_calloc(size_t count, size_t size);
char		*ft_strjoin_gnl(char const *line, char const *new_line);
size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *str, int c);
char		*free_join(char *buffer, char *buff);

#endif