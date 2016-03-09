/*
** my_sort_int_tab.c for my_sort_int_tab in /home/delaco_c/rendu/Piscine_C_J04
** 
** Made by benjamin delacour
** Login   <delaco_c@epitech.net>
** 
** Started on  Thu Oct  2 15:24:56 2014 benjamin delacour
** Last update Thu Oct  2 16:22:40 2014 benjamin delacour
*/

void	my_sort_int_tab(int *tab, int size)
{
  int	index;
  int	count;
  int	swap;

  index = 0;
  count = index + 1;
  while (index < size)
    {
      while (count < size)
	{
	  if (tab[count] < tab[index])
	    {
	      swap = tab[index];
	      tab[index] = tab[count];
	      tab[count] = swap;
	    }
	  count++;
	}
      index++;
      count = index + 1;
    }
}
