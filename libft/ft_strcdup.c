#include "libft.h"

char    *ft_strcdup(char *s, int c)
{
    size_t        i;
    char        *ret;

    i = 0;
    if (s == NULL)
        return (NULL);
    while (s[i] != (char)c && s[i])
        i++;
    ret = ft_strnew(i);
    ret = ft_strncpy(ret, s, i);
    return (ret);
}
