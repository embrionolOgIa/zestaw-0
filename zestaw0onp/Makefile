# Definicja kompilatora i flag
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Pliki źródłowe
SOURCES = LinkedStack.cpp Node.cpp onp.cpp

# Pliki obiektowe
OBJECTS = $(SOURCES:.cpp=.o)

# Nazwa pliku wykonywalnego
ONP = onp

# Reguła do kompilacji programu onp
$(ONP): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Reguła do kompilacji plików źródłowych
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Reguła do kompilacji i uruchomienia programu onp
run: $(ONP)
	./$(ONP)

# Reguła do czyszczenia plików obiektowych i wykonywalnych
clean:
	rm -f $(OBJECTS) $(ONP)

.PHONY: all run clean

