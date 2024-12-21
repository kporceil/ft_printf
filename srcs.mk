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
