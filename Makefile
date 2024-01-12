# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++11 -Wall
# SFML libraries
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lboost_serialization
# Include directories
INCLUDE_DIRS = -I./engine -I./engine/Entity -I./engine/Objet -I./engine/Scenes \
               -I./Client -I./server/includes

# Source directories
CLIENT_SRC_DIR = Client
SERVER_SRC_DIR = server
ENGINE_SRC_DIR = engine

# Object files
CLIENT_OBJ = $(CLIENT_SRC_DIR)/Client.o $(CLIENT_SRC_DIR)/ConnectionServer.o $(CLIENT_SRC_DIR)/main.o \
             $(ENGINE_SRC_DIR)/ManageElement.o $(ENGINE_SRC_DIR)/ManageScene.o $(ENGINE_SRC_DIR)/TypeEnum.o \
			 $(ENGINE_SRC_DIR)/Entity/Bullet.o $(ENGINE_SRC_DIR)/Entity/Obstacles.o $(ENGINE_SRC_DIR)/Entity/Player.o \
			 $(ENGINE_SRC_DIR)/Objet/Background.o $(ENGINE_SRC_DIR)/Objet/Buttons.o $(ENGINE_SRC_DIR)/Objet/Icons.o \
			 $(ENGINE_SRC_DIR)/Objet/Input.o $(ENGINE_SRC_DIR)/Objet/Text.o $(ENGINE_SRC_DIR)/Scenes/Game.o \
			 $(ENGINE_SRC_DIR)/Scenes/Lobby.o $(ENGINE_SRC_DIR)/Scenes/Menu.o
SERVER_OBJ = $(SERVER_SRC_DIR)/server.o $(SERVER_SRC_DIR)/main.o

# Executables
CLIENT_EXE = r-type_client
SERVER_EXE = r-type_server

# Targets
all: $(CLIENT_EXE) $(SERVER_EXE)

$(CLIENT_EXE): $(CLIENT_OBJ)
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -o $@ $^ $(SFML_LIBS)

$(SERVER_EXE): $(SERVER_OBJ)
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -o $@ $^ $(SFML_LIBS)

# Client object files
$(CLIENT_SRC_DIR)/%.o: $(CLIENT_SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -c -o $@ $<

# Server object files
$(SERVER_SRC_DIR)/%.o: $(SERVER_SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -c -o $@ $<

# Engine object files
$(ENGINE_SRC_DIR)/%.o: $(ENGINE_SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -c -o $@ $<

clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ) $(CLIENT_EXE) $(SERVER_EXE)

.PHONY: all clean
