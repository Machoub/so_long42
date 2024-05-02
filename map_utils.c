#include "so_long.h"

int open_file(char *path)
{
    int fd;

    fd = open(path, O_RDONLY)
    if (fd < 0)
    {
        ft_printf("Error fd\n");
        exit(1);
    }
    return (fd);
}

t_counter   new_counter(void)
{
    t_counter   counter;

    counter.empty = 0;
    counter.collect = 0;
    counter.exit = 0;
    counter.movements = 0;
    counter.start = 0;
    return (counter);
}