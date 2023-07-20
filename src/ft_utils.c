/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:56:50 by cjouenne          #+#    #+#             */
/*   Updated: 2023/07/20 15:10:29 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}

void	ft_putnbr(int n)
{
	if (n < 0)
		n *= -1;
	if (n > 9)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar((n % 10) + 48);
}

int	ft_atoi(char *str)
{
	int				n;
	unsigned int	i;

	n = 0;
	i = 0;
	while ('0' <= str[i] && str[i] <= '9')
		n = (n * 10) + (str[i++] - '0');
	return (n);
}
