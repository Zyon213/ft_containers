CPP = c++
FMNAME = ft_map
SMNAME = std_map
TCMP = exec_time
MAIN = test
TIME = time
STDNAME = std_vector
FTNAME = ft_vector
TNAME = t_vector
FMFILE = tester/ft_map_main.cpp
SMFILE = tester/std_map_main.cpp
STDFILE = tester/std_main.cpp
FTFILE = tester/ft_main.cpp
TEST = tester/test_main.cpp
FFILE = tester/main.cpp
TFILE = tester/time_test.cpp
FTTXT = ft_vector.txt
STDTXT = std_vector.txt
FMAP = ft_map.txt
SMAP = std_map.txt
EXET = tester/map_main.cpp
FLAG = -Wall -Wextra -Werror -std=c++98
FLAG11 = -Wall -Wextra -Werror -std=c++11
DF = diff
RM = rm -f
NS_FT = -D NAMESPACE=ft
NS_STD = -D NAMESPACE=std
TS = tester/name_space.cpp
NSTD = nstd
NFT = nft

ft :
	$(CPP) $(FLAG11) $(NS_FT) $(TS) -o $(NFT)
std :
	$(CPP) $(FLAG11) $(NS_STD) $(TS) -o $(NSTD)
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
exet:
	$(CPP) $(FLAG11) $(EXET) -o $(TCMP)
main:
	$(CPP) $(FLAG) $(FFILE) -o $(MAIN)
time: $(TFILE)
	$(CPP) $(FLAG11) $(TFILE) -o $(TIME)

all: fvec svec smap fmap
cmp_vec: fvec svec
	@ ./$(FTNAME) > $(FTTXT)
	@ ./$(STDNAME) > $(STDTXT)
	@ $(DF) $(FTTXT) $(STDTXT) && echo "SUCCES" || "FAIL"

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
	$(RM) $(TCMP)
	$(RM) $(MAIN)
	$(RM) $(TIME)
	$(RM) $(NSTD)
	$(RM) $(NFT)
leakvec:
	valgrind --leak-check=full -s ./$(FTNAME)
leakmap:
	valgrind --leak-check=full -s ./$(FMNAME)
leaktest:
	valgrind --leak-check=full ./$(TNAME)
.phony: clean fmap smap fvec svec test exet all cmp_vec cmp_map clean leakvec leakmap leaktest
