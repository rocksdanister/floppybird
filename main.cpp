#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <floppy.h>

double queuedMilliseconds,prev0,fps,responseTime;
int resX,resY,movementX;
double movementY;
void reshape(int w, int h)
{
   
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glOrtho(0,resX,0,resY,-5,10);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      case 27:
         exit(0);
         break;
      default:
         break;
   }
}

int main(int argc, char** argv)
{
   //..frame-update setup
   queuedMilliseconds=0;
   prev0=0;
   fps=60;
   responseTime=(1/fps)*1000;

//... Rendering resoultion
   resX=854;resY=480;

   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
   //glutInitWindowSize(1280, 720);
   //glutInitWindowPosition(100, 100);
   //glutCreateWindow("Floppy Bird");
   glutGameModeString("1360x768");
   if (glutGameModeGet(GLUT_GAME_MODE_POSSIBLE))
    glutEnterGameMode();
   else {
    printf("ERROR: The selected resolution not available, Enter xrandr in terminal & change parameter in glutGameModeString to available resolution\n");
    //... running window mode instead
    glutInitWindowSize(1280, 720);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Floppy Bird");
    glutFullScreen();  
    }
   glutIgnoreKeyRepeat(1);
   glutDisplayFunc(draw); 
   glutIdleFunc(mixedStepLoop); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard); 
   glutSpecialFunc(processSpecialKeys);
   glutMainLoop();
   return 0; 
}
