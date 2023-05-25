CPP = c++
FILE = main.cpp
NAME = vector
RM = rm -f
all:
	$(CPP) $(FILE) -o $(NAME)
clean:
	$(RM) $(NAME)