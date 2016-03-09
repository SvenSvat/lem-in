/*
** main.c for lemin in /home/blanqu_a/Workspace/rendu/lemin
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Wed Apr 22 15:40:31 2015 Adrien Blanquer
** Last update Sun May  3 18:59:49 2015 Delacour Benjamin
*/

#include "includes.h"

int		main()
{
  t_stock	*stock;
  t_ants	*ants;
  t_room	*rooms;
  t_temp	*ptr;
  int		bin;

  bin = 0;
  if ((ants = get_ants()) == NULL)
    return (my_put_sterror("Ants number must be > 0\n"));
  if ((ptr = get_rooms(bin)) == NULL)
    return (-1);
  if (ptr->bin != 2)
    return (my_put_sterror("Error : No start or no end in file.\n"));
  rooms = ptr->room;
  if (put_pipe(rooms, ptr->first_tube))
    return (my_put_sterror("Error setting tubes\n"));
  if ((stock = get_stock(rooms)) == NULL)
    return (my_put_sterror("Error: list of paths failed\n"));
  send_ants(ants, stock);
  free_all(stock, rooms, ptr);
  return (0);
}
