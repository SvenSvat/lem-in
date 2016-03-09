/*
** struct.h for H in /home/delaco_c/rendu/CPE_2014_lemin/include
** 
** Made by Delacour Benjamin
** Login   <delaco_c@epitech.net>
** 
** Started on  Tue Apr 21 17:26:22 2015 Delacour Benjamin
** Last update Sun May  3 18:21:45 2015 Adrien Blanquer
*/

#ifndef STRUCT_H_
# define STRUCT_H_

typedef struct		s_ants
{
  struct s_room		*room;
  int			n;
  struct s_stock	*path;
  struct s_ants		*next;
}			t_ants;

typedef struct          s_path
{
  struct s_room		*rooms;
  struct s_path		*next;
}                       t_path;

typedef struct          s_stock
{
  struct s_path		*path;
  int			size;
  struct s_stock	*next;
}                       t_stock;

typedef struct		s_pipe
{
  struct s_room		*rooms;
  struct s_pipe		*next;
}			t_pipe;

typedef struct		s_room
{
  char			*name;
  int			x;
  int			y;
  struct s_pipe		*pipe;
  struct s_room		*next;
}			t_room;

typedef struct	s_temp
{
  t_room	*room;
  char		*first_tube;
  int		bin;
}		t_temp;

#endif /* !STRUCT_H_ */
