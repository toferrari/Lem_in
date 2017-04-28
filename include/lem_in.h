/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 14:19:18 by tferrari          #+#    #+#             */
/*   Updated: 2017/04/28 15:02:40 by tferrari         ###   ########.fr       */
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
	char		*order;
	int			ret;
	int			parse;
	int			x;
	int			y;
}				t_lem;

typedef	struct	s_elem
{
	char				*room;
	int					y;
	int					x;
	int					start;
	int					end;
	struct s_elem		*next;
}				t_elem;

typedef	struct	s_lst
{
	char				*room;
	int					y;
	int					x;
	int					start;
	int					end;
	struct s_elem		*first;
}				t_lst;


typedef	struct	s_eleml
{
	char				*link1;
	char				*link2;
	struct s_eleml		*next;
}				t_eleml;

typedef	struct	s_lstl
{
	char				*link1;
	char				*link2;
	struct s_eleml		*first;
}				t_lstl;


int				ft_parse(char *text, t_lem *lem, t_lst *list, t_lstl *lstl);
void			ft_check_parse(char * test, t_lem *lem);
void			ft_inti_lst(t_lst *lst);
void			ft_inti_lstl(t_lstl *lstl);
int				ft_lstnewroom(t_lst *lst, char *content, t_lem *lem);
void			ft_printlst(t_lst *lst);
void			ft_printlstl(t_lstl *lstl);
int				ft_room(char *text, t_lem *lem, t_lst *lst);
int				ft_check_link(t_lstl *lstl, char *text, t_lem *lem, t_lst *lst);

#endif
