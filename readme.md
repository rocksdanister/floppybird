Floppy Bird 2D Scroller Game  (alpha build v0.5)

Requirement:

SOIL image loader library : `sudo apt-get install libsoil-dev`

Freeglut : `sudo apt-get install freeglut3-dev`

If required packages are satisfied, then just type `make` & press Enter to compile & enter ./floppybird to run.

Changelog:
1. Added Parallax tree effect.
2. tweaking of movement and collision.
3. Added gameover animation.
4. Variable falling velocity added.
5. tweaked brick positioning and texture.

Known Issue:

1. stuttering/frameskip issue, needs to properly implement vsync using glew. Adjust fps and run with vlbank_mode=0 option as a temp fix.
2. Collision detecition and gravity algorithm tweaking required
3. Initial game rendering delay/stutter.

![Alt text](/WorkOut/temp_files/floppy.jpg?raw=true "floppy")

Note: Its alpha build & I am only learning as I go , go easy on me ^_^
