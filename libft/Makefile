NAME = libft.a

SRCDIR = src
INCDIR = include
HEADER = $(INCDIR)/libft.h

SOURCES = ft_isalpha.c \
		  ft_isdigit.c \
		  ft_isalnum.c \
		  ft_isascii.c \
		  ft_isprint.c \
		  ft_strlen.c \
		  ft_memset.c \
		  ft_bzero.c \
		  ft_memcpy.c \
		  ft_memmove.c \
		  ft_strlcpy.c \
		  ft_strlcat.c \
		  ft_toupper.c \
		  ft_tolower.c \
		  ft_strchr.c \
		  ft_strrchr.c \
		  ft_strncmp.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_strnstr.c \
		  ft_atoi.c \
		  ft_calloc.c \
		  ft_strdup.c \
		  ft_substr.c \
		  ft_strjoin.c \
		  ft_strtrim.c \
		  ft_split.c \
		  ft_itoa.c \
		  ft_strmapi.c \
		  ft_striteri.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_printf.c \
		  print_char.c \
		  print_str.c \
		  print_ptr.c \
		  print_int.c \
		  print_uint.c \
		  print_hex.c

BSOURCES = ft_lstnew_bonus.c \
		   ft_lstadd_front_bonus.c \
		   ft_lstsize_bonus.c \
		   ft_lstlast_bonus.c \
		   ft_lstadd_back_bonus.c \
		   ft_lstdelone_bonus.c \
		   ft_lstclear_bonus.c \
		   ft_lstiter_bonus.c \
		   ft_lstmap_bonus.c 


SRCS = $(addprefix $(SRCDIR)/,$(SOURCES))
BSRCS = $(addprefix $(SRCDIR)/,$(BSOURCES))
OBJECTS = $(SRCS:.c=.o)
BOBJECTS = $(BSRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror 
CPPFLAGS = -I$(INCDIR)

AR = ar -rcs

RM = rm -f

all: $(NAME)
	@echo "[$(NAME)] ✅ Build complete"

$(NAME) : $(OBJECTS)
	@echo "[$(NAME)] 📦 Creating static library: $(NAME)..."
	@$(AR) $(NAME) $(OBJECTS)
	@echo "[$(NAME)] ✅ $(NAME) created/updated"

bonus: $(NAME) .bonus
	@echo "[$(NAME)] ✅ Bonus complete"

.bonus: $(OBJECTS) $(BOBJECTS)
	@echo "[$(NAME)] 📦 Archiving bonus objects into $(NAME)..."
	@$(AR) $(NAME) $(BOBJECTS)
	@touch .bonus
	@echo "[$(NAME)] ✅ Bonus objects added"

$(SRCDIR)/%.o : $(SRCDIR)/%.c $(HEADER)
	@echo "[$(NAME)] 🛠️ Compiling $<"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	@echo "[$(NAME)] 🧹 Cleaning objects..."
	@$(RM) $(OBJECTS) $(BOBJECTS)
	@$(RM) .bonus
	@echo "[$(NAME)] ✅ Clean done"

fclean: clean
	@echo "[$(NAME)] 🗑️  Removing library..."
	@$(RM) $(NAME)
	@echo "[$(NAME)] ✅ Full clean done"

re:
	@echo "[$(NAME)] ♻️  Rebuilding all..."
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all bonus clean fclean re