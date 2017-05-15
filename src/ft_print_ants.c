/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 10:59:05 by tferrari          #+#    #+#             */
/*   Updated: 2017/05/15 16:58:51 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "ft_printf.h"

static void		ft_print(t_way *way)
{
	t_way	*tmp;

	tmp = way->next;
	while (tmp)
	{
		if (tmp->p->ant > 0)
			ft_printf("L%d-%s ", tmp->p->ant, tmp->p->name);
		tmp = tmp->next;
	}
	ft_printf("\n");
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
	int		nb;

	begin = way;
	nb = 1;
	way->p->ant = lem->ants;
	while (lem->ants_end < lem->ants)
	{
		if (lem->ant_start <= lem->ants)
			lem->ant_start++;
		nb = lem->ant_start;
		while (way)
		{
			if (way->p->pos == 1 && way->p->ant > 0)
				way = ft_room_start(way, &nb);
			else if (way->p->pos == 1)
				while (way && way->p->ant != lem->ants)
					way = way->next;
			ft_ants(way, lem, &nb);
			way = way->next;
		}
		way = begin;
		ft_print(way);
		ft_check_end(way, lem);
	}
}
