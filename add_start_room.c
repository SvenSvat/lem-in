/*
** add_start_room.c for lemin in /home/blanqu_a/Workspace/rendu/CPE_2014_lemin
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Sun May  3 13:57:49 2015 Adrien Blanquer
** Last update Sun May  3 21:13:46 2015 Adrien Blanquer
*/

#include "includes.h"

void		*add_start(char *line, t_room *rooms)
{
  t_room	*start;

  start = NULL;
  if (check_entry(line) == 2)
    {
      if (my_put_in_list(&start, line, rooms) != 0)
	return (NULL);
    }
  else
    return (NULL);
  start->next = rooms;
  rooms = start;
  return (rooms);
}

void		*start(char *line, t_room *rooms, int bin)
{
  (void)bin;
  if ((line = next_valid(line)) != NULL)
    {
      if ((rooms = add_start(line, rooms)) == NULL)
	{
	  my_put_sterror("Error : No valid start room.\n");
	  return (NULL);
	};
    }
  else
    {
      my_put_sterror("Error : No start room.\n");
      return (NULL);
    }
  return (rooms);
}

