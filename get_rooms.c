/*
** get_rooms.c for lemin in /home/blanqu_a/Workspace/rendu/CPE_2014_lemin
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Tue Apr 28 16:38:40 2015 Adrien Blanquer
** Last update Sun May  3 21:15:22 2015 Adrien Blanquer
*/

#include <stdlib.h>
#include "includes.h"

void		*error_handling(char *line, t_room *rooms, t_room *end, int bin)
{
  t_room	*tmp;
  t_temp	*ptr;

  if ((ptr = malloc(sizeof(t_temp))) == NULL)
    return (NULL);
  if (rooms && check_entry(line) != 2)
    {
      tmp = rooms;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = end;
      ptr->room = rooms;
      ptr->first_tube = line;
      ptr->bin = bin;
      return (ptr);
    }
  return (NULL);
}

void	aff_line(char *line)
{
  if (line[0])
    {
      my_putstr(line);
      my_putchar('\n');
    }
}

char	*next_valid(char *line)
{
  while ((!line[0] && line[0] != '\n') || line[0] == '#')
    {
      if ((line = get_next_line(0)) == NULL)
	break;
    }
  if (line)
    aff_line(line);
  if (line && check_entry(line) == 2)
    return (line);
  return (NULL);
}

void		*add_end(char *line, int bin, t_room *rooms)
{
  t_room	*end;

  (void)bin;
  end = NULL;
  if ((line = next_valid(line)) != NULL)
    {
      if (check_entry(line) == 2)
	{
	  if (my_put_in_list(&end, line, rooms) != 0)
	    return (NULL);
	}
      else
	{
	  free(line);
	  my_put_sterror("Error : No end room\n");
	  return (NULL);
	}
    }
  else
    {
      free(line);
      my_put_sterror("Error : No end room\n");
      return (NULL);
    }
  return (end);
}

void		*get_rooms(int bin)
{
  t_room	*rooms;
  t_room	*end;
  t_temp	*ptr;
  char		*line;

  rooms = NULL;
  while ((line = get_next_line(0)))
    {
      aff_line(line);
      if (my_strcmp(line, "##start") == 0)
	if ((rooms = start(line, rooms, bin++)) == NULL)
	  return (NULL);
      if (my_strcmp(line, "##end") == 0)
	if ((end = add_end(line, bin++, rooms)) == NULL)
	  return (NULL);
      if (line[0] != '#' && line[0] != '\n' && line[0])
	{
	  if ((ptr = error_handling(line, rooms, end, bin)) != NULL)
	    return (ptr);
	  if (my_put_in_list(&rooms, line, rooms) != 0)
	    return (NULL);
	}
      free(line);
    }
  return (NULL);
}
