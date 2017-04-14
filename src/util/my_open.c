/*
** my_open.c for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/tmp_work/gene
** 
** Made by NicolasOVEJERO
** Login   <ovejer_n@epitech.net>
** 
** Started on  Mon May 19 18:32:41 2014 NicolasOVEJERO
** Last update Tue Jun 10 05:48:15 2014 NicolasOVEJERO
*/

#include "gene.h"

int	my_open_s(t_gene *utils, char *name)
{
  char	name_cpy[256];
  int	i;

  i = -1;
  while (name[++i] && (name[i] > ' '))
    name_cpy[i] = name[i];
  name_cpy[i] = 0;
  if ((utils->new_fd = open(name_cpy, O_CREAT | O_TRUNC | O_RDWR,
			    S_IRWXU | S_IRWXG | S_IRWXO)) == -1)
    {
      printf("Error open with %s\n", name_cpy);
      return (-1);
    }
  return (0);
}

int	my_open_d(t_gene *utils, char *name)
{
  char	name_cpy[256];
  int	i;

  i = -1;
  while (name[++i] && (name[i] > ' '))
    name_cpy[i] = name[i];
  name_cpy[i] = 0;
  if ((utils->new_fd = open(name_cpy, O_CREAT |  O_APPEND | O_RDWR,
			    S_IRWXU | S_IRWXG | S_IRWXO)) == -1)
    {
      printf("Error open with %s\n", name_cpy);
      return (-1);
    }
  return (0);
}

int	my_open_ronly(t_gene *utils, char *name)
{
  char	**tab_open;

  if ((tab_open = my_str_to_wordtab(name, ' ')) == NULL)
    return (-2);
  if ((utils->old_fd = open(epure_end(tab_open[0], strlen(tab_open[0])),
			    O_RDONLY)) < 0)
    {
      printf("42sh: %s: No such file or directory\n", name);
      return (-1);
    }
  return (0);
}
