# Nom de l'exécutable
EXEC = day02

# Compilateur
CXX = c++

# Options de compilation
CXXFLAGS = -Wall -Wextra -std=c++17

# Fichiers sources
SRC = safe.cpp

# Cible par défaut
all: $(EXEC)

# Compilation de l'exécutable
$(EXEC): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(SRC)

# Nettoyage des fichiers générés
clean:
	rm -f $(EXEC)

# Exécution du programme
run: $(EXEC)
	./$(EXEC)
