/*
** my_str_to_wordtab.c for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/src/util
** 
** Made by NicolasOVEJERO
** Login   <ovejer_n@epitech.net>
** 
** Started on  Tue Jun 10 06:50:40 2014 NicolasOVEJERO
** Last update Tue Jun 10 06:50:41 2014 NicolasOVEJERO
*/

#include	"gene.h"

int	my_wordcount(char *str, int c)
{
  int	i;
  int	word;

  i = 0;
  word = 2;
  while (str[i] && str[i] != '\n')
    {
      if (str[i] == c && str[i + 1] != '\0')
        word = word + 1;
      ++i;
    }
  return (word);
}

int	my_countchar(char *str, int c)
{
  int	i;

  i = 0;
  while (str[i] != c && str[i] && str[i] != '\n')
    ++i;
  ++i;
  return (i);
}

int	space(int i, char *str)
{
  while ((str[i] == ' ' || str[i] == '\t') && str[i])
    i++;
  return (i);
}

char	**my_str_to_wordtab(char *str, int c)
{
  char	**tab;
  t_nb	nb;

  if (str == NULL)
    return (NULL);
  nb.a = -1;
  nb.i = ((str[0] == c) ? 1 : 0);
  if ((tab = malloc(sizeof(*tab) * (my_wordcount(str, c) + 1))) == NULL)
    return (NULL);
  while (str[nb.i])
    {
      nb.b = 0;
      if ((str[nb.i] && str[nb.i] == c) || str[nb.i] == '\n')
	nb.i = space(++nb.i, str);
      if ((tab[++nb.a] = malloc(my_countchar(str + nb.i, c))) == NULL)
	  return (NULL);
      while (str[nb.i] != c && str[nb.i] != '\n' && str[nb.i])
	tab[nb.a][nb.b++] = str[nb.i++];
      tab[nb.a][nb.b] = 0;
    }
  tab[nb.a + 1] = NULL;
  return (tab);
}
