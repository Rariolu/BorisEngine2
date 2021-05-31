CC=g++

# TODO separate flags for different build (Release and debug)
CXXFLAGS=-g -Wall -Wextra -O2 -fPIC -std=c++17 # necessary for filesystem interface
LIBS=-lstdc++fs

all: BorisEngine_static BorisEngine_shared

objs = BorisConsoleManager.o BorisExternalInterface.o \
       BorisOperations.o CSRand.o DigitSprite.o       \
       ExternalResourceManager.o FontManager.o Font.o Game.o \
       Line.o PointsCounter.o SceneManager.o Scene.o \
       SDL_Window_Manager.o SoundManager.o Sound.o SoundWrap.o \
       Sprite.o TextureManager.o Texture.o ThreadManager.o Util.o

BorisEngine_static: $(objs)
	ar rcs libBorisEngine_static.a $(objs)

BorisEngine_shared: $(objs)
	$(CC) -shared -o libBorisEngine.so $(objs)

%.o: %.c
	$(CC) -c $< -o $@ $(CXXFLAGS)

