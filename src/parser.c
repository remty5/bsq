/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:44:56 by cjouenne          #+#    #+#             */
/*   Updated: 2023/07/24 18:04:17 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "bsq.h"

#include <stdio.h>

int	ft_parse_first_line(char *buf, t_map *map)
{
	int	i;
	int	j;
	int	h;

	i = -1;
	j = 0;
	h = 0;
	map->h = 0;
	while (buf[++i] != '\n')
		;
	while (++h <= 3)
		map->c[h - 1] = buf[i - h];
	i -= 4;
	while (j <= i)
	{
		map->h = (int)(buf[j] - 48);
		map->h *= 10;
		j++;
	}
	map->h /= 10;
	return (i + 4 + 1);
}

void	ft_parse_map(t_map *map, char *file, int start)
{
	int	i;
	int	j;

	i = -1;
	file += start;
	while (file[++i] != '\n')
		;
	map->w = i;
	i = -1;
	map->map = malloc(sizeof(char *) * map->h);
	if (map->map == NULL)
		return ;
	while (++i < map->h)
	{
		j = -1;
		map->map[i] = malloc(sizeof(char) * map->w);
		if (map->map[i] == NULL)
			return ;
		while (++j < map->w)
		{
			map->map[i][j] = file[i + j];
		}
	}
}
