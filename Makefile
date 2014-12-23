NAME    = 	avm

SRC		=	main.cpp \
			Operands/Int8.cpp \
			Operands/Int16.cpp \
			Operands/Int32.cpp \
			Operands/Float.cpp \
			Operands/Double.cpp \
			Manager/Manager.cpp \
			Parser/Parser.cpp \
			Stack/Stack.cpp

OBJ    	= $(SRC:.cpp=.o)

CC      = g++

RM      = rm -f

CXXFLAGS  += -Wextra -W -Werror -I Operands/ -I Manager/ -I Parser/ -I Stack/

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)
	$(RM) *~

fclean:	clean
	$(RM) $(NAME)

re: fclean all