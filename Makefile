cc=gcc
lib=-lwiringPi -lwiringPiDev

TARGET=tempToDisplay

make: $(TARGET).c
	$(cc) $(TARGET).c -o $(TARGET) $(lib)

clean: 
	rm $(TARGET)
