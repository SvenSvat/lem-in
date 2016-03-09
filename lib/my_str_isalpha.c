/*
** my_str_isalpha.c for C in /home/delaco_c/rendu/Piscine_C_J06/ex_10
** 
** Made by benjamin delacour
** Login   <delaco_c@epitech.net>
** 
** Started on  Mon Oct  6 16:06:20 2014 benjamin delacour
** Last update Mon Oct  6 16:16:31 2014 benjamin delacour
*/

int	my_str_isalpha(char *str)
{
  int	count;

  count = 0;
  while (str[count] != '\0')
    {
      if (str[count] > 122 || str[count] < 97)
	if (str[count] > 90 || str[count] < 65)
	  return (0);
      count++;
    }
  return (1);
}
