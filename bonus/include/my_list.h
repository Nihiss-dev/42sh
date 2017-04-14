/*
** my_list.h for my_list in /home/chardo_j/exercices/list
** 
** Made by Julien Chardon
** Login   <chardo_j@epitech.net>
** 
** Started on  Wed May 14 00:29:01 2014 Julien Chardon
** Last update Wed May 14 02:45:56 2014 Julien Chardon
*/

#ifndef MY_LIST_H_
# define MY_LIST_H_

typedef struct	s_list t_list;

struct		s_list
{
  void		*data;
  t_list	*next;
};

/*
** add_elem.c
*/
int		add_elem_on_begin(t_list **list, void *data);
int		add_elem_on_end(t_list **list, void *data);
/*
** count_elems.c
*/
int		count_elems_on_list(t_list **list);
/*
** del_elem.c
*/
void		del_elem_on_begin(t_list **list);
void		del_elem_on_end(t_list **list);
/*
** del_list.c
*/
void		del_list(t_list **list);

#endif /* !MY_LIST_H_ */
