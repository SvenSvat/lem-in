/*
** my_str_has_char.c for C in /home/delaco_c/rendu/PSU_2014_minishell2/lib
** 
** Made by Delacour Benjamin
** Login   <delaco_c@epitech.net>
** 
** Started on  Sat Mar  7 16:20:14 2015 Delacour Benjamin
** Last update Sat Mar  7 16:20:59 2015 Delacour Benjamin
*/

int	my_str_has_char(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    if (str[i++] != ' ')
      return (1);
  return (0);
}
