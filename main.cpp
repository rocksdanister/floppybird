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
glutGameModeString("10x10");
   display_test:
   if (glutGameModeGet(GLUT_GAME_MODE_POSSIBLE))
    glutEnterGameMode();
   else {
   	 printf("Select Screen Resolution, if you are unsure select Window mode\n"
   	 		"1. 1920x1080\n2. 1600x900\n3. 1280x720\n4. 1368x768 \n"
   	 		"5. 1366x768 \n6. 800x600\n7. 640x480\n8. Window(try to avoid this!)");
   	 int ch;
   	 scanf("%d",&ch);

   	 if(ch==8)
   	 {
     printf("\n*WARNING: The selected resolution not available, "
    	"Enter xrandr in terminal.\nChange parameter in glutGameModeString to available resolution in xrandr.\n"
    	"Currently running in windowmode.\nVsync may not perform correctly resulting in poor performance.\n");
     glutInitWindowSize(1280, 720);
     //glutInitWindowPosition(100, 100);
     glutCreateWindow("Floppy Bird");
     glutFullScreen();
     }
    else if(ch==1)
    	glutGameModeString("1920x1080");
    else if(ch==2)
    	glutGameModeString("1600x900");
    else if(ch==3)
    	glutGameModeString("1280x720");
    else if(ch==4)
    	glutGameModeString("1368x768");
    else if(ch==5)
   	glutGameModeString("1366x768");
    else if(ch==6)
    	glutGameModeString("800x600");
    else 
    	glutGameModeString("640x480");

    if(ch!=8)
    	goto display_test;
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
