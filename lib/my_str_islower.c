/*
** my_str_islower.c for C in /home/delaco_c/rendu/Piscine_C_J06/ex_12
** 
** Made by benjamin delacour
** Login   <delaco_c@epitech.net>
** 
** Started on  Mon Oct  6 16:28:42 2014 benjamin delacour
** Last update Mon Oct  6 16:33:43 2014 benjamin delacour
*/

int	my_str_islower(char *str)
{
  int	count;

  count = 0;
  while (str[count] != '\0')
    if (str[count] < 97 || str[count++] > 122)
      return (0);
  return (1);
}
