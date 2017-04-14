/*
** cd.c for 42sh in /home/feldma_a/rendu/PSU_2013_42sh/tmp_work/builtin
**
** Made by Alexis Feldmar
** Login   <feldma_a@epitech.net>
**
** Started on  Mon Apr 21 19:36:17 2014 Alexis Feldmar
** Last update Tue Jun 10 05:03:36 2014 NicolasOVEJERO
*/

#include "gene.h"

int	chdir_back(t_gene *utils)
{
  char	stock[256];
  char	tmp[256];
  int	i;

  getcwd(tmp, sizeof(tmp));
  if (change_oldpath(getcwd(stock, sizeof(stock)), utils) == -1)
    return (-1);
  if (chdir(utils->back) < 0)
    {
      printf("No oldpwd defined\n");
      return (-1);
    }
  if (change_pwd(getcwd(stock, sizeof(stock)), utils) == -1)
    return (-1);
  bzero(utils->back, 256);
  i = -1;
  while (tmp[++i] && i < 255)
    utils->back[i] = tmp[i];
  utils->back[i] = '\0';
  return (0);
}

int	cd_exec(char **cmd, t_gene *utils)
{
  char	stock[256];

  if ((access(cmd[1], F_OK)) == -1)
    {
      printf("cd: %s No such file or directory\n", cmd[1]);
      return (-1);
    }
  if ((access(cmd[1], R_OK)) == -1)
    {
      printf("Access denied\n");
      return (-1);
    }
  bzero(utils->back, 256);
  if (change_oldpath(getcwd(utils->back, sizeof(utils->back)), utils) == -1)
    return (-1);
  if (chdir(cmd[1]) < 0)
    {
      printf("%s: Not a directory\n", cmd[1]);
      return (-1);
    }
  if (change_pwd(getcwd(stock, sizeof(stock)), utils) == -1)
    return (-1);
  return (0);
}

int	cd_fct_exec(char **cmd, t_gene *utils)
{
  if ((strcmp(cmd[1], "-")) == 0)
    {
      if (chdir_back(utils) == -1)
	return (-1);
    }
  else
    {
      if (cd_exec(cmd, utils) == -1)
	return (-1);
    }
  return (0);
}

int	cd_fct(char **cmd, t_gene *utils)
{
  if (cmd[1] && strcmp(cmd[1], "--") != 0)
    {
      if (cd_fct_exec(cmd, utils) == -1)
	return (-1);
    }
  else if (!cmd[1] || strcmp(cmd[1], "--") == 0)
    if (cd_home(utils) == -1)
      return (-1);
  return (0);
}
