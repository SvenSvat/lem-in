/*
** path_duplicate.c for C in /home/delaco_c/rendu/CPE_2014_lemin
** 
** Made by Delacour Benjamin
** Login   <delaco_c@epitech.net>
** 
** Started on  Fri May  1 21:21:08 2015 Delacour Benjamin
** Last update Sun May  3 14:52:05 2015 Delacour Benjamin
*/

#include "includes.h"

int		add_elem_to_path(t_path **tmp, t_path *path, t_path **buf)
{
  t_path	*elem;

  if (*tmp == NULL)
    {
      if ((*tmp = malloc(sizeof(t_path))) == NULL)
	return (1);
      (*tmp)->rooms = path->rooms;
      (*tmp)->next = NULL;
      *buf = *tmp;
    }
  else
    {
      if ((elem = malloc(sizeof(t_path))) == NULL)
	return (1);
      elem->rooms = path->rooms;
      (*buf)->next = elem;
      elem->next = NULL;
      *buf = elem;
    }
  return (0);
}

static void	print_status()
{
  static int	i = 0;

  if (i % 1000 == 0 && i < 3000)
    my_put_sterror(".");
  i++;
  if (i == 3001)
    {
      my_put_sterror("\b\b\b   \b\b\b");
      i = 0;
    }
}

int		copy_path(t_path *path, t_path **tmp, t_room *stop)
{
  t_path	*buf;

  while (path)
    {
      if (add_elem_to_path(tmp, path, &buf))
	return (1);
      if (path->rooms == stop)
	path = NULL;
      else
	path = path->next;
    }
  return (0);
}

void		*duplicate(t_path *path, t_stock **stock, t_room *stop)
{
  t_path	*tmp;
  t_stock	*stock_tmp;
  t_stock	*stock_buf;

  tmp = NULL;
  if (copy_path(path, &tmp, stop))
    return (NULL);
  if ((stock_tmp = malloc(sizeof(t_stock))) == NULL)
    return (NULL);
  stock_tmp->path = tmp;
  stock_tmp->next = NULL;
  stock_buf = *stock;
  while (stock_buf->next)
    stock_buf = stock_buf->next;
  sort(stock, stock_buf);
  while (stock_buf->next)
    stock_buf = stock_buf->next;
  stock_buf->next = stock_tmp;
  print_status();
  return (tmp);
}
