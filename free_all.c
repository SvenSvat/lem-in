/*
** free_all.c for lemin in /home/blanqu_a/Workspace/rendu/CPE_2014_lemin
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Fri May  1 17:58:47 2015 Adrien Blanquer
** Last update Sun May  3 19:19:00 2015 Delacour Benjamin
*/

#include "includes.h"

void		free_path(t_path *path)
{
  t_path	*tmp;

  tmp = path->next;
  while (path)
    {
      free(path);
      path = tmp;
      if (tmp)
	tmp = tmp->next;
    }
}

void		free_stock(t_stock *stock)
{
  t_stock	*next;

  while (stock)
    {
      next = stock->next;
      free_path(stock->path);
      free(stock);
      stock = next;
    }
}

void		free_pipes(t_pipe *pipes)
{
  t_pipe	*tmp;

  while (pipes)
    {
      tmp = pipes->next;
      free(pipes);
      pipes = tmp;
    }
}

void		free_all(t_stock *stock, t_room *rooms, t_temp *ptr)
{
  t_room	*tmp;

  free_stock(stock);
  while (rooms)
    {
      free(rooms->name);
      free_pipes(rooms->pipe);
      tmp = rooms->next;
      free(rooms);
      rooms = tmp;
    }
  free(ptr);
}
