/*
** my_getnbr.c for C in /home/delaco_c/rendu/PSU_2014_minishell2/lib
** 
** Made by Delacour Benjamin
** Login   <delaco_c@epitech.net>
** 
** Started on  Fri Mar  6 16:45:45 2015 Delacour Benjamin
** Last update Fri Mar  6 16:45:46 2015 Delacour Benjamin
*/

int	my_getnbr(char *str)
{
  int	index;
  int	nbr;
  int	neg;
  int	verif;

  nbr = 0;
  index = 0;
  neg = 0;
  while (str[index] != '\0')
    {
      if (nbr == 0)
	verif = stat_0(&str[0], &index, &nbr, &neg);
      else
	verif = stat_1(&str[0], &index, &nbr, &neg);
      if (verif == 1)
	return (nbr);
      if (verif == 2)
	return (0);
    }
  if (neg % 2 == 1)
    return (-nbr);
  return (nbr);
}

int	stat_0(char *str, int *index, int *nbr, int *neg)
{
  if (str[*index] <= 57 && str[*index] >= 48)
    *nbr = (*nbr * 10) + str[*index] - '0';
  else
    if (str[*index] == 45)
      *neg = *neg + 1;
    else
      if (str[*index] == 43);
      else
	return (1);
  *index = *index + 1;
  return (0);
}

int	stat_1(char *str, int *index, int *nbr, int *neg)
{
  int	save_nb;

  if (*neg % 2 == 1)
    {
      *nbr *= -1;
      *neg = 0;
    }
  save_nb = *nbr;
  if (str[*index] <= 57 && str[*index] >= 48)
    {
      if (*nbr > 0)
	*nbr = (*nbr * 10) + str[*index] - '0';
      else
	*nbr = (*nbr * 10) - (str[*index] - '0');
      *index = *index + 1;
      if (*nbr / 10 != save_nb)
	return (2);
    }
  else
    return (1);
  return (0);
}
