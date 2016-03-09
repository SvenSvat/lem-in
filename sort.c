/*
** sort.c for lemin in /home/blanqu_a/Workspace/rendu/CPE_2014_lemin
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Fri May  1 18:40:04 2015 Adrien Blanquer
** Last update Sun May  3 14:45:24 2015 Delacour Benjamin
*/

#include "includes.h"

int	path_len(t_path *path)
{
  int	i;

  i = 0;
  while (path)
    {
      path = path->next;
      i++;
    }
  return (i);
}

void		sort(t_stock **stock, t_stock *to_sort)
{
  t_stock	*tmp;
  t_stock	*prev;
  t_stock	*to_s_prev;

  to_sort->size = path_len(to_sort->path);
  to_s_prev = *stock;
  while (to_s_prev != to_sort && to_s_prev->next != to_sort)
    to_s_prev = to_s_prev->next;
  tmp = *stock;
  prev = NULL;
  while (tmp && to_sort->next == NULL)
    {
      if (tmp->size > to_sort->size)
	{
	  to_s_prev->next = to_sort->next;
	  to_sort->next = tmp;
	  if (prev)
	    prev->next = to_sort;
	  else
	    *stock = to_sort;
	}
      prev = tmp;
      tmp = tmp->next;
    }
}
