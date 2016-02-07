OUTPUT= Renderer
BINS_DIR= ../bin
INCLUDES= 	-I./include/ \
			-I/usr/local/include \
			-I./src/include/

LIBS_DIR= -L/usr/local/lib -L/usr/lib64 -L./lib/

LIBS= -lSOIL -lGL -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -ldl -lXcursor -lXinerama -lGLEW -lassimp -lz -lminizip 

CCFLAGS= -std=c++11 -O0 -g -DGLEW_NO_GLU
	
all: $(BINS_DIR)/renderer.o $(BINS_DIR)/windowManager.o $(BINS_DIR)/glewManager.o $(BINS_DIR)/shader.o $(BINS_DIR)/modelManager.o $(BINS_DIR)/meshManager.o $(BINS_DIR)/texture.o
	g++ $(BINS_DIR)/windowManager.o $(BINS_DIR)/renderer.o $(BINS_DIR)/glewManager.o $(BINS_DIR)/shader.o \
		$(BINS_DIR)/modelManager.o $(BINS_DIR)/meshManager.o -o $(BINS_DIR)/$(OUTPUT) $(LIBS_DIR) $(LIBS)

$(BINS_DIR)/renderer.o: src/Renderer.cpp
	g++ -c src/Renderer.cpp $(INCLUDES) -o $(BINS_DIR)/renderer.o $(CCFLAGS)

$(BINS_DIR)/windowManager.o: src/include/WindowManager.h src/WindowManager.cpp
	g++ -c src/WindowManager.cpp $(INCLUDES) -o $(BINS_DIR)/windowManager.o $(CCFLAGS)

$(BINS_DIR)/glewManager.o: src/include/GLEWManager.h src/GLEWManager.cpp
	g++ -c src/GLEWManager.cpp $(INCLUDES) -o $(BINS_DIR)/glewManager.o $(CCFLAGS)

$(BINS_DIR)/shader.o: src/include/Shader.h src/Shader.cpp
	g++ -c src/Shader.cpp $(INCLUDES) -o $(BINS_DIR)/shader.o $(CCFLAGS)

$(BINS_DIR)/modelManager.o: src/include/ModelManager.h src/ModelManager.cpp
	g++ -c src/ModelManager.cpp $(INCLUDES) -o $(BINS_DIR)/modelManager.o $(CCFLAGS)

$(BINS_DIR)/meshManager.o: src/include/MeshManager.h src/MeshManager.cpp
	g++ -c src/MeshManager.cpp $(INCLUDES) -o $(BINS_DIR)/meshManager.o $(CCFLAGS)

# $(BINS_DIR)/texture.o: src/include/Texture.h src/Texture.cpp
#	g++ -c src/Texture.cpp $(INCLUDES) -o $(BINS_DIR)/texture.o $(CCFLAGS)
