/*
** my_semicolon.c for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/tmp_work/myshrc
** 
** Made by NicolasOVEJERO
** Login   <ovejer_n@epitech.net>
** 
** Started on  Sun May 25 04:40:24 2014 NicolasOVEJERO
** Last update Sun May 25 22:28:23 2014 Julien Chardon
*/

#include "gene.h"

int	check_semicolon(char *line, t_gene *utils)
{
  int	ret;

  if (strlen(line) > 0)
    {
      if (pars_cd(epure_end(line, strlen(line)), utils) == 1)
	{
	  if ((ret = pars_sp_da(line, utils)) == -1)
	    return (0);
	  else if (ret == -2)
	    return (-1);
	}
    }
  return (0);
}

int	pars_semicolon(char *line, t_gene *utils)
{
  int	nb_sc;
  int	i;
  char	**tab_sc;

  i = 0;
  nb_sc = 0;
  nb_sc = nb_car_spe(line, ';');
  if (nb_sc != 0)
    {
      if ((tab_sc = my_str_to_wordtab(epure_end(line,
						strlen(line)), ';')) == NULL)
	return (-1);
      while (tab_sc[i])
	{
	  if (check_semicolon(tab_sc[i], utils) < 0)
	    {
	      free(tab_sc);
	      return (0);
	    }
	  ++i;
	}
      free(tab_sc);
      return (0);
    }
  return (-1);
}
