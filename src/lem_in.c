/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 14:18:10 by tferrari          #+#    #+#             */
/*   Updated: 2017/04/28 14:49:55 by tferrari         ###   ########.fr       */
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
	else if (i == 3)
		ft_putendl("Error room");
	else if (i == 4)
		ft_putendl("Error room");
	return (0);
}

int				main(int argc, char **argv)
{
	t_lem	lem;
	t_lst	lst;
	t_lstl	lstl;

	ft_bzero(&lem, sizeof(lem));
	if (argv || argc)
		;
	ft_inti_lst(&lst);
	ft_inti_lstl(&lstl);
	while ((lem.ret = get_next_line(0, &lem.order)) == 1)
	{
		lem.parse = ft_parse(lem.order, &lem, &lst, &lstl);
		if (lem.parse == 0 || lem.parse == 3)
			return (ft_error(lem.parse));
		if (lem.parse != 1)
		{
			ft_error(lem.parse);
			break ;
		}
		else
			ft_printf("%s : est une bonne saisie\n", lem.order);
		ft_memdel((void **)&lem.order);
	}
	//ft_theway();
	ft_printlst(&lst);
	ft_printlstl(&lstl);
	return (0);
}
