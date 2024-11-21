/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:51:30 by akunegel          #+#    #+#             */
/*   Updated: 2023/04/12 13:51:35 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	taille(int nb)
{
	int	c;

	c = 1;
	if (nb < 0)
	{
		nb = -nb;
		c++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		i;

	i = taille(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	dest = malloc((sizeof(char) * i) + 1);
	if (!dest)
		return (0);
	if (n < 0)
	{
		dest[0] = '-';
		n = -n;
	}
	dest[i] = '\0';
	while (n)
	{
		dest[i - 1] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	return (dest);
}

/*int	main(void)
{
	printf("%s", ft_itoa(-4540LL));
	return (0);
}*/
