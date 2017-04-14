/*
** my_read.c for my_read in /home/ovejer_n/rendu/PSU_2013_42sh/tmp_work/42sh/src
**
** Made by Nicolas OVEJERO
** Login   <ovejer_n@epitech.net>
**
** Started on  Sat Apr 26 19:57:10 2014 Nicolas OVEJERO
** Last update Tue Jun 10 22:03:24 2014 Alexis Feldmar
*/

#include <ncurses/curses.h>
#include <term.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "read.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_putint(int c)
{
  my_putchar(c);
  return (0);
}

void	print_new_prompt(t_gene *utils)
{
  char	temp[256];

  tputs(tgetstr("cl", NULL), 0, my_putint);
  getcwd(temp, sizeof(temp));
  write(1, "[42sh][", 7);
  write(1, temp, strlen(temp));
  write(1, "]$ ", 3);
  write(1, TERM.str, strlen(TERM.str));
}

int	check_read(t_gene *utils, char *buf, int fd)
{
  TERM.bs = TERM.i_read;
  if (buf[0] == 12)
    {
      print_new_prompt(utils);
      bzero(buf, 4);
      read(fd, buf, 4);
    }
  if (buf[0] == 127 && buf[1] == 0)
    {
      TERM.bs > 0 ? write(1, "\b \b", 3) && (TERM.bs = TERM.bs) : (TERM.bs = 0);
      return (1);
    }
  if (check_dg(buf, utils) == 1)
    return (1);
  if (buf[0] == 27 && buf[1] == 91 && buf[2] == 68)
    {
      tputs(tgetstr("le", NULL), 0, my_putint);
      return (2);
    }
  if (buf[0] == 27 && buf[1] == 91 && buf[2] == 67)
    {
      tputs(tgetstr("nd", NULL), 0, my_putint);
      return (3);
    }
  return (0);
}

char	*my_read(t_gene *utils, int fd)
{
  char	buf[4];

  bzero(buf, 4);
  if ((TERM.str = malloc(LEN_READ + 1)) == NULL)
    return (NULL);
  memset(TERM.str, 0, 4096);
  if (raw_no_echo(&TERM.term_p3) == -1)
    return (NULL);
  TERM.i_read = 0;
  utils->hist.num_cmd = utils->hist.nb_cmd;
  if ((TERM.str = strdup(read_my_line(utils, buf, fd))) == NULL)
    return (NULL);
  TERM.str[TERM.i_read] = '\0';
  if (tcsetattr(0, TCSANOW, &TERM.term_p) == -1)
    return (NULL);
  return (TERM.str);
}
