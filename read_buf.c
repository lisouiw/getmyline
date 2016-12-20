/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_buf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 01:08:20 by ltran             #+#    #+#             */
/*   Updated: 2016/12/20 01:38:50 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	int		rd;
	char 	buf[2];
	char	*moi = "Acoucou";
	char	*toi = (moi + 1);

	fd = open(argv[1], O_RDWR);
	rd = read(fd, buf, 2);
	puts(buf);
	rd = read(fd, buf, 2);
	puts(buf);
	puts(moi);
	puts(toi);
	return (0);
}
