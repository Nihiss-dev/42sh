##
## Makefile for my_list in /home/chardo_j/exercices/list
## 
## Made by Julien Chardon
## Login   <chardo_j@epitech.net>
## 
## Started on  Wed May 14 02:35:00 2014 Julien Chardon
## Last update Sun Jun  8 21:45:10 2014 NicolasOVEJERO
##

NAME	= my_list.a

AR	= ar rc

RM	= rm -f

CC	= gcc -Iinclude/

SRC	= src/add_elem.c		\
	  src/count_elems.c		\
	  src/del_elem.c		\
	  src/del_list.c		\
	  ../getnextline/my_gnl.c 	\

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
