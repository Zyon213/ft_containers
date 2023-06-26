NAME = test
CXX = c++
FLAG = -Wall -Werror -Wextra -std=c++98
RM = rm -f
DIR = main_dir
SFILE = 
OBJ_DIR = object
OBJ = objects


FILE = main.cpp

RED ='\033[0;31m'
GREEN ='\033[0;32m'
BLUE ='\033[0;34m'
WHITE ='\033[1;37m'

OBJS = $(addprefix $(OBJ_DIR)/$(OBJ)/, $(FILE:%cpp=%o))

$(OBJ_DIR)/$(OBJ)/%.o : $(DIR)/$(FILE)
	@mkdir -p $(OBJ_DIR)/$(OBJ)
	$(CXX) $(FLAG) -c $< -o $@
	@ echo $(GREEN) "ft main objects file created" $(WHITE)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAG) $(OBJ_DIR)/$(OBJ)/main.o -o $(NAME)
	@ echo $(BLUE) "ft container created" $(WHITE)

clean:
	$(RM) -r $(OBJ) $(OBJ_DIR)
	@ echo $(RED) "Object files cleaned" $(WHITE)

fclean: clean
	$(RM) $(NAME)
	@ echo $(RED) "Container files cleaned" $(WHITE)

re : fclean all

PHONY : re fclean all std ft