/*
** main.c for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/tmp_work/gene
**
** Made by ovejer_n
** Login   <ovejer_n@epitech.net>
**
** Started on  Mon May 12 20:21:02 2014 ovejer_n
** Last update Tue Jun 10 20:26:48 2014 Alexis Feldmar
*/

#include "gene.h"

void	get_sigint(int __attribute__((__unused__)) sig)
{
  char	temp[256];

  getcwd(temp, sizeof(temp));
  write(1, "\n[42sh][", 8);
  my_putstr(temp);
  write(1, "]$ ", 3);
}

int		init_back(t_gene *utils)
{
  char		tmp[256];
  int		i;

  i = 0;
  if (getcwd(tmp, sizeof(tmp)) == NULL)
    return (EXIT_FAILURE);
  while (tmp[i])
    {
      utils->back[i] = tmp[i];
      ++i;
    }
  utils->back[i] = '\0';
  return (EXIT_SUCCESS);
}

int		init_42sh(t_gene *utils, char **env)
{
  char		tmp[256];

  TERM.back = 0;
  utils->ret_exit = 0;
  if (open_history(utils) == -1)
    return (-1);
  utils->hist.nb_cmd = 0;
  utils->hist.num_cmd = 0;
  utils->hist.path_hist = my_strcat_pers(getcwd(tmp, sizeof(tmp)),
					 "/", ".history");
  if (my_env(utils, env) == -1)
    return (-1);
  if (manage_myshrc(utils) == -1)
    {
      free_env(utils->env);
      return (-1);
    }
  signal(SIGINT, get_sigint);
  if (init_back(utils) == -1)
    return (-1);
  return (0);
}

int		main(int ac, char **av, char **env)
{
  t_gene	utils;

  if (ac != 1)
    {
      printf("Usage : %s\n", av[0]);
      return (1);
    }
  if (init_42sh(&utils, env) == -1)
    return (utils.ret_exit);
  if (init_termcaps(&utils) == -1)
    return (-1);
  my_pars(&utils);
  free_myshrc(&utils);
  return (utils.ret_exit);
}
