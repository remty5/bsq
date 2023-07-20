/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:44:56 by cjouenne          #+#    #+#             */
/*   Updated: 2023/07/20 14:44:26 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include "bsq.h"

#define SIZE 1024

void	ft_read_map(char *path)
{
	char	buf[SIZE];
	int		fd;
	int		c;

	fd = open(path, O_RDONLY);
	c = 0;
	if (fd)
	{
		while (c > 0)
		{
			c = read(fd, buf, SIZE);
			write(1, buf, c);
		}
		if (!c)
			exit(0);
	}
}
