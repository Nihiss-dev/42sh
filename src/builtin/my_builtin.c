/*
** my_builtin.c for 42sh in /home/feldma_a/Documents/semestre2/PSU/42sh_test/pouet
** 
** Made by Alexis Feldmar
** Login   <feldma_a@epitech.net>
** 
** Started on  Sat May 24 23:05:12 2014 Alexis Feldmar
** Last update Sun Jun  8 19:32:47 2014 NicolasOVEJERO
*/

#include "gene.h"

int	my_builtin(char __attribute__((__unused__)) **cmd,
		   t_gene __attribute__((__unused__)) *utils)
{
  printf("Builtins availables:\n"
	 "- env\n- setenv\n- unsetenv\n"
	 "- echo\n- cd\n"
	 "- yoda\n- man 42sh\n");
  return (0);
}
