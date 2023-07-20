/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:08:30 by cjouenne          #+#    #+#             */
/*   Updated: 2023/07/20 21:22:06 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	bsq_main(int fd)
{
	struct s_map	map;
	char			*file;

	map.h = 0;
	if (ft_read_file(&file, fd) == 0)
	{
		printf("%s", file);
		free(file);
		return (0);
	}
	else
		return (1);
}
