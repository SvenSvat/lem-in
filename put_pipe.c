/*
** put_pipe.c for C in /home/delaco_c/rendu/CPE_2014_lemin
** 
** Made by Delacour Benjamin
** Login   <delaco_c@epitech.net>
** 
** Started on  Wed Apr 22 16:24:46 2015 Delacour Benjamin
** Last update Sun May  3 22:08:58 2015 Delacour Benjamin
*/

#include "includes.h"

int	room_exists(char *str, t_room *rooms)
{
  while (rooms)
    {
      if (!my_strcmp(str, rooms->name))
	return (1);
      rooms = rooms->next;
    }
  return (0);
}

int	is_pipe(char *str, t_room *rooms)
{
  int	i;

  i = 0;
  if (str[0] == '#' && my_strcmp(str, "##start") && my_strcmp(str, "##end"))
    return (2);
  while (str[i] && str[i] != '-')
    i++;
  if (str[i] == 0)
    return (0);
  str[i] = 0;
  if (room_exists(str, rooms) && room_exists(str + i + 1, rooms))
    return (1);
  return (0);
}

int	check_existing_pipe(t_pipe *pipe, t_room *rooms)
{
  while (pipe)
    {
      if (pipe->rooms == rooms)
	return (1);
      pipe = pipe->next;
    }
  return (0);
}

int		set_pipe(t_room *rooms, char *str)
{
  t_room	*buf;
  t_pipe	*pipe;

  buf = rooms;
  while (buf && my_strcmp(buf->name, str))
    buf = buf->next;
  while (rooms && my_strcmp(rooms->name, str + my_strlen(str) + 1))
    rooms = rooms->next;
  if (check_existing_pipe(buf->pipe, rooms) || buf == rooms)
    return (0);
  if ((pipe = malloc(sizeof(t_pipe))) == NULL)
    return (1);
  pipe->rooms = rooms;
  pipe->next = buf->pipe;
  buf->pipe = pipe;
  if ((pipe = malloc(sizeof(t_pipe))) == NULL)
    return (1);
  pipe->rooms = buf;
  pipe->next = rooms->pipe;
  rooms->pipe = pipe;
  return (0);
}

int		put_pipe(t_room *rooms, char *str)
{
  int		ret;
  t_room	*buf;

  buf = rooms;
  while (buf)
    {
      buf->pipe = NULL;
      buf = buf->next;
    }
  ret = is_pipe(str, rooms);
  if ((ret == 1 && set_pipe(rooms, str)) || ret == 0)
    return (1);
  free(str);
  while ((str = get_next_line(0)))
    {
      my_putstr(str);
      my_putchar('\n');
      if ((ret = is_pipe(str, rooms)) < 0)
	return (0);
      if ((ret == 1 && set_pipe(rooms, str)) || ret == 0)
	return (1);
      free(str);
    }
  return (0);
}
