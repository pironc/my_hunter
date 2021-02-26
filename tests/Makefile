##
## EPITECH PROJECT, 2020
## Makefile
## File description:
##  makefile
##

TEST_SRC	=		test_my_hunter.c 		\

TEST_OBJ	= 		$(TEST_SRC:.c=.o)

TEST_NAME	=		unit_tests

CFLAGS 		= 		-I../include --coverage -lcriterion

LIB 		=		-L../lib/my -lmy

all: $(TEST_NAME)

$(TEST_NAME): 		$(TEST_OBJ)
		gcc -o $(TEST_NAME) $(TEST_OBJ) $(CFLAGS) $(LIB)
		cp ./unit_tests ../
		rm unit_tests

clean:
		rm -f $(OBJ)
		$(RM) *.gc*
		$(RM) tests/*.o
		$(RM) tests/*.gc*

fclean:		clean
		$(RM) -f $(NAME) *.gc*
		$(RM) -f $(NAME) tests/*.gc*
		$(RM) tests/*.o
		$(RM) *.o
		$(RM) ../lib/my/*.o
		$(RM) unit_tests

re: 	fclean all

.PHONY  : all clean fclean re