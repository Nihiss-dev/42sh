/*
** builtins.h for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/include
** 
** Made by NicolasOVEJERO
** Login   <ovejer_n@epitech.net>
** 
** Started on  Tue Jun 10 21:06:10 2014 NicolasOVEJERO
** Last update Tue Jun 10 21:06:48 2014 NicolasOVEJERO
*/

#ifndef BUILTINS_H_
# define BUILTINS_H_

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

#endif /* !BUILTINS_H_ */
