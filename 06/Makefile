
EXEC=program
SRC=main.c prout.c
OBJ=$(SRC:.c=.o)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c $< -o $@
	
clean: 
	$(RM) -f *.o $(EXEC)