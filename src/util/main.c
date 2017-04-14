/*
** main.c for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/tmp_work/gene
**
** Made by ovejer_n
** Login   <ovejer_n@epitech.net>
**
** Started on  Mon May 12 20:21:02 2014 ovejer_n
** Last update Tue Jun 10 06:52:03 2014 NicolasOVEJERO
*/

#include	"gene.h"

void		get_sigint(int __attribute__((__unused__)) sig)
{
  char		temp[256];

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
  utils->ret_exit = 0;
  if (my_env(utils, env) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (manage_myshrc(utils) == EXIT_FAILURE)
    {
      free_env(utils->env);
      return (EXIT_FAILURE);
    }
  signal(SIGINT, get_sigint);
  if (init_back(utils) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		main(int ac, char **av, char **env)
{
  t_gene	utils;

  if (ac != 1)
    {
      printf("Usage : %s\n", av[0]);
      return (1);
    }
  if (init_42sh(&utils, env) == EXIT_FAILURE)
    return (utils.ret_exit);
  my_pars(&utils);
  free_myshrc(&utils);
  return (utils.ret_exit);
}
