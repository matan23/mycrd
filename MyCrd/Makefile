#------------------------------------------------------------------------------

SOURCE=get_next_line.cpp main.cpp mydictionnary.cpp str_to_wtb.cpp
MYPROGRAM=MyCrd
MYINCLUDES=./

CC=g++ -g

#------------------------------------------------------------------------------



all: $(MYPROGRAM)



$(MYPROGRAM): $(SOURCE)

	$(CC) -I$(MYINCLUDES) $(SOURCE) -o$(MYPROGRAM)

clean:

	rm -f $(MYPROGRAM)