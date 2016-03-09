/*
** my_swap.c for my_swap in /home/delaco_c/rendu/Piscine_C_J04
** 
** Made by benjamin delacour
** Login   <delaco_c@epitech.net>
** 
** Started on  Thu Oct  2 08:51:15 2014 benjamin delacour
** Last update Thu Oct  2 16:23:09 2014 benjamin delacour
*/

int	my_swap(int *a, int *b)
{
  int	swap;

  swap = *a;
  *a = *b;
  *b = swap;
  return (0);
}
