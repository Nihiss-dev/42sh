/*
** my_tab.c for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/tmp_work/gene
** 
** Made by NicolasOVEJERO
** Login   <ovejer_n@epitech.net>
** 
** Started on  Fri May 23 14:36:18 2014 NicolasOVEJERO
** Last update Sun May 25 05:06:53 2014 Alexis Feldmar
*/

#include "gene.h"

char	**tab()
{
  char	**tab;

  if ((tab = malloc(sizeof(char *) * (TAB_BF_SIZE + 1))) == NULL)
    return (NULL);
  tab[0] = "echo";
  tab[1] = "env";
  tab[2] = "yoda";
  tab[3] = "builtin";
  tab[4] = NULL;
  return (tab);
}

void	init_tab(int (**tab_bf)())
{
  tab_bf[0] = (void *)&echo_fct;
  tab_bf[1] = (void *)&aff_env;
  tab_bf[2] = (void *)&my_yoda;
  tab_bf[3] = (void *)&my_builtin;
}

