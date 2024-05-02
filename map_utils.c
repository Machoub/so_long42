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