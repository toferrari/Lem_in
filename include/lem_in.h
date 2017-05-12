/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 14:19:18 by tferrari          #+#    #+#             */
/*   Updated: 2017/05/11 19:49:45 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

typedef	struct	s_lem
{
	int			ants;
	int			ant_start;
	int			ants_end;
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

typedef struct		s_way
{
	struct s_room	*p;
	struct s_way	*next;
}					t_way;

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
t_way			*ft_init_way();
int				ft_way_ants(t_room *room, t_way *way);
void			ft_print_ants(t_way *way, t_lem *lem);

#endif
