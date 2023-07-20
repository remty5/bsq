/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:07:02 by cjouenne          #+#    #+#             */
/*   Updated: 2023/07/20 17:22:58 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

void	bsq_main(int argc, char *argv[]);
void	ft_read_map(char *path);
void	ft_parse_first_line(char *buf, int *line_count);

#endif
