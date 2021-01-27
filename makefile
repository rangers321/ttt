DEPS=tic_tac_toe_2077_deluxe_edition_bot.o tic_tac_toe_2077_deluxe_edition_funkcjonalne.o tic_tac_toe_2077_deluxe_edition_wykonawcze.o


start:play
	
compile:$(DEPS)
	cc  $(DEPS) -o tic_tac_toe_2077_deluxe_edition.a

%.o:%.c
	cc -c $^ -o $@

clean:
	rm -f *.a
	rm -f *.o
	rm -f tostery/*.a

play: compile
	./tic_tac_toe_2077_deluxe_edition.a

memtest:tic_tac_toe_2077_deluxe_edition.a
	valgrind --leak-check=full -s ./tic_tac_toe_2077_deluxe_edition.a

test_sprawdz:
	cc tostery/sprawdz_test.c tic_tac_toe_2077_deluxe_edition_funkcjonalne.c -o tostery/sprawdz_test.a
	./tostery/sprawdz_test.a