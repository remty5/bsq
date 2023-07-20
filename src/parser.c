/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:44:56 by cjouenne          #+#    #+#             */
/*   Updated: 2023/07/20 15:59:22 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#include "ft.h"
#include "bsq.h"

#define SIZE 1024

void	ft_read_map(char *path)
{
	char	buf[SIZE];
	int		fd;
	int		c;
	int		line_count;

	fd = open(path, O_RDONLY);
	c = 1;
	line_count = 0;
	if (fd)
	{
		{
			c = read(fd, buf, SIZE);
			line_count = ft_parse_first_line(buf);
			printf("line_count = %d\n", line_count);
		}
		if (!c)
			exit(0);
	}
}

int	ft_parse_first_line(char *buf)
{
	int	i;
	int	j;
	int	res;

	i = -1;
	j = 0;
	res = 0;
	while (buf[++i] != '\n')
		;
	i -= 4;
	while (j <= i)
	{
		res += (int)(buf[j] - 48);
		res *= 10;
		j++;
	}
	res /= 10;
	return (res);
}
