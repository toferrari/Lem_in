/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 10:59:05 by tferrari          #+#    #+#             */
/*   Updated: 2017/05/17 15:52:17 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "ft_printf.h"

static void		ft_2room(t_way *way, t_lem *lem)
{
	t_way *tmp;

	tmp = way;
	if (tmp->next->p->pos == 2)
		lem->room = 1;
	if (lem->room == 1)
	{
		while (tmp->next->p->ant < lem->ants)
		{
			tmp->next->p->ant++;
			ft_print(way, lem);
		}
	}
}

static void		ft_check_end(t_way *way, t_lem *lem)
{
	t_way	*tmp;

	tmp = way;
	while (tmp && tmp->p->pos != 2)
		tmp = tmp->next;
	if (tmp->p->pos == 2 && tmp->p->ant > 0 && lem->ant_start > 0)
		lem->ants_end++;
}

static t_way	*ft_room_start(t_way *way, int *nb)
{
	way->p->ant--;
	way->next->p->ant = *nb;
	*nb -= 1;
	way = way->next->next;
	return (way);
}

static void		ft_ants(t_way *way, t_lem *lem, int *nb)
{
	if (way->p->ant == lem->ants)
	{
		*nb = lem->ants;
		way->p->ant = 0;
	}
	else if (*nb > 0)
	{
		way->p->ant = *nb;
		*nb -= 1;
	}
}

void			ft_print_ants(t_way *way, t_lem *lem)
{
	t_way	*begin;

	begin = way;
	lem->nb = 1;
	way->p->ant = lem->ants;
	ft_2room(way, lem);
	while (lem->ants_end < lem->ants && lem->room == 0)
	{
		if (lem->ant_start <= lem->ants)
			lem->ant_start++;
		lem->nb = lem->ant_start;
		while (way)
		{
			if (way->p->pos == 1 && way->p->ant > 0)
				way = ft_room_start(way, &lem->nb);
			else if (way->p->pos == 1)
				while (way && way->p->ant != lem->ants)
					way = way->next;
			ft_ants(way, lem, &lem->nb);
			way = way->next;
		}
		way = begin;
		ft_print(way, lem);
		ft_check_end(way, lem);
	}
}
