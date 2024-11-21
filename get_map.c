/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:58:59 by akunegel          #+#    #+#             */
/*   Updated: 2023/12/05 16:37:33 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

char	**get_map(char *file, t_data *data)
{
	char	*lines;
	char	*line;
	int		fd;

	line = ft_strdup("");
	lines = ft_strdup("");
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_error("file not readble", data);
		exit (0);
	}
	while (line)
	{
		line = get_next_line(fd);
		if (line == 0 || line[0] == '\n')
			break ;
		lines = ft_strjoin(lines, line);
		free(line);
	}
	free(line);
	close(fd);
	return (ft_split(lines, '\n'));
}
