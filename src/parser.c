/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:44:56 by cjouenne          #+#    #+#             */
/*   Updated: 2023/07/25 02:34:02 by rvandepu         ###   ########.fr       */
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
	h = 0;
	while (buf[++i] != '\n' && buf[i])
		;
	while (++h <= 3)
		map->c[h - 1] = buf[i - h];
	i -= 4;
	j = 0;
	map->h = 0;
	while (j <= i)
		map->h = (map->h * 10) + (int)(buf[j++] - 48);
	//map->h /= 10;
	return (i + 4 + 1);
}

int	ft_free_map(t_map m)
{
	int	i;

	i = 0;
	while (m.map[i])
		free(m.map[i++]);
	free(m.map);
	return (1);
}

int	ft_parse_map(t_map *map, char *file, int start)
{
	int	i;

	if (!ft_verif_map(file))
		return (0);
	file += start;
	i = -1;
	while (file[++i] != '\n')
		;
	map->w = i;
	map->map = ft_split(file, "\n");
	i = -1;
	while (map->map[++i])
		;
	if (i != map->h)
		return (!ft_free_map(*map));
	return (1);
}
