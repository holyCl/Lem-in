#include "../inc/Lemin.h"
#include <fcntl.h>

void    check_links(t_lm *st)
{
    int flag1;
    int flag2;
    t_room  *temp;
    t_link  *link;

    link = st->link;
    while (link)
    {
        temp = st->room;
        flag1 = 0;
        flag2 = 0;
        while (temp &&(!flag1 || !flag2))
        {
            if (!ft_strcmp(link->cur, temp->name))
                flag1 = 1;
            if (!ft_strcmp(link->dest, temp->name))
                flag2 = 1;
            temp = temp->next;
        }
        if (!flag1 || !flag2)
            error(401);
        link = link->next;
    }
}

int     check_link(char *str)
{
    int count;

    count = 0;
    while(*str)
    {
        if (*str == '-')
            count++;
        str++;
    }
    if (count == 1)
        return (1);
    return(0);
}

int len_mas(char **tmp)
{
    int i;

    i = 0;
    while(tmp[i])
        i++;
    return(i);
}




void     check_coment(t_lm *st, int fd, int *i)
{
    if (ft_strcmp(st->line, "##start") == 0) // command start
    {
        if (!st->start)
        {
            if(st->line[0] == '#' && st->line[1] != '#')
            {
                ft_putendl("DSADAS");

            }
            ft_putendl(st->line);
            free(st->line);
            get_next_line(fd, &st->line);
            st->cordstart = ft_strsplit(st->line, ' ');
            if(len_mas(st->cordstart) != 3)
                error(501);
            st->start = st->cordstart[0];
            add_new_room(st);
        }
    } else if (ft_strcmp(st->line, "##end") == 0) // command end
    {
        if (!st->end) {
            ft_putendl(st->line);
            free(st->line);
            get_next_line(fd, &st->line);
            st->cordend = ft_strsplit(st->line, ' ');
            st->end = st->cordend[0];
            if(!search_right_room(st->room, *st->cordend))
                add_new_room(st);
            else {
                ft_putendl(st->line);
                error(201);
            }
        }else
            error(301);
    }
    if(st->line[1] != '#')
        ft_putendl(st->line);
    (*i)++;
}

void	parse(t_lm *st)
{
    int i;
    int fd;

//     fd = open("../test1", O_RDONLY);
    fd = 0;
    i = 0;
    while (get_next_line(fd, &st->line) > 0) {
        if(st->line[0] == '#' && st->line[1] != '#')
        {
            ft_putendl(st->line);
            free(st->line);
            continue;
        }
        if (i == 0) {
            check_ants_count(st);
            st->ants = ft_atoi(st->line);
            if (st->ants <= 0)
                error(101);
            ft_printf("%d\n", st->ants = ft_atoi(st->line));
            i++;
        }
        else if (st->line[0] != '#')
        {
            if(st->line[0] == '\0') {
                free(st->line);
                error(603);
            }
            if (!check_link(st->line)) {
                add_new_room(st);
                ft_putendl(st->line);
            } else
                add_new_link(st);
        } else
            check_coment(st, fd, &i);
        free(st->line);
    }

}

