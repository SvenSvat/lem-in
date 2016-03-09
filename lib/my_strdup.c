/*
** my_strdup.c for C in /home/delaco_c/rendu/Piscine_C_J08/ex_01
** 
** Made by benjamin delacour
** Login   <delaco_c@epitech.net>
** 
** Started on  Wed Oct  8 10:45:51 2014 benjamin delacour
** Last update Sun Dec  7 04:58:37 2014 benjamin delacour
*/

#include <stdlib.h>

char	*my_strdup(char *src)
{
  char	*new_str;
  int	count;

  count = 0;
  while (src[count] != '\0')
    count++;
  if ((new_str = malloc(count + 1)) == NULL)
    return (NULL);
  count = 0;
  while (src[count] != '\0')
    new_str[count] = src[count++];
  new_str[count] = src[count];
  return (new_str);
}
