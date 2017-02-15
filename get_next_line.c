/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 01:11:43 by ltran             #+#    #+#             */
/*   Updated: 2017/02/15 06:27:47 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_no(int fd, char *buf, int num, int r)
{
	char	*lg;

	lg = ft_strdup(buf);
	while (num == 0 && r > 0 && ft_strchr(buf, '\n') == NULL)
	{
		r = ft_read(fd, buf, 0);
		if (ft_strchr(buf, '\n') == NULL)
			lg = ft_strjoin(lg, buf);
	}
	if (num == 0 && r < BUFF_SIZE && ft_strchr(buf, '\n') == NULL)
		return (lg);
	r = ft_strlen(buf) - ft_strlen(ft_strchr(buf, '\n'));
	lg = ft_strjoin(lg, ft_strsub(buf, 0, r));
	while (num == 1 && r-- >= 0)
		++buf;
	if (num == 1)
		return (buf);
	return (lg);
}

char	*ft_sep(char *buf, size_t b, size_t c)
{
	char	*lg;

	lg = ft_strsub(buf, 0, (b - c));
	return (lg);
}

int		ft_read(int fd, char *buf, int r)
{
	r = read(fd, buf, BUFF_SIZE);
	buf[r] = '\0';
	return (r);
}

int		get_next_line(int fd, char **line)
{
	static char			buf[BUFF_SIZE + 1];

	if (ft_strlen(buf) > 0)
	{
		ft_strcpy(buf, ft_no(fd, buf, 1, 0));
		*line = ft_strnew(0);
		free(*line);
		if (ft_strlen(buf) == 0 && ft_read(fd, buf, 0) == 0)
			return (0);
		if (ft_strchr(buf, '\n') == buf)
			return (1);
	}
	if (!(ft_strlen(buf) > 0) && ft_read(fd, buf, 0) < 0)
		return (-1);
	if (ft_strchr(buf, '\n') != NULL)
	{
		*line = ft_sep(buf, ft_strlen(buf), ft_strlen(ft_strchr(buf, '\n')));
		return (1);
	}
	while (ft_strlen(buf) > 0)
	{
		*line = ft_no(fd, buf, 0, ft_strlen(buf));
		return (1);
	}
	return (0);
}
