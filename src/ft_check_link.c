/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 18:15:32 by tferrari          #+#    #+#             */
/*   Updated: 2017/04/26 19:20:36 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "ft_printf.h"

void			ft_inti_lstl(&lstl)
{
	lstl->link1 = NULL;
	lstl->link2 = NULL;
	lstl->first = NULL;
}

int				ft_check_link(t_lstl lstl, char *text, t_lem *lem)
{
	char	*tmp1;
	char	*tmp2;
	int		i;

	i = ft_strclen(text, '-');
	if (!(tmp1 = ft_strnew(i)))
		return (0);
	tmp1 = ft_strncat(tmp1, text, i);
	i++;
	if (!(tmp2 = ft_strnew(ft_strlen(text + i))))
		return (0);
	tmp2 = ft_strcat(tmp2, text + i);
	return (1);
}
