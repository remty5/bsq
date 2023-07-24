/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:28:07 by cjouenne          #+#    #+#             */
/*   Updated: 2023/07/24 21:37:22 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	is_charset(char *str, char *charset, int start)
{
	int	i;

	i = -1;
	while (charset[++i])
		if (str[start] == charset[i])
			return (1);
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	if (str == 0 || charset == 0)
		return (0);
	while (str[++i])
	{
		if (is_charset(str, charset, i) && i > 0)
		{
			i += 1;
			if (str[i + 1] != 0)
				count++;
		}
	}
	return (count + 1);
}

char	*_ft_strdup(char *src, char *charset)
{
	int		i;
	char	*buf;

	buf = (char *) malloc(sizeof(char) * ft_strlen(src) + 1);
	if (buf == NULL)
		return (NULL);
	i = 0;
	while (src[i] && !(is_charset(src, charset, i)))
	{
		buf[i] = src[i];
		++i;
	}
	buf[i] = '\0';
	return (buf);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		i;
	int		j;

	split = (char **) malloc(sizeof(char *) * count_word(str, charset) + 1);
	if (split == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (is_charset(str, charset, i))
			i += 0;
		else
		{
			split[j] = _ft_strdup(str + i, charset);
			i += ft_strlen(split[j]) - 1;
			j++;
		}
	}
	split[j] = 0;
	return (split);
}
