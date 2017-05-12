/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:18:33 by tferrari          #+#    #+#             */
/*   Updated: 2017/05/11 18:20:08 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "ft_printf.h"

void		ft_print_way(t_way *way)
{
	t_way	*tmp;

	tmp = way;
	while(way)
	{
		ft_printf("%s", way->p->name);
		if (way->p->pos != 2)
			ft_printf("->");
		way = way->next;
	}
	way = tmp;
}
