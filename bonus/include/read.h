/*
** read.h for 42sh in /home/feldma_a/rendu/PSU_2013_42sh/test
** 
** Made by Alexis Feldmar
** Login   <feldma_a@epitech.net>
** 
** Started on  Mon Jun  9 18:17:10 2014 Alexis Feldmar
** Last update Tue Jun 10 19:01:34 2014 Alexis Feldmar
*/

#ifndef READ_H_
# define READ_H_

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <ncurses/curses.h>
# include <term.h>
# include "struct.h"

/*
** my_read.c
*/
char		*my_read(t_gene *utils, int fd);
int		my_putint(int c);
int		check_read(t_gene *utils, char *buf, int fd);

/*
** new_read.c
*/
char		*new_read(t_gene *utils, char *buf, int fd);

/*
** my_cmd.c
*/
int		my_cmd(char *line, t_gene *utils);
void		my_putstr(char *str);

/*
** arrow.c
*/
char		*cursor_back(t_gene *utils, int fd);
void		my_arrow(t_gene *utils);
char		*arrow(t_gene *utils, int fd);

/*
** getnextline_histo.c
*/
char		*get_next_line_h(const int fd);

/*
** check_dg.c
*/
int		check_dg(char *buf, t_gene *utils);

/*
** history.c
*/
int		history_up(t_gene *utils);
int		history_down(t_gene *utils);
int		put_in_history(t_gene *utils, char *cmd);

/*
** init_termcaps.c
*/
int		raw_no_echo(struct termios *term_p);
char		*read_my_line(t_gene *utils, char *buf, int fd);


# endif /* !READ_H_ */
