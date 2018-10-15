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
    char            **cordstart;
    char            **cordend;
    int             count_rooms;
    t_link          *link;
    t_room          *room;
    t_way           *way;
};

struct		s_room
{
	char 			*name;
    int             x;
    int             y;
    int             ants;
	t_room			*next;
	t_way           *way;
	t_room          *root;
	int             visit;

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

void	parse(t_lm *st);
void     check_coment(t_lm *st, int fd, int *i);
int     check_link(char *str);
void    check_links(t_lm *st);
void    output_ants(t_lm *st);
void    check_ants_count(t_lm *st);
void    printing_way(t_room *room, int *cur_ant, int *count);
t_room    *search_right_room(t_room *st, char *room);
void    get_links(t_link *link, const char *str);
void    valid(t_lm *st);
void    findway(t_lm *st);
void    connect(t_lm *st);
void    check_rooms(t_lm *st);
int     add_new_room(t_lm *st);
int     add_new_link(t_lm *st);
void    connect_link(t_room *cur, t_room *dst);
void	error(int numb);
int		len_mas(char **tmp);
void    clear_leaks(t_lm **st);


#endif