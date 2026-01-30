NAME = push_swap

SRCDIR = src
INCDIR = include
HEADER = $(INCDIR)/push_swap.h

SOURCES = main.c \
	  parse_and_push.c \
	  parse_utils.c \
	  push_op.c \
	  radix.c \
	  reverse_rotate_op.c \
	  rotate_op.c \
	  simplify_list.c \
	  sort_five.c \
	  sort_four.c \
	  sort_stack.c \
	  sort_three.c \
	  stack_utils.c \
	  swap_op.c

SRCS = $(addprefix $(SRCDIR)/,$(SOURCES))
OBJECTS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I$(INCDIR) -I./libft/include

RM = rm -f

all: $(NAME)
	@echo "[$(NAME)] ✅ Build complete"

$(LIBFT):
	@echo "[$(NAME)] 📦 Building libft..."
	@$(MAKE) -C ./libft
	@echo "[$(NAME)] ✅ libft ready"

$(NAME): $(LIBFT) $(OBJECTS)
	@echo "[$(NAME)] 🔗 Linking executable: $(NAME)..."
	@$(CC) $(OBJECTS) $(LIBFT) -o $(NAME)
	@echo "[$(NAME)] ✅ $(NAME) created/updated"

$(SRCDIR)/%.o : $(SRCDIR)/%.c $(HEADER)
	@echo "[$(NAME)] 🛠️ Compiling $<"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	@echo "[$(NAME)] 🧹 Cleaning objects..."
	@$(MAKE) clean -C ./libft
	@$(RM) $(OBJECTS)
	@echo "[$(NAME)] ✅ Clean done"

fclean: clean
	@echo "[$(NAME)] 🗑️  Removing binary..."
	@$(MAKE) fclean -C ./libft
	@$(RM) $(NAME)
	@echo "[$(NAME)] ✅ Full clean done"

re:
	@echo "[$(NAME)] ♻️  Rebuilding all..."
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re