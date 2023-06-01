CPP = c++
STDFILE = std_main.cpp
FTFILE = ft_main.cpp
TEST = test_main.cpp
STDNAME = std_vector
FTNAME = ft_vector
TNAME = t_vector
FTTXT = ft_vector.txt
STDTXT = std_vector.txt
FLAG = -Wall
# FLAG11 = -Wall -Wextra -Werror -std=c++98

DF = diff
RM = rm -f

ft:
	$(CPP) $(FLAG) $(FTFILE) -o $(FTNAME)
std:
	$(CPP) $(FLAG) $(STDFILE) -o $(STDNAME)
test:
	$(CPP) $(FLAG) $(TEST) -o $(TNAME)

all: ft std
compare:
	@ ./$(FTNAME) > $(FTTXT)
	@ ./$(STDNAME) > $(STDTXT)
	@ $(DF) $(FTTXT) $(STDTXT)
clean:
	$(RM) $(NAME)
	$(RM) $(FTNAME)
	$(RM) $(FTTXT)
	$(RM) $(STDNAME)
	$(RM) $(STDTXT)
	$(RM) $(TNAME)
leakft:
	valgrind --leak-check=full -s ./$(FTNAME)
leakstd:
	valgrind --leak-check=full ./$(STDNAME)
leaktest:
	valgrind --leak-check=full ./$(TNAME)
.phony: clean compare all ft std test
