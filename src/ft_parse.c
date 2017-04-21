/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 16:13:02 by tferrari          #+#    #+#             */
/*   Updated: 2017/04/21 12:06:08 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "ft_printf.h"

static int	ft_ants(char *text, t_lem *lem)
{
	int i;

	i = -1;
	while (text[++i])
		if (!ft_isdigit(text[i]))
			return (0);
	lem->ants = ft_atoi(text);
	lem->check++;
	return ((lem->ants == 0) ? 0 : 1);
}

static int	ft_instruction(char *text, t_lem *lem)
{
	if (lem->start == 1 || lem->end == 1)
		return (2);
	if (ft_strstr(text, "start") && ft_strlen(text) == 5 && lem->start == 0)
		lem->start = 1;
	else if (ft_strstr(text, "end") && ft_strlen(text) == 3 && lem->end == 0)
		lem->end = 1;
	return (1);
}

int			ft_parse(char *text, t_lem *lem, t_room **room)
{
	if (lem->check > 0 && (text[0] == 'L' || text[0] == '\0'))
		return (2);
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
		return(1);
	return (2);
}
