/*
** search_fonc.c for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/PSU_2013_42sh/tmp_work/42sh/exec
**
** Made by ovejer_n
** Login   <ovejer_n@epitech.net>
**
** Started on  Mon May  5 13:42:25 2014 ovejer_n
** Last update Tue Jun 10 21:02:47 2014 Alexis Feldmar
*/

#include	"gene.h"

char		*search_path(char **env)
{
  int		i;

  i = 0;
  while (env[i])
    {
      if (strncmp(env[i], "PATH=", 5) == 0)
	return (env[i] + 5);
      i++;
    }
  printf("[42sh][error] There is no path\n");
  return (NULL);
}

int		search(char **cmd, t_gene *utils)
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
	  i = exe_cmd(path_cat, cmd, utils->env);
	  free(path_cat);
      	  return (i);
      	}
      free(path_cat);
      i = i + 1;
    }
  fprintf(stderr, "[42sh][error] %s : Command not found\n", cmd[0]);
  return (-1);
}
