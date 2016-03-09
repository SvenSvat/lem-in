/*
** my_strncmp.c for C in /home/delaco_c/rendu/Piscine_C_J06/ex_06
** 
** Made by benjamin delacour
** Login   <delaco_c@epitech.net>
** 
** Started on  Mon Oct  6 14:42:51 2014 benjamin delacour
** Last update Mon Oct  6 22:28:50 2014 benjamin delacour
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	count;

  count = 0;
  while (count < (n - 1) && s1[count] != '\0' && s2[count] != '\0')
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
