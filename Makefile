
NAME = ./wolf3d

FILES = main.c \
        draw.c \
        check.c \
        arrow.c \
        key_hook.c \
		closes.c \
		raicasting.c \
		side.c \

SRC = $(addprefix src/,$(FILES))

OBJ = $(addprefix obj/,$(FILES:.c=.o))

LIB = libft/libft.a


all : $(NAME)

$(NAME) : $(OBJ) inc
	@make -C libft/
	@gcc -g -o $(NAME) $(OBJ) $(LIB) -lmlx -framework OpenGL -framework AppKit

obj/%.o: src/%.c
	@mkdir -p obj/
	@gcc $(FLAGS) -Iinc -o $@ -c $<

clean :
	@make clean -C libft/
	@rm -rf obj/

fclean : clean
	@make fclean -C libft
	@rm -f $(NAME)

re : fclean all