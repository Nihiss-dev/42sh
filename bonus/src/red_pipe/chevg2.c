/*
** chevg2.c for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/src
** 
** Made by NicolasOVEJERO
** Login   <ovejer_n@epitech.net>
** 
** Started on  Sun Jun  8 20:57:58 2014 NicolasOVEJERO
** Last update Tue Jun 10 06:56:19 2014 NicolasOVEJERO
*/

#include "gene.h"

int	chevg_pipe_last(char **chev_g, t_gene *utils)
{
  int	i;
  int	ret;

  i = 0;
  if (chev_g != NULL)
    {
      while (chev_g[++i])
	if (my_open_ronly(utils, chev_g[i]))
	  return (-1);
      utils->pipe.save = utils->old_fd;
      ret = end_pipe(utils, chev_g[0]);
    }
  else
    return (-2);
  my_free_dtab(chev_g);
  return (ret);
}

int	check_chev_end(t_gene *utils, char *last)
{
  if (nb_car_spe(last, '<') != 0)
    return (chevg_pipe_last(my_str_to_wordtab(last, '<'), utils));
  else
    return (end_pipe(utils, last));
  return (0);
}
