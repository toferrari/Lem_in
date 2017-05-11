/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_theway.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 10:35:15 by tferrari          #+#    #+#             */
/*   Updated: 2017/05/10 18:07:48 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "ft_printf.h"

static void	ft_first_tube(t_room *room, int i)
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

int			ft_theway(t_room *room)
{
	t_room	*begin;
	t_room	*tmp;

	tmp = room;
	ft_first_tube(room, 1);
	while (room->pos != 1)
		room = room->next;
	begin = room;
	if (room->tube == NULL)
		return (0);
	while(room && room->pos != 2)
	{
		if (room->pos == 1 && room->tube == NULL)
			return (0);
		room->way = 1;
		if (room->tube)
		{
			if (room->tube->salle->way == 0)
			{
				ft_printf("Name: \033[33m%s\033[0m - Poids = %d\n", room->name, room->way);
				room = room->tube->salle;
			}
			else
			{
				while (room->tube && room->tube->salle->way != 0)
					room->tube = room->tube->next;
			}
		}
		else
		{
			room->way = 2;
			ft_printf("Cul de sac a \033[35m%s\033[0m\n", room->name);
			room = tmp;
			while (room)
			{
				if (room->way == 1)
					room->way = 0;
				room = room->next;
			}
			room = begin;
		}
	}
	ft_printf("END = \033[31m%s\033[0m", room->name);
	room = begin;
	ft_first_tube(room, 0);
	// ft_printf("pointeur = \033[32m%s\033[0m\n", room->tube->salle->name);
	return (1);
}
