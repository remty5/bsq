/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:43:05 by rvandepu          #+#    #+#             */
/*   Updated: 2023/07/24 22:43:02 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "ft.h"
#include "test_map.h"

int	ft_free_tab(int **tab, int n)
{
	int	i;

	i = 0;
	while (i < n || (n == -1 && tab[i]))
		free(tab[i++]);
	free(tab);
	return (1);
}

int	ft_create_tab(int ***tab, struct s_map m)
{
	int	i;

	*tab = malloc(sizeof(int *) * (m.h + 1));
	if (*tab == NULL)
		return (0);
	i = -1;
	while (++i < m.h)
	{
		(*tab)[i] = malloc(sizeof(int) * m.w);
		if ((*tab)[i] == NULL)
			return (!ft_free_tab(*tab, i));
	}
	i = -1;
	printf("chars:%c%c%c\n", m.c[0], m.c[1], m.c[2]);
	while (++i < m.w * m.h)
	{
		(*tab)[i / m.w][i % m.w] = m.map[i / m.w][i % m.w] != m.c[1];
		printf("c:%c, v:%d\n", m.map[i / m.w][i % m.w], (*tab)[i / m.w][i % m.w]);
	}
	(*tab)[m.h] = NULL;
	return (1);
}

int	ft_solve(struct s_map m)
{
	int	**tab;
	int	i;
	int	imax;

	if (!ft_create_tab(&tab, m))
		return (0);
	i = m.w * (m.h - 1);
	printf("w:%d, h:%d\n", m.w, m.h);
	while (i-- > 0 && m.w > 1 && m.h > 1 && ((i % m.w == m.w - 1 && --i) || 1))
	{
		printf("x:%d,y:%d,v:%d,", i % m.w, i / m.w, tab[i / m.w][i % m.w]);
		tab[i / m.w][i % m.w] *= 1 + ft_min(tab[(i / m.w) + 1][(i % m.w) + 1], \
			ft_min(tab[(i / m.w) + 1][i % m.w], tab[i / m.w][(i % m.w) + 1]));
		printf("val:%d\n", tab[i / m.w][i % m.w]);
	}
	imax = 0;
	while (++i < m.w * m.h)
		if (tab[i / m.w][i % m.w] > tab[imax / m.w][imax % m.w])
			imax = i;
	printf("x: %d, y: %d, size: %d\n", imax % m.w, imax / m.w, tab[imax / m.w][imax % m.w]);
	return (1);
}

void	disp(char	**tab, int w, int h)
{
	int	i;

	i = -1;
	while (++i < w * h)
	{
		printf("%c", tab[i / w][i % w]);
		if (i % w == w - 1)
			printf("\n");
	}
}

int	main(void)
{
	int	i;

	g_test.map = malloc(sizeof(char *) * (g_test.h + 1));
	g_test.map[g_test.h] = NULL;
	i = -1;
	while (++i < g_test.h)
		g_test.map[i] = malloc(sizeof(char) * g_test.w);
	i = -1;
	while (++i < g_test.w * g_test.h)
	{
		printf("x:%d,y:%d\n", i % g_test.w, i / g_test.w);
		g_test.map[i / g_test.w][i % g_test.w] = g_map[i / g_test.w][i % g_test.w];
	}
	disp(g_test.map, g_test.w, g_test.h);
	ft_solve(g_test);
	return (0);
}
