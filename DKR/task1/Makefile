CC=gcc
CFLAGS=-c
RM=rm -f

OBJS=main.o MyMath.o
TARGET=binary

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

main.o: main.c
	$(CC) $(CFLAGS) main.c

MyMath.o: MyMath.c
	$(CC) $(CFLAGS) MyMath.c

clean:
	$(RM) $(OBJS) $(TARGET)