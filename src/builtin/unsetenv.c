/*
** unsetenv.c for 42sh in /home/chardo_j/exercices/backup_42sh
** 
** Made by Julien Chardon
** Login   <chardo_j@epitech.net>
** 
** Started on  Sun May 25 17:00:38 2014 Julien Chardon
** Last update Sun May 25 19:19:06 2014 Julien Chardon
*/

#include "gene.h"

static void	del_var_env(char *cmd, t_gene *utils, int *flag, int *i)
{
  int		len;

  *flag = 0;
  *i = 0;
  while (utils->env[*i] != NULL)
    {
      len = strlen(cmd);
      if (strncmp(utils->env[*i], cmd, strlen(cmd)) == 0 &&
	  (utils->env[*i][len] == '=' || utils->env[*i][len] == '\0'))
	{
	  *flag = 1;
	  free(utils->env[*i]);
	}
      if (*flag)
	utils->env[*i] = utils->env[*i + 1];
      ++(*i);
    }
}

int	my_unsetenv(char **cmd, t_gene *utils)
{
  char	**ptr_tmp;
  int	flag;
  int	i;

  if (cmd[1])
    {
      del_var_env(cmd[1], utils, &flag, &i);
      if (flag)
	{
	  if ((ptr_tmp = realloc(utils->env, sizeof(char *) * i)) == NULL)
	    return (-2);
	  utils->env = ptr_tmp;
	  utils->env[i] = NULL;
	}
    }
  return (0);
}
