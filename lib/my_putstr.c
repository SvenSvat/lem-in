/*
** my_putstr.c for my_putstr in /home/delaco_c/rendu/Piscine_C_J04
** 
** Made by benjamin delacour
** Login   <delaco_c@epitech.net>
** 
** Started on  Thu Oct  2 08:55:39 2014 benjamin delacour
** Last update Wed Jan 14 12:45:26 2015 benjamin delacour
*/

int	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
  return (0);
}

int	my_put_sterror(char *str)
{
  write(2, str, my_strlen(str));
  return (1);
}
