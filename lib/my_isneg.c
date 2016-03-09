/*
** my_isneg.c for my_isneg in /home/delaco_c/rendu/Piscine_C_J03
** 
** Made by benjamin delacour
** Login   <delaco_c@epitech.net>
** 
** Started on  Wed Oct  1 09:55:44 2014 benjamin delacour
** Last update Wed Oct  1 15:58:01 2014 benjamin delacour
*/

int	my_isneg(int n)
{
  if (n < 0)
    my_putchar('N');
  else
    my_putchar('P');
  return (0);
}
