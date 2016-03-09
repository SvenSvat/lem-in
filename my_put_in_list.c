/*
** my_put_in_list.c for lemin in /home/blanqu_a/Workspace/rendu/lemin
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Thu Apr 23 14:14:48 2015 Adrien Blanquer
** Last update Sun May  3 21:41:30 2015 Adrien Blanquer
*/

#include "includes.h"

int	go_to_word(char *line, int pos)
{
  while (line[pos] && line[pos] == ' ')
    pos++;
  return (pos);
}

char		*extract(char *line)
{
  static int	i;
  static int	cpt;
  char		*tmp;
  int		j;

  j = 0;
  if (line[0] == '#')
    return (NULL);
  if ((tmp = malloc(sizeof(char) * (my_strlen(line) + 1))) == NULL)
    return (NULL);
  tmp[my_strlen(line)] = '\0';
  i = go_to_word(line, i);
  while (line[i] && line[i] != ' ')
    tmp[j++] = line[i++];
  tmp[j] = '\0';
  if (++cpt == 3)
    {
      cpt = 0;
      i = 0;
    }
  return (tmp);
}

int		existing(t_room *elem, t_room *rooms)
{
  t_room	*tmp;

  tmp = rooms;
  while (tmp)
    {
      if (my_strcmp(elem->name, tmp->name) == 0)
	return (1);
      if (elem->x == tmp->x && elem->y == tmp->y)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

int		my_put_in_list(t_room **rooms, char *line, t_room *check)
{
  t_room	*elem;
  t_room	*tmp_list;

  tmp_list = *rooms;
  if ((elem = malloc(sizeof(t_room))) == NULL)
    return (-1);
  if ((elem->name = extract(line)) == NULL)
    return (-1);
  elem->x = my_getnbr(extract(line));
  elem->y = my_getnbr(extract(line));
  if (existing(elem, check) == 1)
    return (my_put_sterror("Error: room already exist\n"));
  if (tmp_list != NULL)
    {
      while (tmp_list->next != NULL)
	tmp_list = tmp_list->next;
      tmp_list->next = elem;
      elem->next = NULL;
      return (0);
    }
  elem->next = *rooms;
  *rooms = elem;
  return (0);
}
