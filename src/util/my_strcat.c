/*
** my_strcat.c for my_strcat in /home/ovejer_n/rendu/Piscine-C-Jour_07/ex_01
**
** Made by OVEJERO Nicolas
** Login   <ovejer_n@epitech.net>
**
** Started on  Tue Oct  8 11:41:57 2013 OVEJERO Nicolas
** Last update Thu Jun  5 21:22:06 2014 NicolasOVEJERO
*/

# include "gene.h"

char	*my_strcat_pers(char *s1, char *s2, char *s3)
{
  char	*fin;
  int	i;
  int	j;
  int	k;

  j = -1;
  k = -1;
  i = -1;
  if ((fin = malloc(strlen(s1) + strlen(s2) + strlen(s3) + 1)) == NULL)
    return (NULL);
  while (s1[++i] != '\0')
    fin[i] = s1[i];
  while (s2[++j] != '\0')
    fin[i + j] = s2[j];
  while (s3[++k] != '\0')
    fin[i + j + k] = s3[k];
  fin[i + j + k] = 0;
  return (fin);
}
