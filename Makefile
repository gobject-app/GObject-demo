all:
	gcc `pkg-config --cflags --libs gobject-2.0` lib/*.c main.c -o test
