/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 10:59:05 by tferrari          #+#    #+#             */
/*   Updated: 2017/05/10 16:47:11 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "ft_printf.h"

void			ft_print_ants(t_room *room, t_lem *lem)
{
	int		nb;
	int		ended;
	t_room	*begin;

	nb = 1;
	while (room->pos != 1)
		room = room->next;
	begin = room;
	while (ended < lem->ants)
	{
		if (room->tube && room->tube->salle->ant != 0)
		
	}
}
