#include "../inc/Lemin.h"
#include <fcntl.h>

int     check_coment(t_lm *st, int fd, int *i)
{
    char **tmp;

    if (st->line[1] != '#') // there is comment
    {
        ft_putendl(st->line);
        get_next_line(fd, &st->line);
    } else if (ft_strcmp(st->line, "##start") == 0) // command start
    {
        if (!st->start) {
            ft_putendl(st->line);
            get_next_line(fd, &st->line);
            tmp = ft_strsplit(st->line, ' ');
            st->start = tmp[0];
        } else {
            ft_printf("Error, start allready exist");
            exit(1);
        }
    } else if (ft_strcmp(st->line, "##end") == 0) // command end
    {
        if (!st->end) {
            ft_putendl(st->line);
            get_next_line(fd, &st->line);
            tmp = ft_strsplit(st->line, ' ');
            st->end = tmp[0];
        } else {
            ft_printf("Error, end allready exist");
            exit(1);
        }
    }
    ft_putendl(st->line);
    (*i)++;
}

//int     check_com(t_lm *st)
//{
//    if (st->line[0] == '#')
//    {
//        if (st->line[1] == '#')
//            return(1);
//        return(1);
//    }
//    return(0);
//}

void	check_ants_count(t_lm *st)
{
	int i;

	i = -1;
	while (st->line[++i])
		if (!ft_isdigit(st->line[i]))
		{
			ft_printf("Incorrect number of ants");
			exit(1);	
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

int     add_new_room(t_lm *st)
{
    t_room      *temp;
    int         i;

    i = 0;
    while (st->tmp && st->tmp[i])
    {
        free(st->tmp[i]);
        i++;
    }
    if (st->tmp)
        free(st->tmp);
    st->tmp = ft_strsplit(st->line, ' ');
    temp = st->room;
    while (temp)
    {
        temp = temp->next;
    }
    if (!(temp = (t_room *)malloc(sizeof(t_room))))
        exit(1);
    temp->name = strdup(st->tmp[0]);
    temp->x = ft_atoi(st->tmp[1]);
    temp->y = ft_atoi(st->tmp[2]);
    temp->next = st->room;
    st->room = temp;
//    ft_printf("test          name:%s\n", st->room->name);
    return(1);
}

void    get_links(t_link *link, const char *str)
{
    unsigned int i;

    i = 0;
    while (str[++i])
    {
        if (str[i] == '-'){
            link->cur = ft_strsub(str, 0, i);
            link->dest = ft_strsub(str, i+1, ft_strlen(str));
        }
    i++;
    }
}

int     add_new_link(t_lm *st)
{
    t_link  link;
    t_link  *lk;

    if (st->line[0] != '#')
    {
        get_links(&link, st->line);
        lk = st->link;
        while(lk)
            lk = lk->next;
        lk = (t_link*)malloc(sizeof(t_link));
        lk->cur = link.cur;
        lk->dest = link.dest;
        lk->next = st->link;
        st->link = lk;
    }
    return(1);
}

void	parse(t_lm *st)
{

    int i;
    int fd;

    fd = open("../test", O_RDONLY);
    i = 0;
    while (get_next_line(fd, &st->line) > 0) {
        if (i == 0) {
            check_ants_count(st);
            st->ants = ft_atoi(st->line);
            i++;
        }
        else if (st->line[0] != '#') // check rooms
        {
            if (!check_link(st->line)) {
                add_new_room(st);
                ft_putendl(st->line);
            } else
                add_new_link(st);
        } else  // check on comands or comments
            check_coment(st, fd, &i);
    }
}

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
            if (ft_strcmp(link->cur, temp->name))
                flag1 = 1;
            if (ft_strcmp(link->dest, temp->name))
                flag2 = 1;
            temp = temp->next;
        }
        if (!flag1 || !flag2)
        {
            printf("Connecting to non-existing room");
            exit(1);
        }
        link = link->next;
    }
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
            ft_printf("!!!!! %s %s\n", cur->name, dest->name);
            if (!ft_strcmp(cur->name,dest->name))
            {
                ft_printf("The rooms has same names");
                exit(1);
            }
            if (cur->x == dest->x && cur->y == dest->y)
            {
                ft_printf("The rooms has same cords");
                exit(1);
            }
            dest = dest->next;

        }
//        ft_printf(" ___%s ___%i %i", cur->name, cur->x, cur->y);
        cur = cur->next;
    }
    check_links(st);
}

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
        ft_printf("ERORR");
        exit(1);
    }
    check_rooms(st);
}


t_room    *search(t_room *st, char *room)
{
    t_room *temp;

    temp = st;
    while(temp)
    {
        if(!ft_strcmp(temp->name, room))
            return(temp);
        temp = temp->next;
    }
    return(NULL);
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
    way = (t_way *)malloc(sizeof(t_way));
    way->room = dst;
    way->next = cur->way;
    cur->way = way->next;
}

void    connect(t_lm *st)
{
    t_link  *temp;
    t_room  *cur;
    t_room  *dst;

    temp = st->link;
    while(temp)
    {
        cur = search(st->room, temp->cur);
        dst = search(st->room, temp->dest);
        if(cur && dst)
        {
            connect_link(cur, dst);
            connect_link(dst, cur);
        }
        temp = temp->next;
    }
}

void    findway(t_lm *st)
{


}

int main()
{
	t_lm st;
	
	ft_bzero(&st, sizeof(t_lm));
	parse(&st);
    valid(&st);
    connect(&st);
    findway(&st);
	ft_printf("\nCount of ants which we given: %d\nName of start room: %s\nName of end room: %s\n", st.ants, st.start, st.end);
}
