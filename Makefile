NAME = minirt
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./include -I./libft
LDFLAGS = -lm

SRC_DIR = src
OBJ_DIR = obj

MATRIX_DIR = matrix

SRC = tuple.c tuple_utils.c print_utils.c main.c tuple_math1.c vector_math1.c test_ch1.c 

MATRIX_SRC = matrix.c matrix_math.c matrices.c invert_matrix.c invert_matrix_utils.c

TEST_SRC = test_ch1.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o)) \
$(addprefix $(OBJ_DIR)/$(MATRIX_DIR)/, $(MATRIX_SRC:.c=.o))

LIBFT_DIR= ./libft
LIBFT= ./libft/libft.a
LIBFT_SRC = \
ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_toupper.c ft_tolower.c \
ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
print_string.c print_pointer.c print_number.c print_unsigned.c print_hexa.c ft_printf.c\
ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \

LIBFT_OBJ := $(addprefix $(LIBFT_DIR)/, $(LIBFT_SRC:.c=.o))

all: $(NAME)

$(NAME) :  $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L. $(LIBFT) $(LDFLAGS) -o $(NAME)

bonus: .bonus

.bonus: $(LIBFT) $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -L. $(LIBFT)  $(LDFLAGS) -o $(NAME)
	@touch .bonus

$(LIBFT): $(LIBFT_OBJ)
	make bonus -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/$(MATRIX_DIR)/%.o: $(SRC_DIR)/$(MATRIX_DIR)/%.c
	mkdir -p $(OBJ_DIR)/$(MATRIX_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) .bonus
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all