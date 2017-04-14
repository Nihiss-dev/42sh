/*
** my_cmd_pipe.c for 42sh in /home/feldma_a/Documents/semestre2/PSU/42sh_test/pouet
** 
** Made by Alexis Feldmar
** Login   <feldma_a@epitech.net>
** 
** Started on  Sat May 24 21:02:30 2014 Alexis Feldmar
** Last update Sun Jun  8 14:21:17 2014 NicolasOVEJERO
*/

#include "gene.h"

int	second_pipe(t_gene *utils)
{
  return (exec_alias(my_str_to_wordtab(epure_end(utils->latest,
						 strlen(utils->latest)
						 ), ' '), utils, 1));
}
