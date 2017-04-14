/*
** home.c for 42sh in /home/feldma_a/Documents/semestre2/PSU/42sh_test
** 
** Made by Alexis Feldmar
** Login   <feldma_a@epitech.net>
** 
** Started on  Fri May 16 14:23:32 2014 Alexis Feldmar
** Last update Wed Jun 11 12:04:17 2014 NicolasOVEJERO
*/

#include "gene.h"

char	*find_home(char **env)
{
  int	i;
  char	*home;

  i = 0;
  home = NULL;
  while (env[i])
    {
      if (strncmp(env[i], "HOME", 4) == 0)
	home = strdup(env[i] + 5);
      ++i;
    }
  if (home != NULL)
    return (home);
  else
    return (NULL);
}

int	home_here(t_gene *utils)
{
  char	stock[256];
  int	ret;

  if ((access(utils->home, R_OK)) == -1)
    {
      printf("Access denied\n");
      return (-1);
    }
  bzero(utils->back, 256);
  ret = change_oldpath(getcwd(stock, sizeof(stock)), utils);
  ret = change_oldpath(getcwd(utils->back, sizeof(utils->back)), utils);
  if (chdir(utils->home) < 0)
    {
      printf("An error occured while chdir\n");
      return (-1);
    }
  if (ret == -1)
    return (-1);
  if (change_pwd(getcwd(stock, sizeof(stock)), utils) == -1)
    return (-1);
  return (0);
}

int	cd_home(t_gene *utils)
{
  if ((utils->home = find_home(utils->env)) != NULL)
    {
      if (home_here(utils) == -1)
	return (-1);
    }
  else
    {
      printf("No home defined\n");
      return (-1);
    }
  return (0);
}
