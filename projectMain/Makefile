CC = msp430-elf-gcc
CPU = msp430g2553
<<<<<<< HEAD
CFLAGS = -mmcu=${CPU} -I. -I../h -L/opt/ti/msp430_gcc/include
OBJS = main.o button.o timer.o delay.o buzzer.o 
TARGET = main.elf 
=======
CFLAGS = -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include
OBJS = main.o
TARGET = main.elf
>>>>>>> 58cfb0593022609f1d9f81b9a4c21003139b6a5f

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

load: $(TARGET)
<<<<<<< HEAD
	msp430loader.sh $^

clean:
	rm -f *.o *.elf
=======
    msp430loader.sh $^
clean:
    rm -f *.o *.elf
>>>>>>> 58cfb0593022609f1d9f81b9a4c21003139b6a5f
