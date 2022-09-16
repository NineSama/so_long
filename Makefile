NAME =		so_long

SRCS_DIR = srcs/

GNL_DIR = GNL/

SRCS =		main.c 

_DEPS =		so_long.h

INCL =		./includes/

DEPS =		$(patsubst %,$(INCL)/%,$(_DEPS))

OBJS =		${SRCS:.c=.o}

CC =		clang

RM =		rm -f

CFLAGS =	-Wall -Werror -Wextra -g

MLX =		./mlx

MLX_LIB = 	./mlx/libmlx_Linux.a

.c.o:		${DEPS} 
		${CC} ${CFLAGS} -I${INCL} -I${MLX} -g3 -c $< -o ${<:.c=.o}

$(NAME):	${OBJS} $(MLX_LIB)
		${CC} ${CFLAGS}  ${OBJS} -o ${NAME} ${MLX_LIB}\
		-L -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

$(MLX_LIB):
		make -C ${MLX} -j


all:		${NAME}

malloc_test: $(OBJS) $(MLX_LIB)
	$(CC) ${OBJS} $(CFLAGS) -fsanitize=undefined -rdynamic -o $@ ${MLX_LIB} -L. -lmallocator

clean:		
		${RM} ${OBJS}
		make clean -C ${MLX}

fclean:		clean
		${RM} ${NAME}
		${RM} ${NAME} ${MLX_LIB}

re:		fclean
		$(MAKE) all -j

.PHONY:		all clean fclean re
