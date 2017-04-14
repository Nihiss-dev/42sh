/*
** my_cmd2.c for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/src/cmd_pars
** 
** Made by NicolasOVEJERO
** Login   <ovejer_n@epitech.net>
** 
** Started on  Wed Jun 11 11:52:05 2014 NicolasOVEJERO
** Last update Wed Jun 11 11:52:40 2014 NicolasOVEJERO
*/

#include "gene.h"

int	_my_open(char *file, int type, t_gene *utils)
{
  if (type == 2)
    return (my_open_d(utils, file));
  else if (type == 1)
    return (my_open_s(utils, file));
  return (5);
}

char	*bonjour(char *line, int type, t_gene *utils)
{
  int	i;

  i = -1;
  bzero(utils->pass, 0);
  while (line[++i] && (line[i] >= 'A' && line[i] <= 'z'))
    utils->pass[i] = line[i];
  utils->pass[i] = 0;
  if (_my_open(utils->pass, type, utils) != 0)
    return (NULL);
  while (line[i] && (line[i] < 'A' || line[i] > 'z'))
    i++;
  return (line + i);
}
