CC=g++
INCLUDE_DIR=/usr/local/include/SDL2/

# TODO separate flags for different build (Release and debug)
CXXFLAGS=-g -Wall -Wextra -O2 -fPIC -std=c++17 # necessary for filesystem interface
LIBS=-lstdc++fs

all: libBorisEngine.a libBorisEngine.so

objs = BorisConsoleManager.o BorisExternalInterface.o \
       BorisOperations.o CSRand.o DigitSprite.o       \
       ExternalResourceManager.o FontManager.o Font.o Game.o \
       Line.o PointsCounter.o SceneManager.o Scene.o \
       SDL_Window_Manager.o SoundManager.o Sound.o SoundWrap.o \
       Sprite.o TextureManager.o Texture.o ThreadManager.o Util.o

PIC_objs = BorisConsoleManager_shared.o BorisExternalInterface_shared.o \
       BorisOperations_shared.o CSRand_shared.o DigitSprite_shared.o       \
       ExternalResourceManager_shared.o FontManager_shared.o Font_shared.o Game_shared.o \
       Line_shared.o PointsCounter_shared.o SceneManager_shared.o Scene_shared.o \
       SDL_Window_Manager_shared.o SoundManager_shared.o Sound_shared.o SoundWrap_shared.o \
       Sprite_shared.o TextureManager_shared.o Texture_shared.o ThreadManager_shared.o Util_shared.o

libBorisEngine.a: $(objs)
	ar rcs $@ $(objs)

libBorisEngine.so: $(PIC_objs)
	$(CC) -shared -o $@ $(PIC_objs)

BorisConsoleManager_shared.o: BorisConsoleManager.h
	$(CC) -c BorisConsoleManager.cpp -o $@ $(CXXFLAGS) -fPIC -I $(INCLUDE_DIR)

BorisExternalInterface_shared.o: BorisExternalInterface.h
	$(CC) -c BorisExternalInterface.cpp -o $@ $(CXXFLAGS) -fPIC -I $(INCLUDE_DIR)

BorisOperations_shared.o: BorisOperations.h
	$(CC) -c BorisOperations.cpp -o $@ $(CXXFLAGS) -fPIC -I $(INCLUDE_DIR)

CSRand_shared.o: CSRand.h
	$(CC) -c CSRand.cpp -o $@ $(CXXFLAGS) -fPIC -I $(INCLUDE_DIR)

DigitSprite_shared.o: DigitSprite.h
	$(CC) -c DigitSprite.cpp -o $@ $(CXXFLAGS) -fPIC -I $(INCLUDE_DIR)

ExternalResourceManager_shared.o: ExternalResourceManager.h
	$(CC) -c ExternalResourceManager.cpp -o $@ $(CXXFLAGS) -fPIC -I $(INCLUDE_DIR)

FontManager_shared.o: FontManager.h
	$(CC) -c FontManager.cpp -o $@ $(CXXFLAGS) -fPIC -I $(INCLUDE_DIR)

Font_shared.o: Font.h
	$(CC) -c Font.cpp -o $@ $(CXXFLAGS) -fPIC -I $(INCLUDE_DIR)

Game_shared.o: Game.h
	$(CC) -c Game.cpp -o $@ $(CXXFLAGS) -fPIC -I $(INCLUDE_DIR)

Line_shared.o: Line.h
	$(CC) -c Line.cpp -o $@ $(CXXFLAGS) -fPIC -I $(INCLUDE_DIR)

PointsCounter_shared.o: PointsCounter.h
	$(CC) -c PointsCounter.cpp -o $@ $(CXXFLAGS) -fPIC -I $(INCLUDE_DIR)

SceneManager_shared.o: SceneManager.h
	$(CC) -c SceneManager.cpp -o $@ $(CXXFLAGS) -fPIC -I $(INCLUDE_DIR)

Scene_shared.o: Scene.h
	$(CC) -c Scene.cpp -o $@ $(CXXFLAGS) -fPIC -I $(INCLUDE_DIR)

SDL_Window_Manager_shared.o: SDL_Window_Manager.h
	$(CC) -c SDL_Window_Manager.cpp -o $@ $(CXXFLAGS) -fPIC -I $(INCLUDE_DIR)

SoundManager_shared.o: SoundManager.h
	$(CC) -c SoundManager.cpp -o $@ $(CXXFLAGS) -fPIC -I $(INCLUDE_DIR)

Sound_shared.o: Sound.h
	$(CC) -c Sound.cpp -o $@ $(CXXFLAGS) -fPIC -I $(INCLUDE_DIR)

SoundWrap_shared.o: SoundWrap.h
	$(CC) -c SoundWrap.cpp -o $@ $(CXXFLAGS) -fPIC -I $(INCLUDE_DIR)

Sprite_shared.o: Sprite.h
	$(CC) -c Sprite.cpp -o $@ $(CXXFLAGS) -fPIC -I $(INCLUDE_DIR)

TextureManager_shared.o: TextureManager.h
	$(CC) -c TextureManager.cpp -o $@ $(CXXFLAGS) -fPIC -I $(INCLUDE_DIR)

Texture_shared.o: Texture.h
	$(CC) -c Texture.cpp -o $@ $(CXXFLAGS) -fPIC -I $(INCLUDE_DIR)

ThreadManager_shared.o: ThreadManager.h
	$(CC) -c ThreadManager.cpp -o $@ $(CXXFLAGS) -fPIC -I $(INCLUDE_DIR)

Util_shared.o: Util.h
	$(CC) -c Util.cpp -o $@ $(CXXFLAGS) -fPIC -I $(INCLUDE_DIR)

BorisConsoleManager.o: BorisConsoleManager.h
	$(CC) -c BorisConsoleManager.cpp -o $@ $(CXXFLAGS) -I $(INCLUDE_DIR)

BorisExternalInterface.o: BorisExternalInterface.h
	$(CC) -c BorisExternalInterface.cpp -o $@ $(CXXFLAGS) -I $(INCLUDE_DIR)

BorisOperations.o: BorisOperations.h
	$(CC) -c BorisOperations.cpp -o $@ $(CXXFLAGS) -I $(INCLUDE_DIR)

CSRand.o: CSRand.h
	$(CC) -c CSRand.cpp -o $@ $(CXXFLAGS) -I $(INCLUDE_DIR)

DigitSprite.o: DigitSprite.h
	$(CC) -c DigitSprite.cpp -o $@ $(CXXFLAGS) -I $(INCLUDE_DIR)

ExternalResourceManager.o: ExternalResourceManager.h
	$(CC) -c ExternalResourceManager.cpp -o $@ $(CXXFLAGS) -I $(INCLUDE_DIR)

FontManager.o: FontManager.h
	$(CC) -c FontManager.cpp -o $@ $(CXXFLAGS) -I $(INCLUDE_DIR)

Font.o: Font.h
	$(CC) -c Font.cpp -o $@ $(CXXFLAGS) -I $(INCLUDE_DIR)

Game.o: Game.h
	$(CC) -c Game.cpp -o $@ $(CXXFLAGS) -I $(INCLUDE_DIR)

Line.o: Line.h
	$(CC) -c Line.cpp -o $@ $(CXXFLAGS) -I $(INCLUDE_DIR)

PointsCounter.o: PointsCounter.h
	$(CC) -c PointsCounter.cpp -o $@ $(CXXFLAGS) -I $(INCLUDE_DIR)

SceneManager.o: SceneManager.h
	$(CC) -c SceneManager.cpp -o $@ $(CXXFLAGS) -I $(INCLUDE_DIR)

Scene.o: Scene.h
	$(CC) -c Scene.cpp -o $@ $(CXXFLAGS) -I $(INCLUDE_DIR)

SDL_Window_Manager.o: SDL_Window_Manager.h
	$(CC) -c SDL_Window_Manager.cpp -o $@ $(CXXFLAGS) -I $(INCLUDE_DIR)

SoundManager.o: SoundManager.h
	$(CC) -c SoundManager.cpp -o $@ $(CXXFLAGS) -I $(INCLUDE_DIR)

Sound.o: Sound.h
	$(CC) -c Sound.cpp -o $@ $(CXXFLAGS) -I $(INCLUDE_DIR)

SoundWrap.o: SoundWrap.h
	$(CC) -c SoundWrap.cpp -o $@ $(CXXFLAGS) -I $(INCLUDE_DIR)

Sprite.o: Sprite.h
	$(CC) -c Sprite.cpp -o $@ $(CXXFLAGS) -I $(INCLUDE_DIR)

TextureManager.o: TextureManager.h
	$(CC) -c TextureManager.cpp -o $@ $(CXXFLAGS) -I $(INCLUDE_DIR)

Texture.o: Texture.h
	$(CC) -c Texture.cpp -o $@ $(CXXFLAGS) -I $(INCLUDE_DIR)

ThreadManager.o: ThreadManager.h
	$(CC) -c ThreadManager.cpp -o $@ $(CXXFLAGS) -I $(INCLUDE_DIR)

Util.o: Util.h
	$(CC) -c Util.cpp -o $@ $(CXXFLAGS) -I $(INCLUDE_DIR)

# TODO figure out the implicit pattern to capture all of these component .o files?
#%.o : %.c
#	$(CC) -c $< -o $@ $(CXXFLAGS) -I $(INCLUDE_DIR)

