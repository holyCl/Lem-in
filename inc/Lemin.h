#ifndef LEMIN_H
# define LEMIN_H
# include "../libftprintf/inc/ft_printf.h"

typedef struct		s_lemin t_lm;
typedef struct		s_room t_room;
typedef struct		s_link t_link;
typedef struct      s_way t_way;

struct		s_lemin
{
	int				ants;

	char			*start;
	char			*end;
    char            *line;
    char            **tmp;
    t_link          *link;
    t_room          *room;

};

struct		s_room
{
	char 			*name;
    int             x;
    int             y;
	t_room			*next;
	t_way           *way;
};

struct      s_link
{
    char            *cur;
    char            *dest;
    t_link          *next;
};

struct      s_way
{
    t_room          *room;
    t_way           *next;
};


#endif