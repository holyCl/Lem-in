#include "../inc/Lemin.h"

void	ft_splitdel(char ***as)
{
    char	**ptr;

    if (as && *as)
    {
        ptr = *as;
        while (*ptr)
        {
            free(*ptr);
            *ptr = NULL;
            ++ptr;
        }
        free(*as);
        *as = NULL;
    }
}

int     add_new_room(t_lm *st)
{
    char        **tmp;
    t_room      *temp;
    int         i;

    i = 0;

    tmp = ft_strsplit(st->line, ' ');
//    temp = st->room;
    check_rooms(st);
    if (!(temp = (t_room *)malloc(sizeof(t_room))))
        exit(1);
    temp->name = ft_strdup(tmp[0]);
    if(tmp[3]) {
        ft_putendl(st->line);
        error(501);
    }
    temp->x = ft_atoi(tmp[1]);
    temp->y = ft_atoi(tmp[2]);
    temp->next = st->room;
    temp->way = st->way;
    temp->visit = 0;
    temp->ants = 0;
    st->room = temp;
    st->count_rooms++;
    ft_splitdel(&tmp);
//    while (tmp[i])
//    {
//        free(st->tmp[i]);
//        i++;
//    }
//    if (tmp)
//        free(st->tmp);

//    ft_memdel((void*)&temp->name);



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
//            ft_printf("!!!!! %s %s\n", cur->name, dest->name);
            if (!ft_strcmp(cur->name,dest->name))
                error(201);
            if (cur->x == dest->x && cur->y == dest->y)
                error(202);
            dest = dest->next;

        }
//        ft_printf(" ___%s ___%i %i", cur->name, cur->x, cur->y);
        cur = cur->next;
    }
    check_links(st);
}