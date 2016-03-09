/*
** get_ants.c for lemin in /home/blanqu_a/Workspace/rendu/lemin
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Wed Apr 22 17:15:53 2015 Adrien Blanquer
** Last update Sun May  3 18:52:49 2015 Adrien Blanquer
*/

#include "includes.h"

int	check_first_line(char *str)
{
  int	i;

  i = 0;
  while (str[i] && str[i] != '\n')
    if (str[i++] == ' ')
      return (-1);
  return (0);
}

void		*create_t_ants(int nb_ants)
{
  int		i;
  t_ants	*ants;
  t_ants	*elem;

  i = 0;
  ants = NULL;
  if (nb_ants == 0)
    return (NULL);
  while (i < nb_ants)
   {
      if ((elem = malloc(sizeof(t_ants))) == NULL)
	return (NULL);
      elem->next = ants;
      elem->n = nb_ants - i;
      elem->room = NULL;
      elem->path = NULL;
      ants = elem;
      i++;
    }
  return (ants);
}

void		*get_ants(void)
{
  char		*line;
  int		nb;

  nb = 0;
  while ((line = get_next_line(0)))
    {
      my_putstr(line);
      my_putchar('\n');
      if (line[0] != '#')
	{
	  if (check_first_line(line) == -1)
	    return (NULL);
	  nb = my_getnbr(line);
	  break ;
	}
      free(line);
    }
  return (nb > 0 ? create_t_ants(nb) : NULL);
}
