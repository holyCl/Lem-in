#include "../inc/Lemin.h"
#include <fcntl.h>

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
    temp->way = st->way;
    temp->visit = 0;
    st->room = temp;
    st->count_rooms++;
//    ft_printf("test          name:%s\n", st->room->name);
    return(1);
}

void     check_coment(t_lm *st, int fd, int *i)
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
            add_new_room(st);
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
            add_new_room(st);
        } else {
            ft_printf("Error, end allready exist");
            exit(1);
        }
    }
    ft_putendl(st->line);
    (*i)++;
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

    fd = open("../test1", O_RDONLY);
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
//            ft_printf("!!!!! %s %s\n", cur->name, dest->name);
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

////////////////////////// CONNECTING ROOMS
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

void    connect(t_lm *st)
{
    t_link  *temp;
    t_room  *cur;
    t_room  *dst;

    temp = st->link;
    while(temp)
    {
        cur = search_right_room(st->room, temp->cur);
        dst = search_right_room(st->room, temp->dest);
        if(cur && dst)
        {
            connect_link(cur, dst);
            connect_link(dst, cur);
        }
//        ft_printf("\ncur:%s dest:%s \t",cur->name,dst->name);
        temp = temp->next;
    }
    ft_printf("\n");
}


////////////////////// FINDING WAY


void    add_to_path(t_lm **st, t_room *room)
{
    t_way  *path;
    t_way *node;

    path = (*st)->way;
    while(path)
    {
        if (path->room == room)
            return ;
        path = path->next;
    }
//    node = (t_way *)malloc(sizeof(t_path));
    node = malloc(sizeof(t_path));
    node->room = room;
    node->next = NULL;
    if(!(*st)->way){
        (*st)->way = node;
    }else{
        path = (*st)->way;
        while(path->next)
            path = path->next;
        path->next = node;
    }
    room->visit = 1;
}

t_room *get_room1(t_way **room)
{
    t_room *temp;
    t_way   *way;

    way = *room;
    if(way){
        temp = way->room;
        *room = (*room)->next;
        return (temp);
    }
    return(NULL);
}

void    findway(t_lm *st)
{
    t_room  *room;
    t_way   *edge;

    room = search_right_room(st->room, st->start);
    add_to_path(&st, room);
    while (st->way) {
        room = get_room1(&st->way);
        room->visit = 1;
        edge = room->way;
        while (edge) {
            if (!ft_strcmp(room->name, st->end)) {
                break;
            }
            if (edge->room->visit == 0) {
                add_to_path(&st, edge->room);
                edge->room->root = room;
            }
            edge = edge->next;
        }
    }
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

int main()
{
	t_lm st;
	
	ft_bzero(&st, sizeof(t_lm));
	parse(&st);
    valid(&st);
    connect(&st);
    findway(&st);
    output_ants(&st);

    return(0);
}
