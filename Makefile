NAME		=	fractol
CFLAGS		=	-Wall -Wextra -Werror -O3
MANDATORY	=	./MANDATORY/
BONUS_DIR	=	./BONUS/
CFILES		=	input_control.c  main.c  paint_fractal.c  window_control.c
B_CFILES	=	input_control_bonus.c  main_bonus.c  paint_fractal_bonus.c  window_control_bonus.c
SRC			=	${addprefix $(MANDATORY), $(CFILES)}
OBJ			=	${SRC:.c=.o}
B_SRC		=	${addprefix $(BONUS_DIR), $(B_CFILES)}
B_OBJ		=	${B_SRC:.c=.o}
MINILIB		=	./minilibx-linux/libmlx_Linux.a
MAKELIBX	=	./minilibx-linux/Makefile

ifeq ($(findstring bonus, $(MAKECMDGOALS)), bonus)
	SRC = $(B_SRC)
	B_OBJ = $(B_OBJ)
endif

all: $(NAME)

$(NAME): $(MINILIB) $(OBJ)
	cc $(CFLAGS) $(SRC) -Lminilibx-linux -lmlx_Linux -lX11 -lXext -o $(NAME)

$(OBJ):
	cc $(CFLAGS) ${@:.o=.c} -c -o ${@}

$(MINILIB): $(MAKELIBX)
	$(MAKE) -C ./minilibx-linux

$(MAKELIBX):
	tar -xf minilibx-linux.tgz

clean:
	rm -f $(OBJ) $(B_OBJ)

fclean: clean
	rm -rf ./minilibx-linux $(NAME)

bonus: $(NAME)

re: fclean all

.PHONY: all clean fclean bonus re