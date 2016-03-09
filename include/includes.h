/*
** includes.h for H in /home/delaco_c/rendu/CPE_2014_lemin
** 
** Made by Delacour Benjamin
** Login   <delaco_c@epitech.net>
** 
** Started on  Sun May  3 18:22:52 2015 Delacour Benjamin
** Last update Sun May  3 21:14:25 2015 Adrien Blanquer
*/

#ifndef INCLUDES_H_
# define INCLUDES_H_

# include <stdlib.h>
# include "my.h"
# include "struct.h"

int	how_many_ants(t_ants *);
int	how_many_path(t_stock *);
int	put_pipe(t_room *, char *);
int	send_ants(t_ants *, t_stock *);
int	my_put_in_list(t_room **, char *, t_room*);
int	check_entry(char *);
void	*get_ants(void);
void	*get_rooms(int);
void	*get_stock(t_room *);
void	*epur_stock(t_stock *);
void	*duplicate(t_path *, t_stock **, t_room *);
void	*start(char *, t_room *, int);
void	free_path(t_path *);
void	free_stock(t_stock *);
void	free_all(t_stock *, t_room *, t_temp *);
void	sort(t_stock **, t_stock *);
void	remove_useless_paths(t_stock *);
char	*next_valid(char *);
void	send_ants_to_path(t_ants *, t_stock *);

#endif /* !INCLUDES_H_ */
