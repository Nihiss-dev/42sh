/*
** my_str_to_wordtab_cust.c for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/tmp_work/gene
**
** Made by ovejer_n
** Login   <ovejer_n@epitech.net>
**
** Started on  Tue May 13 08:17:31 2014 ovejer_n
** Last update Tue Jun 10 21:20:23 2014 NicolasOVEJERO
*/

#include "gene.h"

int	count_word_cust(char *str)
{
  int	i;
  int	n;

  i = 0;
  n = 1;
  while (str[i] != '\0' && str[i] != '\n')
    {
      if (str[i] == RED_D && str[i + 1] != '\0')
	{
	  n += 2;
	  if (str[i + 1] == RED_D)
	    ++i;
	}
      ++i;
    }
  return (n);
}

int	count_char(char *str)
{
  int	i;

  i = 0;
  while (str[i] && check_sign(str[i]) == 1)
    ++i;
  return (i);
}

int	check_sign(char c)
{
  if (c == RED_D)
    return (0);
  return (1);
}

int	stock_sign(char *str, t_nb  *list, char **tab)
{
  while (str[list->i] && (str[list->i] == ' ' || str[list->i] == '\t'))
    list->i++;
  if ((tab[list->a] = malloc(sizeof(**tab) * 3)) == NULL)
    return (-1);
  while (check_sign(str[list->i]) == 0)
    tab[list->a][list->b++] = str[list->i++];
  tab[list->a][list->b++] = '\0';
  list->b = 0;
  list->a++;
  while (str[list->i] && (str[list->i] == ' ' || str[list->i] == '\t'))
    list->i++;
  return (0);
}

char	**my_str_to_wordtab_cust(char *str)
{
  t_nb	list;
  char	**tab;

  list.i = 0;
  list.a = 0;
  if ((tab = malloc(sizeof(*tab) * ((count_word_cust(str) + 1) * 2))) == NULL)
    return (NULL);
  while (str[list.i] != '\0')
    {
      list.b = 0;
      if (check_sign(str[list.i]) == 0)
	if (stock_sign(str, &list, tab) == -1)
	  return (NULL);
      if ((tab[list.a] = malloc(count_char(str + list.i) + 1)) == NULL)
	return (NULL);
      while (str[list.i] && check_sign(str[list.i]) == 1)
	tab[list.a][list.b++] = str[list.i++];
      tab[list.a][list.b] = '\0';
      list.a++;
    }
  tab[list.a] = NULL;
  return (tab);
}
