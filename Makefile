NAME_CLIENT = client
NAME_SERVER = server

#########
RM = rm -f
CC = cc
CFLAGS = -Werror -Wextra -Wall #-g -fsanitize=address
#########

#########
FILES_CLIENT = client

FILES_SERVER = server server_aux

SRC_CLIENT = $(addsuffix .c, $(FILES_CLIENT))

SRC_SERVER = $(addsuffix .c, $(FILES_SERVER))

vpath %.c srcs
#########

#########
OBJ_DIR = objs
OBJ_CLIENT = $(addprefix $(OBJ_DIR)/, $(SRC_CLIENT:.c=.o))
DEP_CLIENT = $(addsuffix .d, $(basename $(OBJ_CLIENT)))
OBJ_SERVER = $(addprefix $(OBJ_DIR)/, $(SRC_SERVER:.c=.o))
DEP_SERVER = $(addsuffix .d, $(basename $(OBJ_SERVER)))
#########

#########
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@${CC} $(CFLAGS) -MMD -c $< -o $@

all:
	@$(MAKE) $(NAME_CLIENT) $(NAME_SERVER) --no-print-directory
	@echo "EVERYTHING DONE✌️   "

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(NAME_SERVER)

# bonus:
# 	@$(MAKE) $(NAME_BONUS) --no-print-directory

clean:
	$(RM) $(OBJ_CLIENT) $(DEP_CLIENT) $(OBJ_SERVER) $(DEP_SERVER) --no-print-directory
	$(RM) -r $(OBJ_DIR) --no-print-directory
	@echo "OBJECTS REMOVED😭   "

fclean: clean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER) --no-print-directory
	@echo "EVERYTHING REMOVED😭   "

re:	fclean all

.PHONY: all clean fclean re

-include $(DEP)

#########
