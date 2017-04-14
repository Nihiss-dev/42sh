/*
** utils.h for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/include
** 
** Made by NicolasOVEJERO
** Login   <ovejer_n@epitech.net>
** 
** Started on  Tue Jun 10 21:03:30 2014 NicolasOVEJERO
** Last update Tue Jun 10 21:04:48 2014 NicolasOVEJERO
*/

#ifndef UTILS_H_
# define UTILS_H_

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
** str_to_word_tab
*/
char		**my_str_to_wordtab(char *str, int c);
char		**my_str_to_wordtab_cust(char *str);
char		**my_str_to_wordtab_dasp(char *str);
int		check_dsign(char c, char c2);
int		check_sign(char c);
int		stock_sign(char *str, t_nb  *list, char **tab);

#endif /* !UTILS_H_ */
