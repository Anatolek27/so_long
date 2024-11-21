/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:51:36 by akunegel          #+#    #+#             */
/*   Updated: 2023/05/09 11:32:12 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;
	int		length;

	i = 0;
	length = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc((length + 1) * sizeof(char));
	if (!s1 || !s2 || !dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[length] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != c && *str != '\0')
		str++;
	if (*str == c)
		return (str);
	else
		return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

char	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;

	str = malloc(nmemb * size);
	if (!str)
	{
		free (str);
		return (NULL);
	}
	ft_bzero(str, nmemb * size);
	return (str);
}
