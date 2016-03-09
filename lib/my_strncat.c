/*
** my_strncat.c for C in /home/delaco_c/rendu/Piscine_C_J07/ex_01
** 
** Made by benjamin delacour
** Login   <delaco_c@epitech.net>
** 
** Started on  Tue Oct  7 22:59:48 2014 benjamin delacour
** Last update Tue Oct  7 23:13:14 2014 benjamin delacour
*/

char	*my_strncat(char *dest, char *src, int nb)
{
  int	count_1;
  int	count_2;

  count_1 = 0;
  count_2 = 0;
  while (dest[count_1] != '\0')
    count_1++;
  while (count_2 < nb && src[count_2] != '\0')
    dest[count_1++] = src[count_2++];
  if (nb < 0)
    {
      count_2 = 0;
      while (src[count_2] != '\0')
	dest[count_1++] = src[count_2++];
    }
  dest[count_1] = '\0';
}
