# ============================================================================#
# 									Makefile								  #
# ============================================================================#

# --- Couleurs ANSI -----------------------------------------------------------
RED   := \033[0;31m
GREEN := \033[0;32m
YELLOW:= \033[0;33m
BLUE  := \033[0;34m
NC    := \033[0m # No Color

# --- Configuration -----------------------------------------------------------
NAME   := push_swap
CC     := cc
CFLAGS := -Wall -Wextra -Werror -g $(INCDIR)
AR     := ar rcs

# --- Chemins -----------------------------------------------------------------
SRCDIR := src
INCDIR := header
OBJDIR := obj
LIBDIR := libft
LIBNAME:= libft.a
LIB    := $(LIBDIR)/$(LIBNAME)

# --- Sources et objets -------------------------------------------------------
SRCS :=	src/main.c \
		src/pars/ft_pars.c \
		src/pars/ft_pars_utils.c \
		src/pars/ft_pars_tool.c \
		src/Lis/lis.c \
		src/Lis/lis_utils.c \
		src/moves/push.c \
		src/moves/rotate.c \
		src/moves/rrotate.c \
		src/moves/swap.c \
		src/moves/aply.c \
		src/turc/turc.c \
		src/turc/math.c \
		src/mini_sort/mini_sort.c \
		src/mini_sort/mini_sort_utils.c \
		src/init_b.c \


OBJS := $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# --- Commandes utiles --------------------------------------------------------
LIBMAKE := $(MAKE) --no-print-directory -C $(LIBDIR)
RM      := rm -rf
MKDIR   := mkdir -p

# --- Phony targets -----------------------------------------------------------
.PHONY: all clean fclean re libs libclean help

# --- Règles ------------------------------------------------------------------
all: libs $(NAME)

$(NAME): $(OBJS) $(LIB)
	@printf "$(BLUE)🔗 Linking $@...$(NC)\n"
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBDIR) -l:$(LIBNAME) -o $@
	@printf "$(GREEN)✅ Built $@$(NC)\n"

libs:
	@printf "$(BLUE)📦 Building library in $(LIBDIR)...$(NC)\n"
	@$(LIBMAKE)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(MKDIR) $(dir $@)
	@printf "$(YELLOW)🔨 Compiling $< -> $@$(NC)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "$(RED)🧹 Cleaning objects...$(NC)\n"
	@$(RM) $(OBJDIR)

libclean:
	@printf "$(RED)🧹 Cleaning lib in $(LIBDIR)...$(NC)\n"
	@$(LIBMAKE) clean

fclean: clean libclean
	@printf "$(RED)🗑️ Removing binary $(NAME) and library $(LIBNAME)...$(NC)\n"
	@$(RM) $(NAME) $(LIB)

re: fclean all

run: re
	$(shell valgrind --show-leak-kinds=all --leak-check=full ./push_swap 1 4 2 3)

help:
	@echo "$(BLUE)=== Makefile Help ===$(NC)"
	@echo "$(BLUE)NAME:$(NC) $(NAME)"
	@echo "$(BLUE)SRCS:$(NC) $(SRCS)"
	@echo "$(BLUE)OBJS:$(NC) $(OBJS)"
	@echo "$(BLUE)LIB:$(NC) $(LIB)"
