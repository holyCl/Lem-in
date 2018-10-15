#include "../inc/Lemin.h"

int     add_new_room(t_lm *st)
{
    t_room      *temp;
    int         i;

    i = 0;
    st->tmp = ft_strsplit(st->line, ' ');
    check_rooms(st);
    if (!(temp = (t_room *)malloc(sizeof(t_room))))
        exit(1);
    temp->name = ft_strdup(st->tmp[0]);
    if(st->tmp[3]) {
        ft_putendl(st->line);
        error(501);
    }
    temp->x = ft_atoi(st->tmp[1]);
    temp->y = ft_atoi(st->tmp[2]);
    temp->next = st->room;
    temp->way = st->way;
    temp->visit = 0;
    temp->ants = 0;
    st->room = temp;
    st->count_rooms++;
    while (st->tmp && st->tmp[i])
    {
        free(st->tmp[i]);
        i++;
    }
    if (st->tmp)
        free(st->tmp);
    return(1);
}

void    check_rooms(t_lm *st)
{
    t_room  *cur;
    t_room  *dest;

    cur = st->room;
    while(cur)
    {
        dest = cur->next;
        while (dest)
        {
            if (!ft_strcmp(cur->name,dest->name))
                error(201);
            if (cur->x == dest->x && cur->y == dest->y)
                error(202);
            dest = dest->next;
        }
        cur = cur->next;
    }
    check_links(st);
}