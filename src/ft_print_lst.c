/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 17:05:05 by tferrari          #+#    #+#             */
/*   Updated: 2017/05/11 09:44:13 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "ft_printf.h"

void			ft_printlink(t_room *room)
{
	t_room	*tmp;

	tmp = room;
	while (tmp->tube->next)
	{
		ft_printf("il y a un lien entre la salle : %s et la salle %s\n",
		tmp->name, room->tube->salle->name);
		tmp->tube = tmp->tube->next;
	}
}

void			ft_printroom(t_room *room)
{
	while (room)
	{
		ft_printf("\nnom de salle : %s\n", room->name);
		while (room->tube)
		{
			if (room->tube->salle)
				ft_printf("link : %s\n", room->tube->salle->name);
			room->tube = room->tube->next;
		}
		room = room->next;
	}
}
