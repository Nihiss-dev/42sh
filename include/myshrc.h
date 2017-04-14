/*
** myshrc.h for 42sh in /home/chardo_j/rendu/PSU_2013_42sh
** 
** Made by Julien Chardon
** Login   <chardo_j@epitech.net>
** 
** Started on  Fri May 16 01:04:37 2014 Julien Chardon
** Last update Sun May 25 00:00:46 2014 Julien Chardon
*/

#ifndef MYSHRC_H_
# define MYSHRC_H_

# include "my_gnl.h"
# include "my_list.h"
# include "struct.h"

# define MYSHRC_F_NAME	".myshrc"

# define EXPORT		"export "
# define ALIAS		"alias "

# define LEN_EXPORT	7
# define LEN_ALIAS	6

/*
** manage_myshrc.c
*/
int	manage_myshrc(t_gene *util);
void	free_myshrc(t_gene *util);

/*
** manage_export.c
*/
int	manage_export(t_gene *util, char *str);

/*
** manage_alias.c
*/
int	manage_alias(t_gene *util, char *str);
void	free_alias(t_list *alias);

/*
** pars_myshrc.c
*/
int	pars_myshrc(t_gene *util, int fd);

/*
** utils_pars_myshrc.c
*/
int	is_export(char *line);
int	is_alias(char *line);
int	is_commentary_or_empty(char *line);

/*
** utils_manage_ea.c
*/
char	*get_ea_name(char *str, int *i);
char	*get_ea_val(char *str, int i);
int	init_name_val(char **name, char **val, char *str);
char	*create_new_val(char *new_val, char *name, char *val);
void	free_two_str(char *s1, char *s2);

#endif /* !MYSHRC_H_ */
