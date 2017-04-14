/*
** gnl.c for asm in /home/chardo_j/rendu/CPE_2014_corewar/asm_dir/src
** 
** Made by Julien Chardon
** Login   <chardo_j@epitech.net>
** 
** Started on  Sun Nov 17 19:18:17 2013 Julien Chardon
** Last update Sun Jun  8 21:45:47 2014 NicolasOVEJERO
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_gnl.h"

static int	get_strlen(char *str)
{
  int		len;

  len = 0;
  if (str != NULL)
    while(str[len] != '\0')
      ++len;
  return (len);
}

static int	search_end_line(char *save, int *pos)
{
  int		i;

  i = 0;
  *pos = 0;
  while (save[i] != '\0')
    {
      if (save[i] == '\n')
	{
	  *pos = i;
	  return (1);
	}
      ++i;
    }
  return (0);
}

static char	*concat_str(char *save, char *buffer, int n)
{
  char		*res;
  int		len_save;
  int		i;

  i = 0;
  len_save = get_strlen(save);
  if (!(res = malloc(sizeof (char) * (len_save + n + 1))))
    return (NULL);
  if (save != NULL)
    while (save[i] != '\0')
      {
	res[i] = save[i];
	++i;
      }
  free(save);
  res[i + n] = '\0';
  while (n--)
    res[i + n] = buffer[n];
  return (res);
}

static char	*next_line(char **save, int i)
{
  char		*ptr_beg_nl;
  char		*next_line;
  int		j;

  if (!(next_line = malloc(sizeof (char) * (i + 1))))
    return (NULL);
  ptr_beg_nl = next_line;
  while (next_line - ptr_beg_nl < i)
    *next_line++ = *((*save)++);
  *next_line = '\0';
  j = get_strlen(*save);
  if (!(next_line = malloc(sizeof (char) * (j + 1))))
    return (NULL);
  while (**save != '\0')
    *next_line++ = *(++(*save));
  free(*save - (i + j));
  *save = next_line - j;
  return (ptr_beg_nl);
}

char		*get_next_line(const int fd)
{
  static char	*save = NULL;
  char		*buff[2];
  int		i[2];

  if (fd == -1)
    return (NULL);
  if (!(buff[0] = malloc(sizeof (char) * BUFF_SIZE)))
    return (NULL);
  while (save == NULL || (search_end_line(save, &i[0]) == 0))
    {
      buff[1] = NULL;
      if (!(i[1] = read(fd, buff[0], BUFF_SIZE)))
	{
	  buff[1] = save;
	  save = NULL;
	  free(buff[0]);
	  return (buff[1]);
	}
      if (!(save = concat_str(save, buff[0], i[1])))
	return (NULL);
    }
  if (!(buff[1] = next_line(&save, i[0])))
    return (NULL);
  free(buff[0]);
  return (buff[1]);
}
