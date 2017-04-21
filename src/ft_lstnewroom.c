/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewroom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 19:37:12 by tferrari          #+#    #+#             */
/*   Updated: 2017/04/21 15:09:20 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

t_room	*ft_lstnewroom(void const *content, int x, int y)
{
	t_room	*newlst;

	if (!(newlst = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	if (newlst != NULL && content != NULL)
	{
		if (!(newlst->room = ft_strnew(ft_strlen(content))))
			return (NULL);
		newlst->room = ft_strcpy((char *)newlst->room, content);
		newlst->x = x;
		newlst->y = y;
	}
	else
	{
		newlst->room = NULL;
		newlst->x = 0;
		newlst->y = 0;
	}
	newlst->next = NULL;
	return (newlst);
}
