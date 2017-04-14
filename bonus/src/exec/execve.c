/*
** execve.c for 42sh in /home/comte_a/rendu/PSU_2013_42sh/tmp_work/comte_a
**
** Made by
** Login   <comte_a@epitech.net>
**
** Started on  Fri Apr 18 11:41:31 2014
** Last update Tue Jun 10 09:46:06 2014 NicolasOVEJERO
*/

#include "gene.h"

int	exe_cmd(char *cmd_1, char **cmd, char **env)
{
  pid_t	pid;

  cmd[0] = cmd_1;
  if (-1 == access(cmd_1, X_OK))
    {
      fprintf(stderr, "[42sh][error] Cannot access to cmd path\n");
      return (EXIT_FAILURE);
    }
  if ((pid = fork()) != 0)
    {
      if (-1 == wait(&pid))
      	{
  	  fprintf(stderr, "[42sh][error] Waiting for the son to terminate\n");
  	  return (EXIT_FAILURE);
  	}
    }
  else if (0 == pid)
    {
      if (-1 == execve(cmd[0], cmd, env))
	{
	  fprintf(stderr, "[42sh][error] Cannot execute the command\n");
	  return (EXIT_FAILURE);
	}
    }
  return (EXIT_SUCCESS);
}
