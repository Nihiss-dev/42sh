/*
** util.c for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/tmp_work/gene
**
** Made by ovejer_n
** Login   <ovejer_n@epitech.net>
**
** Started on  Thu May 15 13:56:31 2014 ovejer_n
** Last update Tue Jun 10 06:44:19 2014 NicolasOVEJERO
*/

#include "gene.h"

char	*epure_end(char *line, int len)
{
  while (line[len] <= 32)
    --len;
  line[++len] = 0;
  return (line);
}

int	nb_car_spe(char *line, char c)
{
  int	nb;
  int	i;

  nb = 0;
  i = -1;
  while (line[++i])
    if (line[i] == c)
      ++nb;
  return (nb);
}

int	nb_dcar(char *line, char c)
{
  int	nb;
  int	i;

  nb = 0;
  i = -1;
  while (line[++i])
    if (line[i] == c && line[i + 1] == c)
      {
        ++nb;
        ++i;
      }
  return (nb);
}

int     pars_cd(char *pc, t_gene *utils)
{
  char  **lo;
  int	ret;

  ret = 1;
  if (nb_car_spe(epure_end(pc, strlen(pc)), '|') == 0)
    {
      lo = my_str_to_wordtab(pc, ' ');
      if (strcmp(lo[0], "cd") == 0)
	ret = cd_fct(lo, utils);
      else if (strcmp(lo[0], "setenv") == 0)
	ret = my_setenv(lo, utils);
      else if (strcmp(lo[0], "unsetenv") == 0)
	ret = my_unsetenv(lo, utils);
      my_free_dtab(lo);
    }
  return (ret);
}
