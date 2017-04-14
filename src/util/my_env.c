/*
** my_env.c for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/tmp_work/gene
**
** Made by ovejer_n
** Login   <ovejer_n@epitech.net>
**
** Started on  Mon May 12 21:14:52 2014 ovejer_n
** Last update Thu Jun  5 15:56:17 2014 NicolasOVEJERO
*/

#include "gene.h"

int	my_env(t_gene *utils, char **env)
{
  int	len;
  int	i;

  len = 0;
  while (env[len] != NULL)
    ++len;
  if ((utils->env = malloc(sizeof(char *) * (len + 1))) == NULL)
    return (EXIT_FAILURE);
  i = 0;
  while (i < len)
    {
      if ((utils->env[i] = strdup(env[i])) == NULL)
	return (EXIT_FAILURE);
      ++i;
    }
  utils->env[i] = NULL;
  return (EXIT_SUCCESS);
}

void	free_env(char **env)
{
  int	i;

  i = -1;
  while (env[++i] != NULL)
    free(env[i]);
  free(env);
}
