/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 14:19:18 by tferrari          #+#    #+#             */
/*   Updated: 2017/04/21 13:52:12 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

typedef	struct	s_lem
{
	int			ants;
	int			start;
	int			end;
	int			line;
	int			check;
}				t_lem;

typedef	struct	s_room
{
	const void			*room;
	int					y;
	int					x;
	struct s_room		*next;
}				t_room;

int				ft_parse(char *text, t_lem *lem, t_room **room);
void			ft_check_parse(char * test, t_lem *lem);
t_room			*ft_lstnewroom(void const *content, int x, int y);
int				ft_room(char *text, t_lem *lem, t_room **room);

#endif
