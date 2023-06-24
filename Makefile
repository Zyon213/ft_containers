STDNAME = std_container
FTNAME = ft_container
CXX = c++
FLAG = -Wall -Werror -Wextra -std=c++98
RM = rm -f
DIR = tester
STD_NS = -D NAMESPACE=std
FT_NS = -D NAMESPACE=ft
FILE = main.cpp
SFILE = 
OBJ_DIR = object
OBJ_STD = std_object
OBJ_FT = ft_object

RED ='\033[0;31m'
GREEN ='\033[0;32m'
BLUE ='\033[0;34m'
WHITE ='\033[1;37m'

OBJS_STD = $(addprefix $(OBJ_DIR)/$(OBJ_STD)/, $(FILE:%cpp=%o))
OBJS_FT = $(addprefix $(OBJ_DIR)/$(OBJ_FT)/, $(FILE:%cpp=%o))

$(OBJ_DIR)/$(OBJ_STD)/%.o : $(DIR)/$(FILE)
	@mkdir -p $(OBJ_DIR)/$(OBJ_STD)
	$(CXX) $(FLAG) $(STD_NS) -c $< -o $@
	@ echo $(GREEN) "std objects file created" $(WHITE)

$(OBJ_DIR)/$(OBJ_FT)/%.o : $(DIR)/$(FILE)
	@mkdir -p $(OBJ_DIR)/$(OBJ_FT)
	$(CXX) $(FLAG) $(FT_NS) -c $< -o $@
	@ echo $(GREEN) "ft objects file created" $(WHITE)

all: $(FTNAME) $(STDNAME)

$(FTNAME): $(OBJS_FT)
	$(CXX) $(FLAG) $(OBJ_DIR)/$(OBJ_FT)/main.o -o $(FTNAME)
	@ echo $(BLUE) "ft container created" $(WHITE)

$(STDNAME): $(OBJS_STD)
	$(CXX) $(FLAG) $(OBJ_DIR)/$(OBJ_STD)/main.o -o $(STDNAME)
	@ echo $(BLUE) "std container created" $(WHITE)


clean:
	$(RM) -r $(OBJ_STD) $(OBJ_FT) $(OBJ_DIR)
	@ echo $(RED) "Object files cleaned" $(WHITE)

fclean: clean
	$(RM) $(FTNAME) $(STDNAME)
	@ echo $(RED) "Container files cleaned" $(WHITE)

re : fclean all

PHONY : re fclean all std ft