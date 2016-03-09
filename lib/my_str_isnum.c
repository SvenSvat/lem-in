/*
** my_str_isnum.c for C in /home/delaco_c/rendu/Piscine_C_J06/ex_11
** 
** Made by benjamin delacour
** Login   <delaco_c@epitech.net>
** 
** Started on  Mon Oct  6 16:18:43 2014 benjamin delacour
** Last update Wed Oct  8 16:54:14 2014 benjamin delacour
*/

int	my_str_isnum(char *str)
{
  int	count;

  count = 0;
  while (str[count] != '\0')
    if (str[count] < '0' || str[count++] > '9')
      return (0);
  return (1);
}
