/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 14:18:10 by tferrari          #+#    #+#             */
/*   Updated: 2017/04/14 15:11:29 by tferrari         ###   ########.fr       */
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
	int		line;
	t_lem	lem;

	order = NULL;
	line = 0;
	ft_bzero(&lem, sizeof(lem));
	if (argv || argc)
		;
	while ((ret = get_next_line(0, &order)) == 1)
	{
		if (!ft_parse(order, line, &lem))
			return (ft_error());
		line++;
		ft_memdel((void **)&order);
	}
	ft_putendl("ok");
	return (0);
}
