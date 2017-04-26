/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewroom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 19:37:12 by tferrari          #+#    #+#             */
/*   Updated: 2017/04/26 17:57:56 by tferrari         ###   ########.fr       */
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
	lst->first = NULL;
}

int				ft_lstnewroom(t_lst *lst, char *content, int x, int y)
{
	t_elem *elem;

	if (!(elem = (t_elem *)malloc(sizeof(t_elem))))
		return (0);
	if (elem != NULL && content != NULL)
	{
		if (!(elem->room = ft_strnew(ft_strlen(content))))
			return (0);
		elem->room = ft_strcpy(elem->room, content);
		elem->x = x;
		elem->y = y;
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
