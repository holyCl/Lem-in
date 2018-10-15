#include "../inc/Lemin.h"

void    valid(t_lm *st)
{
    t_link *temp;
    int start_link;
    int end_link;

    temp = st->link;
    start_link  = 0;
    end_link = 0;

    while (temp && !(start_link == 1 && end_link == 1))
    {
        if (start_link == 0 && (!ft_strcmp(temp->cur, st->start) || !ft_strcmp(temp->dest, st->start)))
            start_link = 1;
        if (end_link == 0 && (!ft_strcmp(temp->cur,st->end) || !ft_strcmp(temp->dest,st->end)))
            end_link = 1;
        temp = temp->next;
    }
    if (!start_link || !end_link){
        ft_printf("ERORR!");
        exit(1);
    }
    check_rooms(st);
}
