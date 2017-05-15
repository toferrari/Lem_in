/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_theway.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 10:35:15 by tferrari          #+#    #+#             */
/*   Updated: 2017/05/15 19:17:22 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "ft_printf.h"

static void		ft_first_tube(t_room *room, int i)
{
	if (i == 1)
	{
		while (room)
		{
			room->first_tube = room->tube;
			room = room->next;
		}
	}
	else
	{
		while (room)
		{
			room->tube = room->first_tube;
			room = room->next;
		}
	}
}

static t_room	*ft_short(t_room *room, t_room *begin, t_room *tmp)
{
	room->way = 2;
	room = tmp;
	while (room)
	{
		if (room->way == 1)
			room->way = 0;
		room = room->next;
	}
	return (begin);
}

static t_room	*ft_begin(t_room *room)
{
	while (room->pos != 1)
		room = room->next;
	return (room);
}

static t_room	*ft_roomway(t_room *room)
{
	if (room->tube->salle->way == 0)
		room = room->tube->salle;
	else
		while (room->tube && room->tube->salle->way != 0)
			room->tube = room->tube->next;
	return (room);
}

int				ft_theway(t_room *room)
{
	t_room	*begin;
	t_room	*tmp;

	tmp = room;
	ft_first_tube(room, 1);
	room = ft_begin(room);
	begin = room;
	while (room && room->pos != 2)
	{
		if (room->pos == 1 && room->tube == NULL)
			return (0);
		room->way = 1;
		if (room->tube)
			room = ft_roomway(room);
		else
			room = ft_short(room, begin, tmp);
	}
	room->way = 1;
	room = begin;
	ft_first_tube(room, 0);
	return (1);
}
