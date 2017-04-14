/*
** init_termcaps.c for 42sh in /home/feldma_a/rendu/PSU_2013_42sh/test
** 
** Made by Alexis Feldmar
** Login   <feldma_a@epitech.net>
** 
** Started on  Mon Jun  9 18:13:36 2014 Alexis Feldmar
** Last update Tue Jun 10 01:28:19 2014 Alexis Feldmar
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <term.h>
#include <ncurses/curses.h>
#include <termios.h>
#include "struct.h"
#include "read.h"

int	raw_no_echo(struct termios *term_p)
{
  term_p->c_lflag &= ~ICANON;
  term_p->c_lflag &= ~ECHO;
  term_p->c_cc[VMIN] = 1;
  term_p->c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, term_p) == -1)
    return (-1);
  return (0);
}

int	my_raw(struct termios *term_p)
{
  term_p->c_lflag &= ~ICANON;
  term_p->c_cc[VMIN] = 1;
  term_p->c_cc[VTIME] = 0;
  return (0);
}

char	*read_my_line(t_gene *utils, char *buf, int fd)
{
  while (buf[0] != '\n')
    {
      if ((TERM.len = read(fd, buf, 4)) <= 0)
	return (NULL);
      if ((TERM.ret = check_read(utils, buf, fd)) == -1)
	return (NULL);
      else if (TERM.ret == 1)
	my_arrow(utils);
      else if (TERM.ret > 1)
	{
	  if ((TERM.str = arrow(utils, fd)) == NULL)
	    return (NULL);
	}
      else
	{
	  TERM.str[TERM.i_read] = buf[0];
	  write(fd, &TERM.str[TERM.i_read++], 1);
	}
    }
  return (TERM.str);
}

int	init_termcaps(t_gene *utils)
{
  int	i;

  i = 0;
  while (utils->env[i])
    {
      if (strncmp(utils->env[i], "TERM", 4) == 0)
	{
	  if ((utils->termcaps.term = malloc(sizeof(char) *
					     strlen(utils->env[i]))) == NULL)
	    return (-1);
	  utils->termcaps.term = utils->env[i] + 5;
	}
      ++i;
    }
  tgetent(NULL, utils->termcaps.term);
  tcgetattr(0, &utils->termcaps.term_p);
  tcgetattr(0, &utils->termcaps.term_p2);
  tcgetattr(0, &utils->termcaps.term_p3);
  my_raw(&utils->termcaps.term_p);
  return (0);
}
