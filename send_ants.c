/*
** send_ants.c for send_ants in /home/dubosc_a/rendu/CPE_2014_lemin
** 
** Made by Valentin Duboscq
** Login   <dubosc_a@epitech.net>
** 
** Started on  Mon Apr 27 15:35:58 2015 Valentin Duboscq
** Last update Sun May  3 18:11:31 2015 Delacour Benjamin
*/

#include "includes.h"

int		nb_path_to_use(t_stock *stock, int nb_ants)
{
  int		res;
  int		nb;
  t_stock	*prev;
  t_stock	*tmp;

  prev = stock;
  tmp = stock->next;
  res = 0;
  nb = 1;
  while (tmp)
    {
      res += tmp->size - prev->size;
      if (res < nb_ants)
	{
          nb += 1;
	  prev = prev->next;
	  tmp = tmp->next;
	}
      else
	break;
    }
  return (nb);
}

int		send_ants(t_ants *ants, t_stock *stock)
{
  t_stock	*tmp;
  int		nb_ants;
  int		to_use;

  nb_ants = how_many_ants(ants);
  to_use = nb_path_to_use(stock, nb_ants);
  tmp = stock;
  while (to_use-- > 1)
    tmp = tmp->next;
  free_stock(tmp->next);
  tmp->next = NULL;
  send_ants_to_path(ants, stock);
  return (0);
}
