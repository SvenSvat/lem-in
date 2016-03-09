/*
** my_str_islower.c for C in /home/delaco_c/rendu/Piscine_C_J06/ex_12
** 
** Made by benjamin delacour
** Login   <delaco_c@epitech.net>
** 
** Started on  Mon Oct  6 16:28:42 2014 benjamin delacour
** Last update Mon Oct  6 16:37:11 2014 benjamin delacour
*/

int	my_str_isupper(char *str)
{
  int	count;

  count = 0;
  while (str[count] != '\0')
    if (str[count] < 65 || str[count++] > 90)
      return (0);
  return (1);
}
