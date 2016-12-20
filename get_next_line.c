/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 06:06:29 by ltran             #+#    #+#             */
/*   Updated: 2016/12/20 08:21:50 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*retour(char *buf, int num, size_t len)
{
	char	*chr = NULL;

	printf("num = %i\n", num);
	if (num == 1)
	{
		printf("coucou\n");
		ft_strncat(chr, buf, len);
		printf("coucou\n");
	}
	if (num == 0)
	{
		chr = ft_strchr(buf, '\n');
		printf("aurevoir\n");
	}
	return (chr);
}

int		get_next_line(int fd, char **line)
{
	static int		rd;
	static int		i;
	static size_t	len;
	static char		*chr;
	static char		buf[BUFF_SIZE];

	i = 0;
	while (i >= 0 && rd != -1)
	{
		rd = read(fd, buf, BUFF_SIZE);
		printf("rd = %d\n", rd);
		len = 2;
		while(*buf != '\0' && len != 0)
		{
			chr = retour(buf, 0, 0);
			len = ft_strlen(buf) - ft_strlen(chr);
			printf("%zu\n", len);
			line[i] = retour(buf, 1, len);
			printf("put me\n");
			puts(line[i]);
			if ((chr + 1) != NULL)
			{
				free(buf);
			   	ft_strcpy(buf, (chr + 1));
			}
			else
				len = 0;
			if (chr != NULL) //on return 1 si on a lu une ligne
			{
				i++;
				return (1);
			}
		}
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	**line = NULL;

	fd = open(argv[1], O_RDWR);
	get_next_line(fd, line);
	return (0);
}

/*int		get_next_line(int fd, char **line)
{
	ssize_t		rd;
	char		*buf[BUFF_SIZE];

	rd = read(fd, buf, BUFF_SIZE);
	printf("rd = %zi\n", rd);
	printf("coucou\n");
	return(0);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		get;
	char	**line = NULL;

	fd = open(argv[1] , O_RDWR);
	get = get_next_line(fd, line);
	return (0);
}*/

/*int		main()
{
	char	*bufi[BUFF_SIZE];
	int		i;

	i = 0;
	printf("coucou1\n");
	while (i < BUFF_SIZE)
	{
		printf("coucou2\n");
		bufi[i] = "k";
		puts(bufi[i]);
		i++;
		if (i == BUFF_SIZE)
		{
			printf("BUFF??\n");
			bufi[i] = "caca";
			puts(bufi[i]);
		} 
	}
	printf("coucou3\n");
	return (0);
}

read puis write, free buf ect*/
