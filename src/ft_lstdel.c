/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:38:01 by tferrari          #+#    #+#             */
/*   Updated: 2017/04/20 11:41:52 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	while (*alst)
	{
		(*del)((void *)(*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = (*alst)->next;
	}
	ft_memdel((void **)alst);
}
