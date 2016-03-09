/*
** my_strcpy.c for C in /home/delaco_c/rendu/Piscine_C_J06
** 
** Made by benjamin delacour
** Login   <delaco_c@epitech.net>
** 
** Started on  Mon Oct  6 10:15:37 2014 benjamin delacour
** Last update Mon Oct  6 11:29:17 2014 benjamin delacour
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	count;

  count = 0;
  if (n < 0)
    return (dest);
  while (count < n && src[count] != '\0')
    dest[count] = src[count++];
  if (src[n - 1] == '\0')
    dest[n - 1] = '\0';
  return (dest);
}
