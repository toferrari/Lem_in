/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 16:13:02 by tferrari          #+#    #+#             */
/*   Updated: 2017/05/17 15:51:54 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "ft_printf.h"

static int	ft_ants(char *text, t_lem *lem)
{
	int i;

	i = -1;
	if (text[0] == '#' && text[1] != '#')
		return (1);
	if (text[0] == '#' && text[1] == '#' && ((ft_strcmp(text + 2, "start") != 0)
	|| (ft_strcmp(text + 2, "end") != 0)))
		return (1);
	while (text[++i])
		if (!ft_isdigit(text[i]))
			return (5);
	lem->ants = ft_atoi(text);
	lem->check++;
	return ((lem->ants < 1) ? 5 : 1);
}

static int	ft_instruction(char *text, t_lem *lem)
{
	if (((ft_strstr(text, "start") && ft_strlen(text) == 5) ||
	(ft_strstr(text, "end") && ft_strlen(text) == 3)) &&
	((lem->start > 0 && lem->start < 3) || (lem->end > 0 && lem->end < 3)))
		return (3);
	if (ft_strstr(text, "start") && ft_strlen(text) == 5 && lem->start == 0)
		lem->start = 1;
	else if (ft_strstr(text, "end") && ft_strlen(text) == 3 && lem->end == 0)
		lem->end = 1;
	return (1);
}

int			ft_parse(char *text, t_lem *lem, t_room *room)
{
	if (lem->check > 0 && text[0] == 'L')
		return (6);
	if (text[0] == '\0')
		return (10);
	if (lem->check == 0)
		return (ft_ants(text, lem));
	if (text[0] == '#' && text[1] == '#')
		return (ft_instruction(text + 2, lem));
	else if (text[0] == '#')
		return (1);
	ft_check_parse(text, lem);
	if (lem->check == 1)
		return (ft_room(text, lem, room));
	else if (lem->check == 2)
		return (ft_add_link(text, room));
	return (lem->check);
}
