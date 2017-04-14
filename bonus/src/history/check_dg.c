/*
** check_dg.c for 42sh in /home/feldma_a/rendu/PSU_2013_42sh/test/src/history
** 
** Made by Alexis Feldmar
** Login   <feldma_a@epitech.net>
** 
** Started on  Mon Jun  9 20:34:41 2014 Alexis Feldmar
** Last update Mon Jun  9 22:06:57 2014 Alexis Feldmar
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

int	check_dg(char *buf, t_gene *utils)
{
  int	i;

  i = 0;
  if (utils->hist.num_cmd > 0 && buf[0] == 27 && buf[1] == 91 && buf[2] == 65) //haut
    {
      TERM.str[strlen(TERM.str)] = 0;
      i = strlen(TERM.str) + 1;
      while (--i > 0)
	write(1, "\b \b", 3);
      return (history_up(utils));
    }
  else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 66) //bas
    {
      if (utils->hist.num_cmd <= utils->hist.nb_cmd)
  	{
  	  TERM.str[strlen(TERM.str)] = 0;
  	  i = strlen(TERM.str) + 1;
  	  while (--i > 0)
  	    write(1, "\b \b", 3);
  	  return (history_down(utils));
  	}
    }
  return (0);
}
