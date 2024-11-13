##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## makefile
##

SRC			=		src/main.c 									\
					src/my_hunter.c 							\
					src/error_handling.c 						\
					src/help_display.c 							\
					src/game_init.c 							\
\
					src/splash_screen/spl_scr.c 				\
					src/splash_screen/spl_scr_init.c 			\
					src/splash_screen/spl_scr_draw.c 			\
					src/splash_screen/spl_scr_keypresses.c 		\
					src/splash_screen/spl_scr_dispose.c 		\
\
					src/menu/menu.c 							\
					src/menu/menu_init.c 						\
					src/menu/menu_init_top_score.c 				\
					src/menu/menu_draw.c 						\
					src/menu/menu_keypresses.c 					\
					src/menu/menu_dispose.c 					\
\
					src/play/play.c 							\
					src/play/play_init.c 						\
					src/play/play_init_dog.c 					\
					src/play/play_init_scene.c 					\
					src/play/play_init_hud.c 					\
					src/play/play_init_duck.c					\
					src/play/play_takeoff.c 					\
					src/play/play_alive_or_dead.c 				\
					src/play/play_dog_anims.c 					\
					src/play/play_shot_checks.c 				\
					src/play/play_game_over.c					\
					src/play/play_draw.c 						\
					src/play/play_duck_status.c		 			\
					src/play/play_duck_movements_left.c 		\
					src/play/play_duck_movements_right.c 		\
					src/play/play_duck_movements_up.c 			\
					src/play/play_duck_redirect.c				\
					src/play/play_duck_death.c 					\
					src/play/play_keypresses.c 					\
					src/play/play_dispose.c 					\

OBJ 		= 		$(SRC:.c=.o)

NAME 		=		my_hunter

CFLAGS 		= 		-Werror -Wextra -Wshadow -W -Wall -I./include

CSFMLflags 	=		-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

LIB 		=		-L./lib/my -lmy

ifeq ($(UNAME_S),Darwin)
	LIB += -L./lib/csfml
endif

all: $(NAME)

$(NAME): 		$(OBJ)
		make -C lib/my/
		gcc -g -o $(NAME) $(OBJ) $(CFLAGS) $(LIB) $(CSFMLflags)

clean:
		$(RM) -f $(OBJ)
		$(RM) *.gc*
		$(RM) tests/*.o
		$(RM) tests/*.gc*
		$(RM) src/*.gc*
		$(RM) src/*.o
		$(RM) lib/my/*.o
		$(RM) lib/my/CSFML/*.o
		$(RM) lib/my/my_printf/*.o
		$(RM) lib/my/my_printf/*.gc*

fclean:		clean
		$(RM) -f $(NAME) *.gc*
		$(RM) -f $(NAME) tests/*.gc*
		$(RM) tests/*.o
		$(RM) *.o
		$(RM) ../lib/my/*.o
		$(RM) unit_tests
		$(RM) my_hunter

re: 	fclean all

test:
		make -C tests/

.PHONY  : all clean fclean re test