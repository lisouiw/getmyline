/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 06:06:29 by ltran             #+#    #+#             */
/*   Updated: 2017/01/08 19:34:07 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

char	*retour(char *buf, int num, char *line)
{
	char	*chr;
	int		i;

	chr = buf;
	if (num == 1 && line != NULL)
		chr = ft_strjoin(line, chr);
	if (num == 0 || num == 2)
	{
		chr = ft_strchr(chr, '\n');
		if (chr == NULL)
			return (buf);
		if (num == 0)
			chr = ft_strsub(buf, 0, ft_strlen(buf) - ft_strlen(chr));
	}
	if (num == 2)
		chr = ft_strsub(chr, 1, (ft_strlen(chr) - 1));
	if (num == 3)
	{
		i = ft_strlen(chr);
		while (i-- > 1)
			(chr)++;
	}
	return (chr);
}

int		get_next_line(int fd, char **line)
{
	static int		r;
	static char		*chr;
	static char		buf[BUFF_SIZE];

	if (!r)
		r = read(fd, buf, BUFF_SIZE);
	while (r > 0 && r != 0)
	{
		chr = retour(buf, 0, *line);
		*line = retour(chr, 1, *line);
		ft_strcpy(buf, retour(buf, 2, chr));
		*line = retour(buf, 3, *line);
		if (ft_strcmp(chr, buf) != 0 || (ft_strlen(chr) == r && r != BUFF_SIZE))
			return (1);
		if (ft_strlen(buf) == ft_strlen(chr) || ft_strlen(chr) == r)
			r = read(fd, buf, BUFF_SIZE);
		if (r > 0 && ft_strlen(buf) != r)
		{
			ft_strcpy(buf, ft_strsub(buf, 0, r));
			*line = retour(*line, 1, buf);
			r = read(fd, buf, BUFF_SIZE);
			return (1);
		}
	}
	return (0);
}
