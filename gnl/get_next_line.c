/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:44:15 by akunegel          #+#    #+#             */
/*   Updated: 2023/05/09 13:04:22 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join(char *buffer, char *dest)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, dest);
	free (buffer);
	return (tmp);
}

char	*ft_free_line(char *buffer)
{
	char	*new_buffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free (buffer);
		return (NULL);
	}
	i++;
	new_buffer = ft_calloc(ft_strlen(buffer) + 2 - i, sizeof(char));
	while (buffer[i])
	{
		new_buffer[j] = buffer[i];
		i++;
		j++;
	}
	free(buffer);
	return (new_buffer);
}

char	*ft_get_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_read(int fd, char *buffer)
{
	char	*dest;
	int		byte;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	byte = 1;
	dest = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	while (byte > 0)
	{
		byte = read(fd, dest, BUFFER_SIZE);
		if (byte == -1)
		{
			free (buffer);
			free (dest);
			return (NULL);
		}
		dest[byte] = '\0';
		buffer = ft_join(buffer, dest);
		if (ft_strchr(dest, '\n'))
			break ;
	}
	free (dest);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_free_line(buffer);
	return (line);
}
