prefix = /usr/local

CC = gcc
CFLAGS = -I.
DEPS = binary.h
OBJ = main.o binary.o
LIBS = -lm

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

binary: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

install: binary
	install -D binary \
		$(DESTDIR)$(prefix)/games/

.PHONY: clean

clean:
	rm -f $(OBJ)
