##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## file that makes
##

SHELL	=	/bin/sh

CC	=	gcc

SRC	=	my_get_more_flags.c	\
		process_result.c	\
		my_strnmodify.c		\
		my_show_octal.c		\
		my_get_flags.c		\
		my_strmodify.c		\
		my_strparse.c		\
		my_hexaptr.c		\
		my_printf.c		\
		my_strcmp.c		\
		my_power.c		\
		my_atoi.c		\
		my_puts.c		\
		my_mem.c		\
		my_len.c		\
		my_bc.c

OBJ	=	$(addsuffix .o, $(basename $(SRC)))

INC	=	-I ../../include

ERRORS	=	-Wall -Wextra -Werror

CPPFLAGS=	$(INC) $(ERRORS)

OK	=	\e[32m

FAIL	=	\e[91m

NAME	=	libmy.a

PHONY	=	all

TXT_SIZE=	20

DEBUG	=	0

define center_text
	printf "\e[92m";
	$(SHELL) -c "printf '=%.0s' \
	{1..$$(($(TXT_SIZE) - $$(awk 'BEGIN{print length("$1")}') / 2))}";
	printf '%s' "$1";
	$(SHELL) -c "printf '=%.0s' \
	{1..$$(($(TXT_SIZE) - $$(awk 'BEGIN{print length("$1")}') / 2 - \
	$$[$$(($$(($$(awk 'BEGIN{print length("$1")}') / 2)) * 2))!=\
	$$(awk 'BEGIN{print length("$1")}')]))}";
	echo -e "\e[0m";
endef

ifeq ($(DEBUG), 1)
	CPPFLAGS += -g
endif

all:	$(NAME)

$(NAME):	$(SRC)
	@$(call center_text,$(NAME))
	@$(MAKE) -s $(OBJ)
	@ar rc $(NAME) $(OBJ) && \
	echo -e "$(OK)[DONE]\t$(NAME)\e[0m" || \
	echo -e "$(FAIL)[FAIL]\t$(NAME)\e[0m"

%.o:	%.c
	@$(CC) $< $(CPPFLAGS) -c -o $@ && \
	echo -e "$(OK)[OK]\t$<\e[0m" || \
	echo -e "$(FAIL)[FAILURE]\t$<\e[0m"

PHONY += clean
clean:
	@rm -rf *.o
	@echo -e "\e[91mLibmy : Removed object files.\e[0m"

PHONY += fclean
fclean:
	@rm -rf *.o
	@rm -rf *.a
	@echo -e "\e[91mLibmy : Removed object files and $(NAME).\e[0m"

PHONY += re
re: fclean all

.PHONY: $(PHONY)
