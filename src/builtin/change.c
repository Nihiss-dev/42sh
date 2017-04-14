/*
** change.c for 42sh in /home/feldma_a/documents/builtin
**
** Made by Alexis Feldmar
** Login   <feldma_a@epitech.net>
**
** Started on  Fri May 16 03:42:07 2014 Alexis Feldmar
** Last update Tue Jun 10 05:55:11 2014 NicolasOVEJERO
*/

#include "gene.h"

int	change_oldpath(char *oldpath, t_gene *utils)
{
  int	i;
  char	*path[2];

  i = 0;
  path[0] = "setenv";
  path[1] = my_strcat_pers("OLDPWD", "=", oldpath);
  while (utils->env[i])
    {
      if (strncmp(utils->env[i], "OLDPWD", 6) == 0)
	break;
      ++i;
    }
  if (utils->env[i] == NULL)
    my_setenv(path, utils);
  else
    utils->env[i] = my_strcat_pers("OLDPWD", "=", oldpath);
  return (0);
}

int	change_pwd(char *pwd, t_gene *utils)
{
  int	i;
  char	*cat_path;

  i = 0;
  while (utils->env[i])
    {
      if (strncmp(utils->env[i], "PWD", 3) == 0)
	break;
      ++i;
    }
  cat_path = my_strcat_pers("PWD", "=", pwd);
  utils->env[i] = cat_path;
  return (0);
}
