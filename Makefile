# Exemplu de Makefile pentru solutii scrise in C++.

CC = g++
CCFLAGS = -Wall -Wextra -std=c++17 -O0 -lm

.PHONY: build clean

build: numarare trenuri drumuri scandal

# Nu compilati aici, nici macar ca dependente de reguli.
run-p1:
	./numarare
run-p2:
	./trenuri
run-p3:
	./drumuri
run-p4:
	./scandal

# Schimbati numele surselor (si, eventual, ale executabilelor - peste tot).
numarare: src/numarare.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
trenuri: src/trenuri.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
drumuri: src/drumuri.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
scandal: src/scandal.cpp
	$(CC) -o $@ $^ $(CCFLAGS)

# Vom sterge executabilele.
clean:
	rm -f numarare trenuri drumuri scandal
