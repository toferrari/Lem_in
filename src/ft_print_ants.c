/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 10:59:05 by tferrari          #+#    #+#             */
/*   Updated: 2017/05/11 19:50:40 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "ft_printf.h"

void			ft_print_ants(t_way *way, t_lem *lem)
{
	t_way	*begin;
	// int		nb;
	// int		tmp;

	begin = way;
	// nb = 1;
	lem->ant_start = 0;
	way->p->ant = lem->ants;
	while (lem->ants_end < lem->ants)
	{
		lem->ant_start++;
		way = begin;
		while (way)
		{
			if (way->p->pos == 1 && lem->ant_start <= lem->ants)
			{
				way->next->p->ant = lem->ant_start;
				ft_printf("la fourmis %d est dans la salle %s\n", lem->ant_start, way->p->name);
				way = way->next;
			}
			way = way->next;
		}
	}
}
