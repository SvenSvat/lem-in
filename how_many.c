/*
** how_many.c for how_many in /home/dubosc_a/rendu/CPE_2014_lemin
** 
** Made by Valentin Duboscq
** Login   <dubosc_a@epitech.net>
** 
** Started on  Wed Apr 29 15:11:35 2015 Valentin Duboscq
** Last update Sat May  2 16:27:14 2015 Delacour Benjamin
*/

#include "includes.h"

int	how_many_ants(t_ants *ants)
{
  int	cpt;

  cpt = 0;
  while (ants != NULL)
    {
      cpt++;
      ants = ants->next;
    }
  return (cpt);
}

int		how_many_path(t_stock *stock)
{
  int		i;

  i = 0;
  while (stock != NULL)
    {
      stock = stock->next;
      i++;
    }
  return (i);
}

int		how_many_room(t_path *path)
{
  int		i;

  i = 0;
  while (path != NULL)
    {
      path = path->next;
      i++;
    }
  return (i);
}
