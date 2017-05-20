# Floppybird Game
[![GitHub release](https://img.shields.io/github/release/phw/peek.svg)](https://github.com/rocksdanister/floppybird/releases)

Floppy Bird 2D Scroller Game  (stable v1.0.1)

Requirements:

SOIL image loader library : `sudo apt-get install libsoil-dev`

Freeglut : `sudo apt-get install freeglut3-dev`

g++ compiler : `sudo apt-get install g++`

If required packages are satisfied, then just type `make`, press Enter to compile & enter `./floppybird` to run.

![Alt text](/res/animated.gif?raw=true "floppy")

Changelog:
1. Added Parallax tree effect.
2. tweaking of movement and collision.
3. Added gameover animation.
4. tweaked brick positioning and texture.
5. Changed input key to spacebar.
6. Awaits user input to start the game.
7. Added God Mode (cheat code: ?)

Known Issue:

1. game mode used to implement vsync currently, cant find the required extension in my intel hd driver for linux using glewInit.
2. Screen tearing on nvidia gpu.

