/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 22:16:44 by anatolek          #+#    #+#             */
/*   Updated: 2023/04/12 13:22:45 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	n;
	char	*str;

	i = 0;
	n = ft_strlen(s1);
	if (!set)
		return ((char *) s1);
	if (!s1)
		return (0);
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	if (i == n)
	{
		str = ft_strdup("");
		return (str);
	}
	while (ft_strchr(set, s1[n - 1]) && i < n)
		n--;
	str = ft_substr(s1, i, n - i);
	return (str);
}
