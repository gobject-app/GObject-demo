all:
	gcc `pkg-config --cflags --libs gobject-2.0` *.c -o test
