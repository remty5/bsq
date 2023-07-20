/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:44:56 by cjouenne          #+#    #+#             */
/*   Updated: 2023/07/20 14:54:25 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

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
		while (c > 0)
		{
			c = read(fd, buf, SIZE);
			write(1, buf, c);
		//	line_count = atoi(&buf[0]);
		//	printf("line_count = %d\n", line_count);
		}
		if (!c)
			exit(0);
	}
}
