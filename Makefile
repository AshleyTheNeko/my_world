##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## file that makes
##

SHELL	=	/bin/sh

CC	=	gcc

MAIN	=	src/main.c

SRC	=	src/utils/render_window_functions.c	\
		src/saves_management/write_save.c	\
		src/saves_management/read_save.c	\
		src/hovering/hovering_display.c		\
		src/init/data_initialization.c		\
		src/init/make_isometric_map.c		\
		src/hovering/hover_actions.c		\
		src/hovering/bar_hovering.c		\
		src/display/draw_iso_map.c		\
		src/events/view_manager.c		\
		src/events/key_actions.c		\
		src/events/bar_actions.c		\
		src/utils/string_utils.c		\
		src/events/event_loop.c			\
		src/init/taskbar_init.c			\
		src/init/texture_init.c			\
		src/hovering/hovering.c			\
		src/init/map_resize.c			\
		src/init/get_lyrics.c			\
		src/display/menu.c			\
		src/free_data.c				\
		src/my_world.c

OBJ	=	$(addsuffix .o, $(basename $(SRC)))

LDFLAGS	=	-L lib/my/ -l my -l csfml-window -l \
		csfml-graphics -l csfml-system -lm

CFLAGS =	-Wall -Wextra

CPPFLAGS=	-I "include/"

OK	=	\e[32m

FAIL	=	\e[91m

T_PRUNE	=

SRC_T	=	tests/unit_tests.c

T_NAME	=	unit_tests

NAME	=	my_world

PHONY	:=	all

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
	CFLAGS += -g
endif

all: $(NAME)

$(NAME): $(SRC) $(MAIN)
	@$(MAKE) -s -C lib/my
	@$(call center_text,$(NAME))
	$(eval OBJ += $(MAIN:.c=.o))
	@$(MAKE) -s $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) && \
	echo -e "$(OK)[DONE]\t$(NAME)\e[0m" || \
	(echo -e "$(FAIL)[FAILURE]\t$(NAME)\e[0m"; $(MAKE) -s fclean)

%.o: %.c
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $< && \
	echo -e "$(OK)[OK]\t$<\e[0m" || \
	(echo -e "$(FAIL)[FAILURE]\t$<\e[0m")

PHONY += rm_prompt
rm_prompt:
	@$(call center_text,Clean)

PHONY += clean
clean: rm_prompt
	@find -name "*.o" -delete
	@echo -e "\e[91m$(NAME) : Removed object files.\e[0m"

PHONY += fclean
fclean: rm_prompt
	@find -name "*.o" -delete
	@rm -f $(NAME)
	@echo -e "\e[91m$(NAME) : Removed object files and $(NAME).\e[0m"

PHONY += tclean
tclean: rm_prompt
	@find ./ -name "*.gcno" -delete -o -name "*.gcda" -delete
	@rm -f $(T_NAME)
	@echo -e "\e[91mTests : Cleaned gc** and ./$(T_NAME).\e[0m"

PHONY += lclean
lclean: rm_prompt
	@$(MAKE) -s -C lib/my fclean

PHONY += fltclean
fltclean: fclean lclean tclean

PHONY += flclean
flclean: fclean lclean

PHONY += re
re: fltclean all

PHONY += tests_run
tests_run: fltclean $(SRC) $(SRC_T)
	@$(MAKE) -s -C lib/my
	@$(call center_text,$(T_NAME))
	@$(eval CFLAGS += --coverage)
	@$(eval LDFLAGS += -l criterion --coverage)
	@$(eval OBJ += $(addsuffix .o, $(basename $(SRC_T))))
	@$(eval OBJ := $(filter-out $(T_PRUNE:.c=.o),$(OBJ)))
	@$(eval SRC := $(filter-out $(T_PRUNE),$(SRC)))
	@$(MAKE) -s $(OBJ) CFLAGS="$(CFLAGS)"
	@$(CC) -o $(T_NAME) $(OBJ) $(LDFLAGS) && \
	(echo -e "$(OK)[DONE]\t$(T_NAME)\e[0m";\
	echo -e "$(OK)[EXECUTING TESTS]\e[0m"; ./$(T_NAME)) || \
	(echo -e "$(FAIL)[FAILURE]\t$(T_NAME)\e[0m"; $(MAKE) -s fltclean)

.PHONY: $(PHONY)