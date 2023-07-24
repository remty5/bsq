/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:07:02 by cjouenne          #+#    #+#             */
/*   Updated: 2023/07/24 18:09:27 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

// TODO: get rid of this
# include <stdio.h>

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define READ_SIZE 512

typedef struct s_map {
	char	**map;
	int		w;
	int		h;
	char	c[3];
}	t_map;

// parser.c
int		ft_read_file(char **str, int fd);
//void	ft_read_map(int fd);
int		ft_parse_first_line(char *buf, t_map *map);
void	ft_parse_map(t_map *map, char *file, int start);

#endif
