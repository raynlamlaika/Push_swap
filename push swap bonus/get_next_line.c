/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:47:42 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/01/10 10:29:36 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	freed(char **point)
{
	if (*point)
	{
		free(*point);
		*point = NULL;
	}
}

static int	readtobuff(int fd, char **buffer)
{
	char		*tohold;
	char		*temp;
	ssize_t		byts;

	tohold = malloc((size_t)BUFFER_SIZE + 1);
	if (!tohold)
		return (0);
	while (!*buffer || !ft_strchr(*buffer, '\n'))
	{
		byts = read(fd, tohold, BUFFER_SIZE);
		if (byts <= 0)
			return (freed(&tohold), byts);
		tohold[byts] = '\0';
		temp = *buffer;
		*buffer = ft_strjoin(*buffer, tohold);
		freed(&temp);
		if (!*buffer)
		{
			freed(&tohold);
			return (-1);
		}
	}
	freed(&tohold);
	return (1);
}

static void	update_buffer( char **buffer)
{
	char	*temp;
	char	*newline_pos;

	newline_pos = ft_strchr(*buffer, '\n');
	if (newline_pos)
	{
		temp = *buffer;
		*buffer = ft_strdup(newline_pos + 1);
		freed(&temp);
	}
	else
		freed(buffer);
}

static char	*extract_line(char *buffer)
{
	size_t	i;
	char	*line;

	if (!buffer || !*buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	ssize_t		retu;

	if (BUFFER_SIZE <= 0 || (read(fd, 0, 0)) < 0 || fd < 0)
		return (freed(&buffer), NULL);
	retu = readtobuff(fd, &buffer);
	if (retu <= 0)
	{
		if (!buffer || *buffer == '\0')
			return (freed(&buffer), NULL);
	}
	line = extract_line(buffer);
	update_buffer(&buffer);
	return (line);
}
