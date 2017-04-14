/*
** struct.h for 42sh in /home/chardo_j/exercices/42sh/src/myshrc
** 
** Made by Julien Chardon
** Login   <chardo_j@epitech.net>
** 
** Started on  Sat May 24 23:59:19 2014 Julien Chardon
** Last update Tue Jun 10 21:41:09 2014 Alexis Feldmar
*/

#ifndef STRUCT_H_
# define STRUCT_H_

# include <termios.h>
# include <unistd.h>
# include "my_list.h"

# define	LEN_READ	4096
# define	TERM		utils->termcaps

typedef struct		s_termcaps
{
  int			len;
  int			ret;
  int			j;
  int			back;
  int			bs;
  char			*term;
  int			i_read;
  char			*str;
  struct termios	term_p;
  struct termios	term_p2;
  struct termios	term_p3;
}			t_termcaps;

typedef struct	s_hist
{
  int		fd;
  int		nb_cmd;
  int		num_cmd;
  char		*path_hist;
  char		*cmd;
}		t_hist;

typedef struct	s_nb
{
  int		i;
  int		a;
  int		b;
}		t_nb;

typedef struct	s_value
{
  int		j;
  int		i;
  int		val_first;
  char		copy[4096];
  int		ret_pa;
  int		nb_pipe;
}		t_val;

typedef struct	s_alias
{
  char		*name;
  char		*cmd;
}		t_alias;

typedef struct  s_chev
{
  int           i;
  int           j;
  int           pos;
}               t_chev;

typedef struct  s_pipe
{
  int           pid;
  int           save;
  char          *cmd;
}               t_pipe;

typedef struct		s_general
{
  char                  **env;
  char                  *home;
  char                  back[256];
  char                  *latest;
  char                  pass[256];
  char                  *chev;
  int                   nb;
  int                   time;
  int                   new_fd;
  int                   old_fd;
  int                   ret_exit;
  int                   pipefd[2];
  int                   fd_chev;
  t_pipe                pipe;
  t_list		*alias;
  t_termcaps		termcaps;
  t_hist		hist;
  struct s_value	val;
}			t_gene;

# define	TAB_BF_SIZE	5

typedef struct	s_tab
{
  int		(*tab_bf[TAB_BF_SIZE])(char **, t_gene *);
}		t_tab;

#endif /* !STRUCT_H_ */
