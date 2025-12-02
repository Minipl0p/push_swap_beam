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
		src/Lis/lis.c \
		src/Lis/lis_utils.c \
		src/moves/push.c \
		src/moves/rotate.c \
		src/moves/rrotate.c \
		src/moves/aply.c \
		src/turc/turc.c \
		src/turc/math.c \
		src/init_b.c \
		src/a_del.c \


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
	@echo "$(BLUE)🔗 Linking $@...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBDIR) -l:$(LIBNAME) -o $@
	@echo "$(GREEN)✅ Built $@$(NC)"

libs:
	@echo "$(BLUE)📦 Building library in $(LIBDIR)...$(NC)"
	@$(LIBMAKE)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(MKDIR) $(dir $@)
	@echo "$(YELLOW)🔨 Compiling $< -> $@$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)🧹 Cleaning objects...$(NC)"
	@$(RM) $(OBJDIR)

libclean:
	@echo "$(RED)🧹 Cleaning lib in $(LIBDIR)...$(NC)"
	@$(LIBMAKE) clean

fclean: clean libclean
	@echo "$(RED)🗑️ Removing binary $(NAME) and library $(LIBNAME)...$(NC)"
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
