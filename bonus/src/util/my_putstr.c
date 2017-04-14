/*
** my_putstr.c for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/tmp_work/gene
** 
** Made by ovejer_n
** Login   <ovejer_n@epitech.net>
** 
** Started on  Mon May 12 21:01:01 2014 ovejer_n
** Last update Sun May 25 19:03:52 2014 Julien Chardon
*/

#include "gene.h"

void	my_putstr(char *str)
{
  write(1, str, strlen(str));
}
