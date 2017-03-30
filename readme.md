Floppy Bird 2D Scroller Game  (alpha build v0.8)

Requirement:

SOIL image loader library : `sudo apt-get install libsoil-dev`

Freeglut : `sudo apt-get install freeglut3-dev`

If required packages are satisfied, then just type `make` & press Enter to compile & enter ./floppybird to run.

![Alt text](/res/screenshot.jpg?raw=true "floppy")

Changelog:
1. Added Parallax tree effect.
2. tweaking of movement and collision.
3. Added gameover animation.
4. tweaked brick positioning and texture.
5. Changed input key to spacebar.

Known Issue:

1. game mode used to implement vsync currently, cant find the required extension in my intel hd driver for linux using glewInit.
2. gravity algorithm tweaking required

Note: Its alpha build & I am only learning as I go , go easy on me ^_^
