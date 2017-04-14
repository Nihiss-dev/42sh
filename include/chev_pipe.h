/*
** chev_pipe.h for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/include
** 
** Made by NicolasOVEJERO
** Login   <ovejer_n@epitech.net>
** 
** Started on  Tue Jun 10 20:59:00 2014 NicolasOVEJERO
** Last update Tue Jun 10 21:00:21 2014 NicolasOVEJERO
*/

#ifndef CHEV_PIPE__H_
# define CHEV_PIPE_H_

/*
** chevrons
*/
int		chevg_base(char **chev_g, t_gene *utils);
int		start_chev(char *cmd, t_gene *utils, int);
int		chevg_pipe(char **chev_g, t_gene *utils);
int		pars_chevg_pipe(char *cmd_line, t_gene *utils);
int		check_chev_end(t_gene *utils, char *last);
void		my_exec_chev_input_pipe(t_gene *utils, char *line_cmd, char *);
int		chev_right(char *cmd_line, t_gene *utils);
int		my_exec_chev_input(t_gene *utils, char *line_cmd);
char		*my_read_chev(char *pass);
int		password(char *first, int i, t_gene *utils);
char		*my_exec_rrchev(char *word, t_gene *utils);
void		exec_rrchev(t_gene *utils);

/*
** pipe
*/
int		my_exec_pipe(char **cmd, t_gene *utils);
int		exec_pipe(char **cmd_line, t_gene *utils);
int		end_pipe(t_gene *utils, char *cmd);
int		my_pipe(char *cmd_line, t_gene *utils);
int		check_cmd_pipe(char **tab_fct, t_gene *utils, int pipe);

#endif /* !CHEV_PIPE_H_ */
