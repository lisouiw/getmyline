/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 06:06:29 by ltran             #+#    #+#             */
/*   Updated: 2016/12/29 02:57:43 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*retour(char *buf, int num, char *line)
{
	char	*chr;

	chr = buf;
	if (num == 1 && line != NULL)
	{
		chr = ft_strdup(ft_strcat(line, chr));
	}
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
	return (chr);
}

int		get_next_line(int fd, char **line)
{
	int				 i;
	static int		rd;
	static char		*chr;
	static char		buf[BUFF_SIZE];

	i = 0;
	if (!rd)
		rd = read(fd, buf, BUFF_SIZE);
	while(rd > 0 && rd != 0)
	{
		chr = retour(buf, 0, *line);
		*line = retour(chr, 1, *line);
		ft_strcpy(buf, retour(buf, 2, chr));
		if (ft_strlen(chr) != ft_strlen(buf) || (ft_strlen(chr) == rd && rd != BUFF_SIZE))
		{
			printf("###line = %s\n", *line);
			i = ft_strlen(*line);
			while (i != 0)
			{
				i--;
				(*line)++;
			}
			printf("len %zu\n", ft_strlen(*line));
			printf("^^^line = %s\n", *line);
			return (1);
		}
		if (ft_strlen(buf) == ft_strlen(chr) || ft_strlen(chr) == rd)
		{
			rd = read(fd, buf, BUFF_SIZE);
			printf("if dc rd = %i\n", rd);
			if (rd > 0 && ft_strlen(buf) != rd)
				ft_strncpy(buf, buf, rd);
		}
	}
	return (0);
}

/*int		main(int argc, char **argv)
{
	int		fd;
	char	*line = NULL;

	fd = open(argv[1], O_RDWR);
	while (get_next_line != 0)
	{
		get_next_line(fd, &line);
	}
	return (0);
}*/
