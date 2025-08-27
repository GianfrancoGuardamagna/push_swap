#include "push_swap.h"

int error_checker(int argc, char** argv)
{
    int i;

    i = 0;
    if(argc != 2)
        return(0);
    while(argv[1][i])
    {
        if (ft_isspace(argv[1][i]) || ft_isdigit(argv[1][i]))
            i++;
        else
            return(0);
    }
    return(1);
}