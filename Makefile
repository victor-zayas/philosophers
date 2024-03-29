# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 19:16:20 by vzayas-s          #+#    #+#              #
#    Updated: 2023/08/30 19:34:24 by vzayas-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# RULES #

# NAME #
NAME = philosophers

# FLAGS #
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address

# INCLUDES #
INCDIR = includes/
INCLUDES = $(INCDIR)

# OBJS #
OBJS = $(SRCS:.c=.o)

OBJDIR := objs/
SRCDIR := src/

# SRC #
SRCS =	main.c			\
		actions.c		\
		create_list.c	\
		init_args.c		\
		print.c			\
		time.c			\
		utils.c			\
		
SRC := $(addprefix $(SRCDIR), $(SRCS))
OBJS := $(addprefix $(OBJDIR), $(OBJS))

# ASCII COLORS #
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

# MAKEFILE ART #
define PHILO
$(PAPYRUS)
   ▄███████▄    ▄█    █▄     ▄█   ▄█        ▄██████▄     ▄████████  ▄██████▄     ▄███████▄    ▄█    █▄       ▄████████    ▄████████    ▄████████ 
  ███    ███   ███    ███   ███  ███       ███    ███   ███    ███ ███    ███   ███    ███   ███    ███     ███    ███   ███    ███   ███    ███ 
  ███    ███   ███    ███   ███▌ ███       ███    ███   ███    █▀  ███    ███   ███    ███   ███    ███     ███    █▀    ███    ███   ███    █▀  
  ███    ███  ▄███▄▄▄▄███▄▄ ███▌ ███       ███    ███   ███        ███    ███   ███    ███  ▄███▄▄▄▄███▄▄  ▄███▄▄▄      ▄███▄▄▄▄██▀   ███        
▀█████████▀  ▀▀███▀▀▀▀███▀  ███▌ ███       ███    ███ ▀███████████ ███    ███ ▀█████████▀  ▀▀███▀▀▀▀███▀  ▀▀███▀▀▀     ▀▀███▀▀▀▀▀   ▀███████████ 
  ███          ███    ███   ███  ███       ███    ███          ███ ███    ███   ███          ███    ███     ███    █▄  ▀███████████          ███ 
  ███          ███    ███   ███  ███▌    ▄ ███    ███    ▄█    ███ ███    ███   ███          ███    ███     ███    ███   ███    ███    ▄█    ███ 
 ▄████▀        ███    █▀    █▀   █████▄▄██  ▀██████▀   ▄████████▀   ▀██████▀   ▄████▀        ███    █▀      ██████████   ███    ███  ▄████████▀  
                                 ▀                                                                                       ███    ███              
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
# open a photo
	open The_file/philosophers.jpeg
# message for compilation finished
	echo "$(BLUE)༺ Program compiled༻$(END)"
# show ascii art with env variable
	echo "$$PHILO"

clean:
	$(RM) -rf $(OBJDIR)
	$(RM) $(OBJS)
	echo "$(RED)༺ Objs deleted༻$(END)"

fclean: clean
	$(RM) $(NAME)
		echo "$(YELLOW)༺ Executable deleted༻$(END)"

re: fclean all

.PHONY: all clean fclean re
