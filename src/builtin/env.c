/*
** env.c for 42sh in /home/feldma_a/rendu/PSU_2013_42sh/tmp_work/builtin
**
** Made by Alexis Feldmar
** Login   <feldma_a@epitech.net>
**
** Started on  Tue Apr 22 20:22:58 2014 Alexis Feldmar
** Last update Sun May 25 17:01:03 2014 Julien Chardon
*/

#include "gene.h"

int	aff_env(char __attribute__((__unused__)) **cmd, t_gene *utils)
{
  int	i;

  i = -1;
  while (utils->env[++i] != NULL)
    printf("%s\n", utils->env[i]);
  return (0);
}
