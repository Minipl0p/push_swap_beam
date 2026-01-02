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
NAME_BONUS   := bonus
CC     := cc
CFLAGS := -Wall -Wextra -Werror -g $(INCDIR)

# --- Chemins -----------------------------------------------------------------
SRCDIR := src
SRCDIR_BONUS := src_bonus
INCDIR := header
OBJDIR := obj
OBJDIR_BONUS := obj_bonus
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
		src/moves/apply.c \
		src/turc/turc.c \
		src/turc/math.c \
		src/mini_sort/mini_sort.c \
		src/mini_sort/mini_sort_utils.c \
		src/init_b.c \

SRCS_BONUS :=	src_bonus/main_bonus.c \
				src_bonus/moves/push_bonus.c \
				src_bonus/moves/rotate_bonus.c \
				src_bonus/moves/rrotate_bonus.c \
				src_bonus/moves/swap_bonus.c \
				src_bonus/pars/ft_pars_bonus.c \
				src_bonus/pars/ft_pars_utils_bonus.c \
				src_bonus/pars/ft_pars_tool_bonus.c \

OBJS := $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
OBJS_BONUS := $(SRCS_BONUS:$(SRCDIR_BONUS)/%.c=$(OBJDIR_BONUS)/%.o)

# --- Commandes utiles --------------------------------------------------------
LIBMAKE := $(MAKE) --no-print-directory -C $(LIBDIR)
RM      := rm -rf
MKDIR   := mkdir -p

# --- Phony targets -----------------------------------------------------------
.PHONY: all clean fclean re libs libclean help bonus

# --- Règles ------------------------------------------------------------------
all: libs $(NAME) $(NAME_BONUS)

$(NAME): $(OBJS) $(LIB)
	@printf "$(BLUE)🔗 Linking $@...$(NC)\n"
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBDIR) -l:$(LIBNAME) -o $@
	@printf "$(GREEN)✅ Built $@$(NC)\n"

$(NAME_BONUS): libs $(OBJS_BONUS) $(LIB)
	@printf "$(BLUE)🔗 Linking $@...$(NC)\n"
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -L$(LIBDIR) -l:$(LIBNAME) -o checker
	@printf "$(GREEN)✅ Built $@$(NC)\n"

libs:
	@printf "$(BLUE)📦 Building library in $(LIBDIR)...$(NC)\n"
	@$(LIBMAKE)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(MKDIR) $(dir $@)
	@printf "$(YELLOW)🔨 Compiling $< -> $@$(NC)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR_BONUS)/%.o: $(SRCDIR_BONUS)/%.c
	@$(MKDIR) $(dir $@)
	@printf "$(YELLOW)🔨 Compiling $< -> $@$(NC)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "$(RED)🧹 Cleaning objects...$(NC)\n"
	@$(RM) $(OBJDIR) $(OBJDIR_BONUS)

libclean:
	@printf "$(RED)🧹 Cleaning lib in $(LIBDIR)...$(NC)\n"
	@$(LIBMAKE) clean

fclean: clean libclean
	@printf "$(RED)🗑️ Removing binary $(NAME) and library $(LIBNAME)...$(NC)\n"
	@$(RM) $(NAME) $(LIB) checker

re: fclean all

run: re
	$(shell valgrind --show-leak-kinds=all --leak-check=full ./push_swap 1 4 2 3)

help:
	@echo "$(BLUE)=== Makefile Help ===$(NC)"
	@echo "$(BLUE)NAME:$(NC) $(NAME)"
	@echo "$(BLUE)NAME_BONUS:$(NC) $(NAME_BONUS)"
	@echo "$(BLUE)SRCS:$(NC) $(SRCS)"
	@echo "$(BLUE)SRCS_BONUS:$(NC) $(SRCS_BONUS)"
	@echo "$(BLUE)OBJS:$(NC) $(OBJS)"
	@echo "$(BLUE)OBJS_BONUS:$(NC) $(OBJS_BONUS)"
	@echo "$(BLUE)LIB:$(NC) $(LIB)"
