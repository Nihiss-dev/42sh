/*
** echo.c for 42sh in /home/feldma_a/rendu/PSU_2013_42sh/tmp_work/builtin
**
** Made by Alexis Feldmar
** Login   <feldma_a@epitech.net>
**
** Started on  Sun Apr 20 14:47:32 2014 Alexis Feldmar
** Last update Sat Jun  7 21:11:03 2014 NicolasOVEJERO
*/

#include "gene.h"

char	*fill_pattern(char *str, char *pattern)
{
  int	i;
  int	j;

  i = 1;
  j = 0;
  if ((pattern = malloc(sizeof(char) * strlen(str))) == NULL)
    return (NULL);
  while (str[i])
    {
      pattern[j] = str[i];
      ++i;
      ++j;
    }
  pattern[j] = 0;
  return (pattern);
}

int	echo_dollar(char **tab, char **env)
{
  char	*pattern;
  int	i;

  i = 0;
  pattern = NULL;
  if ((pattern = fill_pattern(tab[1], pattern)) == NULL)
    return (-1);
  while (env[i])
    {
      if (strncmp(pattern, env[i], strlen(pattern)) == 0)
	printf("%s", env[i] + strlen(pattern) + 1);
      ++i;
    }
  return (0);
}

int	echo_fct(char **echo, t_gene *utils)
{
  int	i;

  i = 0;
  if (echo[1])
    if (echo[1][0] == '$')
      {
	if (echo_dollar(echo, utils->env) == -1)
	  return (-1);
	printf("\n");
      }
    else
      {
	while (echo[++i])
	  {
	    printf("%s", echo[i]);
	    if (echo[i + 1])
	      printf(" ");
	  }
	printf("\n");
      }
  else
    printf("\n");
  return (0);
}
