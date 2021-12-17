# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ababa <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 19:55:20 by ababa             #+#    #+#              #
#    Updated: 2021/12/17 20:13:16 by ababa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS =-Wall -Werror -Wextra

SERVER = server.c minitalk_utils.c

SERVER_BONUS = server_bonus.c minitalk_utils_bonus.c

CLIENT = client.c minitalk_utils.c

CLIENT_BONUS = client_bonus.c minitalk_utils_bonus.c

NAME = server client

NAME_BONUS = server_bonus client_bonus

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SERVER) -o server
	$(CC) $(FLAGS) $(CLIENT) -o client

bonus: $(NAME_BONUS)

$(NAME_BONUS):
	$(CC) $(FLAGS) $(SERVER_BONUS) -o server_bonus
	$(CC) $(FLAGS) $(CLIENT_BONUS) -o client_bonus

re: fclean all

re_bonus: clean bonus

fclean: clean
	rm -f $(NAME)
clean:
	rm -f $(NAME_BONUS)
