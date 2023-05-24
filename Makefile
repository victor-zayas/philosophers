# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 19:16:20 by vzayas-s          #+#    #+#              #
#    Updated: 2023/05/24 15:01:53 by vzayas-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# RULES #

# NAME #
NAME = philosophers

# FLAGS #
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -pthread -fsanitize=thread
RM = /bin/rm -rf

# INCLUDES #
INCDIR = includes/
INCLUDES = $(INCDIR)

# OBJS #
OBJS = $(SRCS:.c=.o)

OBJDIR := objs/
SRCDIR := src/

# SRC #
SRCS =	philo.c	\
		utils.c \
		initialize.c \

SRC := $(addprefix $(SRCDIR), $(SRCS))
OBJS := $(addprefix $(OBJDIR), $(OBJS))

# MAKEFILE ART #
# COLORS #
BLACK=\033[0;30m
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
MAG=\033[0;35m
CYAN=\033[0;36m
WHITE=\033[0;37m
PAPYRUS=\033[38;5;223m
END=\033[0m

define PHILO
$(PAPYRUS)

$(END)
endef
export PHILO

# COMPILATION #
.SILENT:

all: $(NAME) $(INCLUDES)

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $^ -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)
#	open The_file/philosophers.jpeg
	echo "$(BLUE)༺ library created༻$(END)"
#	echo "$$PHILO"

clean:
	rm -rf $(OBJDIR)
	$(RM) $(OBJS)
	echo "$(RED)༺ Objs deleted༻$(END)"

fclean: clean
	$(RM) $(NAME)
		echo "$(YELLOW)༺ Executable deleted༻$(END)"

re: fclean all

.PHONY: all clean fclean re

####### TOTALMENTE INNECESARIO #######
#ifeq ($(USER), $(filter $(USER), "intra_user"))
#		echo $$"TEXT" (Variable de entorno a exportar)
#		osascript -e "set Volume 10" (ajustar el volumen del ordenador)
#		say --voice="Luciana" rellenar con mensaje. (reproduce el mensaje en el idioma seleccionado)
#endif
####### 	  NO BORRAR		   #######