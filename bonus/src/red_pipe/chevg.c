/*
** chevg.c for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/src
** 
** Made by NicolasOVEJERO
** Login   <ovejer_n@epitech.net>
** 
** Started on  Sat Jun  7 14:33:40 2014 NicolasOVEJERO
** Last update Tue Jun 10 06:56:53 2014 NicolasOVEJERO
*/

#include "gene.h"

int		start_chev(char *cmd, t_gene *utils, int red)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  bzero(utils->pass, 256);
  while (cmd[++i] <= ' ');
  while (cmd[i] > ' ')
    utils->pass[j++] = cmd[i++];
  utils->pass[j] = 0;
  while (cmd[++i] <= ' ');
  if (my_open_ronly(utils, utils->pass))
    return (-1);
  dup2(utils->old_fd, 0);
  if (red == 1)
    return (check_cmd(my_str_to_wordtab(epure_end(cmd + i, strlen(cmd + i)),
					' '), utils));
  else
    utils->chev = strdup(cmd + i);
  return (0);
}

int		chevg_base(char **chev_g, t_gene *utils)
{
  int		i;
  int		ret;

  i = 0;
  while (chev_g[++i])
    if (my_open_ronly(utils, chev_g[i]))
      return (-1);
  ret = my_exec_chev_input(utils, chev_g[0]);
  return (ret);
}

int		chevg_pipe(char **chev_g, t_gene *utils)
{
  int		i;
  int		ret;

  i = 0;
  if (chev_g != NULL)
    {
      while (chev_g[++i])
        if (my_open_ronly(utils, chev_g[i]))
          return (-1);
      dup2(utils->old_fd, 0);
      ret = exec_pipe(my_str_to_wordtab(epure_end(chev_g[0],
						  strlen(chev_g[0])), ' '),
		      utils);
    }
  else
    return (-2);
  my_free_dtab(chev_g);
  return (ret);
}

int		pars_chevg_pipe(char *cmd_line, t_gene *utils)
{
  t_chev	chev;
  char		**tab;

  utils->pipe.save = 0;
  chev.pos = 0;
  if ((tab = my_str_to_wordtab(cmd_line, '|')) == NULL)
    return (-2);
  chev.i = -1;
  while (tab[++chev.i + 1])
    if (nb_car_spe(tab[chev.i], '<') != 0)
      {
	if (chevg_pipe(my_str_to_wordtab(tab[chev.i], '<'), utils) != 0)
	  return (-1);
	chev.pos = chev.i;
      }
    else if (tab[chev.i])
      if (exec_pipe(my_str_to_wordtab(epure_end(tab[chev.i],
						strlen(tab[chev.i])), ' '),
		    utils) == -1)
	return (-1);
  if (check_chev_end(utils, tab[chev.i]) != 0)
    return (-1);
  my_free_dtab(tab);
  return (0);
}
