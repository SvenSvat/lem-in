/*
** check_entry.c for lemin in /home/blanqu_a/Workspace/rendu/CPE_2014_lemin
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Sun May  3 14:02:51 2015 Adrien Blanquer
** Last update Sun May  3 14:28:57 2015 Adrien Blanquer
*/

#include "includes.h"

int	get_next_word(char *str, int pos)
{
  if (str[pos] && str[pos] != ' ' && str[pos] != '\t')
    return (pos);
  while (str[pos] && (str[pos] == ' ' || str[pos] == '\t'))
    pos++;
  return (pos);
}

int	is_end(char *str, int pos)
{
  while (str[pos])
    {
      if (str[pos] != '\0' && str[pos] != ' ' && str[pos] != '\t')
	return (1);
      pos++;
    }
  return (0);
}

int	check_entry(char *str)
{
  int	i;
  int	spaces;

  i = 0;
  i = get_next_word(str, 0);
  spaces = 0;
  while (str[i])
    {
      if (str[i] == ' ' && is_end(str, i) == 1)
	{
	  i = get_next_word(str, i);
	  spaces++;
	}
      else
	i++;
    }
  return (spaces);
}
