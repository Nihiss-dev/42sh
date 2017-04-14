/*
** my_chev.c for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/tmp_work/gene
** 
** Made by NicolasOVEJERO
** Login   <ovejer_n@epitech.net>
** 
** Started on  Fri May 23 13:28:19 2014 NicolasOVEJERO
** Last update Tue Jun 10 04:31:19 2014 NicolasOVEJERO
*/

#include "gene.h"

int	my_exec_chev_input(t_gene *utils, char *line_cmd)
{
  dup2(utils->old_fd, 0);
  return (check_cmd(my_str_to_wordtab(epure_end(line_cmd, strlen(line_cmd)),
				      ' '), utils));
}
