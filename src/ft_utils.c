/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:56:50 by cjouenne          #+#    #+#             */
/*   Updated: 2023/07/20 19:25:20 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dest = malloc(i + 1);
	if (dest)
	{
		dest[i] = '\0';
		while (i--)
			dest[i] = src[i];
	}
	return (dest);
}

/*void	ft_putnbr(int n)
{
	if (n < 0)
		n *= -1;
	if (n > 9)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar((n % 10) + 48);
}*/

int	ft_atoi(char *str)
{
	int				n;

	n = 0;
	while ('0' <= *str && *str <= '9')
		n = (n * 10) + (*str++ - '0');
	return (n);
}
