/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:54:53 by cjouenne          #+#    #+#             */
/*   Updated: 2023/07/20 19:57:28 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
//# include <unistd.h>

void	*ft_realloc(char *buf, int size);
char	*ft_strdup(char *src);
//void	ft_putnbr(int n);
int		ft_atoi(char *str);

#endif
