# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/26 18:52:01 by ulefebvr          #+#    #+#              #
#    Updated: 2016/12/26 18:52:05 by ulefebvr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET_EXEC ?= philo

BUILD_DIR ?= ./build
SRC_DIRS ?= ./srcs
INC_DIR ?= ./includes ./lib/libft/includes

SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c' -or -name '*.s')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(INC_DIR) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS) ./lib/option/includes/ $(HOME)/.brew/include)

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP -Wall -Werror -Wextra

# Extra flags to give to compilers when they are supposed to invoke the linker, ‘ld’, such as -L.
# Libraries (-lfoo) should be added to the LDLIBS variable instead.
LDFLAGS ?= -L ./lib/libft -lft \
			-lpthread \
			-L $(HOME)/.brew/lib -lcsfml-audio -lcsfml-graphics -lcsfml-network \
				-lcsfml-window -lcsfml-system -Wl,-rpath,$(HOME)/.brew/lib/\
			-L ./lib/option -loption

all: $(TARGET_EXEC) $(OBJS)

# $(TARGET_EXEC): $(OBJS)
# 	ar rc $(TARGET_EXEC) $(OBJS)
# 	ranlib $(TARGET_EXEC)

$(TARGET_EXEC): $(OBJS)
	make -C lib/libft
	make -C lib/option
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# assembly
$(BUILD_DIR)/%.s.o: %.s
	$(MKDIR_P) $(dir $@)
	$(AS) $(ASFLAGS) -c $< -o $@

# c source
$(BUILD_DIR)/%.c.o: %.c
	@$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# c++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean fclean re norme

clean:
	make clean -C lib/libft
	make clean -C lib/option
	$(RM) -r $(BUILD_DIR)

fclean: clean
	make fclean -C lib/libft
	make fclean -C lib/option
	$(RM) $(TARGET_EXEC)

re: fclean
	make

norme:
	norminette $(SRC_DIRS) $(INC_DIR)

test:	re
	make -C test

-include $(DEPS)

MKDIR_P ?= mkdir -p
