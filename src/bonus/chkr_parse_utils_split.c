/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chkr_parse_utils_split.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:57:15 by arouzen           #+#    #+#             */
/*   Updated: 2022/08/29 21:38:08 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	tabcount(const char *str, char c)
{
	int	i;
	int	count;
	int	j;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		j = i;
		while (str[i] != c && str[i])
			i++;
		if (j != i)
			count++;
	}
	return (count);
}

static char	**freeme(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static char	**allo_mem(char **blk, char *str, char c)
{
	char	*loc;
	int		i;
	int		m;

	i = 0;
	m = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		loc = &str[i];
		while (str[i] != c && str[i])
			i++;
		if ((&str[i] - loc) != 0)
		{
			blk[m] = malloc(sizeof(char) * (&str[i] - loc + 1));
			if (!blk[m])
				return (freeme(blk, m));
			m++;
		}
	}
	blk[m] = NULL;
	return (blk);
}

static void	feelme(char *str, char c, char **tab)
{
	int		i;
	int		m;
	char	*loc;

	i = 0;
	m = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		loc = &str[i];
		while (str[i] != c && str[i])
			i++;
		if (&str[i] - loc != 0)
			ft_strlcpy(tab[m], loc, &str[i] - loc + 1);
		m++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	*ns;

	ns = (char *)s;
	if (!ns)
		return (NULL);
	tab = malloc(sizeof(char **) * tabcount(ns, c) + 1);
	if (!tab)
		return (NULL);
	allo_mem(tab, ns, c);
	if (!tab)
		return (NULL);
	feelme(ns, c, tab);
	return (tab);
}
