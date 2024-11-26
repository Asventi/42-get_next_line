/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:59:17 by pjarnac           #+#    #+#             */
/*   Updated: 2024/11/26 15:25:24 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static char	*get_from_stock(char *stock)
{
	char	*res;
	char	*delimiter;

	delimiter = ft_strchr(stock, '\n');
	if (!delimiter)
		return (0);
	res = ft_strndup(stock, (ssize_t)(delimiter - stock + 1));
	if (!res)
		return (0);
	return (res);
}

static void	remove_from_stock(char **stock, bool end)
{
	char	*res;
	char	*delimiter;

	delimiter = ft_strchr(*stock, '\n');
	if (end && (!delimiter || ft_strlen(delimiter + 1) == 0))
	{
		free_stock(stock);
		return ;
	}
	if (!delimiter)
		return ;
	res = ft_strndup(delimiter + 1, ft_strlen(delimiter + 1));
	if (!res)
		return ;
	free(*stock);
	*stock = res;
}

static char	*get_line(char *buf, ssize_t count)
{
	static char	*stock;
	char		*line;

	if (count < 0)
		return (free_stock(&stock), (char *)0);
	if ((!stock || stock[0] == 0) && count == 0)
		return (free_stock(&stock), (char *)0);
	if (count != 0)
		add_stock(&stock, buf, count);
	line = get_from_stock(stock);
	if (!line && (count < BUFFER_SIZE))
	{
		line = ft_strndup(stock, ft_strlen(stock));
		free_stock(&stock);
		if (!line)
			return (0);
	}
	else if (line)
		remove_from_stock(&stock, (count < BUFFER_SIZE));
	return (line);
}

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE];
	char	*line;
	ssize_t	res;

	res = read(fd, buf, BUFFER_SIZE);
	line = get_line(buf, res);
	if (!line)
	{
		if (res <= 0)
			return (0);
		return (get_next_line(fd));
	}
	return (line);
}
