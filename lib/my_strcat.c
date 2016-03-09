/*
** my_strcat.c for  in /home/delaco_c/rendu/Piscine_C_J07/ex_01
** 
** Made by benjamin delacour
** Login   <delaco_c@epitech.net>
** 
** Started on  Tue Oct  7 22:37:28 2014 benjamin delacour
** Last update Sun Dec  7 05:03:54 2014 benjamin delacour
*/

#include <stdlib.h>

char	*my_strcat(char *s1, char *s2)
{
  int	i;
  int	j;
  char	*res;

  i = 0;
  if ((res = malloc((my_strlen(s1) + my_strlen(s2) + 1)
                    * sizeof(char))) == NULL)
    return (NULL);
  while (s1[i])
    res[i] = s1[i++];
  j = 0;
  while (s2[j])
    res[i++] = s2[j++];
  res[i] = 0;
  return (res);
}
