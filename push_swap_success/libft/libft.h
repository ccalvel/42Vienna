/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <ccaldero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:35:46 by ccaldero          #+#    #+#             */
/*   Updated: 2023/05/26 17:04:18 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include<string.h>
# include<stdlib.h>
# include<unistd.h>
# include<stdarg.h>

int		ft_isalpha(int str);
int		ft_isdigit(int var);
int		ft_isalnum(int var);
int		ft_isascii(int var);
int		ft_isprint(int var);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *str, int var, size_t n);
void	ft_bzero(void *dst, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
int		ft_toupper(int var);
int		ft_tolower(int var);
char	*ft_strchr(const char *str, int var);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strrchr(const char *s, int var);
void	*ft_memchr(const void *str, int var, size_t count);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t num, size_t size);
char	*ft_itoa(int n);
char	*ft_strdup(const char *src);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_memcmp(const void *str1, const void *str2, size_t n);
void	*ft_memcpy(void *str1, const void *str2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);

//printf

int		ft_printf(const char *var, ...);
int		ft_putchar(char c);
int		ft_putstr(char const *str);
int		ft_putnbr(long long nb);
int		ft_dec_to_hex(unsigned int num);
int		ft_dec_to_hex_klein(unsigned int num);
int		ft_strlen_pf(int str);
int		ft_point_hex(unsigned long long int num);

#endif
