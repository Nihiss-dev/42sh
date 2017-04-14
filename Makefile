##
## Makefile for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/tmp_work/myshrc
## 
## Made by NicolasOVEJERO
## Login   <ovejer_n@epitech.net>
## 
## Started on  Sun May 25 06:47:23 2014 NicolasOVEJERO
## Last update Wed Jun 11 11:53:33 2014 NicolasOVEJERO
## Last update Wed Jun 11 12:30:10 2014 
##

NAME		= 42sh

CC		= gcc

CFLAGS		+= -Iinclude/
CFLAGS		+= -g -Wall -Wextra -Werror -O3

RM		= rm -fr

SRC		+= src/util/main.c			\
		   src/util/my_putstr.c			\
		   src/util/my_str_to_wordtab.c		\
		   src/util/my_str_to_wordtab_cust.c	\
		   src/util/my_env.c			\
		   src/util/my_strcat.c			\
		   src/util/util.c			\
		   src/util/m_free.c			\
		   src/util/my_kill.c			\
		   src/util/my_open.c			\
		   src/util/my_str_to_wordtab_cust2.c	\
		   src/util/my_tab.c			\
		   src/util/util2.c			\

SRC		+= src/cmd_pars/check_cmd.c		\
		   src/cmd_pars/my_cmd_pipe.c		\
		   src/cmd_pars/my_pars.c		\
		   src/cmd_pars/my_read.c		\
		   src/cmd_pars/my_cmd.c		\
		   src/cmd_pars/my_cmd2.c		\


SRC		+= src/separateur/my_etet_ouou.c	\
		   src/separateur/my_etet_ouou2.c	\
		   src/separateur/my_semicolon.c	\

SRC		+= src/exec/execve.c			\
		   src/exec/search_fonc.c		\
		   src/exec/execve_pipe.c		\

SRC		+= src/builtin/cd.c			\
		   src/builtin/change.c			\
		   src/builtin/env.c			\
		   src/builtin/setenv.c			\
		   src/builtin/unsetenv.c		\
		   src/builtin/home.c			\
		   src/builtin/my_builtin.c		\
		   src/builtin/echo.c			\
		   src/builtin/yoda.c			\

SRC		+= src/myshrc/my_gnl.c			\
		   src/myshrc/manage_myshrc.c		\
		   src/myshrc/manage_export.c		\
		   src/myshrc/manage_alias.c		\
		   src/myshrc/pars_myshrc.c		\
		   src/myshrc/utils_pars_myshrc.c	\
		   src/myshrc/utils_manage_ea.c		\
		   src/myshrc/my_alias.c		\

SRC		+= src/red_pipe/chevg.c			\
		   src/red_pipe/chevg2.c		\
		   src/red_pipe/chevd.c			\
		   src/red_pipe/dchevg.c		\
		   src/red_pipe/dchevg2.c		\
		   src/red_pipe/my_chev.c		\
		   src/red_pipe/my_pipe.c		\

OBJ		= $(SRC:.c=.o)

MY_LIST		= libs/my_list/my_list.a

LIBS		= $(MY_LIST)

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(CC) -o $(NAME) $(OBJ) $(LIBS)

clean:
		$(RM) $(OBJ)
		@$(RM) .red_file
		@$(RM) .history

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
