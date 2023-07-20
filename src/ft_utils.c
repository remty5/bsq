/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:56:50 by cjouenne          #+#    #+#             */
/*   Updated: 2023/07/20 21:19:05 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	*ft_realloc(char *buf, int size)
{
	char	*new_buf;
	int		i;

	new_buf = malloc(size + SIZE);
	if (new_buf == NULL)
	{
		free(buf);
		return (NULL);
	}
	i = -1;
	while (++i < size)
		new_buf[i] = buf[i];
	free(buf);
	return (new_buf);
}

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
