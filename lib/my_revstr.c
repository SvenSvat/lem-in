/*
** my_revstr.c for C in /home/delaco_c/rendu/Piscine_C_J06/ex_03
** 
** Made by benjamin delacour
** Login   <delaco_c@epitech.net>
** 
** Started on  Mon Oct  6 11:37:55 2014 benjamin delacour
** Last update Mon Oct  6 11:52:24 2014 benjamin delacour
*/

char	*my_revstr(char *str)
{
  char	swap;
  int	end;
  int	count;

  count = 0;
  end = 0;
  while (str[end] != '\0')
    end++;
  end--;
  while (count < end)
    {
      swap = str[count];
      str[count++] = str[end];
      str[end--] = swap;
    }
  return (str);
}
