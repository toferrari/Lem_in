/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewroom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 19:37:12 by tferrari          #+#    #+#             */
/*   Updated: 2017/04/28 15:11:20 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "ft_printf.h"

void			ft_inti_lst(t_lst *lst)
{
	lst->room = NULL;
	lst->x = 0;
	lst->y = 0;
	lst->start = 0;
	lst->end = 0;
	lst->first = NULL;
}

int				ft_lstnewroom(t_lst *lst, char *content, t_lem *lem)
{
	t_elem *elem;

	if (!(elem = (t_elem *)malloc(sizeof(t_elem))))
		return (0);
	if (elem != NULL && content != NULL)
	{
		if (!(elem->room = ft_strnew(ft_strlen(content))))
			return (0);
		elem->room = ft_strcpy(elem->room, content);
		elem->x = lem->x;
		elem->y = lem->y;
		if (lem->start == 2)
		{
			elem->start = 1;
			lem->start = 3;
		}
		else if (lem->end == 2)
		{
			elem->end = 1;
			lem->end = 3;
		}
	}
	else
		return (0);
	elem->next = lst->first;
	lst->first = elem;
	return (1);
}

void			ft_printlst(t_lst *lst)
{
	t_elem *elem;

	elem = lst->first;
	while (elem)
	{
		ft_printf("\nnom de salle : %s\nx = %d\ny = %d\n",
		elem->room, elem->x, elem->y);
		elem = elem->next;
	}
}
