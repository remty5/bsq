/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:44:56 by cjouenne          #+#    #+#             */
/*   Updated: 2023/07/20 21:21:42 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "bsq.h"

int	ft_read_file_return(char **str, char *buf, int c, int i);

int	ft_read_file(char **str, int fd)
{
	char	*buf;
	int		c;
	int		o;
	int		i;

	buf = malloc(SIZE);
	if (buf == NULL)
		return (-1);
	c = 1;
	o = 0;
	i = 0;
	while (c > 0)
	{
		c = read(fd, buf + i, SIZE);
		i += c;
		if (i > o)
		{
			buf = ft_realloc(buf, o += SIZE);
			if (buf == NULL)
				return (-1);
		}
	}
	return (ft_read_file_return(str, buf, c, i));
}

int	ft_read_file_return(char **str, char *buf, int c, int i)
{
	if (c == 0)
	{
		buf[i] = '\0';
		*str = ft_strdup(buf);
		if (*str == NULL)
			return (-1);
		return (0);
	}
	free(buf);
	return (-1);
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
