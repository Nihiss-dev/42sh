/*
** history.c for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/src/history
** 
** Made by NicolasOVEJERO
** Login   <ovejer_n@epitech.net>
** 
** Started on  Sun Jun  8 22:15:42 2014 NicolasOVEJERO
** Last update Mon Jun  9 22:08:05 2014 Alexis Feldmar
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "read.h"

int	open_history(t_gene *utils)
{
  if ((utils->hist.fd = open(".history", O_CREAT | O_TRUNC | O_RDWR,
			     S_IRWXU | S_IRWXG | S_IRWXO)) == -1)
    {
      perror("open");
      return (-1);
    }
  return (0);
}

int	put_in_history(t_gene *utils, char *cmd)
{
  int	div;
  char	c;
  int	i;

  div = 10000;
  i = 1;
  ++utils->hist.nb_cmd;
  while (div > 1)
    {
      i = div / 10;
      c = ((utils->hist.nb_cmd % div) / i) + 48;
      write(utils->hist.fd, &c, 1);
      div /= 10;
    }
  write(utils->hist.fd, "\t", 1);
  write(utils->hist.fd, cmd, strlen(cmd));
  write(utils->hist.fd, "\n", 1);
  return (0);
}

int	my_history(char __attribute__((__unused__)) **cmd, t_gene *utils)
{
  int	i;
  int	fd;
  char	*str;

  i = 0;
  if ((fd = open(utils->hist.path_hist, O_RDONLY)) == -1)
    return (-1);
  while ((str = get_next_line_h(fd)))
    {
      if (i != 0)
	write(1, "\n", 1);
      write(1, str, strlen(str));
      free(str);
      ++i;
    }
  return (0);
}

int	history_down(t_gene *utils)
{
  int	i;
  int	fd;
  char	*str;

  i = 0;
  memset(&utils->hist.cmd, 0, 4096);
  if ((fd = open(utils->hist.path_hist, O_RDONLY)) == -1)
    return (-1);
  if (utils->hist.num_cmd > 0 && utils->hist.num_cmd <= utils->hist.nb_cmd)
    {
      while (i != utils->hist.num_cmd)
	{
	  str = get_next_line_h(fd);
	  free(str);
	  i++;
	}
      str = get_next_line_h(fd);
      write(1, str + 5, strlen(str + 5));
      utils->hist.cmd = strdup(str + 5);
      free(str);
    }
  utils->hist.num_cmd++;
  return (1);
}

int	history_up(t_gene *utils)
{
  int	i;
  int	fd;
  char	*str;

  i = 0;
  memset(&utils->hist.cmd, 0, 4096);
  if ((fd = open(utils->hist.path_hist, O_RDONLY)) == -1)
    return (-1);
  if (utils->hist.num_cmd > 0)
    {
      while (i != utils->hist.num_cmd - 1)
	{
	  str = get_next_line_h(fd);
	  free(str);
	  i++;
	}
      str = get_next_line_h(fd);
      write(1, str + 5, strlen(str + 5));
      utils->hist.cmd = strdup(str + 5);
      free(str);
    }
  utils->hist.num_cmd--;
  return (1);
}
