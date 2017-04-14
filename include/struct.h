/*
** struct.h for 42sh in /home/chardo_j/exercices/42sh/src/myshrc
** 
** Made by Julien Chardon
** Login   <chardo_j@epitech.net>
** 
** Started on  Sat May 24 23:59:19 2014 Julien Chardon
** Last update Wed Jun 11 11:08:54 2014 NicolasOVEJERO
*/

#ifndef STRUCT_H_
# define STRUCT_H_

#include	"my_list.h"

typedef struct	s_hist
{
  char		*cmd;
  struct s_hist	*next;
  struct s_hist	*prev;
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

typedef struct	s_chev
{
  int		i;
  int		j;
  int		pos;
}		t_chev;

typedef struct	s_pipe
{
  int		pid;
  int		save;
  char		*cmd;
}		t_pipe;

typedef struct		s_general
{
  char			**env;
  char			*home;
  char			back[256];
  char			*latest;
  char			pass[256];
  char			*chev;
  int		        nb;
  int                   time;
  int			new_fd;
  int			old_fd;
  int			ret_exit;
  int			pipefd[2];
  int			fd_chev;
  t_list		*alias;
  t_pipe		pipe;
  struct s_value	val;
}			t_gene;

# define	TAB_BF_SIZE	4

typedef struct	s_tab
{
  int		(*tab_bf[TAB_BF_SIZE])(char **, t_gene *);
}		t_tab;

#endif /* !STRUCT_H_ */
