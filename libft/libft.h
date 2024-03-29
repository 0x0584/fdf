/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 17:32:57 by archid-           #+#    #+#             */
/*   Updated: 2019/08/06 21:21:44 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>

# define ABS(x)								((x) < 0 ? (x) * -1 : (x))
# define MAX(a, b)							((a) > (b) ? (a) : (b))
# define MIN(a, b)							((a) < (b) ? (a) : (b))
# define IN_RANGE(n, a, b)					(MIN(n, a) <= a && MAX(n, b) <= b)

# define ALLOC(type, n, sz)					((type)ft_memalloc((n) * (sz)))
# define SAFE_PTRVAL(ptr)					(ptr && *ptr)

# define ASSERT_RET(expr, ret)				if ((expr)) return (ret)
# define UNLESS_RET(expr, ret)				if (!(expr)) return (ret)

# define LST_NEXT(e)						e = e->next

# include "types.h"
# include "floats.h"

struct			s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
};

void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memalloc(size_t size);
void			*ft_dumb_realloc(void **ptr, size_t old, size_t new);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_memdel(void **mem);
void			ft_bzero(void *s, size_t n);

char			*ft_strnew(size_t size);
char			*ft_strdup(const char *str);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *dst, const char *src);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strncat(char *dst, const char *src, size_t len);
char			*ft_strstr(const char *s, const char *to_find);
char			*ft_strnstr(const char *s, const char *tofind, size_t len);
void			ft_strdel(char **s);
void			ft_strclr(char *s);
int				ft_strcmp(const char *s1, const char *s2);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t len);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
size_t			ft_strlcat(char *s1, const char *s2, size_t len);
char			**ft_strsplit(char const *s, char c);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
char			*ft_strjoin(char const *s1, char const *s2);
ssize_t			ft_strnprepend(char **dest, const char *prefix, size_t presz);
ssize_t			ft_strprepend(char **dest, const char *prefix);

int				ft_atoi(const char *s);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);

t_list			*ft_lstnew(void const *content, size_t content_size);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void(*del)(void*, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstiter_recu(t_list *lst, void (*f)(t_list *elem));
int				ft_lstadd(t_list **alst, t_list *new);
int				ft_lstpush(t_list **alst, t_list *e);
size_t			ft_lstlen(t_list *lst);
void			ft_lst_mergesort(t_plist *alst, int (cmp)(t_plist, t_plist));

t_list			*ft_lstpeek(t_list **alst);
t_list			*ft_lstpop(t_list **alst);

char			*ft_strrdup(const char *head, const char *tail);
void			*ft_memdup(const void *mem, size_t n);
t_int16			ft_wordcount(char const *s, char using);

int				ft_power(int x, int y);
int				ft_sqrt(int nb);

t_int8			ft_digitcount(int n);
int				ft_isspace(int c);
int				ft_isblank(int c);
int				ft_iscntrl(int c);
int				ft_swap(void *u, void *v, size_t size);

t_int64			ft_utf8tostr(t_int8 *dest, size_t destsz,
								const t_int32 *wsrc, size_t srcsz);
t_int8			ft_utf8tostr_ch(t_int8 *dest, t_int32 wch);

char			*ft_itoa(int n);
char			*ft_ftoa(float f, t_int8 precision);
char			*ft_ltoa_hex(long l);

int				ft_atoi_base(const char *nptr, const char *base);
char			*ft_strcdup(char *s, int c);

#endif
