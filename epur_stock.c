/*
** epur_stock.c for C in /home/delaco_c/rendu/CPE_2014_lemin
** 
** Made by Delacour Benjamin
** Login   <delaco_c@epitech.net>
** 
** Started on  Fri May  1 21:06:57 2015 Delacour Benjamin
** Last update Sat May  2 14:35:49 2015 Delacour Benjamin
*/

#include "includes.h"

void	remove_stock_elem(t_stock *tmp_stock, t_stock **tmp,
			  t_stock **stock)
{
  free_path((*tmp)->path);
  if (tmp_stock)
    {
      tmp_stock->next = (*tmp)->next;
      free(*tmp);
      *tmp = tmp_stock->next;
    }
  else
    {
      *stock = (*stock)->next;
      free(*tmp);
      *tmp = *stock;
    }
}

void		*epur_stock(t_stock *stock)
{
  t_stock	*tmp;
  t_stock	*tmp_stock;
  t_path	*tmp_path;

  tmp = stock;
  tmp_stock = NULL;
  while (tmp)
    {
      tmp_path = tmp->path;
      while (tmp_path->next)
	tmp_path = tmp_path->next;
      if (tmp_path->rooms->next)
	remove_stock_elem(tmp_stock, &tmp, &stock);
      else
	{
	  tmp_stock = tmp;
	  tmp = tmp->next;
	}
    }
  return (stock);
}

void	remove_useless_paths(t_stock *stock)
{
  t_stock	*tmp;
  t_stock	*riffle;
  t_stock	*prev;

  tmp = stock;
  while (tmp)
    {
      prev = tmp;
      riffle = tmp->next;
      while (riffle)
	{
	  if (riffle->path->next->rooms == tmp->path->next->rooms)
	    {
	      free_path(riffle->path);
	      prev->next = riffle->next;
	      free(riffle);
	      riffle = prev;
	    }
	  if (riffle != prev)
	    prev = prev->next;
	  riffle = riffle->next;
	}
      tmp = tmp->next;
    }
}
