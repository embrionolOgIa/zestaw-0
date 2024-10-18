# Definicja kompilatora i flag
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Pliki źródłowe
SOURCES = Generator.cpp Stack.cpp LinkedStack.cpp Node.cpp onp.cpp

# Pliki obiektowe
OBJECTS = $(SOURCES:.cpp=.o)

# Nazwy plików wykonywalnych
PROGRAM = generator
STACK = stack
ONP = onp

# Reguła domyślna
all: $(PROGRAM) $(STACK)

# Reguła do kompilacji programu Generator
$(PROGRAM): Generator.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Reguła do kompilacji stacka
$(STACK): Stack.o LinkedStack.o Node.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Reguła do kompilacji programu onp
$(ONP): onp.o LinkedStack.o Node.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Reguła do kompilacji plików źródłowych
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Reguła do uruchomienia programu z potokiem
run: all
	./$(PROGRAM) 15 | ./$(STACK)

# Reguła do kompilacji i uruchomienia programu onp
run2: $(ONP)
	./$(ONP)

# Reguła do czyszczenia plików obiektowych i wykonywalnych
clean:
	rm -f $(OBJECTS) $(PROGRAM) $(STACK) $(ONP)

.PHONY: all run run2 clean

