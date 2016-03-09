##
## Makefile for M in /home/delaco_c/rendu/Bistromathique/lib
## 
## Made by benjamin delacour
## Login   <delaco_c@epitech.net>
## 
## Started on  Sat Nov  8 17:04:54 2014 benjamin delacour
## Last update Tue Mar 10 15:26:09 2015 Delacour Benjamin
##

NAME	=	libmy.a

CREATE	=	ar rc

RM	=	rm -f

SRCS	=	my_getnbr.c                    	\
	        my_isneg.c                      \
		my_is_prime.c                   \
	        my_power_rec.c                  \
	        my_putchar.c                    \
	        my_put_nbr.c                    \
	        my_putstr.c                     \
	        my_revstr.c                     \
	        my_showstr.c                    \
	        my_show_wordtab.c               \
	        my_sort_int_tab.c               \
	        my_square_root.c                \
	        my_strcapitalize.c              \
	        my_strcat.c                     \
	        my_strcmp.c                     \
	        my_strcpy.c                     \
	        my_strdup.c                     \
	        my_str_isalpha.c                \
	        my_str_islower.c                \
	        my_str_isnum.c                  \
	        my_str_isprintable.c            \
	        my_str_isupper.c                \
	        my_strlen.c                     \
	        my_strlowcase.c                 \
	        my_strncat.c                    \
	        my_strncmp.c                    \
	        my_strncpy.c                    \
	        my_strstr.c                     \
	        my_str_to_wordtab.c             \
	        my_strupcase.c                  \
	        my_swap.c			\
		get_next_line.c			\
		my_str_has_char.c		\
		my_is_redirection.c

OBJS	=	$(SRCS:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		@$(CREATE) $(NAME) ../include/my.h $(OBJS)
		@ranlib $(NAME)

clean	:
		@$(RM) $(OBJS)

fclean	:	clean
		@$(RM) $(NAME)

re	:	fclean	all

.PHONY	:	all clean fclean re

.SILENT	:	all clean fclean re $(OBJS) $(NAME)
