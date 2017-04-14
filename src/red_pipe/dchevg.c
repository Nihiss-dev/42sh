/*
** dchevg.c for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/src
** 
** Made by NicolasOVEJERO
** Login   <ovejer_n@epitech.net>
** 
** Started on  Sun May 25 15:28:55 2014 NicolasOVEJERO
** Last update Wed Jun 11 10:58:54 2014 NicolasOVEJERO
*/

#include "gene.h"

char	*my_first(char *first, t_gene *utils)
{
  char	*copy;

  utils->val.i = 0;
  if ((copy = malloc(strlen(first))) == NULL)
    return (NULL);
  utils->val.j = 0;
  while (first[utils->val.i + 1] && strncmp(first + utils->val.i, "<<", 2) != 0)
    copy[utils->val.j++] = first[utils->val.i++];
  copy[utils->val.j] = 0;
  if (copy[utils->val.j - 1] == ' ')
    copy[utils->val.j - 1] = 0;
  utils->val.i = password(first, utils->val.i, utils);
  if (nb_car_spe(first, PIPE) != 0 && strcmp(copy, "cat") == 0)
    return (my_strcat_pers("cat .red_file ", first + utils->val.i, "\0"));
  else
    return (copy);
}

void	dsign_check(char *first, t_val *val)
{
  if (val->ret_pa != 0 && nb_car_spe(first, PIPE) == 0)
    while (first[val->i] && (strncmp(first + val->i, ">", 1) != 0) &&
           (strncmp(first + val->i, DRED_D, 2) != 0))
      val->i++;
  else if (nb_car_spe(first, PIPE) != 0)
    {
      while (first[val->i] && first[val->i] != PIPE)
	val->i++;
      while (first[val->i] && (first[val->i] < 'a' || first[val->i] > 'z') &&
	     (first[val->i] < 'A' || first[val->i] > 'Z'))
	val->i++;
    }
}

char	*other_ddg(char *first, t_gene *utils)
{
  t_val	val;
  char	*copy;

  val.j = 0;
  val.ret_pa = 0;
  val.i = 0;
  val.i = password(first, val.i, utils);
  if ((copy = malloc(strlen(first))) == NULL)
    return (NULL);
  while (first[val.i] && (first[val.i] < 'a' || first[val.i] > 'z') &&
         (first[val.i] < 'A' || first[val.i] > 'Z'))
    val.i++;
  val.ret_pa = nb_car_spe(first, RED_D) + nb_dcar(first, RED_D);
  dsign_check(first, &val);
  while (first[val.i])
    copy[val.j++] = first[val.i++];
  copy[val.j] = 0;
  if (val.ret_pa != 0 && nb_car_spe(first, PIPE) == 0)
    return (my_strcat_pers("cat .red_file ", copy, "\0"));
  else
    return (copy);
}

char	*my_exec_rrchev(char *word, t_gene *utils)
{
  char	*cmd;

  if ((utils->fd_chev = open(".red_file", O_CREAT | O_TRUNC
			     | O_RDWR, S_IRWXU)) == -1)
    return (NULL);
  if (word[0] != RED_G && word[1] != RED_G)
    cmd = my_first(word, utils);
  else
    cmd = other_ddg(word, utils);
  if (nb_car_spe(word, PIPE) != 0 || (strncmp(cmd, "grep", 4) == 0))
    word = my_strcat_pers("cat .red_file ", "|", cmd);
  else if ((strncmp(cmd, "cat", 3) == 0) && (strlen(cmd) == 3))
    word = strdup("cat .red_file");
  else
    word = strdup(epure_end(cmd, strlen(cmd)));
  exec_rrchev(utils);
  free(cmd);
  close(utils->fd_chev);
  return (word);
}

void	exec_rrchev(t_gene *utils)
{
  char	*pass;

  my_putstr(">");
  if ((pass = malloc(400)))
    pass = my_read_chev(pass);
  if (strcmp(pass, utils->pass) != 0)
    {
      write(utils->fd_chev, pass, strlen(pass));
      write(utils->fd_chev, "\n", 1);
      free(pass);
      exec_rrchev(utils);
    }
}
