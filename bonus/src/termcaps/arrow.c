/*
** arrow.c for 42sh in /home/feldma_a/rendu/PSU_2013_42sh/test
** 
** Made by Alexis Feldmar
** Login   <feldma_a@epitech.net>
** 
** Started on  Mon Jun  9 18:15:53 2014 Alexis Feldmar
** Last update Tue Jun 10 21:47:40 2014 Alexis Feldmar
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <term.h>
#include <ncurses/curses.h>
#include <termios.h>
#include "struct.h"
#include "read.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    ++i;
  return (i);
}

char	*cursor_front(t_gene *utils, int fd)
{
  char	buf[4];
  int	len;
  char	*stock;
  int	j;

  bzero(buf, 4);
  j = -1;
  (++TERM.i_read > my_strlen(TERM.str)) ? (TERM.i_read = my_strlen(TERM.str)) :
    (TERM.i_read = TERM.i_read);
  if ((len = read(fd, buf, 4)) <= 0)
    return (NULL);
  if ((stock = malloc(sizeof(char) * TERM.i_read)) == NULL)
    return (NULL);
  if (buf[0] >= 32)
    {
      while (++j != TERM.i_read)
	stock[j] = TERM.str[j];
      strcat(stock, buf);
      strcat(stock, TERM.str + TERM.i_read);
      write(fd, strcat(buf, TERM.str + TERM.i_read),
      	    strlen(buf) + strlen(TERM.str + TERM.i_read));
    }
  else
    stock = new_read(utils, buf, fd);
  return (stock);
}

char	*cursor_back(t_gene *utils, int fd)
{
  char	buf[4];
  int	len;
  char	*stock;
  int	j;

  bzero(buf, 4);
  j = -1;
  (--TERM.i_read < 0) ? (TERM.i_read = 0) : (TERM.i_read = TERM.i_read);
  if ((len = read(fd, buf, 4)) <= 0)
    return (NULL);
  if ((stock = malloc(sizeof(char) * TERM.i_read)) == NULL)
    return (NULL);
  if (buf[0] >= 32)
    {
      while (++j < TERM.i_read)
	stock[j] = TERM.str[j];
      strcat(stock, buf);
      strcat(stock, TERM.str + TERM.i_read);
      write(fd, strcat(buf, TERM.str + TERM.i_read),
      	    strlen(buf) + strlen(TERM.str + TERM.i_read));
    }
  else
    stock = new_read(utils, buf, fd);
  return (stock);
}

void	my_arrow(t_gene *utils)
{
  if (utils->hist.num_cmd > 0 && utils->hist.cmd)
    {
      TERM.str = strdup(utils->hist.cmd);
      TERM.i_read = strlen(TERM.str) + 1;
    }
  (--TERM.i_read < 0) ? (TERM.i_read = 0) : (TERM.i_read = TERM.i_read);
}

char	*arrow(t_gene *utils, int fd)
{
  if (TERM.ret == 2)
    {
      TERM.j = strlen(TERM.str);
      (++TERM.back > TERM.j) ? (TERM.back = TERM.j) : (TERM.back = TERM.back);
      if ((TERM.str = cursor_back(utils, fd)) == NULL)
	return (NULL);
      TERM.i_read += strlen(TERM.str) - TERM.j + 1;
    }
  if (TERM.ret == 3)
    {
      (--TERM.back < 0) ? (TERM.back = 0) : (TERM.back);
      TERM.j = strlen(TERM.str);
      if ((TERM.str = cursor_front(utils, fd)) == NULL)
	return (NULL);
      TERM.i_read = strlen(TERM.str) - TERM.j;
    }
  return (TERM.str);
}
