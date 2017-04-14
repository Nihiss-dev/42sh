/*
** my_pipe.c for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/tmp_work/gene
** 
** Made by NicolasOVEJERO
** Login   <ovejer_n@epitech.net>
** 
** Started on  Thu May 22 21:33:26 2014 NicolasOVEJERO
** Last update Wed Jun 11 11:59:36 2014 NicolasOVEJERO
*/

#include "gene.h"

int	exec_pipe(char **cmd_line, t_gene *utils)
{
  if (pipe(utils->pipefd) < 0)
    return (-1);
  if ((utils->pipe.pid = fork()) < 0)
    return (-1);
  else if (utils->pipe.pid == 0)
    {
      dup2(utils->pipe.save, 0);
      close(utils->pipefd[0]);
      dup2(utils->pipefd[1], 1);
      exit(check_cmd_pipe(cmd_line, utils , 2));
    }
  close(utils->pipefd[1]);
  utils->pipe.save = utils->pipefd[0];
  return (check_exit(utils->pipe.pid));
}

int		my_exec_pipe(char **cmd, t_gene *utils)
{
  struct stat	sb;
  char		**path;
  char		*path_cat;
  int		i;

  i = 0;
  if ((path = my_str_to_wordtab(search_path(utils->env), ':')) == NULL)
    return (-1);
  while (path[i])
    {
      if ((path_cat = my_strcat_pers(path[i], "/", cmd[0])) == NULL)
	return (-1);
      if (stat(path_cat, &sb) != -1)
        {
          if (execve(path_cat, cmd, utils->env) == -1)
	    exit(-1);
	  free(path_cat);
          return (0);
        }
      free(path_cat);
      i = i + 1;
    }
  printf("[42sh][error] %s Command not found\n", cmd[0]);
  return (-1);
}

int	check_cmd_pipe(char **tab_fct, t_gene *utils, int pipe)
{
  int	i;
  char	**tab_f;
  t_tab	tab_i;

  i = -1;
  utils->time = 0;
  init_tab(tab_i.tab_bf);
  if ((tab_f = tab()) == NULL)
    return (-2);
  while (tab_f[++i])
    if (strcmp(tab_f[i], tab_fct[0]) == 0)
      return (tab_i.tab_bf[i](tab_fct, utils));
  if (strcmp("kill", tab_fct[0]) == 0)
    if (my_kill(tab_fct, utils) == -1)
      return (-1);
  if (strcmp("exit", tab_fct[0]) == 0)
    {
      if (tab_fct[1])
        utils->ret_exit = atoi(tab_fct[1]);
      return (-2);
    }
  if (check_setun(tab_fct[0]) != 0)
    return (exec_alias(tab_fct, utils, pipe));
  return (0);
}

int	end_pipe(t_gene *utils, char *cmd)
{
  int	pid;
  int	status;

  if ((pid = fork()) < 0)
    return (-1);
  if (pid == 0)
    {
      dup2(utils->pipe.save , 0);
      exit(check_cmd_pipe(my_str_to_wordtab(epure_end(cmd, strlen(cmd)),
					    ' '), utils , 1));
    }
  else
    waitpid(pid, &status, 0);
  return (check_exit(pid));
}

int	my_pipe(char *cmd_line, t_gene *utils)
{
  char	**tab_pipe;
  int	i;

  utils->pipe.save = 0;
  if ((tab_pipe = my_str_to_wordtab(cmd_line, PIPE)) == NULL)
    return (-2);
  i = 0;
  while (tab_pipe[i + 1])
    {
      if (exec_pipe(my_str_to_wordtab(epure_end(tab_pipe[i],
						strlen(tab_pipe[i])), ' '),
		    utils) != 0)
	return (-1);
      i++;
    }
  utils->pipe.cmd = strdup(tab_pipe[i]);
  my_free_dtab(tab_pipe);
  return (0);
}
