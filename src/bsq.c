/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:08:30 by cjouenne          #+#    #+#             */
/*   Updated: 2023/07/20 19:25:20 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#define SIZE 1024

int	bsq_main(int fd)
{
	struct s_map	map;
	char			buf[SIZE];
	int				c;

	c = 1;
	map.h = 0;
	if (fd >= 0)
	{
		{
			c = read(fd, buf, SIZE);
			ft_parse_first_line(buf, &map.h);
			printf("line_count = %d\n", map.h);
		}
		if (!c)
			exit(0);
	}
	return (1);
}
