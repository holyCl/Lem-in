#include "../inc/Lemin.h"

int main()
{
	t_lm st;
	
	ft_bzero(&st, sizeof(t_lm));
	parse(&st);
    valid(&st);
    connect(&st);
    findway(&st);
    output_ants(&st);
    system("leaks lem-in");

    return(0);
}
