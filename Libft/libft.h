/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 09:56:56 by ksainte           #+#    #+#             */
/*   Updated: 2024/06/03 16:18:47 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s
{
	int	len;
}		t_s;

size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isalnum(int c);
void				*ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strchr(const char *s, int c);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
int					ft_atoi(const char *str);
int					ft_isprint(int c);
int					ft_isascii(int c);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
int					ft_printf(const char *s, ...);
int					ft_write_str(char *str);
int					ft_len_print_nbr(int nbr);
int					ft_putchar(int c);
int					handle_ptr(unsigned long ptr, int c);
char				ft_hexadecimal(long int n, char c);
int					ft_putnbr_u(unsigned int n);
int					arg_search(va_list arg, char str, t_s *s);
int					text_read(t_s *s, char str);
int					ft_printf(const char *str, ...);

#endif
