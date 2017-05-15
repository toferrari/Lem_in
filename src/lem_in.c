/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 14:18:10 by tferrari          #+#    #+#             */
/*   Updated: 2017/05/15 19:28:54 by tferrari         ###   ########.fr       */
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
	else if (i == 2)
		ft_putendl("Error link");
	else if (i == 3)
		ft_putendl("Error room");
	else if (i == 4)
		ft_putendl("Error room");
	else if (i == 6)
		ft_putendl("No way");
	return (0);
}

int				main(int argc, char **argv)
{
	t_lem	lem;
	t_room	*room;
	t_way	*way;

	ft_bzero(&lem, sizeof(lem));
	if (argv || argc)
		;
	room = ft_init_room();
	way = ft_init_way();
	while ((lem.ret = get_next_line(0, &lem.order)) == 1)
	{
		lem.parse = ft_parse(lem.order, &lem, room);
		if (lem.parse == 0 || lem.parse == 3)
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
	if (!ft_theway(room))
		return (ft_error(6));
	ft_way_ants(room, way);
	ft_print_way(way);
	ft_print_ants(way, &lem);
	//  ft_printroom(room);
	ft_printf("\n\n\n%d", argc);
	return (0);
}
