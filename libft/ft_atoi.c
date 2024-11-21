/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:32:30 by akunegel          #+#    #+#             */
/*   Updated: 2023/04/03 14:11:05 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_signe(const char *str)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v' \
		|| str[i] == '\f' || str[i] == ' ')
	{
		i++;
	}
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			c++;
		i++;
	}
	return (c);
}

int	ft_atoi(const char *str)
{
	int	m;
	int	nb;
	int	i;

	i = 0;
	m = 0;
	nb = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v' \
	|| str[i] == '\f' || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
		i++;
	m = ft_signe(str);
	while ((str[i]) && (str[i] > 47 && str[i] < 58))
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	if (m % 2 == 1)
		nb = -nb;
	return (nb);
}
