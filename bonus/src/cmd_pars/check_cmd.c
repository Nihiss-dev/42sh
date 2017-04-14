/*
** check_cmd.c for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/src
** 
** Made by NicolasOVEJERO
** Login   <ovejer_n@epitech.net>
** 
** Started on  Tue Jun 10 05:51:11 2014 NicolasOVEJERO
** Last update Wed Jun 11 09:12:01 2014 NicolasOVEJERO
*/

#include "gene.h"

int	top(char **tab_sd, t_gene *utils, int i, int re)
{
  if (nb_car_spe(tab_sd[re], '|') == 0 && i == 1)
    {
      if (nb_car_spe(tab_sd[re], '<') == 0)
	return (check_cmd(my_str_to_wordtab(epure_end(tab_sd[re],
						      strlen(tab_sd[re])), ' '),
			  utils));
      else if (i == 1)
	return (pars_pr(epure_end(tab_sd[re], strlen(tab_sd[re])), utils, i));
    }
  return (10);
}

int	in_moddle(char **tab_sd, t_gene *utils,  int re)
{
  int	ret;

  ret = 0;
  utils->pipe.save = 0;
  if ((ret = pars_pr(epure_end(tab_sd[re], strlen(tab_sd[re])),
		     utils, 0)) == 0)
    {
      if ((ret = my_pipe(epure_end(utils->chev, strlen(utils->chev)),
			 utils)) == 0)
	return (end_pipe(utils, utils->pipe.cmd));
      else
	return (ret);
    }
  else
    return (ret);
  return (10);
}

int	middle(char **tab_sd, t_gene *utils, int i, int re)
{
  int	ret;

  ret = 0;
  if (i == 1)
    {
      if (tab_sd[re][0] != '<')
	{
	  if ((ret = pars_pr(epure_end(tab_sd[re], strlen(tab_sd[re])),
			     utils, i)) == 0)
	    return (end_pipe(utils, utils->pipe.cmd));
	  else
	    return (ret);
	}
      else
	return (in_moddle(tab_sd, utils, re));
    }
  else
    {
      if (pars_pr(epure_end(tab_sd[re], strlen(tab_sd[re])), utils, i) == 0)
	return (chev_right(utils->pipe.cmd, utils));
    }
  return (10);
}

int     down(char **tab_sd, t_gene *utils, int i, int re)
{
  int	ret;

  ret = 0;
  if (nb_car_spe(tab_sd[re], '<') != 0)
    {
      utils->pipe.save = utils->old_fd;
      if ((ret = pars_pr(epure_end(tab_sd[re], strlen(tab_sd[re])),
			 utils, i)) == 0)
	return (chev_right(epure_end(utils->chev,
				     strlen(utils->chev)), utils));
      else
	return (ret);
    }
  else
    return (chev_right(epure_end(tab_sd[re], strlen(tab_sd[re])), utils));
  return (-1);
}

int	other(char **tab_sd, t_gene *utils, int i, int re)
{
  int	ret;

  ret = 0;
  if  ((ret = top(tab_sd, utils, i, re)) == 10)
    {
      if (nb_car_spe(tab_sd[re], '|') != 0)
	return (middle(tab_sd, utils, i, re));
      else
	return (down(tab_sd, utils, i, re));
    }
  return (ret);
}
