/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verificator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:05:45 by cjouenne          #+#    #+#             */
/*   Updated: 2023/07/24 20:04:27 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "ft.h"

void	ft_verif_map(char *file_buffer)
{
	int	i;

	i = -1;
	while (file_buffer[++i] != '\n')
		;
	if (i < 4)
		write(2, "map error !\n", 12);
	ft_verif_line(&file_buffer[i + 1]);
}

void	ft_verif_line(char *file_buffer)
{
	int	line_len;
	int	n;
	int	i;
	int	is_first_line;

	if (*file_buffer == '\0' || *file_buffer == '\n')
		write(2, "map error !\n", 12);
	n = 0;
	i = -1;
	is_first_line = 1;
	while (file_buffer[++i])
	{
		if (file_buffer[i] == '\n')
		{
			is_first_line = 0;
			if (line_len != n)
				write(2, "map error !\n", 12);
			n = 0;
			continue ;
		}
		n++;
		if (is_first_line)
			line_len = n;
	}
}