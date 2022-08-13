NAME = cub3D

SRCS = 	./getnextline/get_next_line.c ./getnextline/get_next_line_utils.c ./parser/maps_parser.c ./validations/map_validations.c ./utils/utils.c \
		./movement/keyboard_inputs.c ./exit/exit.c ./parser/maps_utils_functions.c mallocs.c player.c inits.c raycast.c time.c validations/map_validations2.c \
		./parser/map_vars_parser.c ./parser/map_vars_parse_functions.c ./parser/map_vars_parse_functions2.c inits2.c \
		./movement/key_mov.c ./movement/check_routes.c raycast2.c map_checks.c draws.c render.c clean_imgs.c ./exit/exit2.c ./exit/exit3.c main.c 
		

SRCSBONUS = main.c ./getnextline/get_next_line.c ./getnextline/get_next_line_utils.c ./bonus/maps_parser.c ./bonus/map_validations.c ./utils/utils.c \
		./bonus/keyboard_inputs.c ./bonus/exit.c ./parser/maps_utils_functions.c mallocs.c player.c ./bonus/inits.c ./bonus/raycast.c time.c validations/map_validations2.c \
		./parser/map_vars_parser.c ./parser/map_vars_parse_functions.c ./parser/map_vars_parse_functions2.c ./bonus/mini_map.c ./bonus/load_gun_imgs.c \
		./bonus/gun_animations.c ./bonus/player_actions.c ./bonus/key_mov.c ./movement/check_routes.c ./bonus/map_checks.c draws.c ./bonus/render.c ./bonus/exit2.c \
		./bonus/init_doors.c ./bonus/doors.c clean_imgs.c ./bonus/free_bonus_extras.c ./bonus/key_mov2.c ./bonus/raycast2.c ./bonus/mini_map2.c ./bonus/exit3.c 


CC = gcc
HEADER = cub3D.h
CFLAGS = -Wall -g -Werror -Wextra -MMD
OBJS = $(SRCS:.c=.o)
OBJSBONUS = ${SRCSBONUS:.c=.o}
DEP = ${SRCS:.c=.d}
DEPBONUS = ${SRCSBONUS:.c=.d}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		@echo "\033[36m"--Compilando--"\033[0m ";
		make -C minilibx
		mv minilibx/libmlx.a .
		${CC} -Wall -g -Werror -Wextra -L. -lmlx -framework OpenGL -framework Appkit $(SRCS) -o $(NAME)
		@clear

all: $(NAME)

-include		${DEP} ${DEPBONUS}

bonus:	${OBJSBONUS}
		@echo "\033[36m"--Compilando Bonus--"\033[0m ";
		make -C minilibx
		mv minilibx/libmlx.a .
		${CC} -Wall -g -Werror -Wextra -L. -lmlx -framework OpenGL -framework Appkit $(SRCSBONUS) -o $(NAME)
		@clear

clean:
		make -C minilibx clean
		rm -rf $(OBJS) $(OBJSBONUS) $(DEP) ${DEPBONUS}
		@clear
		@echo "\033[34m"🗑️\  Todo depurado correctamente  \🗑️"\033[0m"

fclean: clean
		make -C minilibx clean
		rm -rf $(NAME)
		@clear
		@echo "\033[34m"🗑️\  Todo depurado correctamente  \🗑️"\033[0m"

re : fclean all

.PHONY: all clean fclean re

