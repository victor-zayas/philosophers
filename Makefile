# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 19:16:20 by vzayas-s          #+#    #+#              #
#    Updated: 2022/11/15 19:14:26 by vzayas-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME #
NAME = philosophers

# COMPILATION #
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread -g3 #$-fsanitize=address
RM = /bin/rm -rf

# OBJS #
OBJS = $(SRCS:.c=.o)

# SRC #
SRCS = philo.c	\

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

# RULES #
.SILENT:

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	open The_file/philosophers.jpeg
	echo "$(BLUE)༺ library created༻$(END)"
	echo "$$PHILO"

clean: 
	$(RM) $(OBJS)
	echo "$(RED)༺ Objs deleted༻$(END)"

fclean: clean
	$(RM) $(NAME)
		echo "$(YELLOW)༺ Executable deleted༻$(END)"

re: fclean all

.PHONY: all clean fclean re