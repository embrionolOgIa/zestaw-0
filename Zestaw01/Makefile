# Definicja kompilatora i flag
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Pliki zrodlowe
SOURCES = Generator.cpp Stack.cpp LinkedStack.cpp Node.cpp onp.cpp onpstacklib.cpp Stack.x

# Pliki obiektowe
OBJECTS = $(SOURCES:.cpp=.o)

# Nazwy plikow wykonywalnych
PROGRAM = Generator.x
STACK = Stack.x
ONP = ONP.x

# Regusa domyslna
all: $(PROGRAM) $(STACK) $(ONP)

# Regula do kompilacji generatora
$(PROGRAM): Generator.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regula do kompilacji stacka
$(STACK): Stack.o LinkedStack.o Node.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regula do kompilacji onp
$(ONP): onp.o Node.o onpstacklib.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regula do kompilacji plikow zrodlowych
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Reguła do kompilacji plikow .x
%.o: %.x
	$(CXX) $(CXXFLAGS) -c $<

# Regula do uruchomienia programu z potokiem
run: all
	./$(PROGRAM) 15 | ./$(STACK)

# Reguła do kompilacji i uruchomienia programu onp
run2: $(ONP)
	@./$(ONP) # @ zeby nie pokazywać polecenia

# Regula do czyszczenia plików obiektowych i wykonywalnych
clean:
	rm -f $(OBJECTS) $(PROGRAM) $(STACK) $(ONP)

.PHONY: all run run2 clean

