/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_theway.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 10:35:15 by tferrari          #+#    #+#             */
/*   Updated: 2017/05/10 10:30:21 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "ft_printf.h"

int			ft_theway(t_room *room)
{
	t_room	*begin;
	t_room	*tmp;

	tmp = room;
	while (room->pos != 1)
		room = room->next;
	begin = room;
	if (room->tube == NULL)
		return (0);
	ft_printf("passe\n");
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
	while (room)
	{
		//printf("salle %s\n", room->name);
		while (room->tube && room->tube->prev)
		{
		//	printf("tube %s\n", room->tube->salle->name);
			room->tube = room->tube->prev;
		//	printf("prev %s\n", room->tube->salle->name);
		}
		room = room->next;
	}
	room = begin;
	// ft_printf("pointeur = \033[32m%s\033[0m\n", room->tube->salle->name);
	return (1);
}
