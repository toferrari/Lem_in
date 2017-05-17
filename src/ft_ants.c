/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ants.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:32:11 by tferrari          #+#    #+#             */
/*   Updated: 2017/05/17 15:40:48 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "ft_printf.h"
#define RESET "\033[0m"

void			ft_print(t_way *way, t_lem *lem)
{
	t_way	*tmp;

	tmp = way->next;
	while (tmp)
	{
		if (tmp->p->ant > 0)
		{
			if (lem->b_color == 1)
				ft_color(tmp);
			ft_printf("L%d-%s ", tmp->p->ant, tmp->p->name);
			ft_putstr(RESET);
		}
		tmp = tmp->next;
	}
	ft_printf("\n");
}
