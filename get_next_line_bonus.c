/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:12:47 by aceauses          #+#    #+#             */
/*   Updated: 2023/06/09 11:27:40 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*get_text_fd(int fd, char *buffer)
{
	char	*tmp;
	int		bytes_readed;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_readed = 1;
	while (bytes_readed > 0)
	{
		bytes_readed = read(fd, tmp, BUFFER_SIZE);
		if (bytes_readed == -1)
			return (free(tmp), tmp = NULL, free(buffer), buffer = NULL, NULL);
		tmp[bytes_readed] = '\0';
		buffer = free_join(buffer, tmp);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	return (free(tmp), buffer);
}

static char	*get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (buffer[i] == '\0' || buffer == NULL)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (line == NULL)
		return (free(buffer), free(line), NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\n';
	if (buffer[i] == '\0')
		line[i] = '\0';
	return (line);
}

static void	*update_buffer(char *buffer)
{
	char	*new;
	int		j;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	new = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		new[j++] = buffer[i++];
	return (free(buffer), new);
}
/* [100000] == 'aaaaaa\n
				bbbbbb\n
				cccccc\n
				dddddd'*/

char	*get_next_line(int fd)
{
	static char	*buffer[OPENMAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = get_text_fd(fd, buffer[fd]);
	if (buffer[fd] == NULL)
		return (NULL);
	line = get_line(buffer[fd]);
	if (line == NULL)
		return (free(buffer[fd]), buffer[fd] = NULL, free(line), NULL);
	buffer[fd] = update_buffer(buffer[fd]);
	if (buffer[fd] == NULL)
		free(buffer[fd]);
	return (line);
}
