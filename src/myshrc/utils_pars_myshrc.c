/*
** utils_pars_myshrc.c for myshrc in /home/chardo_j/exercices/42shrc/src
** 
** Made by Julien Chardon
** Login   <chardo_j@epitech.net>
** 
** Started on  Fri May 16 02:40:28 2014 Julien Chardon
** Last update Tue Jun 10 06:59:36 2014 NicolasOVEJERO
*/

#include	<string.h>
#include	"myshrc.h"

static int	is_ok(char *line)
{
  int		i;
  int		flag;

  i = -1;
  flag = 0;
  while (line[++i] != '\0')
    {
      if (line[i] == '=' && i > 0)
	flag = 1;
    }
  return (((flag) ? 1 : 0));
}

int		is_export(char *line)
{
  if (strncmp(line, EXPORT, LEN_EXPORT) == 0 && is_ok(line + 7))
    return (1);
  return (0);
}

int		is_alias(char *line)
{
  if (strncmp(line, ALIAS, LEN_ALIAS) == 0 && is_ok(line + 6))
    return (1);
  return (0);
}

int		is_commentary_or_empty(char *line)
{
  int		i;

  i = 0;
  while (line[i] != '\0')
    {
      if (line[i] != ' ' && line[i] != '#')
	return (0);
      else if (line[i] == '#')
	return (1);
      ++i;
    }
  return (1);
}
