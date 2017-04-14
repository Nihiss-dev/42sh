/*
** my_kill.c for 42sh in /home/feldma_a/Documents/semestre2/PSU/42sh_test
** 
** Made by Alexis Feldmar
** Login   <feldma_a@epitech.net>
** 
** Started on  Fri May 16 12:29:24 2014 Alexis Feldmar
** Last update Thu Jun  5 14:52:05 2014 NicolasOVEJERO
*/

#include <sys/types.h>
#include <signal.h>
#include "gene.h"

int	my_kill(char **cmd, t_gene __attribute__((__unused__)) *utils)
{
  if (cmd[1] && cmd[2])
    {
      if (atoi(cmd[2]) == 0)
	{
	  printf("Segmentation fault\n");
	  return (-1);
	}
    }
  return (0);
}
