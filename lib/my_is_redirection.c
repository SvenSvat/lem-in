/*
** my_is_redirection.c for C in /home/delaco_c/rendu/PSU_2014_minishell2/lib
** 
** Made by Delacour Benjamin
** Login   <delaco_c@epitech.net>
** 
** Started on  Tue Mar 10 15:24:37 2015 Delacour Benjamin
** Last update Fri Mar 13 17:36:23 2015 benjamin delacour
*/

#include "../include/my.h"

int	my_is_redirection(char *str)
{
  if (my_strcmp(str, "|") && my_strcmp(str, ">") &&
      my_strcmp(str, ">>") && my_strcmp(str, "<") &&
      my_strcmp(str, "<<") && my_strcmp(str, ">&"))
    return (0);
  return (1);
}
