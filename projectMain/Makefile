CC = msp430-elf-gcc
CPU = msp430g2553
CFLAGS = -mmcu=${CPU} -I. -I../h -L/opt/ti/msp430_gcc/include
OBJS = main.o button.o timer.o delay.o buzzer.o melodies.o font-11x16.o font-5x7.o font-8x12.o lcdutils.o lcddraw.o
TARGET = main.elf 

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

load: $(TARGET)
	msp430loader.sh $^

clean:
	rm -f *.o *.elf