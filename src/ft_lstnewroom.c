/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewroom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 19:37:12 by tferrari          #+#    #+#             */
/*   Updated: 2017/05/02 17:07:15 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "ft_printf.h"

t_room		*ft_init_room()
{
	t_room *room;

	if (!(room = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	room->name = NULL;
	room->pos = 0;
	room->next = NULL;
	room->tube = NULL;
	return (room);
}

int				ft_lstnewroom(t_room *room, char *name, t_lem *lem)
{
	if (room->name != NULL)
	{
		while (room && room->next)
			room = room->next;
		if (!(room->next = (t_room *)malloc(sizeof(t_room))))
			return (0);
		room = room->next;
	}
	if (!(room->name = ft_strnew(ft_strlen(name))))
			return (0);
	room->name = ft_strcpy(room->name, name);
	if (lem->start == 2)
	{
		room->pos = 1;
		lem->start = 3;
	}
	else if (lem->end == 2)
	{
		room->pos = 2;
		lem->end = 3;
	}
	else
		room->pos = 0;
	room->tube = NULL;
	room->next = NULL;
	return (1);
}
