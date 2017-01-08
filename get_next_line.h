/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 06:06:19 by ltran             #+#    #+#             */
/*   Updated: 2017/01/08 23:50:21 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# define BUFF_SIZE 9999

int	get_next_line(int fd, char **line);

#endif
