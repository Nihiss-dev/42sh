/*
** util2.c for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/src
** 
** Made by NicolasOVEJERO
** Login   <ovejer_n@epitech.net>
** 
** Started on  Sun May 25 15:30:38 2014 NicolasOVEJERO
** Last update Tue Jun 10 13:32:42 2014 NicolasOVEJERO
*/

#include "gene.h"

int	exec_live(char **tab_fct, t_gene *utils)
{
  if ((strncmp(tab_fct[0], "/", 1) == 0) ||
      (strncmp(tab_fct[0], "./", 2) == 0))
    {
      if (strcmp("/bin/kill", tab_fct[0]) == 0)
	{
	  if (my_kill(tab_fct, utils) == -1)
	    return (-1);
	}
      else
	return (exe_cmd(tab_fct[0], tab_fct, utils->env));
    }
  return (-1);
}

int	check_access(char **tab_fct)
{
  int	i;

  i = 1;
  if (strncmp(tab_fct[0], "ls", 2) == 0)
    while (tab_fct[i])
      {
	if (tab_fct[i][0] != '-')
	  {
	    if (access(tab_fct[i], R_OK) != -1)
	      return (0);
	    else if (!(tab_fct[i]))
	      return (0);
	    else
	      {
		printf("[42sh] Error: %s: Permission denied\n", tab_fct[i]);
		return (-1);
	    }
	  }
	i++;
      }
  return (0);
}

int	exec(char **tab_fct, t_gene *utils)
{
  if (strncmp(tab_fct[0], "/", 1) == 0 || strncmp(tab_fct[0], "./", 2) == 0)
    return (exec_live(tab_fct, utils));
  if (check_access(tab_fct) == 0)
    return (search(tab_fct, utils));
  else
    return (-1);
}

int	exec_check_pipe(char **tab_fct, t_gene *utils)
{
  if (strncmp(tab_fct[0], "/", 1) == 0 || strncmp(tab_fct[0], "./", 2) == 0)
    return (exec_live(tab_fct, utils));
  else
    return (my_exec_pipe(tab_fct, utils));
}

int	check_setun(char *cmd)
{
  if (strcmp(cmd, "setenv") == 0)
    return (0);
  else if (strcmp(cmd, "unsetenv") == 0)
    return (0);
  else if (strcmp(cmd, "cd") == 0)
    return (0);
  return (-1);
}
