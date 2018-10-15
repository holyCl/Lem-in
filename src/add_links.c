#include "../inc/Lemin.h"

int     add_new_link(t_lm *st)
{
    t_link  *lk;
    char **tmp;

    if(ft_strstr(st->line," ")) {
        ft_putendl(st->line);
        error(502);
    }
    if(!st->start)
        error(303);
    if(!st->end)
        error(304);
    if (st->line[0] != '#')
    {
        tmp = ft_strsplit(st->line, '-');
        lk = st->link;
        while(lk)
            lk = lk->next;
        lk = (t_link*)malloc(sizeof(t_link));
        lk->cur = tmp[0];
        lk->dest = tmp[1];
        lk->next = st->link;
        st->link = lk;
    }

    ft_memdel((void **)&tmp);
    ft_putendl(st->line);
    check_links(st);
    return(1);
}

void    connect_link(t_room *cur, t_room *dst)
{
    t_way *way;

    way = cur->way;
    while (way)
    {
        if (way->room == dst)
            return ;
        way = way->next;
    }
    way = malloc(sizeof(t_way *));
    way->room = dst;
    way->next = cur->way;
    cur->way = way;
}