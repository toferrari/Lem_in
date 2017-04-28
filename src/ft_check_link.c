/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 18:15:32 by tferrari          #+#    #+#             */
/*   Updated: 2017/04/27 16:16:01 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "ft_printf.h"

void			ft_inti_lstl(t_lstl *lstl)
{
	lstl->link1 = NULL;
	lstl->link2 = NULL;
	lstl->first = NULL;
}

static int		ft_lst_link(t_lstl *lstl, char *tmp1, char *tmp2)
{
	t_eleml *eleml;

	if (!(eleml = (t_eleml *)malloc(sizeof(t_eleml))))
		return (0);
	if (!(eleml->link1 = ft_strnew(ft_strlen(tmp1))) ||
	!(eleml->link2 = ft_strnew(ft_strlen(tmp2))))
		return (0);
	eleml->link1 = ft_strcpy(eleml->link1, tmp1);
	eleml->link2 = ft_strcpy(eleml->link2, tmp2);
	eleml->next = lstl->first;
	lstl->first = eleml;
	return (1);
}

int				ft_check_link(t_lstl *lstl, char *text, t_lem *lem, t_lst *lst)
{
	char	*tmp1;
	char	*tmp2;
	t_elem	*elem;
	int		i;

	i = ft_strclen(text, '-');
	if (text[i] == '\0' || !(tmp1 = ft_strnew(i)))
		return (0);
	tmp1 = ft_strncat(tmp1, text, i);
	i++;
	if (!(tmp2 = ft_strnew(ft_strlen(text + i))))
		return (0);
	tmp2 = ft_strcat(tmp2, text + i);
	if (!ft_strcmp(tmp1, tmp2))
		return (0);
	elem = lst->first;
	i = 0;
	while (elem)
	{
		if (!ft_strcmp(tmp1, elem->room) || !ft_strcmp(tmp2, elem->room))
			i++;
		elem = elem->next;
	}
	if (i != 2)
		return (2);
	if (!ft_lst_link(lstl, tmp1, tmp2))
		return (0);
	if (lem)
		;
	return (1);
}

void		ft_printlstl(t_lstl *lstl)
{
	t_eleml *eleml;

	eleml = lstl->first;
	while (eleml)
	{
		ft_printf("il y a un lien entre la salle : %s et la salle %s\n",
		eleml->link1, eleml->link2);
		eleml = eleml->next;
	}
}
