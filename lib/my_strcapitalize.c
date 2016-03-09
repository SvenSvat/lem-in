/*
** my_strcapitalize.c for C in /home/delaco_c/rendu/Piscine_C_J06/ex_09
** 
** Made by benjamin delacour
** Login   <delaco_c@epitech.net>
** 
** Started on  Mon Oct  6 15:27:30 2014 benjamin delacour
** Last update Mon Oct  6 16:05:08 2014 benjamin delacour
*/

char	*my_strcapitalize(char *str)
{
  int	count;
  int	n;

  count = 0;
  if (str[count] <= 122 && str[count] >= 97)
    str[count++] -= 32;
  while (str[count] != '\0')
    {
      if (str[count] == 32 || str[count] == '-' || str[count] == '+')
	{
	  if (str[++count] <= 122 && str[count] >= 97)
	    str[count] -= 32;
	}
      else
	if (str[count] <= 90 && str[count] >= 65)
	  str[count] += 32;
      count++;
    }
  return (str);
}
