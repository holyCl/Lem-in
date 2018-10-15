#include "../inc/Lemin.h"

void error(int numb) {
    if (numb == 101)
        ft_printf("Incorrect number of ants");
    if (numb == 201)
        ft_printf("rooms has same names");
    if (numb == 202)
        ft_printf("rooms has same cords");
    if (numb == 301)
        ft_printf("finish allready exist");
    if (numb == 302)
        ft_printf("start allready exist");
    if (numb == 303)
        ft_printf("start does not exist");
    if (numb == 304)
        ft_printf("end does not exist");
    if (numb == 401)
        ft_printf("Connecting to non-existing room");
    if (numb == 501)
        ft_printf("Uncorrected room");
    if (numb == 502)
        ft_printf("Uncorrected link");
    if (numb == 603)
        ft_printf("Syntax Error");
    exit(1);
}