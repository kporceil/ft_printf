override SRCDIR := srcs/

override BUILDDIR := .build/

override OBJDIR := $(addprefix $(BUILDDIR), objs/)

override DEPDIR := $(addprefix $(BUILDDIR), deps/)

BASENAME := control_utils ft_printf parsing parsing_utils \
			write_utils add_format convert_base unsigned_convert_base \
			add_utils add_format2 alloc_utils

override SRCS := $(addprefix $(SRCDIR), $(addsuffix .c, $(BASENAME)))

override OBJS := $(addprefix $(OBJDIR), $(addsuffix .o, $(BASENAME)))

override DEPS := $(addprefix $(DEPDIR), $(addsuffix .d, $(BASENAME)))

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
