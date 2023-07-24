/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:02:10 by cjouenne          #+#    #+#             */
/*   Updated: 2023/07/24 16:59:51 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char *argv[])
{
	int	i;
	int	f;
	int	e;

	e = 0;
	if (argc >= 2)
	{
		i = 1;
		while (i < argc)
		{
			f = open(argv[i++], O_RDONLY);
			if (f == -1 || bsq_main(f) != 0)
			{
				write(2, "map error\n", 10);
				e++;
			}
		}
	}
	else if (bsq_main(0) != 0)
	{
		write(2, "map error\n", 10);
		e++;
	}
	return (e);
}
