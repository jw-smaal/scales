# Test program for MIDI scales 
# @Author: Jan-Willem Smaal 
# @Date: 3/9/2020 

CC=c++
CFLAGS=-std=c++11
DEPS = midi-scales.h
OBJ = midi-scales-testprogram.o midi-scales.o 


%.o: %.c $(DEPS)
	$(CC) -std=c++11 -c -o $@ $< $(CFLAGS)

midi-scales-testprogram: $(OBJ)
	$(CC) -std=c++11 -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o *~ a.out *~ midi-scales-testprogram

# EOF 
