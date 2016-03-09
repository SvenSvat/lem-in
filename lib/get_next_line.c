/*
** get_next_line.c for C in /home/delaco_c/rendu/PSU_2014_minishell2/lib
** 
** Made by Delacour Benjamin
** Login   <delaco_c@epitech.net>
** 
** Started on  Fri Mar  6 16:44:41 2015 Delacour Benjamin
** Last update Sun May  3 22:03:07 2015 Delacour Benjamin
*/

#include <stdlib.h>
#include <unistd.h>
#include "../include/my.h"

int	is_a_line_end(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '\n')
	return (i);
      i++;
    }
  return (i);
}

char	*retrieve_line(char **save, int i)
{
  char	*res;
  char	*tmp;
  char	repl;

  repl = (*save)[i];
  (*save)[i] = 0;
  if ((res = my_strdup(*save)) == NULL)
    return (NULL);
  if (repl == '\n')
    {
      if ((tmp = my_strdup(*save + i + 1)) == NULL)
	return (NULL);
      free(*save);
      *save = tmp;
    }
  else
    {
      free(*save);
      *save = NULL;
    }
  return (res);
}

char		*get_next_line(const int fd)
{
  char		buffer[4097];
  char		*tmp;
  static char	*save = NULL;
  int		ret;
  int		i;

  if (save == NULL)
    if ((save = my_strdup("\0")) == NULL)
      return (NULL);
  ret = 4096;
  while ((i = is_a_line_end(save)) == my_strlen(save) && ret == 4096)
    {
      if (((ret = read(fd, buffer, 4096)) <= 0 ||
	  (!(buffer[ret] = 0) && my_strlen(buffer) == 0)) && !my_strlen(save))
	{
	  free(save);
	  return (NULL);
	}
      buffer[ret] = 0;
      if ((tmp = my_strcat(save, buffer)) == NULL)
	return (NULL);
      free(save);
      save = tmp;
    }
  return (retrieve_line(&save, i));
}
