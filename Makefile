cc=gcc
lib=-lwiringPi -lwiringPiDev

make:
	$(cc) text.c -o textToDisplay $(lib)

clean: 
	rm textToDisplay 
