/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:18:33 by tferrari          #+#    #+#             */
/*   Updated: 2017/05/17 12:11:04 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "ft_printf.h"

void		ft_color(t_way *tmp)
{
	ft_putstr("\e[38;5;");
	ft_putnbr(tmp->p->ant % 255);
	ft_putchar('m');
}

void		ft_print_way(t_way *way)
{
	while (way)
	{
		ft_printf("%s", way->p->name);
		if (way->p->pos != 2)
			ft_printf("->");
		way = way->next;
	}
	ft_printf("\n\n");
}

void		ft_bonus(int argc, char **argv, t_lem *lem)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "-w"))
			lem->b_way = 1;
		if (!ft_strcmp(argv[i], "-c"))
			lem->b_color = 1;
		i++;
	}
}
