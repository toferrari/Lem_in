/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 14:18:10 by tferrari          #+#    #+#             */
/*   Updated: 2017/05/16 18:55:51 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "get_next_line.h"
#include "ft_printf.h"

static int		ft_error(int i)
{
	if (i == 0)
		ft_putendl("Error");
	else if (i == 7)
		ft_putendl("Error link");
	else if (i == 3)
		ft_putendl("Error room");
	else if (i == 4)
		ft_putendl("Error room duplicate name");
	else if (i == 5)
		ft_putendl("Error ants");
	else if (i == 9)
		ft_putendl("No way");
	else if (i == 6)
		ft_putendl("Illegal name");
	return (0);
}

static int		ft_main2(t_room *room, t_way *way, t_lem *lem)
{
	if (lem->check == 0)
		return (5);
	if (lem->start != 3 || lem->end != 3)
		return (3);
	if (!ft_theway(room))
		return (9);
	ft_way_ants(room, way, lem);
	ft_print_ants(way, lem);
	if (lem->order)
		ft_memdel((void **)&lem->order);
	return (10);
}

int				main(int argc, char **argv)
{
	t_lem	lem;
	t_room	*room;
	t_way	*way;

	ft_bzero(&lem, sizeof(lem));
	room = ft_init_room();
	way = ft_init_way();
	ft_bonus(argc, argv, &lem);
	while ((lem.ret = get_next_line(0, &lem.order)) == 1)
	{
		lem.parse = ft_parse(lem.order, &lem, room);
		if (lem.parse == 0 || (lem.parse >= 3 && lem.parse <= 6))
			return (ft_error(lem.parse));
		if (lem.parse != 1)
		{
			ft_error(lem.parse);
			break ;
		}
		else
			ft_printf("%s\n", lem.order);
		ft_memdel((void **)&lem.order);
	}
	return (ft_error(ft_main2(room, way, &lem)));
}
