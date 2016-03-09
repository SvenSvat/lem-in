/*
** my_strstr.c for C in /home/delaco_c/rendu/Piscine_C_J06/ex_04
** 
** Made by benjamin delacour
** Login   <delaco_c@epitech.net>
** 
** Started on  Mon Oct  6 11:53:01 2014 benjamin delacour
** Last update Mon Dec 15 15:15:14 2014 benjamin delacour
*/

char	*my_strstr(char *str, char *to_find)
{
  int	count_1;
  int	count_2;

  count_1 = 0;
  count_2 = 0;
  while (str[count_1] != '\0')
    {
      if (str[count_1] == to_find[count_2])
        {
          count_2++;
        }
      else
        {
          count_2 = 0;
        }
      if (to_find[count_2] == '\0')
        {
	  if (count_2 > 0)
	    count_1 = count_1 - (count_2 - 1);
          return (str + count_1);
        }
      count_1++;
    }
  return (0);
}
