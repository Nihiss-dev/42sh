/*
** gene.h for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/tmp_work/gene
**
** Made by ovejer_n
** Login   <ovejer_n@epitech.net>
**
** Started on  Mon May 12 20:31:50 2014 ovejer_n
** Last update Tue Jun 10 20:48:25 2014 NicolasOVEJERO
*/

#ifndef GENE_H_
# define GENE_H_

# include	<stdio.h>
# include	<stdlib.h>
# include	<strings.h>
# include	<string.h>
# include	<unistd.h>
# include	<sys/stat.h>
# include	<sys/types.h>
# include	<fcntl.h>
# include	<signal.h>
# include	<sys/wait.h>
# include	"struct.h"
# include	"myshrc.h"

# define	LEN_READ	4096

/*
** parsing
*/
int		my_pars(t_gene *utils);
int		check_cmd(char **tab_fct, t_gene *utils);
int		pars_pr(char *cmd_line, t_gene *utils, int);
int		pars_cmd(char **tab_sd, t_gene *utils);
int		check_setun(char *cmd);
char		*my_read(t_gene *utils, int fd);

/*
** cmd
*/
int		my_cmd(char *line, t_gene *utils);
int		exec_live(char **tab_fct, t_gene *utils);
int		other(char **tab_sd, t_gene *utils, int i, int re);

/*
** str_to_word_tab
*/
char		**my_str_to_wordtab(char *str, int c);
char		**my_str_to_wordtab_cust(char *str);
char		**my_str_to_wordtab_dasp(char *str);
int		check_dsign(char c, char c2);
int		check_sign(char c);
int		stock_sign(char *str, t_nb  *list, char **tab);

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

/*
**  etet ouou
*/
int		end_sp_da(char **pc, t_gene *utils, t_val *val);
int		pars_cd(char *pc, t_gene *utils);
int		pars_sp_da(char *line_sc, t_gene *utils);
int		check_exit(int pid);
int		ok(t_val *val, t_gene *utils, char **pc);

/*
** free
*/
void		my_free_dtab(char **tab);

/*
** execution
*/
int		exe_cmd(char *cmd_1, char **cmd, char **env);
int		exec(char **tab_fct, t_gene *utils);

/*
** my_open.c
*/
int		my_open_ronly(t_gene *utils, char *name);
int		my_open_s(t_gene *utils, char *name);
int		my_open_d(t_gene *utils, char *name);

/*
** util
*/
int		nb_car_spe(char *line, char c);
int		nb_dcar(char *line, char c);
char		*my_strcat_pers(char *s1, char *s2, char *s3);
int		my_kill(char **cmd, t_gene *utils);
char		*my_epur_str(char *line);
char		*epure_end(char *line, int a);
void		my_putstr(char *str);
void		init_tab(int (**tab_bf)());
int		search(char **cmd, t_gene *utils);
int		exec_check_pipe(char **tab_fct, t_gene *utils);

/*
** alias
*/
int		exec_alias(char **cmd, t_gene *utils, int pipe);

/*
** semicolon
*/
int		pars_semicolon(char *line, t_gene *utils);

/*
** BUILTIN
*/

/*
** cd
*/
int		change_oldpath(char *oldpath, t_gene *utils);
int		cd_fct(char **cmd, t_gene *utils);
int		cd_home(t_gene *utils);

/*
** setenv.c
*/
int		my_setenv(char **cmd, t_gene *utils);

/*
** env.c
*/
int		my_env(t_gene *utils, char **env);
void		free_env(char **env);
int		aff_env(char **cmd, t_gene *utils);

/*
** unsetenv.c
*/
int		my_unsetenv(char **cmd, t_gene *utils);

/*
** echo, cd, yoda
*/
int		echo_fct(char **echo, t_gene *utils);
char            *search_path(char **env);
char		**tab();
int		change_pwd(char *pwd, t_gene *utils);
int		other_fct(char **tab_fct, t_gene *utils);
int		my_yoda(char **cmd, t_gene *utils);
int		my_builtin(char **cmd, t_gene *utils);

/*
** HISTORIQUE
*/

/*
** history.c
*/
int		open_history(t_gene *utils);
int		my_history(char __attribute__((__unused__)) **cmd, t_gene *utils);
int		put_in_history(t_gene *utils, char *cmd);

/*
** TERMCAPS
*/

/*
** init_termcaps.c
*/
int		init_termcaps(t_gene *utils);

#endif /* !GENE_H_ */
