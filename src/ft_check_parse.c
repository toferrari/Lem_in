/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 14:47:54 by tferrari          #+#    #+#             */
/*   Updated: 2017/04/21 11:31:38 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "ft_printf.h"

static int		ft_word(char *text)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (text[i])
	{
		while (text[i] != ' ' && text[i])
			i++;
		nb++;
		if (text[i])
			i++;
	}
	return (nb);
}
/*
static void		ft_coor(char *text, t_lem *lem)
{
	int i;
	int compt;

	i = 0;
	compt = 0;
	while (text[i])
	{
		while (text[i] && ft_isdigit(text[i]))
			i++;
		compt++;
		if (text[i] != '-' && text[i])
			lem->check = 3;
		if (text[i])
			i++;
	}
	if (compt != 2)
		lem->check = 3;
}
*/
void			ft_check_parse(char *text, t_lem *lem)
{
	int		nb;
	int		i;
	int		compt;

	nb = ft_word(text);
	i = 0;
	compt = 0;
	if (lem->check == 1 && nb == 1)
		lem->check++;
	if ((lem->check == 1 && nb != 3) || (lem->check == 2 && nb != 1))
		lem->check = 3;
	if (lem->check == 1 && nb == 3)
	{
		i = ft_strclen(text, ' ');
		if (text[i] == '\0')
			lem->check = 3;
		i++;
		while (text[i])
		{
			while (text[i] != ' ' && text[i])
			{
				if (!ft_isdigit(text[i]))
					lem->check = 3;
				i++;
			}
			compt++;
			if (text[i])
				i++;
		}
		if (compt != 2)
			lem->check = 3;
		if (lem->start == 1)
			lem->start = 2;
		if (lem->end == 1)
			lem->end = 2;
		return ;
	}
	//if (lem->check == 2 && nb == 1)
		//ft_coor(text, lem);
	/*if (lem->check == 1)
	{
		i = ft_strclen(text, ' ');
		if (text[i] == '\0')
			return (2);
		text += i;
		while (text[i])
		{
			while (text[i] != ' ' && text[i])
			{
				if (!ft_isdigit(text[i]))
					return (2);
				i++;
			}
			nb++;
			if (text[i])
				i++;
		}
		if (nb != 2)
			return (2);
		return (1);
	}*/
}
