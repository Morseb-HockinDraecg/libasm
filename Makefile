SRC_DIR	:= srcs/
INC_DIR	:= inc/
OBJ_DIR	:= obj/
BIN_DIR	:= bin/

NAME	:= $(BIN_DIR)libasm.a
SRC		:= $(SRC_DIR)main.c
SRC_ASM	:= $(SRC_DIR)ft_strlen.s\
	$(SRC_DIR)ft_strcpy.s\
	$(SRC_DIR)ft_strcmp.s\
	$(SRC_DIR)ft_write.s\
	$(SRC_DIR)ft_read.s\
	$(SRC_DIR)ft_strdup.s

OBJ_ASM	:= $(SRC_ASM:$(SRC_DIR)%.s=$(OBJ_DIR)%.o)
OBJ		:= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
INCLUDE	:= -I$(INC_DIR)
LDFLAGS	:=

.PHONY: all clean fclean re
.SILENT:

all: $(NAME)
	$(info "/bin/libasm.a rdy 2 use)
	$(info --------------------------------------------)

$(NAME):  $(OBJ_ASM) | $(BIN_DIR)
	ar rcs $@ $^
	echo "$@ (exec) \033[32mcreated\033[0m"
	echo "--------------------------------------------"

$(OBJ_DIR)%.o: $(SRC_DIR)%.s $(INC_DIR)libasm.h | $(OBJ_DIR)
	nasm -f macho64 $< -o $@
	echo "$@ \033[32mcreated\033[0m"

proj: $(NAME)
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC) $(NAME) -o $(BIN_DIR)exec_libasm
	$(info "/bin/exec_libasm rdy 2 use)

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@
	echo "$(OBJ_DIR) \033[32mdir created\033[0m"

clean:
	$(RM) -rf $(OBJ_DIR)
	echo "$(OBJ_DIR) \033[31mdir deleted\033[0m"

fclean: clean
	$(RM) -rf $(BIN_DIR)
	echo "$(BIN_DIR) \033[31mdir deleted\033[0m"

fclean_re:
	$(RM) -rf $(OBJ_DIR)*.o
	echo "$(OBJ_DIR)*.o \033[31mdeleted\033[0m"
	$(RM) -rf $(BIN_DIR)
	echo "$(BIN_DIR) \033[31mdir deleted\033[0m"
	echo "--------------------------------------------"

re: fclean_re all