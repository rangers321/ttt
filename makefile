DEPS=tic_tac_toe_2077_deluxe_edition_bot.o tic_tac_toe_2077_deluxe_edition_funkcjonalne.o tic_tac_toe_2077_deluxe_edition_wykonawcze.o

all:new

compile:$(DEPS)
	cc  $(DEPS) -o tic_tac_toe_2077_deluxe_edition.a

%.o:%.c
	cc -c $^ -o $@

clean:
	rm -f *.a
	rm -f *.o
	rm -f tostery/*.a

play:compile
	./tic_tac_toe_2077_deluxe_edition.a

new:clean compile play

memtest:compile
	valgrind --leak-check=full -s ./tic_tac_toe_2077_deluxe_edition.a

