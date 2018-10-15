#include "../inc/Lemin.h"

void    check_ants_count(t_lm *st) {
    int i;

    i = -1;
    if (!st->line[++i])
        error(101);
    while (st->line[++i])
        if (!ft_isdigit(st->line[i]))
            error(101);
}



t_room    *search_right_room(t_room *st, char *room)
{

    while(st)
    {
        if(!ft_strcmp(st->name, room))
            return(st);
        st = st->next;
    }
    return(NULL);
}

void    printing_way(t_room *room, int *cur_ant, int *count)
{
    room->root->ants--;
    room->ants++;
    (*cur_ant)++;
    (*count == 0)?(*count)++:ft_printf(" ");
    ft_printf("L%d-%s", *cur_ant, room->name);
}


void    output_ants(t_lm *st)
{
    t_room      *room;
    t_room      *finish;
    int         cur_ant;
    int         count;

    room = search_right_room(st->room, st->start);
    finish = search_right_room(st->room, st->end);
    room->ants = st->ants;
    while(finish->ants < st->ants) {
        room = finish;
        cur_ant = finish->ants;
        count = 0;
        while (ft_strcmp(room->name, st->start))
        {
            if (room->root->ants != 0)
                printing_way(room, &cur_ant, &count);
            room = room->root;
        }
        ft_printf("\n");
    }
}