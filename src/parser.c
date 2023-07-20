/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:44:56 by cjouenne          #+#    #+#             */
/*   Updated: 2023/07/20 19:25:20 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "bsq.h"

int	ft_read_line(char **str, int fd, int size)
{
	char	*buf;
	int		c;
	int		i;

	
}

void	ft_parse_first_line(char *buf, int *line_count)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	*line_count = 0;
	while (buf[++i] != '\n')
		;
	i -= 4;
	while (j <= i)
	{
		*line_count += (int)(buf[j] - 48);
		*line_count *= 10;
		j++;
	}
	*line_count /= 10;
}
