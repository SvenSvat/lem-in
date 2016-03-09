/*
** my_strlen.c for my_strlen in /home/delaco_c/rendu/Piscine_C_J04
** 
** Made by benjamin delacour
** Login   <delaco_c@epitech.net>
** 
** Started on  Thu Oct  2 09:16:51 2014 benjamin delacour
** Last update Wed Jan 14 19:09:22 2015 benjamin delacour
*/

int	my_strlen(char *str)
{
  int	count_l;

  count_l = 0;
  while (str[count_l] != '\0')
    count_l++;
  return (count_l);
}
