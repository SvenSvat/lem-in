/*
** my_power_rec.c for C in /home/delaco_c/rendu/Piscine_C_J05
** 
** Made by benjamin delacour
** Login   <delaco_c@epitech.net>
** 
** Started on  Fri Oct  3 10:38:07 2014 benjamin delacour
** Last update Mon Oct  6 19:58:37 2014 benjamin delacour
*/

int	my_power_rec(int nb, int power)
{
  return (recur_pow(nb, power, nb, nb));
}

int	recur_pow(int nb, int power, int base_nb, int save_nb)
{
  if (nb != save_nb && nb / base_nb != save_nb)
    return (0);
  if (power == 0)
    return (1);
  if (power < 0 || nb == 0)
    return (0);
  if (power <= 1)
    return (nb);
  recur_pow(nb * base_nb, power - 1, base_nb, nb);
}
