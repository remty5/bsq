/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:02:10 by cjouenne          #+#    #+#             */
/*   Updated: 2023/07/25 02:37:32 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	bsq(int fd)
{
	t_map	map;
	char	*file;
	int		start;

	map.h = 0;
	if (!ft_read_file(&file, fd))
		return (0);
	start = ft_parse_first_line(file, &map);
	if (!ft_parse_map(&map, file, start) || !ft_post_verif_map(&map))
	{
		free(file);
		return (0);
	}
	//printf("file is %s\n", file);
	free(file);
	ft_solve(map);
	ft_free_map(map);
	return (1);
}

int	ft_main_err(int fd)
{
	write(2, "map error\n", 10);
	if (fd >= 3)
		close(fd);
	return (1);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	fd;
	int	err;

	err = 0;
	if (argc >= 2)
	{
		i = 1;
		while (i < argc)
		{
			fd = open(argv[i++], O_RDONLY);
			if (fd == -1 || !bsq(fd))
				err += ft_main_err(fd);
			if (i < argc)
				write(1, "\n", 1);
		}
	}
	else if (!bsq(0))
		err += ft_main_err(0);
	return (err);
}
