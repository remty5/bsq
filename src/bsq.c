/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:08:30 by cjouenne          #+#    #+#             */
/*   Updated: 2023/07/20 13:12:32 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

#include <unistd.h>
#include <fcntl.h>

void	bsq_main(int argc, char *argv[])
{
	int	fd;

	if (argc >= 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (!(fd < 0))
			write(1, "Success\n", 9);
	}
}
