##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## lib makefile
##

SRC		=		my_compute_power_rec.c		\
				my_compute_square_root.c	\
				my_find_prime_sup.c			\
				my_getnbr.c					\
				my_is_prime.c				\
				my_isneg.c					\
				my_put_nbr.c 				\
				my_putchar.c 				\
				my_putstr.c 				\
				my_revstr.c 				\
				my_sort_int_array.c 		\
				my_str_isalpha.c 			\
				my_str_islower.c 			\
				my_str_isnum.c 				\
				my_str_isprintable.c 		\
				my_str_isupper.c 			\
				my_strcapitalize.c 			\
				my_strcat.c 				\
				my_strcmp.c 				\
				my_strcpy.c 				\
				my_strlen.c 				\
				my_strlowcase.c 			\
				my_strncat.c 				\
				my_strncmp.c 				\
				my_strncpy.c 				\
				my_strstr.c 				\
				my_strupcase.c 				\
				my_swap.c		 			\
				my_int_to_str.c				\
				print_error.c				\
				my_show_word_array.c		\
				my_atoi.c 					\
\
				my_printf/my_printf.c				\
				my_printf/flags_0to4.c				\
				my_printf/flags_bases.c				\
				my_printf/my_put_unsigned_nbr.c		\
\
				CSFML/create_object.c 				\
				CSFML/create_text.c 				\
				CSFML/create_sound.c 				\

OBJ 	= 		$(SRC:.c=.o)

NAME 	=		libmy.a

CFLAGS 	=		-I../../include

all: $(NAME)

$(NAME): 		$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)