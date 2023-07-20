/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:02:10 by cjouenne          #+#    #+#             */
/*   Updated: 2023/07/20 18:18:54 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char *argv[])
{
	int	i;
	int	e;

	e = 0;
	if (argc >= 2)
	{
		i = 1;
		while (i < argc)
			e += bsq_main(open(argv[i++], O_RDONLY));
	}
	else
		e = bsq_main(0);
	return (e);
}
