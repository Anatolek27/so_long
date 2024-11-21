/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:23:16 by akunegel          #+#    #+#             */
/*   Updated: 2023/04/12 13:24:20 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	srclen;

	j = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = 0;
	if (n <= j)
	{
		return (n + srclen);
	}
	while (src[i] && j + 1 < n)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (ft_strlen(src + i) + j);
}
