/*
** my_show_wordtab.c for C in /home/delaco_c/rendu/Piscine_C_J08/ex_05
** 
** Made by benjamin delacour
** Login   <delaco_c@epitech.net>
** 
** Started on  Wed Oct  8 21:20:29 2014 benjamin delacour
** Last update Fri Oct 24 12:42:28 2014 benjamin delacour
*/

int	my_show_wordtab(char **tab)
{
  int	count;

  count = 0;
  while (tab[count])
    {
      my_putstr(tab[count++]);
      my_putchar('\n');
    }
}
