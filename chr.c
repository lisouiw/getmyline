/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 19:48:15 by ltran             #+#    #+#             */
/*   Updated: 2016/12/19 22:01:29 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	const char		*s1;
	char			*b;

	s1 = s;
	b = (char *)s1;
	i = 0;
	while (i < n)
	{
		if (b[i] == (char)c)
			return (b + i);
		i++;
	}
	return (NULL);
}

int		main(int argc, char **argv)
{
	char	*c;
	int		fd;
	ssize_t		rd;
	char	buf[100];

	fd = open(argv[1], O_RDWR);
	rd = read(fd, buf, 100);
	c = ft_memch(buf, 'n', 20);
	puts(c);
}
