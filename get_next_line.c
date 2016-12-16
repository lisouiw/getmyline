/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 06:06:29 by ltran             #+#    #+#             */
/*   Updated: 2016/12/16 17:27:25 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int		get_next_line(const int fd, char **line)
{
	printf("Je rentre");
	char		*buf;
	size_t			rd;
	int				i;
	char			*lg;

	printf("Je rentre");
	lg = *line;
	i = 0;
	rd = read(fd, (buf + i), BUFF_SIZE);
	printf("rd = %zu\n", rd);
	while (i < rd)
	{	
		printf("Hello\n");
		if (buf[i] == '\n')
		{
			printf("boucle!!!\n");
			lg[i] = '\0';
			puts(lg);
			return (1);
		}
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	**line;

	fd = open(argv[1] , O_RDWR);
	printf("argv[1] = %s\nfd = %d\n", argv[1], fd);
	get_next_line((const int)fd, line);
}
