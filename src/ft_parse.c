/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 16:13:02 by tferrari          #+#    #+#             */
/*   Updated: 2017/04/14 18:25:48 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "ft_printf.h"

static int	ft_ants(char *text, t_lem *lem)
{
	int i;

	i = 0;
	while (text[i])
	{
		if (!ft_isdigit(text[i]))
			return (0);
		i++;
	}
	lem->ants = ft_atoi(text);
	ft_printf("nb = %d\n", lem->ants);
	if (text[0] == '\0' || lem->ants == 0)
		return (0);
	return (1);
}

static int	ft_instruction(char *text, t_lem * lem)
{
	int i;

	i = 0;
	if ()
}

int			ft_parse(char *text, int line, t_lem *lem)
{
	if (line == 0)
		return (ft_ants(text, lem));
	else if (text[0] == '#' && text[1] == '#')
		return (ft_instruction(text + 2, lem))
	return (1);
}
