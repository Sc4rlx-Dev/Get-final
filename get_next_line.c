/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-raou <oer-raou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:21:04 by oer-raou          #+#    #+#             */
/*   Updated: 2024/03/28 17:59:02 by oer-raou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_next(char **temp)
{
	char	*line;
	char	*ptr;

	ptr = *temp;
	while (*ptr && *ptr != '\n')
		++ptr;
	ptr += (*ptr == '\n');
	line = ft_substr(*temp, 0, (size_t)(ptr - *temp));
	if (!line)
	{
		free(*temp);
		return (NULL);
	}
	ptr = ft_substr(ptr, 0, ft_strlen(ptr));
	free(*temp);
	*temp = ptr;
	return (line);
}

static char	*ft_read(char *temp, int fd, char *buf)
{
	ssize_t	reader;

	reader = 1;
	while (reader && !ft_strchr(temp, '\n'))
	{
		reader = read(fd, buf, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buf);
			free(temp);
			return (NULL);
		}
		buf[reader] = 0;
		temp = ft_strjoin(temp, buf);
		if (!temp)
		{
			free(buf);
			return (NULL);
		}
	}
	free(buf);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*buf;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	if (!temp)
		temp = ft_strdup("");
	if (!temp)
		return (NULL);
	buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		free(temp);
		return (NULL);
	}
	temp = ft_read(temp, fd, buf);
	if (!temp)
		return (NULL);
	if (!*temp)
	{
		free(temp);
		temp = NULL;
		return (NULL);
	}
	return (ft_next(&temp));
}
