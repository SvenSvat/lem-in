/*
** ants_op.c for C in /home/delaco_c/rendu/CPE_2014_lemin
** 
** Made by Delacour Benjamin
** Login   <delaco_c@epitech.net>
** 
** Started on  Sun May  3 18:05:21 2015 Delacour Benjamin
** Last update Sun May  3 18:11:39 2015 Delacour Benjamin
*/

#include "includes.h"

int	is_path_free(t_ants *select, t_ants *ants, t_stock *stock)
{
  t_path	*tmp;

  while (select->path == NULL && ants && ants->path)
    {
      if (ants->room == stock->path->next->rooms)
	return (0);
      ants = ants->next;
    }
  if (select->path)
    {
      if (ants == select)
	return (1);
      tmp = select->path->path;
      while (tmp->rooms != select->room)
	tmp = tmp->next;
      while (ants && ants->path)
	{
	  if (ants->room == tmp->next->rooms)
	    return (0);
	  ants = ants->next;
	  if (ants == select)
	    return (1);
	}
    }
  return (1);
}

void	remove_ant(t_ants **tmp_ants, t_ants **ants, t_ants **prev)
{
  if (!(*prev))
    *ants = (*tmp_ants)->next;
  else
    (*prev)->next = (*tmp_ants)->next;
  free(*tmp_ants);
  *tmp_ants = *prev;
  if (*prev)
    {
      if (*prev == *ants)
	*prev = NULL;
      else
	{
	  *prev = *ants;
	  while ((*prev)->next != *tmp_ants)
	    *prev = (*prev)->next;
	}
    }
}

void	move_ant(t_stock *tmp_stock, t_ants *tmp_ants,
                 t_path **tmp_path, int *i)
{
  if (tmp_ants->path == NULL)
    tmp_ants->path = tmp_stock;
  if (tmp_ants->room == NULL)
    tmp_ants->room = tmp_stock->path->rooms;
  *tmp_path = tmp_ants->path->path;
  while ((*tmp_path)->rooms != tmp_ants->room)
    *tmp_path = (*tmp_path)->next;
  tmp_ants->room = (*tmp_path)->next->rooms;
  if ((*i)++ > 0)
    my_putchar(' ');
  my_putchar('P');
  my_put_nbr(tmp_ants->n);
  my_putchar('-');
  my_putstr(tmp_ants->room->name);
}

void	next_ant(t_ants **prev, t_ants **tmp_ants, int *i, t_ants *ants)
{
  *prev = *tmp_ants;
  if (*tmp_ants)
    *tmp_ants = (*tmp_ants)->next;
  else
    *tmp_ants = ants;
  if (!(*tmp_ants))
    {
      *i = 0;
      *prev = NULL;
      *tmp_ants = ants;
      my_putchar('\n');
    }
}

void		send_ants_to_path(t_ants *ants, t_stock *stock)
{
  t_stock	*tmp_stock;
  t_ants	*tmp_ants;
  t_ants	*prev;
  t_path	*tmp_path;
  int		i;

  prev = NULL;
  tmp_ants = ants;
  i = 0;
  while (tmp_ants)
    {
      tmp_stock = stock;
      while (tmp_stock && !is_path_free(tmp_ants, ants, tmp_stock))
	tmp_stock = tmp_stock->next;
      if (tmp_stock)
	{
	  move_ant(tmp_stock, tmp_ants, &tmp_path, &i);
	  if (!tmp_ants->room->next)
	    remove_ant(&tmp_ants, &ants, &prev);
	}
      next_ant(&prev, &tmp_ants, &i, ants);
    }
}
