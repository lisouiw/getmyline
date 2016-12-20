/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 06:06:19 by ltran             #+#    #+#             */
/*   Updated: 2016/12/20 08:21:49 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#define BUFF_SIZE 4

#include "./../libft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*ft_strncat(char *restrict dst, const char *restrict src, size_t n);
void	*ft_strcpy(char *dst, const char *src);

#endif
