# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ubeetroo <ubeetroo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/20 16:45:36 by ubeetroo          #+#    #+#              #
#    Updated: 2021/12/28 22:27:59 by ubeetroo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

PATH_LIBFT = ./libft/

PATH_MLX = ./minilibx/

LIBFT = $(PATH_LIBFT)libft.a

MLX = $(PATH_MLX)libmlx.a

FSRCS = ft_openwindow \
		ft_line \
		ft_line_utils\
		ft_readmap \
		ft_draw \
		ft_draw_utils \
		ft_hooks \
		ft_rotate \
		ft_errors \
		ft_inits \
		ft_handlers \

FSRCS_B = ft_openwindow_bonus \
		ft_line_bonus \
		ft_line_utils_bonus \
		ft_readmap_bonus \
		ft_draw_bonus \
		ft_draw_utils_bonus \
		ft_hooks_bonus \
		ft_rotate_bonus \
		ft_errors_bonus \
		ft_inits_bonus \
		ft_handlers_bonus \
		# matrix_utils

FSRC = $(addsuffix .c, $(FSRCS))

FSRC_B = $(addsuffix .c, $(FSRCS_B))

FOBJ = $(addsuffix .o, $(FSRCS))

FOBJ_B = $(addsuffix .o, $(FSRCS_B))

D = $(addsuffix .d, $(FSRCS))

D_BONUS = $(addsuffix .d, $(FSRCS_B))

COMP = gcc

FINC = fdf.h 

FINC_B = fdf_bonus.h

all: $(LIBFT) $(MLX) $(NAME) $(FINC) Makefile

include 		$(wildcard $(D) $(D_BONUS))

%.o : %.c 
	$(COMP) -Wall -Werror -Wextra -Imlx -Im -I$(FINC) -c $< -o $@ 

$(NAME): $(FOBJ) $(LIBFT) $(MLX)
	$(COMP)  -lmlx -framework OpenGL -framework AppKit $(FOBJ) $(LIBFT) $(MLX) -o $(NAME)
	mv fdf ../

$(LIBFT):
	make -C $(PATH_LIBFT)

$(MLX):
	make -C $(PATH_MLX)

bonus:
	@make FSRC="$(FSRC_B)" FOBJ="$(FOBJ_B)" FINC="$(FINC_B)" all	

clean:
	rm -f $(FOBJ) $(FOBJ_B)
	make -C $(PATH_LIBFT) fclean
	make -C $(PATH_MLX) clean

fclean: clean
	rm -f ../$(NAME)

re: fclean all

.PHONY: all clean fclean bonus