/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 09:59:46 by akunegel          #+#    #+#             */
/*   Updated: 2023/04/11 14:37:58 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *) malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!dest)
		return (0);
	while (str[i])
	{
		dest[i] = (char)str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*#include <stdio.h>

int	main(int argc, char **argv)
{
	(void)argc;
	printf("%s\n", argv[1]);
	return (0);
}*/
