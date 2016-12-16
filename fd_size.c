/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 15:28:52 by ltran             #+#    #+#             */
/*   Updated: 2016/12/16 13:38:42 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/uio.h>

#define BUFF_SIZE 2

void	lire(int fd)
{
	size_t		rd;
	int			i;
	size_t		tmp;
	char		buf[BUFF_SIZE];

	i = 0;
	rd = read(fd, buf, BUFF_SIZE);
	tmp = rd;
	printf("tmp = %zu || rd = %zu\n", tmp, rd);
	printf("\nboucle while\n");
	while (i != -1 && i < 10)
	{
		while (i < i + rd && i != -1 && i < 5)
		{
			printf("buf[%d] = %s\n", i, &buf[i]);
			buf[i] != '\n' ? i++ : i == -1;
			if (i == tmp)
			{
				printf("\nentre\ni = %d\n", i);
				free(buf);
				rd = read(fd, (buf + rd), BUFF_SIZE);
				printf("tmp = %zu\n", tmp);
				tmp += tmp;
				printf("tmp = %zu\nsorti\n", tmp);
			}
		}
		printf("\nsortie while\n\n");
		printf("rd = %zu || buf[%d] = ", rd, i);
		puts(buf);
		i != -1 ? i = i + rd : i;
		printf("SIZE = %d || new i = %d\n", BUFF_SIZE, i);
	}
}

int		main(int argc, char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDWR);
	printf("fd = %d\n", fd);
	lire(fd);
	return (0);
}
