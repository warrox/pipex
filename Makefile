CC = clang
CFLAGS = -std=c99 \
         -MMD \
         -MP \
         -Wall \
         -Wextra \
         -Werror 

NAME := Pipex
SRC_DIRS := src
INC_DIRS := include
BUILD_DIR := .build

# Définition manuelle des fichiers sources
SRCS := src/main.c src/pipex.c

INCS := $(addprefix -I, $(INC_DIRS))
OBJS := $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRCS))
DEPS := $(OBJS:.o=.d)

.PHONY: all re clean fclean
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)     
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

-include $(DEPS)

clean:
	$(RM) -r $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
