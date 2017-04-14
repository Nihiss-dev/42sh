/*
** manage_export.c for myshrc in /home/chardo_j/exercices/42shrc
** 
** Made by Julien Chardon
** Login   <chardo_j@epitech.net>
** 
** Started on  Fri May 16 06:33:03 2014 Julien Chardon
** Last update Tue Jun 10 06:58:19 2014 NicolasOVEJERO
*/

#include	"gene.h"

static int	find_var(char **env, char *name)
{
  int		i;
  int		len;

  i = -1;
  len = strlen(name);
  while (env[++i] != NULL)
    if (strncmp(env[i], name, len) == 0)
      return (1);
  return (0);
}

static int	replace_var(char **env, char *name, char *val)
{
  char		*new_val;
  int		len;
  int		i;

  if ((new_val = malloc(sizeof(char) *
			(strlen(name) + strlen(val) + 2))) == NULL)
    return (EXIT_FAILURE);
  new_val = create_new_val(new_val, name, val);
  i = 0;
  len = strlen(name);
  while (strncmp(env[i], name, len) != 0)
    ++i;
  free(env[i]);
  env[i] = new_val;
  return (EXIT_SUCCESS);
}

static int	create_var(t_gene *util, char *name, char *val)
{
  char		**ptr_tmp;
  char		*new_val;
  int		i;

  if ((new_val = malloc(sizeof(char)
			+ (strlen(name) + strlen(val) + 2))) == NULL)
    return (EXIT_FAILURE);
  new_val = create_new_val(new_val, name, val);
  i = 0;
  while (util->env[i] != NULL)
    ++i;
  if ((ptr_tmp = realloc(util->env, sizeof(char *) * (i + 2))) == NULL)
    {
      free(new_val);
      return (EXIT_FAILURE);
    }
  util->env = ptr_tmp;
  util->env[i] = new_val;
  util->env[i + 1] = NULL;
  return (EXIT_SUCCESS);
}

int		manage_export(t_gene *util, char *str)
{
  char		*name;
  char		*val;

  if (init_name_val(&name, &val, str) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (find_var(util->env, name) == 1)
    {
      if (replace_var(util->env, name, val) == EXIT_FAILURE)
	{
	  free_two_str(name, val);
	  return (EXIT_FAILURE);
	}
    }
  else
    {
      if (create_var(util, name, val) == EXIT_FAILURE)
	{
	  free_two_str(name, val);
	  return (EXIT_FAILURE);
	}
    }
  free_two_str(name, val);
  return (EXIT_SUCCESS);
}
