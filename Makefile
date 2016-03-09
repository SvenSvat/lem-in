##
## Makefile for M in /home/delaco_c/rendu/PSU_2014_minishell1
## 
## Made by benjamin delacour
## Login   <delaco_c@epitech.net>
## 
## Started on  Tue Jan 20 16:09:09 2015 benjamin delacour
## Last update Sun May  3 19:26:27 2015 Adrien Blanquer
##

NAME	=	lem_in

CC	=	gcc

RM	=	rm -f

SRCS	=	main.c			\
		put_pipe.c		\
		get_ants.c		\
		my_put_in_list.c 	\
	  	get_rooms.c		\
		get_stock.c		\
		free_all.c		\
		sort.c			\
		send_ants.c		\
		how_many.c		\
		epur_stock.c		\
		path_duplicate.c	\
		add_start_room.c	\
		check_entry.c		\
		ants_op.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+=	-I ./include
CFLAGS	+=	-Wall -Wextra

LDFLAGS	=	-lmy -L./lib

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		echo ""
		echo "Compilation de la lib..."
		echo "..............................................."
		make -s -C ./lib
		echo "La lib a ete compilee."
		echo "Compilation du programme..."
		echo "..............................................."
		$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)
		echo "Le programme a ete compile sous le nom de lem_in."
		echo "_______________________________________________"

clean	:
		echo "Suppression des fichiers inutiles..."
		echo "..............................................."
		make -s -C ./lib clean
		$(RM) $(OBJS)
		echo "Fichiers inutiles supprimes!"
		echo "_______________________________________________"

fclean	:	clean
		echo ""
		echo "Suppression de l'archive et du programme..."
		echo "..............................................."
		make -s -C ./lib fclean
		$(RM) $(NAME)
		echo "L'archive de la lib et le programme ont ete supprimes!"
		echo "_______________________________________________"

re	:	fclean all

.PHONY	:	all clean fclean re

.SILENT	:	all clean fclean re $(OBJS) $(NAME)
