all:
	gcc `pkg-config --cflags --libs gobject-2.0` lib/*.c lib/signal/*.c main.c -std=c99 -o test
