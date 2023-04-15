# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 14:09:08 by fcherrie          #+#    #+#              #
#    Updated: 2023/03/27 16:38:38 by gsaile           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADERS		=   "╔══════════════════════════════════════════════════════╗║    42_School Project Cub3D - by fcherrie & gsaile    ║\n╚══════════════════════════════════════════════════════╝\n"
GREEN		=	\e[1;32m
RED			=	\e[1;31m
GRAY		=	\e[1;30m
BLUE_C		= 	\e[1;36m
WHITE		=	\e[1;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m

SRCS		= 	src/display3D.c src/main.c src/map_pars.c src/map_pars2.c src/map_checker.c   \
				src/utils.c src/player.c src/init2.c src/init.c src/radius.c  \
				src/utils2.c src/get_pixel.c

SRCS_B		= 	bonus/display3D.c bonus/main.c bonus/map_pars.c bonus/map_checker.c   \
				bonus/utils.c bonus/player.c bonus/init2.c bonus/init.c bonus/radius.c  \
				bonus/utils2.c bonus/get_pixel.c bonus/get_door.c bonus/display_map.c \
				bonus/init3.c bonus/init4.c \

OBJS		= 	${SRCS:.c=.o}

OBJS_B		= 	${SRCS_B:.c=.o}

NAME		= 	cub3D

.c.o:
			@gcc -Wall -Wextra -Werror -g3 -c $< -o ${<:.c=.o}

all:		${NAME}

bonus:		${OBJS_B}
			@printf "$(_SUCCESS)$(WHITE)╔══════════════════════════════════════════════════════╗\n║    $(BLUE_C)42_School Project Cub3D - by fcherrie & gsaile    $(WHITE)║\n╠══════════════════════════════════════════════════════╣\n$(RESET)"
			@printf "$(_SUCCESS)$(WHITE)║$(WHITE)LIBFT...$(RESET)"
			@${MAKE} -C libft
			@printf "$(_SUCCESS)$(GREEN)OK                                            $(WHITE)║\n$(RESET)"
			@printf "$(_SUCCESS)$(WHITE)║$(WHITE)MLX...$(RESET)"
			@${MAKE} -C .MLX42
			@printf "$(_SUCCESS)$(GREEN)OK                                              $(WHITE)║\n$(RESET)"
			@printf "$(_SUCCESS)$(WHITE)║$(WHITE)CUB_BONUS...$(RESET)"
			@gcc -Wall -Werror -Wextra .MLX42/libmlx42.a libft/libft.a -lm -lglfw -L /Users/${USER}/.brew/opt/glfw/lib/ ${OBJS_B} -o ${NAME}
			@printf "$(_SUCCESS)$(GREEN)OK                                         $(WHITE)║\n$(RESET)"
			@printf "$(_SUCCESS)$(WHITE)╠══════════════════════════════════════════════════════╣\n$(RESET)"
			@printf "$(_SUCCESS)$(WHITE)║            $(WHITE)Launch Cub3D with ./cub3D [map]$(RESET) $(WHITE)          ║\n"
			@printf "$(_SUCCESS)$(WHITE)╚══════════════════════════════════════════════════════╝\n$(RESET)"


${NAME}:	${OBJS}
			@printf "$(_SUCCESS)$(WHITE)╔══════════════════════════════════════════════════════╗\n║    $(BLUE_C)42_School Project Cub3D - by fcherrie & gsaile    $(WHITE)║\n╠══════════════════════════════════════════════════════╣\n$(RESET)"
			@printf "$(_SUCCESS)$(WHITE)║$(WHITE)LIBFT...$(RESET)"
			@${MAKE} -C libft
			@printf "$(_SUCCESS)$(GREEN)OK                                            $(WHITE)║\n$(RESET)"
			@printf "$(_SUCCESS)$(WHITE)║$(WHITE)MLX...$(RESET)"
			@${MAKE} -C .MLX42
			@printf "$(_SUCCESS)$(GREEN)OK                                              $(WHITE)║\n$(RESET)"
			@printf "$(_SUCCESS)$(WHITE)║$(WHITE)CUB...$(RESET)"
			@gcc -Wall -Werror -Wextra .MLX42/libmlx42.a libft/libft.a -lm -lglfw -L /Users/${USER}/.brew/opt/glfw/lib/ ${OBJS} -o ${NAME}
			@printf "$(_SUCCESS)$(GREEN)OK                                              $(WHITE)║\n$(RESET)"
			@printf "$(_SUCCESS)$(WHITE)╠══════════════════════════════════════════════════════╣\n$(RESET)"
			@printf "$(_SUCCESS)$(WHITE)║            $(WHITE)Launch Cub3D with ./cub3D [map]$(RESET) $(WHITE)          ║\n"
			@printf "$(_SUCCESS)$(WHITE)╚══════════════════════════════════════════════════════╝\n$(RESET)"

debug:		${OBJS}
			@${MAKE} -C libft
			@${MAKE} -C .MLX42
			@gcc -Wall -Werror -Wextra -fsanitize=address .MLX42/libmlx42.a libft/libft.a -lm -lglfw -L /Users/${USER}/.brew/opt/glfw/lib/ ${OBJS} -o ${NAME}

debugb:		${OBJS_B}
			@printf "$(_SUCCESS)$(WHITE)╔══════════════════════════════════════════════════════╗\n║    $(BLUE_C)42_School Project Cub3D - by fcherrie & gsaile    $(WHITE)║\n╠══════════════════════════════════════════════════════╣\n$(RESET)"
			@printf "$(_SUCCESS)$(WHITE)║$(WHITE)LIBFT...$(RESET)"
			@${MAKE} -C libft
			@printf "$(_SUCCESS)$(GREEN)OK                                            $(WHITE)║\n$(RESET)"
			@printf "$(_SUCCESS)$(WHITE)║$(WHITE)MLX...$(RESET)"
			@${MAKE} -C .MLX42
			@printf "$(_SUCCESS)$(GREEN)OK                                              $(WHITE)║\n$(RESET)"
			@printf "$(_SUCCESS)$(WHITE)║$(WHITE)CUB_BONUS...$(RESET)"
			@gcc -Wall -Werror -Wextra -fsanitize=address .MLX42/libmlx42.a libft/libft.a -lm -lglfw -L /Users/${USER}/.brew/opt/glfw/lib/ ${OBJS_B} -o ${NAME}
			@printf "$(_SUCCESS)$(GREEN)OK                                         $(WHITE)║\n$(RESET)"
			@printf "$(_SUCCESS)$(WHITE)╠══════════════════════════════════════════════════════╣\n$(RESET)"
			@printf "$(_SUCCESS)$(WHITE)║            $(WHITE)Launch Cub3D with ./cub3D [map]$(RESET) $(WHITE)          ║\n"
			@printf "$(_SUCCESS)$(WHITE)╚══════════════════════════════════════════════════════╝\n$(RESET)"

clean:
			@printf "$(_SUCCESS)$(WHITE)╔══════════════════════════════════════════════════════╗\n$(RESET)"
			@printf "$(_SUCCESS)$(WHITE)║ 		     $(WHITE)Clean Cub3D 		       $(WHITE)║\n$(RESET)"
			@printf "$(_SUCCESS)$(WHITE)╠══════════════════════════════════════════════════════╣\n$(RESET)"
			@rm -f ${OBJS}
			@rm -f ${OBJS_B}
			@printf "$(_SUCCESS)$(WHITE)║$(RED)Cleaning $(WHITE)Cub3D object files...                        $(WHITE)║\n"
			@${MAKE} -C libft clean
			@printf "$(_SUCCESS)$(WHITE)╠══════════════════════════════════════════════════════╣\n$(RESET)"
			@printf "$(_SUCCESS)$(WHITE)║$(RED)Cleaning $(WHITE)libft object files...                        $(WHITE)║\n"
			@${MAKE} -C .MLX42 clean
			@printf "$(_SUCCESS)$(WHITE)╠══════════════════════════════════════════════════════╣\n$(RESET)"
			@printf "$(_SUCCESS)$(WHITE)║$(RED)Cleaning $(WHITE)MLX object files...                          $(WHITE)║\n"
			@printf "$(_SUCCESS)$(WHITE)╚══════════════════════════════════════════════════════╝\n$(RESET)"

fclean:		clean
			@rm -f ${NAME}
			@${MAKE} -C libft fclean
			@${MAKE} -C .MLX42 fclean

re:			fclean all

.PHONY:		all clean flclean re
