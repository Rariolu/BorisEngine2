
cmake_minimum_required(VERSION 3.1)

project(BorisEngine)

add_library(libBorisEngine.so SHARED
            BorisConsoleManager.cpp
            BorisExternalInterface.cpp
            BorisOperations.cpp
            CSRand.cpp
            DigitSprite.cpp
            ExternalResourceManager.cpp
            Font.cpp
            FontManager.cpp
            Game.cpp
            Line.cpp
            PointsCounter.cpp
            Scene.cpp
            SceneManager.cpp
            SDL_Window_Manager.cpp
            Sound.cpp
            SoundManager.cpp
            SoundWrap.cpp
            Sprite.cpp
            Texture.cpp
            TextureManager.cpp
            ThreadManager.cpp
            Util.cpp)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${BorisEngine_SOURCE_DIR}/cmake-find-modules")

# TODO set compilers?
# Try uncommenting the following two lines if CMake build fails:
#SET(CMAKE_CXX_COMPILER /usr/bin/g++)

set_property(TARGET libBorisEngine.so PROPERTY CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(
         ${BorisEngine_SOURCE_DIR}
         ${SDL2_INCLUDE_DIRS}
         ${SDL2_IMAGE_INCLUDE_DIR}
         ${SDL2_TTF_INCLUDE_DIR}
         ${SDL2_MIXER_INCLUDE_DIR}
         )

