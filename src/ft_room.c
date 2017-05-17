/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_room.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 12:14:23 by tferrari          #+#    #+#             */
/*   Updated: 2017/05/16 15:05:48 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"
#include "ft_printf.h"

static int		ft_check_double(char *tmp, t_room *room)
{
	while (room)
	{
		if (ft_strcmp(tmp, room->name) == 0)
			return (0);
		room = room->next;
	}
	return (1);
}

int				ft_room(char *text, t_lem *lem, t_room *room)
{
	int		i;
	char	*tmp;

	i = ft_strclen(text, ' ');
	if (!(tmp = ft_strnew(i)))
		return (0);
	tmp = ft_strncat(tmp, text, i);
	if (room->name)
		if (!ft_check_double(tmp, room))
			return (4);
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
