# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 19:16:20 by vzayas-s          #+#    #+#              #
#    Updated: 2023/05/01 20:46:44 by vzayas-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# RULES #

# NAME #
NAME = philosophers

# FLAGS #
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread -g3 #$-fsanitize=address
RM = /bin/rm -rf

# INCLUDES #
LIBFTDIR = Libft_extended/

INCDIR = includes/philosophers.h
INCLUDES = -I $(INCDIR)

# OBJS #
OBJS = $(SRCS:.c=.o)

OBJDIR := objs/
SRCDIR := src/

# SRC #
SRCS = philo.c	\

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
$(MAG)
    ____  __  ________    ____  _____ ____  ____  __  ____________  _____
   / __ \/ / / /  _/ /   / __ \/ ___// __ \/ __ \/ / / / ____/ __ \/ ___/
  / /_/ / /_/ // // /   / / / /\__ \/ / / / /_/ / /_/ / __/ / /_/ /\__ \ 
 / ____/ __  // // /___/ /_/ /___/ / /_/ / ____/ __  / /___/ _, _/___/ / 
/_/   /_/ /_/___/_____/\____//____/\____/_/   /_/ /_/_____/_/ |_|/____/  
$(END)
endef
export PHILO

# COMPILATION #
.SILENT:

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $@

$(NAME): $(OBJS)
	make -C $(LIBFTDIR) all
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTDIR)/libft.a -o $^ $(NAME)
	open The_file/philosophers.jpeg
	echo "$(BLUE)༺ library created༻$(END)"
	echo "$$PHILO"
	close philosophers.jpeg

clean:
	make -C $(LIBFTDIR) clean
	rm -rf $(OBJDIR)
	$(RM) $(OBJS)
	echo "$(RED)༺ Objs deleted༻$(END)"

fclean: clean
	make -C $(LIBFTDIR) fclean
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