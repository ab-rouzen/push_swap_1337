/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:04:26 by arouzen           #+#    #+#             */
/*   Updated: 2022/08/30 19:44:36 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*ns1;
	const unsigned char	*ns2;

	ns1 = (const unsigned char *)s1;
	ns2 = (const unsigned char *)s2;
	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] == s2[i])
		{
			i++;
		}
		else
			break ;
	}
	if (i == n && n != 0)
		i--;
	if (n != 0)
		return (ns1[i] - ns2[i]);
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (src[i] && i < dstsize - 1 && dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize)
		dst[i] = '\0';
	return (ft_strlen((char *)src));
}
