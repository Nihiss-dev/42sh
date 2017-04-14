/*
** my_etet_ouou2.c for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/src
** 
** Made by NicolasOVEJERO
** Login   <ovejer_n@epitech.net>
** 
** Started on  Sun Jun  8 18:22:44 2014 NicolasOVEJERO
** Last update Tue Jun 10 10:26:05 2014 NicolasOVEJERO
*/

#include "gene.h"

int	end_sp_da(char **pc, t_gene *utils, t_val *val)
{
  if (pc[0] && (strncmp("exit", pc[0], 4) == 0))
    {
      utils->ret_exit = atoi(pc[0] + 4);
      return (-2);
    }
  if (pc[0])
    return (check_exit(ok(val, utils, pc)));
  return (0);
}

int	check_exit(int pid)
{
  if (WIFEXITED(pid))
    {
      if (WEXITSTATUS(pid) == 255)
        return (-1);
      else if (WEXITSTATUS(pid) == 254)
	return (-2);
      else
        return (0);
    }
  return (0);
}
