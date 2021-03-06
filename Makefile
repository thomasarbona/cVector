##
## Makefile for vector in /home/arbona/libs/vector
## 
## Made by Thomas ARBONA
## Login   <thomas.arbona@epitech.eu>
## 
## Staed on  Mon Feb 27 19:41:55 2017 Thomas ARBONA
## Last update Sat Apr 22 21:10:16 2017 Thomas ARBONA
##

SRC	=	src/vector.c	\
		src/mutator.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libvector.a
HNAME	=	vector.h

CFLAGS	=	-I./include -W -Wall -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp $(NAME) ../$(NAME)
		mkdir -p ../../include
		cp ./include/$(HNAME) ../../include/$(HNAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)
		rm -f ../$(NAME)
		rm -f ../../include/$(HNAME)

re:		fclean all
