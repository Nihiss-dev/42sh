/*
** execve_pipe.c for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/tmp_work/gene
** 
** Made by NicolasOVEJERO
** Login   <ovejer_n@epitech.net>
** 
** Started on  Thu May 22 14:46:41 2014 NicolasOVEJERO
** Last update Tue Jun 10 07:00:07 2014 NicolasOVEJERO
*/

#include	"gene.h"

int		execve_pipe(char **cmd, t_gene *utils)
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
	  cmd[0] = path_cat;
	  execve(cmd[0], cmd, utils->env);
	  free(path_cat);
	  return (0);
	}
      free(path_cat);
      i = i + 1;
    }
  fprintf(stderr, "[42sh][error] %s Command not found\n", cmd[0]);
  return (-1);
}
