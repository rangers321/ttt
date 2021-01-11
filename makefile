DEPS=tic_tac_toe_2077_deluxe_edition.o tic_tac_toe_2077_deluxe_edition_funkcjonalne.o tic_tac_toe_2077_deluxe_edition_wykonawcze.o


main: $(DEPS)
	cc  $(DEPS) -o tic_tac_toe_2077_deluxe_edition -Wall --pedantic

%.o:%.c
	cc -c $^ -o $@

clean:
	rm -f tic_tac_toe_2077_deluxe_edition
	rm -f *.o

p: tic_tac_toe_2077_deluxe_edition
	./tic_tac_toe_2077_deluxe_edition

test:tic_tac_toe_2077_deluxe_edition
	valgrind --leak-check=full -s ./tic_tac_toe_2077_deluxe_edition