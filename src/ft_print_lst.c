/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 17:05:05 by tferrari          #+#    #+#             */
/*   Updated: 2017/05/03 14:49:50 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "ft_printf.h"

void		ft_printlstl(t_tube *tube)
{
	while (tube->next)
	{
		ft_printf("il y a un lien entre la salle : %s et la salle %s\n");
		tube = tube->next;
	}
}

void			ft_printlst(t_room *room)
{
	while (room && room->next)
	{
		ft_printf("\nnom de salle : %s\n", room->name);
		room = room->next;
	}
}
