/*
** my_put_nbr.c for my_put_nbr in /home/delaco_c/rendu
** 
** Made by benjamin delacour
** Login   <delaco_c@epitech.net>
** 
** Started on  Wed Oct  1 19:34:05 2014 benjamin delacour
** Last update Wed Oct  1 21:18:24 2014 benjamin delacour
*/

int	my_put_nbr(int nb)
{
  if (nb < 0)
    my_putchar('-');
  recursive(calc_pow(1, nb), nb);
  return (0);
}

int	recursive(int pow, int nb)
{
  if (pow >= 1)
    {
      if (nb >= 0)
	my_putchar((nb / pow) + '0');
      else
	my_putchar(((nb / pow) * -1) + '0');
      recursive(pow / 10, nb - ((nb / pow) * pow));
    }
  else
    return (0);
}

int	calc_pow(int pow, int nb)
{
  if (nb >= 10 || nb <= -10)
    calc_pow(pow * 10, nb / 10);
  else
    return (pow);
}
