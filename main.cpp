#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <floppy.h>
#include <vector>
#include <math.h>
#include <string.h>

using namespace std;

double queuedMilliseconds,prev0,fps,responseTime;
int resX,resY,movementX,startFlag,god;
double movementY;

//... Reshaping settings & rendering parameters.
void reshape(int w, int h)
{
   
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glOrtho(0,resX,0,resY,-5,10);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

//....  Keyboard input and movement physics
vector<char> inputKey; 
double g,v,tmp2;
int cnt;

void gameoverAnimation()
{
	inputKey.push_back('U');
	v=1.2;
	
}

void movePhysics()
{
unsigned int ii;
g=10;
for(ii=0;ii<inputKey.size();ii++)	
	{

		if(inputKey[ii]=='U')
			{
				if((movementY+(resY/2)+50)<resY)
				movementY+=4;
				cnt++;
			}	
		if(cnt>=10)
			{	
				cnt=0;	
				inputKey.erase(inputKey.begin()+ii);
			}		
		
	}
if(startFlag==1)
{ 

//...GRAVITY
if(inputKey.size()==0)
{
// 0.021125
if(gameover==0)
{	
tmp2=resY/2;
v=0.65+(abs(movementY)/tmp2)/5;
}
else
{

	if( (inputKey.size()==0 ) && (movementY <- (resY/2) ) )
	{	
		gameover=0;
		resetFunc();
	}
}
if( (movementY<-(resY/2-30)) )
{
	if(god==0)
		movementY-= v*v/2*g;
}
else
	movementY-= v*v/2*g;	

}

}

}

int godcnt,abcindex;
char abc[13]; 
void keyboard (unsigned char key, int x, int y)
{
  if(key==32)
  	startFlag=1;
  else
 	abc[abcindex++]=key;

   switch (key) {
      case 27:
         exit(0);
         break;
 	  case 32:
 	  	if(gameover==0)	
		inputKey.push_back('U');
		break;			
   }
   if(abcindex==13)
   { 															
   		if(strcmp(abc,"rocksdanister")==0)
   			god=1;
   		else
   			abcindex=0;		
   }

}

//... keyboard input end.

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
   glutMainLoop();
   return 0; 
}
