/*
** new_read.c for 42sh in /home/feldma_a/rendu/PSU_2013_42sh/test/src/termcaps
** 
** Made by Alexis Feldmar
** Login   <feldma_a@epitech.net>
** 
** Started on  Tue Jun 10 18:58:18 2014 Alexis Feldmar
** Last update Tue Jun 10 20:44:59 2014 Alexis Feldmar
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <term.h>
#include <ncurses/curses.h>
#include <termios.h>
#include "struct.h"
#include "read.h"

char	*new_read(t_gene *utils, char *buf, int fd)
{
  char	*stock;
  int	ret;
  int	j;

  ret = 0;
  j = -1;
  if ((stock = malloc(sizeof(char) * TERM.i_read)) == NULL)
    return (NULL);
  memset(stock, 0, TERM.i_read);
  if ((ret = check_read(utils, buf, fd)) == -1)
    return (NULL);
  else if (ret == 1)
    my_arrow(utils);
  else if (ret > 1)
    {
      if ((TERM.str = arrow(utils, fd)) == NULL)
	return (NULL);
      while (++j != TERM.i_read - TERM.back)
	stock[j] = TERM.str[j];
      strcat(stock, buf);
      strcat(stock, TERM.str + TERM.i_read - TERM.back);
      printf("\nstock: %s\n", stock);
      bzero(buf, 4);
      return (stock);
    }
  return (NULL);
}
