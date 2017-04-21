/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 14:18:10 by tferrari          #+#    #+#             */
/*   Updated: 2017/04/21 14:58:59 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "get_next_line.h"
#include "ft_printf.h"

static int		ft_error()
{
	ft_putendl("Error");
	return (0);
}

int				main(int argc, char **argv)
{
	char	*order;
	int		ret;
	int		parse;
	t_lem	lem;
	t_room	*room;
	int		line;

	order = NULL;
	parse = 0;
	line = 1;
	ft_bzero(&lem, sizeof(lem));
	if (argv || argc)
		;
	while ((ret = get_next_line(0, &order)) == 1)
	{
		parse = ft_parse(order, &lem, &room);
		if (parse == 0)
			return (ft_error());
		if (parse != 1)
			{ft_printf("%s : est une mauvaise saisie\n", order);break ;}
		else
			ft_printf("%s : est une bonne saisie\n", order);
		ft_memdel((void **)&order);
	}
	ft_printf("\nnom de salle : %s\nx = %d\ny = %d\n", room->room, room->x, room->y);
	ft_putendl("ok");
	return (0);
}
