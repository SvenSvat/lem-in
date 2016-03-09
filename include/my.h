/*
** my.h for H in /home/delaco_c/rendu/MUL_2014_fdf/include
** 
** Made by benjamin delacour
** Login   <delaco_c@epitech.net>
** 
** Started on  Sat Dec  6 20:21:18 2014 benjamin delacour
** Last update Wed Apr 29 13:39:28 2015 Adrien Blanquer
*/

#ifndef MY_H_
# define MY_H_

char	*my_strdup(char *);
char	*my_strcpy(char *, char *);
char	*my_strncpy(char *, char *, int);
char	*my_revstr(char *);
char	*my_strstr(char *, char *);
char	*my_strupcase(char *);
char	*my_strlowcase(char *);
char	*my_strcapitalize(char *);
char	**my_str_to_wordtab(char *);
char	*my_strcat(char *, char *);
char	*my_strncat(char *, char *, int);
char	*get_next_line(int);
void	my_putchar(char);
void	my_sort_int_tab(int *, int);
int	my_put_sterror(char *);
int	my_isneg(int);
int	my_put_nbr(int);
int	my_swap(int *, int *);
int	my_putstr(char *);
int	my_strlen(char *);
int	my_getnbr(char *);
int	my_power_rec(int, int);
int	my_square_root(int);
int	my_is_prime(int);
int	my_strcmp(char *, char *);
int	my_strncmp(char *, char *, int);
int	my_str_isalpha(char *);
int	my_str_isnum(char *);
int	my_str_islower(char *);
int	my_str_isupper(char *);
int	my_str_isprintable(char *);
int	my_showstr(char *);
int	my_str_has_char(char *);
int	my_is_redirection(char *);

#endif /* !MY_H */
