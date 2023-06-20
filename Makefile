CPP = c++
FMNAME = ft_map
SMNAME = std_map
FMFILE = ft_map_main.cpp
SMFILE = std_map_main.cpp
STDFILE = ../test/std_main.cpp
FTFILE = ../test/ft_main.cpp
TEST = test/test_main.cpp
STDNAME = std_vector
FTNAME = ft_vector
TNAME = t_vector
FTTXT = ft_vector.txt
STDTXT = std_vector.txt
FMAP = ft_map.txt
SMAP = std_map.txt
# FLAG = -Wall
# FLAG = -Wall -Wextra -Werror -std=c++11
FLAG11 = -Wall -Wextra -Werror -std=c++98
DF = diff
RM = rm -f

fmap: 
	$(CPP) $(FLAG) $(FMFILE) -o $(FMNAME)
smap:
	$(CPP) $(FLAG) $(SMFILE) -o $(SMNAME)
fvec:
	$(CPP) $(FLAG) $(FTFILE) -o $(FTNAME)
svec:
	$(CPP) $(FLAG) $(STDFILE) -o $(STDNAME)
test:
	$(CPP) $(FLAG) $(TEST) -o $(TNAME)

all: fvec svec smap fmap
cmp_vec: fvec svec
	@ ./$(FTNAME) > $(FTTXT)
	@ ./$(STDNAME) > $(STDTXT)
	@ $(DF) $(FTTXT) $(STDTXT)

cmp_map: fmap smap
	@ ./$(FMNAME) > $(FMAP)
	@ ./$(SMNAME) > $(SMAP)
	@ $(DF) $(FMAP) $(SMAP) && echo "SUCCES" || echo "FAIL"
clean:
	$(RM) $(NAME)
	$(RM) $(MNAME)
	$(RM) $(FTNAME)
	$(RM) $(FTTXT)
	$(RM) $(STDNAME)
	$(RM) $(STDTXT)
	$(RM) $(TNAME)
	$(RM) $(FMNAME)
	$(RM) $(SMNAME)
	$(RM) $(SMAP)
	$(RM) $(FMAP)
leakvec:
	valgrind --leak-check=full -s ./$(FTNAME)
leakmap:
	valgrind --leak-check=full -s ./$(FMNAME)
leaktest:
	valgrind --leak-check=full ./$(TNAME)
.phony: clean fmap smap fvec svec 
