/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 22:35:38 by ltran             #+#    #+#             */
/*   Updated: 2016/12/26 22:42:20 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main()
{
	int		len
	char	*phrase = "coucou\nlesbites";
	char	*chr = ft_strchr(phrase, '\n');

	len = strlen((&phrase - &chr)); //impossible
	printf("len = %i\n", len);
	return (0);
}
