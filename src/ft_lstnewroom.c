/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewroom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 19:37:12 by tferrari          #+#    #+#             */
/*   Updated: 2017/05/11 10:47:45 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "ft_printf.h"

t_tube			*ft_init_tube(t_tube *tube)
{
	if (!(tube = (t_tube *)malloc(sizeof(t_tube))))
		return (NULL);
	tube->salle = NULL;
	tube->next = NULL;
	tube->prev = NULL;
	return (tube);
}

t_room			*ft_init_room(void)
{
	t_room *room;

	if (!(room = (t_room *)malloc(sizeof(t_room))) ||
	(!(room->tube = ft_init_tube(room->tube))))
		return (NULL);
	room->name = NULL;
	room->pos = 0;
	room->way = 0;
	room->ant = 0;
	room->next = NULL;
	room->first_tube = NULL;
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
	if (!(room->name = ft_strnew(ft_strlen(name))) ||
	(!(room->tube = ft_init_tube(room->tube))))
		return (0);
	room->name = ft_strcpy(room->name, name);
	if (lem->start == 2)
		room->pos = 1;
	else if (lem->end == 2)
		room->pos = 2;
	else
		room->pos = 0;
	room->way = 0;
	room->ant = 0;
	room->next = NULL;
	room->first_tube = NULL;
	return (1);
}
