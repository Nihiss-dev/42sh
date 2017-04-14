/*
** yoda.c for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/tmp_work/gene
** 
** Made by NicolasOVEJERO
** Login   <ovejer_n@epitech.net>
** 
** Started on  Fri May 23 14:23:51 2014 NicolasOVEJERO
** Last update Sun May 25 13:16:07 2014 NicolasOVEJERO
*/

#include "gene.h"

int	my_yoda(char __attribute__((__unused__)) **cmd,
		t_gene __attribute__((__unused__)) *utils)
{
  char	c[646];
  int	fd;
  int	len;

  if ((fd = open("src/builtin/.yoda", O_RDONLY)) == -1)
    {
      printf("Yoda is dead\n");
      return (-1);
    }
  len = read(fd, c, 645);
  if (len < 0)
    return (-1);
  else
    {
      c[len] = '\0';
      write(1, c, len);
    }
  close(fd);
  printf("\t\e[01;31mMay the force be with you\n \e[0m\n");
  return (0);
}
