/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 18:15:32 by tferrari          #+#    #+#             */
/*   Updated: 2017/05/16 18:57:48 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "ft_printf.h"

static int		ft_link1(t_tube *tube, t_room *tmp2)
{
	t_tube *temp;

	if (tube->salle != NULL)
	{
		while (tube->next)
			tube = tube->next;
		if (!(tube->next = (t_tube *)malloc(sizeof(t_tube))))
			return (0);
		temp = tube;
		tube = tube->next;
		tube->prev = temp;
	}
	tube->salle = tmp2;
	tube->next = NULL;
	return (1);
}

static int		ft_link2(t_tube *tube, t_room *tmp)
{
	t_tube *temp;

	if (tube->salle)
	{
		while (tube->next)
			tube = tube->next;
		if (!(tube->next = (t_tube *)malloc(sizeof(t_tube))))
			return (0);
		temp = tube;
		tube = tube->next;
		tube->prev = temp;
	}
	tube->salle = tmp;
	tube->next = NULL;
	return (1);
}

static int		ft_lst_link(char *ch1, char *ch2, t_room *room)
{
	t_room	*tmp;
	t_room	*tmp2;

	tmp = room;
	tmp2 = room;
	while (ft_strcmp(ch1, tmp->name))
		tmp = tmp->next;
	if (tmp->tube == NULL)
		if (!(tmp->tube = ft_init_tube(tmp->tube)))
			return (0);
	while (ft_strcmp(ch2, tmp2->name))
		tmp2 = tmp2->next;
	if (tmp2->tube == NULL)
		if (!(tmp2->tube = ft_init_tube(tmp2->tube)))
			return (0);
	if (!ft_link1(tmp->tube, tmp2) || !ft_link2(tmp2->tube, tmp))
		return (0);
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

int				ft_add_link(char *text, t_room *room)
{
	char	*tmp1;
	char	*tmp2;
	t_room	*tmp;
	int		i;

	if (!ft_tmp(&tmp1, &tmp2, text))
		return (7);
	i = 0;
	tmp = room;
	while (tmp)
	{
		if (!ft_strcmp(tmp1, tmp->name) || !ft_strcmp(tmp2, tmp->name))
			i++;
		tmp = tmp->next;
	}
	if (i != 2)
		return (7);
	if (!ft_lst_link(tmp1, tmp2, room))
		return (0);
	if (tmp1)
		ft_memdel((void **)&tmp1);
	if (tmp2)
		ft_memdel((void **)&tmp2);
	return (1);
}
