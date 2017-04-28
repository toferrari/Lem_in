/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_room.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 12:14:23 by tferrari          #+#    #+#             */
/*   Updated: 2017/04/28 14:59:26 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"
#include "ft_printf.h"

int				ft_room(char *text, t_lem *lem, t_lst *lst)
{
	int		i;
	char	*tmp;

	i = ft_strclen(text, ' ');
	if (!(tmp = ft_strnew(i)))
		return (0);
	if (lem || lst)
		;
	tmp = ft_strncat(tmp, text, i);
	i++;
	lem->x = ft_atoi(text + i);
	i++;
	lem->y = ft_atoi(text + i + ft_intlen(lem->x));
	if (!ft_lstnewroom(lst, tmp, lem))
		return (0);
	if (tmp)
		ft_memdel((void **)&tmp);
	return (1);
}
