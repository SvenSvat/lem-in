/*
** my_showstr.c for C in /home/delaco_c/rendu/Piscine_C_J06/ex_17
** 
** Made by benjamin delacour
** Login   <delaco_c@epitech.net>
** 
** Started on  Tue Oct  7 21:04:37 2014 benjamin delacour
** Last update Tue Oct  7 21:43:47 2014 benjamin delacour
*/

int	my_showstr(char *str)
{
  int	count;

  count = 0;
  while (str[count] != '\0')
    {
      if (str[count] < 32 || str[count] > 126)
	{
	  my_putchar(92);
	  my_conv_hexa(str[count], "0123456789abcdef");
	}
      else
	my_putchar(str[count]);
      count++;
    }
  return (0);
}

int	my_conv_hexa(int nb, char *str)
{
  my_putchar(str[(nb / 16) % 16]);
  my_putchar(str[nb % 16]);
}
