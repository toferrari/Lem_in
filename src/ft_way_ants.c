/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_way_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:10:05 by tferrari          #+#    #+#             */
/*   Updated: 2017/05/11 18:25:15 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "ft_printf.h"

t_way				*ft_init_way(void)
{
	t_way *way;

	if (!(way = (t_way *)malloc(sizeof(t_way))))
		return (NULL);
	way->p = NULL;
	way->next = NULL;
	return (way);
}

static int			ft_add(t_room *room, t_way *way)
{
	t_way	*tmp;

	tmp = way;
	if (way->p)
	{
		while (way && way->next)
			way = way->next;
		if (!(way->next = (t_way *)malloc(sizeof(t_way))))
			return (0);
		way = way->next;
	}
	way->p = room;
	way->next = NULL;
	way = tmp;
	return (1);
}

int				ft_way_ants(t_room *room, t_way *way)
{
	while (room && room->pos != 1)
		room = room->next;
	while (room && room->pos != 2)
	{
		if (room && room->way == 1)
		{
			room->way++;
			ft_add(room, way);
		}
		else
		{
			while (room->tube && room->tube->salle->way != 1)
				room->tube = room->tube->next;
			room = room->tube->salle;
		}
	}
	ft_add(room, way);
	return (1);
}
