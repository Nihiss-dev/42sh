/*
** my_str_to_wordtab_cust2.c for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/tmp_work/gene
** 
** Made by NicolasOVEJERO
** Login   <ovejer_n@epitech.net>
** 
** Started on  Mon May 19 23:44:40 2014 NicolasOVEJERO
** Last update Sun Jun  8 14:40:41 2014 NicolasOVEJERO
*/

#include "gene.h"

int	count_word_dcust(char *str)
{
  int	i;
  int	n;

  i = 0;
  n = 1;
  while (str[i] != '\0' && str[i] != '\n')
    {
      if (str[i] && ((str[i] == '&' && str[i + 1] == '&') ||
		     ((str[i] == '|' && str[i + 1] == '|') &&
		      str[i + 1] != '\0')))
	n += 2;
      i++;
    }
  return (n);
}

int	count_dchar(char *str)
{
  int	i;

  i = 0;
  while (str[i] && check_dsign(str[i], str[i + 1]) == 1)
    i++;
  return (i);
}

int	check_dsign(char c, char c2)
{
  if ((c == '&' && c2 == '&') || (c == '|' && c2 == '|'))
    return (0);
  return (1);
}

int	stock_dsign(char *str, t_nb  *list, char **tab)
{
  while (str[list->i] && (str[list->i] == ' ' || str[list->i] == '\t'))
    list->i++;
  if ((tab[list->a] = malloc(sizeof(**tab) * 3)) == NULL)
    return (-1);
  while (check_dsign(str[list->i], str[list->i + 1])  == 0)
    tab[list->a][list->b++] = str[list->i++];
  tab[list->a][list->b++] = str[list->i++];
  tab[list->a][list->b++] = '\0';
  list->b = 0;
  list->a++;
  while (str[list->i] && (str[list->i] == ' ' || str[list->i] == '\t'))
    list->i++;
  return (0);
}

char	**my_str_to_wordtab_dasp(char *str)
{
  t_nb	list;
  char	**tab;

  list.i = 0;
  list.a = 0;
  if ((tab = malloc(sizeof(*tab) * ((count_word_dcust(str) + 1) * 2))) == NULL)
    return (NULL);
  while (str[list.i] != '\0')
    {
      list.b = 0;
      if (check_dsign(str[list.i], str[list.i]) == 0)
	if (stock_dsign(str, &list, tab) == -1)
	  return (NULL);
      if ((tab[list.a] = malloc(count_dchar(str + list.i) + 1)) == NULL)
	return (NULL);
      while (str[list.i] && check_dsign(str[list.i], str[list.i + 1]) == 1)
	tab[list.a][list.b++] = str[list.i++];
      tab[list.a][list.b] = '\0';
      list.a++;
    }
  tab[list.a] = NULL;
  return (tab);
}
