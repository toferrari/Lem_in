/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_room.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 12:14:23 by tferrari          #+#    #+#             */
/*   Updated: 2017/05/04 17:39:33 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"
#include "ft_printf.h"

int				ft_room(char *text, t_lem *lem, t_room *room)
{
	int		i;
	char	*tmp;

	i = ft_strclen(text, ' ');
	if (!(tmp = ft_strnew(i)))
		return (0);
	tmp = ft_strncat(tmp, text, i);
	if (!ft_lstnewroom(room, tmp, lem))
		return (0);
	if (tmp)
		ft_memdel((void **)&tmp);
	if (lem->start == 2)
		lem->start = 3;
	else if (lem->end == 2)
		lem->end = 3;
	return (1);
}
