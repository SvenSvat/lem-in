/*
** my_square_root.c for C in /home/delaco_c/rendu/Piscine_C_J05
** 
** Made by benjamin delacour
** Login   <delaco_c@epitech.net>
** 
** Started on  Mon Oct  6 10:03:59 2014 benjamin delacour
** Last update Tue Oct  7 22:18:33 2014 benjamin delacour
*/

int		my_square_root(int nb)
{
  double	d;
  int		i;

  d = 2.0;
  i = 0;
  if (nb < 0)
    d -= 1;
  else
    while (i++ <= 5)
      d += ((nb - d * d) / (2 * d));
  if ((int) d % 1 == 0)
    return (d);
  else
    return (0);
}
