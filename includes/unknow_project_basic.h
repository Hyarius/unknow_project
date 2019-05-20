#ifndef UNKNOW_PROJECT_BASIC_H
# define UNKNOW_PROJECT_BASIC_H

char			*ft_strnew(int size);
int				ft_strlen(char *str);
char			*ft_strdup(char *src);
char			*ft_strjoin(char *src1, char *src2);
void			ft_stradd(char **src1, char *src2);
void 			ft_putchar(char c);
void 			ft_putstr(char *str);
void 			ft_putnbr(int n);
char			*ft_strcut(char **src, char delim);
int				ft_strchr(char *src, char d);
int				get_next_line(const int fd, char **line);
void 			error_exit(int error, char *message);
void			ft_bzero(void *src, size_t nb_bytes);

#endif
