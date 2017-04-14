/*
** gene.h for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/tmp_work/gene
**
** Made by ovejer_n
** Login   <ovejer_n@epitech.net>
**
** Started on  Mon May 12 20:31:50 2014 ovejer_n
** Last update Tue Jun 10 21:13:55 2014 NicolasOVEJERO
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
# include	"chev_pipe.h"
# include	"cmd_pars.h"
# include	"utils.h"
# include	"builtins.h"

# define	LEN_READ	4096
# define	RED_G		'<'
# define	DRED_G		"<<"
# define	RED_D		'>'
# define	DRED_D		">>"
# define	PIPE		'|'
# define	ET		'&'
# define	SEMI_C		';'

/*
**  etet ouou
*/
int		end_sp_da(char **pc, t_gene *utils, t_val *val);
int		pars_cd(char *pc, t_gene *utils);
int		pars_sp_da(char *line_sc, t_gene *utils);
int		check_exit(int pid);
int		ok(t_val *val, t_gene *utils, char **pc);

/*
** alias
*/
int		exec_alias(char **cmd, t_gene *utils, int pipe);

/*
** semicolon
*/
int		pars_semicolon(char *line, t_gene *utils);

#endif /* !GENE_H_ */
