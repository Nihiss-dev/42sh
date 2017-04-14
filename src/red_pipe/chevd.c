/*
** chevd.c for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/src
** 
** Made by NicolasOVEJERO
** Login   <ovejer_n@epitech.net>
** 
** Started on  Sat Jun  7 16:40:43 2014 NicolasOVEJERO
** Last update Tue Jun 10 13:26:37 2014 NicolasOVEJERO
*/

#include "gene.h"

void	end_file(t_gene *utils, int pipefd[2])
{
  char	*str;
  int	i;

  close(pipefd[1]);
  i = 0;
  while ((str = get_next_line(pipefd[0])))
    {
      if (i != 0)
	write(utils->new_fd, "\n", 1);
      write(utils->new_fd, str, strlen(str));
      free(str);
      i++;
    }
}

int	chev_right(char *cmd_line, t_gene *utils)
{
  int	pid;
  int	pipefd[2];

  utils->nb = 2;
  if (pipe(pipefd) < 0)
    return (-1);
  if ((pid = fork()) < 0)
    return (-2);
  if (pid == 0)
    {
      dup2(utils->pipe.save , 0);
      close(pipefd[0]);
      dup2(pipefd[1], 1);
      exit(check_cmd(my_str_to_wordtab(cmd_line, ' '), utils));
    }
  else
    wait(&pid);
  end_file(utils, pipefd);
  return (check_exit(pid));
}
