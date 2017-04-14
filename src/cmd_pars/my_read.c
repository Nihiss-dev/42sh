/*
** my_read.c for my_read in /home/ovejer_n/rendu/PSU_2013_42sh/tmp_work/42sh/src
**
** Made by Nicolas OVEJERO
** Login   <ovejer_n@epitech.net>
**
** Started on  Sat Apr 26 19:57:10 2014 Nicolas OVEJERO
** Last update Tue Jun 10 01:00:37 2014 NicolasOVEJERO
*/

#include "gene.h"

char	*my_read(int fd)
{
  int	len;
  char	*str;

  len = 0;
  if ((str = malloc(LEN_READ + 1)) == NULL)
    return (NULL);
  memset(str, 0, 4096);
  while (len == 0)
    {
      len = read(fd, str, LEN_READ);
      str[len] = '\0';
      if (len <= 0)
	return (NULL);
      else
	return (str);
    }
  return (NULL);
}
