/*
** my_dasp2.c for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/tmp_work/gene
**
** Made by ovejer_n
** Login   <ovejer_n@epitech.net>
**
** Started on  Fri May 16 01:07:28 2014 ovejer_n
** Last update Tue Jun 10 19:30:53 2014 NicolasOVEJERO
*/

#include "gene.h"

int	pars_da(t_val *val, t_gene *utils, char **tab_sd, char **pc)
{
  int	pid;

  pid = -1;
  if (pc[0] && val->ret_pa == 1 && tab_sd[val->i + 1] &&
      strcmp(tab_sd[val->i + 1], "&&") == 0)
    {
      if ((val->ret_pa = pars_cd(epure_end(pc[0], strlen(pc[0])), utils)) == 1)
	{
	  if ((pid = fork()) == 0)
	    exit(pars_cmd(pc, utils));
	  else
	    wait(&pid);
	}
      if ((pid != -1) && (val->ret_pa = check_exit(pid)) == -2)
	return (-1);
      else if (val->ret_pa == -1)
	val->i += 2;
      else
	{
	  ++val->i;
	  val->ret_pa = 1;
	}
    }
  return (0);
}

int	pars_sp(t_val *val, t_gene *utils, char **tab_sd, char **pc)
{
  int	pid;

  pid = -1;
  if (pc[0] && val->ret_pa == 1 && tab_sd[val->i + 1] &&
      strcmp(tab_sd[val->i + 1], "||") == 0)
    {
      if ((val->ret_pa = pars_cd(epure_end(pc[0], strlen(pc[0])), utils)) == 1)
	{
	  if ((pid = fork()) == 0)
	    exit(pars_cmd(pc, utils));
	  else
	    wait(&pid);
	}
      if ((pid != -1) && (val->ret_pa = check_exit(pid)) == -2)
	return (-1);
      else if (val->ret_pa == 0)
	val->i += 2;
      else
	{
	  ++val->i;
	  val->ret_pa = 1;
	}
    }
  return (0);
}

int	ok(t_val *val, t_gene *utils, char **pc)
{
  int	pid;

  pid = getpid();
  if (pc[0])
    {
      if (val->ret_pa == 1)
	{
	  if (pars_cd(pc[0], utils) == 1)
	    {
	      if ((pid = fork()) < 0)
		return (-2);
	      if (pid == 0)
		exit(pars_cmd(pc, utils));
	      else
		wait(&pid);
	    }
	}
    }
  else
    pars_sp_da(my_read(0), utils);
  return (pid);
}

int	pars_sp_da(char *line_sc, t_gene *utils)
{
  t_val	val;
  char	**tab_sd;
  char	**pc;

  val.i = -1;
  val.ret_pa = 1;
  if ((tab_sd = my_str_to_wordtab_dasp(line_sc)) == NULL)
    return (-2);
  pc = NULL;
  while (tab_sd[++val.i])
    {
      val.ret_pa = 1;
      if (nb_dcar(tab_sd[val.i], '<') != 0)
	tab_sd[val.i] = my_exec_rrchev(tab_sd[val.i], utils);
      if ((pc = my_str_to_wordtab_cust(tab_sd[val.i])) == NULL)
	return (-2);
      if (pars_da(&val, utils, tab_sd, pc) == -1)
        return (-1);
      else if (pars_sp(&val, utils, tab_sd, pc) == -1)
        return (-1);
    }
  my_free_dtab(tab_sd);
  return (end_sp_da(pc, utils, &val));
}
