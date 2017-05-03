/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 18:15:32 by tferrari          #+#    #+#             */
/*   Updated: 2017/05/02 17:39:05 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "ft_printf.h"

t_tube			*ft_init_tube()
{
	t_tube *tube;

	if (!(tube = (t_tube *)malloc(sizeof(t_tube))))
		return (NULL);
	tube->salle = NULL;
	tube->next = NULL;
	return (tube);
}

static int		ft_lst_link(t_tube *tube, char *tmp1, char *tmp2, t_room *room)
{
	t_room	*tmp;

	tmp = room;
	while (tube && tube->next)
		tube = tube->next;
	while (!ft_strcmp(tmp1, room->name))
		room = room->next;
	
	return (1);
}

static int		ft_tmp(char **tmp1, char **tmp2, char *text)
{
	int		i;

	i = ft_strclen(text, '-');
	if (text[i] == '\0' || !(*tmp1 = ft_strnew(i)))
		return (0);
	*tmp1 = ft_strncat(*tmp1, text, i);
	i++;
	if (!(*tmp2 = ft_strnew(ft_strlen(text + i))))
		return (0);
	*tmp2 = ft_strcat(*tmp2, text + i);
	if (!ft_strcmp(*tmp1, *tmp2))
		return (0);
	return (1);
}

int				ft_add_link(t_tube *tube, char *text, t_lem *lem, t_room *room)
{
	char	*tmp1;
	char	*tmp2;
	t_room	*tmp;
	int		i;

	if (!ft_tmp(&tmp1, &tmp2, text))
		return (0);
	i = 0;
	tmp = room;
	while (tmp->next)
	{
		if (!ft_strcmp(tmp1, room->name) || !ft_strcmp(tmp2, room->name))
			i++;
		tmp = tmp->next;
	}
	if (i != 2)
		return (2);
	if (!ft_lst_link(tube, tmp1, tmp2, room))
		return (0);
	if (lem)
		;
	return (1);
}
