/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 01:11:43 by ltran             #+#    #+#             */
/*   Updated: 2017/01/18 10:09:07 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_no(int fd, char *buf, int num, int r)
{
	int		i;
	char	*lg;
	char	*sub;

	lg = ft_strdup(buf);
	while (num == 0 && r > 0  && ft_strchr(buf, '\n') == NULL) 
	{
		r = ft_read(fd, buf, 0);
		if (ft_strchr(buf, '\n') == NULL)
			lg = ft_strjoin(lg, buf);
	}
	if (r < BUFF_SIZE  && ft_strchr(buf, '\n') == NULL)
	{
		free(lg);
		return (lg);
	}
	i = ft_strlen(buf) - ft_strlen(ft_strchr(buf, '\n'));
	lg = ft_strjoin(lg, ft_strsub(buf, 0, i));
	while (num == 1 && i-- >= 0)
		++buf;
	if (num == 1)
		return (buf);
	free(lg);
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
		if (ft_strchr(buf, '\n') == buf)
		{
			*line = ft_strnew(0);
			free(*line);
			return (1);
		}
		if (ft_strlen(buf) == 0 && ft_read(fd, buf, 0) == 0)
		{
			*line = ft_strnew(0);
			free(*line);
			return (0);
		}
	}
	if (!(ft_strlen(buf) > 0))
		ft_read(fd, buf, 0);
	while (ft_strlen(buf) > 0)
	{
		*line = ft_no(fd, buf, 0, ft_strlen(buf));
		return (1);
	}
	*line = ft_strnew(0);
	free(*line);
	return (0);
}
