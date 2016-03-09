/*
** get_stock.c for lemin in /home/blanqu_a/Workspace/rendu/CPE_2014_lemin
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Thu Apr 30 12:02:49 2015 Adrien Blanquer
** Last update Sat May  2 14:37:15 2015 Delacour Benjamin
*/

#include "includes.h"

int	check_path(t_path *path, t_room *rooms, t_pipe *pipe)
{
  while (path && path->rooms != rooms)
    {
      if (path->rooms == pipe->rooms)
	return (0);
      path = path->next;
    }
  return (1);
}

void	*get_next_room(t_room *rooms, t_path *path)
{
  t_pipe	*pipe;
  t_path	*buf;

  buf = path;
  pipe = rooms->pipe;
  while (buf && buf->rooms != rooms)
    buf = buf->next;
  while (buf->next && pipe && pipe->rooms != buf->next->rooms)
    pipe = pipe->next;
  if (buf->next && pipe)
    pipe = pipe->next;
  while (pipe)
    {
      if (check_path(path, rooms, pipe))
      	return (pipe->rooms);
      pipe = pipe->next;
    }
  return (NULL);
}

int		next_path(t_path *path, t_room *next_room,
			  t_path **tmp)
{
  t_path	*elem;

  if ((elem = malloc(sizeof(t_path))) == NULL)
    return (1);
  *tmp = path;
  elem->rooms = next_room;
  elem->next = NULL;
  while ((*tmp)->next)
    *tmp = (*tmp)->next;
  (*tmp)->next = elem;
  return (0);
}

int		get_path(t_stock **stock, t_room *rooms, t_path *path)
{
  t_path	*tmp;
  t_path	*elem;
  t_room	*next_room;

  if (rooms && rooms->next && (next_room = get_next_room(rooms, path)))
    {
      if ((elem = malloc(sizeof(t_path))) == NULL)
	return (1);
      tmp = path;
      elem->rooms = next_room;
      elem->next = NULL;
      while (tmp->next)
	tmp = tmp->next;
      tmp->next = elem;
      if (get_path(stock, next_room, path))
      	return (1);
      while ((next_room = get_next_room(rooms, path)))
	{
	  if ((path = duplicate(path, stock, rooms)) == NULL ||
	      next_path(path, next_room, &tmp) ||
	      get_path(stock, next_room, path))
	    return (1);
	}
    }
  return (0);
}

void		*get_stock(t_room *rooms)
{
  t_stock	*stock;
  t_stock	*buf;

  if ((stock = malloc(sizeof(t_stock))) == NULL)
    return (NULL);
  if ((stock->path = malloc(sizeof(t_path))) == NULL)
    return (NULL);
  stock->path->rooms = rooms;
  stock->path->next = NULL;
  stock->next = NULL;
  my_put_sterror("Loading");
  if (get_path(&stock, rooms, stock->path))
    return (NULL);
  buf = stock;
  while (buf->next)
    buf = buf->next;
  sort(&stock, buf);
  my_put_sterror("\r          \r");
  stock = epur_stock(stock);
  remove_useless_paths(stock);
  return (stock);
}
