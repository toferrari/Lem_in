/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_room.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 12:14:23 by tferrari          #+#    #+#             */
/*   Updated: 2017/04/21 15:06:42 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"
#include "ft_printf.h"

int				ft_room(char *text, t_lem *lem, t_room **room)
{
	int		i;
	int		x;
	int		y;
	char	*tmp;

	i = ft_strclen(text, ' ');
	if (!(tmp = ft_strnew(i)))
		return (0);
	if (lem || room)
		;
	tmp = ft_strncat(tmp, text, i);
	i++;
	x = ft_atoi(text + i);
	i++;
	y = ft_atoi(text + i + ft_intlen(x));
	*room = ft_lstnewroom(tmp, x, y);
	//ft_putstr(tmp);
	ft_printf("\nnom de salle : %s\nx = %d\ny = %d\n", tmp, x, y);
	if (tmp)
		ft_memdel((void **)&tmp);
	return (1);
}
