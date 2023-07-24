/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_verificator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:07:33 by cjouenne          #+#    #+#             */
/*   Updated: 2023/07/24 21:40:40 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_post_verif_map(t_map *map)
{
	ft_verif_char(map);
}

void	ft_verif_char(t_map *map)
{
	int	i;
	int	j;
	int	size;

	i = -1;
	size = 3;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
			if (map->c[i] == map->c[j])
				write(2, "map error\n", 10);
	}
	ft_verif_map_char(map);
}

int	ft_is_valid_char(char c, t_map *map)
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	while (++i < 3)
	{
		if (c == map->c[i])
			res++;
	}
	return (res);
}

void	ft_verif_map_char(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	printf("%d\n", map->h);
	while (++i < map->h)
	{
		printf("%s\n", map->map[i]);
		j = -1;
	}
}
