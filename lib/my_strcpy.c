/*
** my_strcpy.c for C in /home/delaco_c/rendu/Piscine_C_J06
** 
** Made by benjamin delacour
** Login   <delaco_c@epitech.net>
** 
** Started on  Mon Oct  6 10:15:37 2014 benjamin delacour
** Last update Mon Oct  6 11:21:38 2014 benjamin delacour
*/

char	*my_strcpy(char *dest, char *src)
{
  int	count;

  count = 0;
  while (src[count] != '\0')
    dest[count] = src[count++];
  dest[count] = '\0';
  return (dest);
}
