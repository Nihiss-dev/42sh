/*
** cmd_pars.h for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/include
** 
** Made by NicolasOVEJERO
** Login   <ovejer_n@epitech.net>
** 
** Started on  Tue Jun 10 21:01:35 2014 NicolasOVEJERO
** Last update Wed Jun 11 11:53:14 2014 NicolasOVEJERO
*/

#ifndef CMD_PARS_H_
# define CMD_PARS_H_

/*
** parsing
*/
int		my_pars(t_gene *utils);
int		check_cmd(char **tab_fct, t_gene *utils);
int		pars_pr(char *cmd_line, t_gene *utils, int);
int		pars_cmd(char **tab_sd, t_gene *utils);
int		check_setun(char *cmd);
char		*my_read(int fd);

/*
** cmd
*/
int		my_cmd(char *line, t_gene *utils);
int		exec_live(char **tab_fct, t_gene *utils);
int		other(char **tab_sd, t_gene *utils, int i, int re);
int		_my_open(char *file, int type, t_gene *utils);
char		*bonjour(char *line, int type, t_gene *utils);

#endif /* !CMD_PARS_H_ */
