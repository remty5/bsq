/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:07:02 by cjouenne          #+#    #+#             */
/*   Updated: 2023/07/20 19:06:50 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

// TODO: get rid of these
# include <stdlib.h>
# include <stdio.h>

# include <unistd.h>
# include <fcntl.h>

typedef struct s_map {
	char	**map;
	int		w;
	int		h;
	char	c[3];
}	t_map;

int		bsq_main(int fd);
void	ft_read_map(int fd);
void	ft_parse_first_line(char *buf, int *line_count);

#endif
