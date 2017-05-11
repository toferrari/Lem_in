/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 14:19:18 by tferrari          #+#    #+#             */
/*   Updated: 2017/05/11 10:47:49 by tferrari         ###   ########.fr       */
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
}				t_lem;

typedef struct		s_room
{
	char			*name;
	int				pos;
	int				ant;
	int				way;
	struct s_tube	*tube;
	struct s_room	*next;
	struct s_tube	*first_tube;
}					t_room;

typedef struct		s_tube
{
	struct s_room	*salle;
	struct s_tube	*next;
	struct s_tube	*prev;
}					t_tube;

int				ft_parse(char *text, t_lem *lem, t_room *room);
void			ft_check_parse(char * test, t_lem *lem);
t_room			*ft_init_room();
t_tube			*ft_init_tube(t_tube *tube);
int				ft_lstnewroom(t_room *room, char *name, t_lem *lem);
void			ft_printroom(t_room *room);
void			ft_printlink(t_room *room);
int				ft_room(char *text, t_lem *lem, t_room *room);
int				ft_add_link(char *text, t_room *room);
int				ft_theway(t_room *room);

#endif
