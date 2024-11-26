/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:59:38 by pjarnac           #+#    #+#             */
/*   Updated: 2024/11/26 14:37:13 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == 0)
		return ((char *)s);
	else
		return (NULL);
}

ssize_t	ft_strlen(char *str)
{
	ssize_t	c;

	c = 0;
	if (!str)
		return (0);
	while (str[c])
		c++;
	return (c);
}

char	*ft_strndup(char *s, ssize_t n)
{
	char		*dup;
	ssize_t		slen;
	ssize_t		i;

	slen = ft_strlen(s);
	if (slen > n)
		slen = n;
	dup = malloc(slen + 1 * sizeof (char));
	if (!dup)
		return (NULL);
	dup[slen] = 0;
	i = 0;
	while (i < slen)
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}

void	add_stock(char **stock, char *buf, ssize_t count)
{
	ssize_t	i;
	ssize_t	j;
	ssize_t	stock_len;
	char	*res;

	stock_len = ft_strlen(*stock);
	res = malloc(stock_len + count + 1);
	if (!res)
		return ;
	res[stock_len + count] = 0;
	i = -1;
	while (++i < stock_len)
		res[i] = (*stock)[i];
	j = -1;
	while (++j < count)
		res[i + j] = buf[j];
	free(*stock);
	*stock = res;
}

void	free_stock(char **stock)
{
	free(*stock);
	*stock = 0;
}
