DEPS=tic_tac_toe_2077_deluxe_edition_bot.o tic_tac_toe_2077_deluxe_edition_funkcjonalne.o tic_tac_toe_2077_deluxe_edition_wykonawcze.o


main: $(DEPS)
	cc  $(DEPS) -o tic_tac_toe_2077_deluxe_edition_bot.a

%.o:%.c
	cc -c $^ -o $@

clean:
	rm -f tic_tac_toe_2077_deluxe_edition.a
	rm -f tic_tac_toe_2077_deluxe_edition_bot.a
	rm -f *.o

p: tic_tac_toe_2077_deluxe_edition.a
	./tic_tac_toe_2077_deluxe_edition.a

test:tic_tac_toe_2077_deluxe_edition.a
	valgrind --leak-check=full -s ./tic_tac_toe_2077_deluxe_edition.a

bot:tic_tac_toe_2077_deluxe_edition_bot.a
	./tic_tac_toe_2077_deluxe_edition_bot.a