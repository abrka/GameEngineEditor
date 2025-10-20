# GameEngineEditor

## Description 

This is an editor written for game engines


## Requirements

- Compiler that supports C++20
- CMake
- SDL2
- SDL2_image

### Installing Dependencies on Ubuntu

```shell
$ sudo apt-get install libsdl2-dev libsdl2-image-dev
```

### Installing Dependencies on Windows

#### Installing SDL2
- Install SDL2 from [here](https://github.com/libsdl-org/SDL/releases/download/release-2.32.10/SDL2-devel-2.32.10-VC.zip)
- Create new environment variable ```SDL2_PATH``` and set it to the directory where SDL2 is installed
- Create new environment variable ```SDL2_INCLUDE_DIR``` and set it to ```<sdl2 directory>/include```
- Create new environment variable ```SDL2_LIBRARY``` and set it to ```<sdl2 directory>/lib/x64``` (or ```<sdl2 directory>/lib/x32``` if using 32 bit system)
- Add ```<sdl2 directory>/lib/x64``` (or ```<sdl2 directory>/lib/x32``` if using 32 bit system) to ```PATH```

#### Installing SDL2_image
- Install SDL2_image from [here](https://github.com/libsdl-org/SDL_image/releases/download/release-2.8.8/SDL2_image-devel-2.8.8-VC.zip)
- Create new environment variable ```SDL2_IMAGE_PATH``` and set it to the directory where SDL2_image is installed
- Create new environment variable ```SDL2_IMAGE_INCLUDE_DIR``` and set it to ```<sdl2_image directory>/include```
- Create new environment variable ```SDL2_IMAGE_LIBRARY``` and set it to ```<sdl2_image directory>/lib/x64``` (or ```<sdl2_image directory>/lib/x32``` if using 32 bit system)
- Add ```<sdl2_image directory>/lib/x64``` (or ```<sdl2_image directory>/lib/x32``` if using 32 bit system) to ```PATH```

## Building

```shell
$ git clone https://github.com/abrka/GameEngineEditor.git
$ cd GameEngineEditor
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build .
```
Now run GameEngineEditor executable

### For Visual Studio
- Open EngineAndEditor.sln in Visual Studio
- Build and run GameEngineEditor


## How To Use
> **_NOTE:_** that the first time this program is run, the ui layout will be messed up. Drag and dock windows wherever you like to create your own layout. Next time the program is run, this layout will be used
