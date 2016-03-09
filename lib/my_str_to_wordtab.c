/*
** my_str_to_wordtab.c for  in /home/delaco_c/rendu/Piscine_C_J08
** 
** Made by benjamin delacour
** Login   <delaco_c@epitech.net>
** 
** Started on  Wed Oct  8 18:50:47 2014 benjamin delacour
** Last update Fri Mar  6 16:14:35 2015 Delacour Benjamin
*/

#include <stdlib.h>
#include "../include/my.h"

int	my_is_print(char c)
{
  if (c > 33 && c < 127)
    return (1);
  return (0);
}

int	my_count_word(char *str)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  while (str[i])
    {
      while (str[i] && !my_is_print(str[i]))
	i++;
      if (str[i])
	{
	  while (my_is_print(str[i]))
	    i++;
	  n++;
	}
    }
  return (n);
}

int	my_fill_wordtab(char **wt, char *str)
{
  int	i;
  int	index;
  char	c;

  index = 0;
  while (*str)
    {
      while (*str && !my_is_print(*str))
	str++;
      if (*str)
	{
	  i = 0;
	  while (my_is_print(str[i]))
	    i++;
	  c = str[i];
	  str[i] = 0;
	  if ((wt[index++] = my_strdup(str)) == NULL)
	    return (1);
	  str[i] = c;
	  str += i;
	}
    }
  return (0);
}

char	**my_str_to_wordtab(char *str)
{
  char	**res;
  int	n;

  n = my_count_word(str);
  if ((res = malloc((n + 1) * sizeof(char *))) == NULL)
    return (NULL);
  res[n] = NULL;
  if (my_fill_wordtab(res, str))
    return (NULL);
  return (res);
}
