/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:59:27 by pjarnac           #+#    #+#             */
/*   Updated: 2024/11/27 16:59:38 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stddef.h>
# include <sys/types.h>
# include <stdbool.h>

char	*get_next_line(int fd);
int		add_stock(char **stock, char *buf, size_t count);
char	*ft_strchr(char *s, int c);
char	*ft_strndup(char *s, size_t n);
size_t	ft_strlen(char *str);
void	free_stock(char **stock);

#endif
