/*
** my_str_isprintable.c for C in /home/delaco_c/rendu/Piscine_C_J06/ex_14
** 
** Made by benjamin delacour
** Login   <delaco_c@epitech.net>
** 
** Started on  Mon Oct  6 16:39:18 2014 benjamin delacour
** Last update Wed Jan 14 18:59:23 2015 benjamin delacour
*/

int	my_str_isptrintable(char *str)
{
  int	count;

  count = 0;
  while (str[count] != '\0')
    if (str[count] < 32 || str[count++] > 126)
      return (0);
  return (1);
}
