/*
** my_isprime.c for C in /home/delaco_c/rendu/Piscine_C_J05
** 
** Made by benjamin delacour
** Login   <delaco_c@epitech.net>
** 
** Started on  Mon Oct  6 23:28:34 2014 benjamin delacour
** Last update Mon Oct 20 10:06:42 2014 benjamin delacour
*/

int		my_sqrt(int a)
{
  double	d;
  int		i;

  d = 2.0;
  i = 0;
  if (a < 0)
    d -= 1;
  else
    while (i++ <= 5)
      d += ((a - d * d) / (2 * d));
  return (d);
}

int	my_is_prime(int nb)
{
  int	i;
  int	nb2;

  if (nb == 0 || nb == 1 || nb < 0)
    return (0);
  i = 2;
  nb2 = my_sqrt(nb);
  while (i < nb2)
    if (nb % i++ == 0)
      return (0);
  return (1);
}
