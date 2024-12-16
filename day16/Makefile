# Nom de l'exécutable
NAME = day16

# Compilateur
CXX = c++

# Options de compilation
CXXFLAGS = -Wall -Wextra -std=c++17

# Répertoire des sources et des objets
SRC_DIR = .
OBJ_DIR = obj

# Fichiers sources
SRC = main.cpp

# Fichiers objets (remplacement .cpp par .o et ajout du répertoire obj)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Cible par défaut
all: $(NAME)

# Compilation de l'exécutable
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)  # Crée le répertoire obj si nécessaire
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage des fichiers générés
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	@echo "Cleaning all generated files..."
	rm -f $(NAME)

# Exécution du programme
run: $(NAME)
	./$(NAME)
