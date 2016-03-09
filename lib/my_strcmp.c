/*
** my_strcmp.c for C in /home/delaco_c/rendu/Piscine_C_J06/ex_04
** 
** Made by benjamin delacour
** Login   <delaco_c@epitech.net>
** 
** Started on  Mon Oct  6 13:57:29 2014 benjamin delacour
** Last update Mon Oct  6 14:36:57 2014 benjamin delacour
*/

int	my_strcmp(char *s1, char *s2)
{
  int	count;

  count = 0;
  while (s1[count] != '\0')
    {
      if (s1[count] < s2[count])
	return (-1);
      if (s2[count] < s1[count])
	return (1);
      count++;
    }
  if (s1[count] < s2[count])
    return (-1);
  if (s2[count] < s1[count])
    return (1);
  return (0);
}
