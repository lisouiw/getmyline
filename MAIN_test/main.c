/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-h <jmarin-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:19:12 by jmarin-h          #+#    #+#             */
/*   Updated: 2017/01/06 04:41:09 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# include <stdio.h>

int	main(int ac,   char **av)
// int	main(void)
{
	int		i;
	int		fd;
	char 	*line;
	int		c;

	i = 0;
	c = 0;
	line = NULL;
	if (ac)
	{
		fd = open(av[1], O_RDONLY);
		// fd = 0;
		while((i = get_next_line(fd, &line)) > 0)
		{
			c++;
			printf("-> [%d] SORTIE GNL : %s\n", i, line);
		}
		if (i == 0)
			printf("-> [%d] SORTIE GNL : %s\n", i, line);
		if (i == (-1))
			printf("-> [%d] SORTIE GNL : %s\n", i, line);
		printf("index read line : %d\n", c);
	}
	return (0);
}
