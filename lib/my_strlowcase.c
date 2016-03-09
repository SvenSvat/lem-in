/*
** my_strupcase.c for C in /home/delaco_c/rendu/Piscine_C_J06/ex_07
** 
** Made by benjamin delacour
** Login   <delaco_c@epitech.net>
** 
** Started on  Mon Oct  6 15:02:07 2014 benjamin delacour
** Last update Mon Oct  6 15:29:23 2014 benjamin delacour
*/

char	*my_strlowcase(char *str)
{
  int	count;

  count = 0;
  while (str[count] != '\0')
    {
      if (str[count] <= 90 && str[count] >= 65)
	str[count] += 32;
      count++;
    }
  return (str);
}
