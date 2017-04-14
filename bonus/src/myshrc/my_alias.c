/*
** my_alias.c for 42sh in /opensuse/home/chardo_j/rendu/PSU_2013_42sh
** 
** Made by Julien Chardon
** Login   <chardo_j@epitech.net>
** 
** Started on  Sun May 25 19:51:24 2014 Julien Chardon
** Last update Tue Jun 10 13:30:14 2014 NicolasOVEJERO
*/

#include	"gene.h"

char		**cpy_dchar(char **cmd_base, char *cmd_new, int pipe)
{
  t_val		val;
  char		**new_tab;
  char		**new_cmd;

  val.j = 0;
  while (cmd_base[val.j])
    val.j++;
  if ((new_cmd = my_str_to_wordtab(cmd_new, ' ')) == NULL)
    return (NULL);
  val.i = -1;
  while (new_cmd[++val.i])
    val.j++;
  if ((new_tab = malloc(sizeof(char *) * val.j + 1)) == NULL)
    return (NULL);
  val.i = -1;
  while (new_cmd[++val.i])
    new_tab[val.i] = strdup(new_cmd[val.i]);
  pipe == 2 && strcmp(cmd_new, "ls --color") == 0 ? val.i-- : (val.i = val.i);
  val.j = 1;
  my_free_dtab(new_cmd);
  while (cmd_base[val.j])
    new_tab[val.i++] = strdup(cmd_base[val.j++]);
  new_tab[val.i] = NULL;
  my_free_dtab(cmd_base);
  return (new_tab);
}

int		end_alias(int pipe, char **cmd, t_gene *utils)
{
  if (pipe != 2 || (strcmp(cmd[0], "emacs") == 0))
    return (exec(cmd, utils));
  else
    return (exec_check_pipe(cmd, utils));
  return (0);
}

int		exec_alias(char **cmd, t_gene *utils, int pipe)
{
  t_list	*tmp;
  t_alias	*data;
  char		**new_cmd;

  utils->val.i = 0;
  new_cmd = cmd;
  tmp = utils->alias;
  utils->time = count_elems_on_list(&tmp) + 1;
  while (--utils->time != 0)
    {
      tmp = utils->alias;
      while (tmp != NULL && pipe >= 1)
	{
	  data = tmp->data;
	  if (strcmp(data->name, new_cmd[0]) == 0)
	    if ((new_cmd = cpy_dchar(new_cmd, data->cmd, pipe)) == NULL)
	      return (-2);
	  tmp = tmp->next;
	  utils->val.i++;
	}
    }
  return (end_alias(pipe, new_cmd, utils));
}
