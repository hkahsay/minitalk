NAME =		minitalk
SRCS = *.c

INCLUDE	=	include	
LIBFT = ./ft_print/libft/libft.a
PRINT  = ./ft_print/libftprintf.a

OBJS = ${SRCS:.c=.o}
RM = rm -f

CC =		gcc
CFLAGS = 			-Wall -Wextra -Werror 

.c.o:		
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS} $(LIBFT) $(PRINT) server client
			

all:		$(NAME)

server:	server.c $(LIBFT) $(PRINT)
		CC $(CFLAG) $(LIBFT) $(PRINT) server.c -o server

client:	client.c $(LIBFT) $(PRINT)
		CC $(CFLAG) $(LIBFT) $(PRINT) client.c -o client

$(LIBFT): 
		make -C ft_print/libft

$(PRINT):
		make -C ft_print/libftprintf


clean:		
			rm -f ${OBJS}

fclean:		clean
			rm -f server client

re:			fclean all

.PHONY:		all clean fclean re  