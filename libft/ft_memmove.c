/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:02:06 by akunegel          #+#    #+#             */
/*   Updated: 2023/04/11 14:45:20 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*s1;
	char	*s2;
	size_t	i;

	s1 = (char *)src;
	s2 = (char *)dest;
	i = 0;
	if (!dest && !src)
		return (0);
	if (s2 > s1)
		while (len-- > 0)
			s2[len] = s1[len];
	else
	{
		while (i < len)
		{
			s2[i] = s1[i];
			i++;
		}
	}
	return (dest);
}
