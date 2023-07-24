/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:08:30 by cjouenne          #+#    #+#             */
/*   Updated: 2023/07/24 13:04:04 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	bsq_main(int fd)
{
	struct s_map	map;
	char			*file;
	int				start;

	map.h = 0;
	if (ft_read_file(&file, fd) == 0)
	{
		start = ft_parse_first_line(file, &map);
		ft_parse_map(&map, file, start);
		printf("%s", file);
		free(file);
		return (0);
	}
	else
		return (1);
}
