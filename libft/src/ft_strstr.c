#include "libft.h"

char    *ft_strstr(char *haystack, char *needle)
{
    int    haystack_len;
    int    needle_len;
    int    i;
    int    j;

    haystack_len = ft_strlen(haystack);
    needle_len = ft_strlen(needle);
    i = 0;
    while (i <= haystack_len - needle_len)
    {
        j = 0;
        while (j < needle_len)
        {
            if (haystack[i + j] != needle[j])
                break ;
            j++;
        }
        if (j == needle_len)
            return ((char *)&haystack[i]);
        i++;
    }
    return (NULL);
}