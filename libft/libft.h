/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:01:50 by tnanchen          #+#    #+#             */
/*   Updated: 2021/12/12 17:25:41 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* --------------------------------------------------------------- */
// Part 0 - Included libraries

# include <stdlib.h>	// FOR USAGE OF:	malloc() && size_t
# include <unistd.h>	// FOR USAGE OF:	write()
# include <stdarg.h>	// FOR USAGE OF:	var args ...

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define DEFAULT "\033[0m"

/* --------------------------------------------------------------- */
// Libc functions
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *s1);
void	*ft_calloc(size_t count, size_t size);

/* --------------------------------------------------------------- */
// Additional functions
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* --------------------------------------------------------------- */
// Personnal functions
char	*ft_itoa_base16(unsigned long int nbr);
void	*ft_malloc_ec(size_t size);
void	ft_free_arr(char **arr);

/* --------------------------------------------------------------- */
// GNL
char	*get_next_line(int fd);

/* --------------------------------------------------------------- */
// ft_printf
int		ft_printf(const char *placeholder, ...);
int		print_char(char c);
int		print_str(char *s);
int		print_int(long int nbr);
int		print_hexa(unsigned long int nbr, int c_case);
int		print_ptr(void *ptr);

#endif