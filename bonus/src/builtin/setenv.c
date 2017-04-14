/*
** setenv.c for 42sh in /home/chardo_j/exercices/backup_42sh
** 
** Made by Julien Chardon
** Login   <chardo_j@epitech.net>
** 
** Started on  Sun May 25 16:59:45 2014 Julien Chardon
** Last update Tue Jun 10 05:34:02 2014 NicolasOVEJERO
*/

#include "gene.h"

static int	search_equ(char *cmd)
{
  int		i;

  i = -1;
  while (cmd[++i])
    if (cmd[i] == '=')
      return (1);
  return (0);
}

static void	set_var(char *cmd, t_gene *utils, int i, int j)
{
  if (utils->env[i])
    {
      if (cmd[j - 1] == '=')
	utils->env[i] = cmd;
      else
	utils->env[i] = my_strcat_pers(cmd, "=", "\0");
    }
  else
    {
      if (search_equ(cmd))
	utils->env[i] = strdup(cmd);
      else
	utils->env[i] = my_strcat_pers(cmd, "=", "\0");
    }
}

static int	search_var(char **cmd, t_gene *utils, int i, int *j)
{
  char		*name;
  int		len;

  if ((name = get_ea_name(cmd[1], j)) == NULL)
    return (-2);
  len = strlen(name);
  if (strncmp(utils->env[i], name, len) == 0 &&
      utils->env[i][len] == '=')
    {
      free(name);
      free(utils->env[i]);
      set_var(cmd[1], utils, i, *j);
      return (1);
    }
  return (0);
}

static int	new_var(char **cmd, t_gene *utils, int i, int j)
{
  char		**ptr_tmp;

  if ((ptr_tmp = realloc(utils->env, sizeof(char *) * (i + 2))) == NULL)
    return (-2);
  utils->env = ptr_tmp;
  set_var(cmd[1], utils, i, j);
  utils->env[i + 1] = NULL;
  return (0);
}

int	my_setenv(char **cmd, t_gene *utils)
{
  int	ret;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (cmd[1] && nb_car_spe(cmd[1], '|') == 0 && nb_car_spe(cmd[1], '<') == 0
      && nb_car_spe(cmd[1], '>') == 0)
    {
      while (utils->env[i])
	{
	  if ((ret = search_var(cmd, utils, i, &j)) == -2)
	    return (-2);
	  else if (ret == 1)
	    return (0);
	  ++i;
	}
      if (new_var(cmd, utils, i, j) == -2)
	return (-2);
      return (0);
    }
  return (-1);
}
