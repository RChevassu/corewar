NAME = bin
CC = gcc
NAME_LIB = ./libft/libft.a
NAME_COR = corewar
NAME_ASM = asm
FLAG = -Werror -Wextra -Wall
INCLIB = libft/includes/libft.h libft/includes/ft_printf.h
INCCOR = includes/op.h includes/proto.h includes/struc.h
INCASM = includes/asm.h

SRCLIB_PATH = ./libft/
SRCCOR_PATH = ./src/
SRCASM_PATH = ./src_asm/
SRCOP_PATH = ./src/op/

OBJCOR_PATH = ./src/obj
OBJLIB_PATH = ./libft/obj
OBJASM_PATH = ./src_asm/obj
OBJOP_PATH = ./src/obj

LIB_PATH = libft/libft.a

SOURCES_LIB = buffer_management.c ft_itoa.c ft_memcmp.c ft_putchar_fd.c\
ft_strchr.c ft_striteri.c ft_strncmp.c ft_strsplit.c parse.c utils.c ft_atoi.c\
ft_lstadd.c ft_memcpy.c ft_putendl.c ft_strclr.c ft_strjoin.c ft_strncpy.c\
ft_strstr.c ft_bzero.c ft_lstdel.c ft_memdel.c ft_putendl_fd.c ft_strcmp.c\
ft_strjoinf.c ft_strndup.c ft_strsub.c print_char.c ft_isalnum.c ft_lstdelone.c\
ft_memmove.c ft_putnbr.c ft_strcpy.c ft_strlcat.c ft_strnequ.c ft_strtrim.c\
print_float.c ft_isalpha.c ft_lstnew.c ft_memset.c ft_putnbr_fd.c ft_strdel.c\
ft_strlen.c ft_strnew.c ft_swap.c print_int.c ft_isascii.c ft_memalloc.c\
ft_numlen.c ft_putstr.c ft_strdup.c ft_strmap.c ft_strnewc.c ft_tolower.c\
print_unsigned.c ft_isdigit.c ft_memccpy.c ft_printf.c ft_putstr_fd.c\
ft_strequ.c ft_strmapi.c ft_strnstr.c ft_toupper.c print_wchar.c ft_isprint.c\
ft_memchr.c ft_putchar.c ft_strcat.c ft_striter.c ft_strncat.c ft_strrchr.c\
print_wstr.c ft_strjoinfreeguf.c ft_lstiter.c

SOURCES_COR =  utils.c main.c op.c play.c init.c proc.c loop.c dump.c utils2.c

SOURCES_OP = add.c and.c fork.c ld.c ldi.c lfork.c live.c lld.c lldi.c st.c\
sti.c sub.c zjmp.c or.c xor.c aff.c

SOURCES_ASM	= asm.c loading_file.c parsing_head.c ft_lines.c utils.c\
	parsing_code.c ft_getop.c ft_gettype.c parsing_arguments.c ft_creatcor.c \
	parsing_labels.c ft_labels.c \

SRCSLIB = $(addprefix $(SRCLIB_PATH)/, $(SOURCES_LIB))
OBJSLIB = $(addprefix $(OBJLIB_PATH)/, $(SOURCES_LIB:.c=.o))

SRCSCOR = $(addprefix $(SRCCOR_PATH)/, $(SOURCES_COR))
OBJSCOR = $(addprefix $(OBJCOR_PATH)/, $(SOURCES_COR:.c=.o))

SRCSOP = $(addprefix $(SRCOP_PATH)/, $(SOURCES_OP))
OBJSOP = $(addprefix $(OBJOP_PATH)/, $(SOURCES_OP:.c=.o))

SRCSASM = $(addprefix $(SRCASM_PATH)/, $(SOURCES_ASM))
OBJSASM = $(addprefix $(OBJASM_PATH)/, $(SOURCES_ASM:.c=.o))

all: $(NAME)

$(NAME): asm corewar

libft: $(OBJSLIB) $(INCLIB)
	@ar rc $(NAME_LIB) $(OBJSLIB)
	@ranlib $(NAME_LIB)
	@echo "Compilation libft.a OK"

$(OBJLIB_PATH)/%.o: $(SRCLIB_PATH)/%.c $(INCLIB)
	@mkdir -p $(OBJLIB_PATH)
	@$(CC) $(FLAG) -o $@ -c $<

corewar: libft $(OBJSCOR) $(OBJSOP) $(INCCOR)
	@$(CC) $(OBJSCOR) $(OBJSOP) $(LIB_PATH) -o $(NAME_COR) -lncurses
	@echo "Compilation corewar OK"

$(OBJCOR_PATH)/%.o: $(SRCCOR_PATH)/%.c $(INCCOR)
	@mkdir -p $(OBJCOR_PATH)
	@$(CC) $(FLAG) -o $@ -c $<

$(OBJOP_PATH)/%.o: $(SRCOP_PATH)/%.c $(INCCOR)
	@mkdir -p $(OBJOP_PATH)
	@$(CC) $(FLAG) -o $@ -c $<

asm: libft $(OBJSASM) $(INCASM)
	@$(CC) $(OBJSASM) $(LIB_PATH) -o $(NAME_ASM)
	@echo "Compilation asm OK"

$(OBJASM_PATH)/%.o: $(SRCASM_PATH)/%.c $(INCASM)
	@mkdir -p $(OBJASM_PATH)
	@$(CC) $(FLAG) -o $@ -c $<


clean:
	@rm -rf $(OBJASM_PATH) $(OBJCOR_PATH) $(OBJLIB_PATH)

fclean: clean
	@rm -f $(LIB_PATH) $(NAME_COR) $(NAME_ASM)

re: fclean all
