/*
** utils_manage_ea.c for myshrc in /opensuse/home/chardo_j/exercices/42shrc
** 
** Made by Julien Chardon
** Login   <chardo_j@epitech.net>
** 
** Started on  Wed May 21 00:59:22 2014 Julien Chardon
** Last update Fri May 23 23:44:15 2014 Julien Chardon
*/

#include <stdlib.h>
#include <string.h>
#include "myshrc.h"

char	*get_ea_name(char *str, int *i)
{
  char	*name;

  *i = 0;
  while (str[*i] != '=' && str[*i] != '\0')
    ++(*i);
  if ((name = malloc(sizeof(char) * (*i + 1))) == NULL)
    return (NULL);
  *i = -1;
  while (str[++(*i)] != '=' && str[*i] != '\0')
    name[*i] = str[*i];
  name[(*i)++] = '\0';
  return (name);
}

char	*get_ea_val(char *str, int i)
{
  char	*val;
  int	j;

  j = i;
  while (str[j] != '\0')
    ++j;
  if ((val = malloc(sizeof(char) * (j - i + 1))) == NULL)
    return (NULL);
  j = 0;
  while (str[i] != '\0')
    val[j++] = str[i++];
  val[j] = '\0';
  return (val);
}

int	init_name_val(char **name, char **val, char *str)
{
  int	i;

  if ((*name = get_ea_name(str, &i)) == NULL)
    return (EXIT_FAILURE);
  if ((*val = get_ea_val(str, i)) == NULL)
    {
      free(*name);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

char	*create_new_val(char *new_val, char *name, char *val)
{
  *new_val = '\0';
  new_val = strcat(new_val, name);
  new_val = strcat(new_val, "=");
  new_val = strcat(new_val, val);
  return (new_val);
}

void	free_two_str(char *s1, char *s2)
{
  free(s1);
  free(s2);
}
