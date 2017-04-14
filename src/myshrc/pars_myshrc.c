/*
** pars_myshrc.c for myshrc in /home/chardo_j/exercices/42shrc/src
** 
** Made by Julien Chardon
** Login   <chardo_j@epitech.net>
** 
** Started on  Fri May 16 02:36:19 2014 Julien Chardon
** Last update Tue Jun 10 06:59:14 2014 NicolasOVEJERO
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"gene.h"

static int	call_manage_fct(t_gene *util, char *line, int n_l)
{
  if (is_export(line))
    {
      if (manage_export(util, line + LEN_EXPORT) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  else if (is_alias(line))
    {
      if (manage_alias(util, line + LEN_ALIAS) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  else if (!is_commentary_or_empty(line))
    printf("\e[1;31m[WARNING]\e[0m Syntax error in %s line %d.\n",
	   MYSHRC_F_NAME, n_l);
  return (EXIT_SUCCESS);
}

int		pars_myshrc(t_gene *util, int fd)
{
  int		n_l;
  char		*line;

  n_l = 0;
  while ((line = get_next_line(fd)) != NULL)
    {
      ++n_l;
      if (*line)
	{
	  if (call_manage_fct(util, line, n_l) == EXIT_FAILURE)
	    {
	      free(line);
	      return (EXIT_FAILURE);
	    }
	}
      free(line);
    }
  return (EXIT_SUCCESS);
}
