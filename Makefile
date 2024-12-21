include srcs.mk

NAME := libftprintf.a

CC := cc

CFLAGS := -Wall -Wextra -Werror

CPPFLAGS := -Iincludes

DEPSFLAGS := -MD -MP -MF

AR := ar rcs

MAKEFLAGS += --no-print-directory

.PHONY: all
all:
	@$(MAKE) $(NAME)

-include $(DEPS)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJDIR)%.o: $(SRCDIR)%.c | $(OBJDIR) $(BUILDDIR) $(DEPDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPSFLAGS) $(DEPDIR)$*.d -c $< -o $@ -g3

$(OBJDIR) $(DEPDIR) $(BUILDDIR):
	mkdir -p $@

.PHONY: clean
clean:
	rm -rf $(BUILDDIR)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all
