#include <GL/glut.h>
#include <stdio.h>
#include <floppy.h>
#include <iostream>
#include <vector>
#include <string>
#include <SOIL/SOIL.h>

using namespace std;

struct bricks
{
int x,y;
int objdisp;
}obj;

vector<bricks> obstacleBrick;
unsigned char* image;
static GLuint texBird[4],texBac[2],texObj[3];
int width, height,score;
float skyX,treeX,treeX2,groundX;
int birdPhys,tmp,highscore,insidebrick,gameover,prevy;
double syncBird;
unsigned int i,j;

void init()
{
	
	
	glShadeModel(GL_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
//............BIRD...............
	glGenTextures(4,texBird);

	glBindTexture(GL_TEXTURE_2D, texBird[0]);  //texture 1 active 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	image = SOIL_load_image( "res/bird/frame-1.png", &width, &height, 0, SOIL_LOAD_RGBA );
	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image );
	SOIL_free_image_data( image );


	glBindTexture(GL_TEXTURE_2D, texBird[1]);  
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	image = SOIL_load_image( "res/bird/frame-2.png", &width, &height, 0, SOIL_LOAD_RGBA );
	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image );
	SOIL_free_image_data( image );


	glBindTexture(GL_TEXTURE_2D, texBird[2]);  
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	image = SOIL_load_image( "res/bird/frame-3.png", &width, &height, 0, SOIL_LOAD_RGBA );
	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image );
	SOIL_free_image_data( image );


	glBindTexture(GL_TEXTURE_2D, texBird[3]);  
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	image = SOIL_load_image( "res/bird/frame-4.png", &width, &height, 0, SOIL_LOAD_RGBA );
	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image );
	SOIL_free_image_data( image );

//.......BACKGROUND.............
	glGenTextures(2,texBac);
	glBindTexture(GL_TEXTURE_2D, texBac[0]);  
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	image = SOIL_load_image( "res/background/cloud.png", &width, &height, 0, SOIL_LOAD_RGBA );
	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image );
	SOIL_free_image_data( image );

	glBindTexture(GL_TEXTURE_2D, texBac[1]);  
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	image = SOIL_load_image( "res/background/ground.png", &width, &height, 0, SOIL_LOAD_RGBA );
	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image );
	SOIL_free_image_data( image );

//..OBJECTS	
	glGenTextures(3,texObj);	
	glBindTexture(GL_TEXTURE_2D, texObj[0]);  
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	image = SOIL_load_image( "res/objects/trees_near.png", &width, &height, 0, SOIL_LOAD_RGBA );
	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image );
	SOIL_free_image_data( image );

	glBindTexture(GL_TEXTURE_2D, texObj[1]);  
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	image = SOIL_load_image( "res/objects/brick.png", &width, &height, 0, SOIL_LOAD_RGBA );
	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image );
	SOIL_free_image_data( image );
	
	glBindTexture(GL_TEXTURE_2D, texObj[2]);  
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	image = SOIL_load_image( "res/objects/trees_far.png", &width, &height, 0, SOIL_LOAD_RGBA );
	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image );
	SOIL_free_image_data( image );

glEnable(GL_TEXTURE_2D);
}

 GLuint base;
void initialiseList()
{
base=glGenLists(6);
glListBase(base);
}

void update(double temp)
{
	syncBird+=temp;
	if(syncBird>=120)  // bird winganimation running at 6fps
		{	
			birdPhys++;
			if(birdPhys==3)
				birdPhys=0;
			syncBird-=120;
		}	

}

void updateSynchronised()
{
	if(gameover==0)
	{
		groundX-=4;
		if(groundX<-resX)
			groundX=0;

		skyX-=0.75;
		if(skyX<-resX)
			skyX=0;

		treeX-=2;
		if(treeX<-resX)
			treeX=0;

		treeX2-=1.75;
		if(treeX2<-resX)
			treeX2=0;
	}
		
}

void staticBird()
{
glNewList(base+0, GL_COMPILE);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(0,resY/2,0);
		glTexCoord2f(1.0, 0.0); glVertex3f(30,resY/2,0);
		glTexCoord2f(1.0, -1.0); glVertex3f(30,(resY/2)+30,0);                        
		glTexCoord2f(0.0, -1.0); glVertex3f(0,(resY/2)+30,0);
	glEnd();
glEndList();
}

void staticGround()
{
glNewList(base+1, GL_COMPILE);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(0,0,0);
		glTexCoord2f(1.0, 0.0); glVertex3f(resX*2,0,0);
		glTexCoord2f(1.0, -1.0); glVertex3f(resX*2,(resY*10)/100,0);                        
		glTexCoord2f(0.0, -1.0); glVertex3f(0,(resY*10)/100,0);
	glEnd();
glEndList();
}

void staticSky()
{
glNewList(base+2, GL_COMPILE);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(0,0,0);
		glTexCoord2f(1.0, 0.0); glVertex3f(resX*2,0,0);
		glTexCoord2f(1.0, -1.0); glVertex3f(resX*2,resY,0);                        
		glTexCoord2f(0.0, -1.0); glVertex3f(0,resY,0);
	glEnd();
glEndList();
}

void staticTrees()
{
glNewList(base+3, GL_COMPILE);
glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(0,0,0);
		glTexCoord2f(1.0, 0.0); glVertex3f(resX*2,0,0);
		glTexCoord2f(1.0, -1.0); glVertex3f(resX*2,resY,0);                        
		glTexCoord2f(0.0, -1.0); glVertex3f(0,resY,0);
	glEnd();
glEndList();
}

void staticTrees_2()
{
glNewList(base+5, GL_COMPILE);
glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(0,0,0);
		glTexCoord2f(1.0, 0.0); glVertex3f(resX*2,0,0);
		glTexCoord2f(1.0, -1.0); glVertex3f(resX*2,resY,0);                        
		glTexCoord2f(0.0, -1.0); glVertex3f(0,resY,0);
	glEnd();
glEndList();
}

void staticBrick()
{
//... BOTTOM BRICK	
glNewList(base+4, GL_COMPILE);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(resX,-resY/2,0);
		glTexCoord2f(1.0, 0.0); glVertex3f(resX+50,-resY/2,0);
		glTexCoord2f(1.0, -1.0); glVertex3f(resX+50,resY/2-38,0);                        
		glTexCoord2f(0.0, -1.0); glVertex3f(resX,resY/2-38,0);
	glEnd();

//.... TOP BRICK
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(resX,resY+resY/2,0);
		glTexCoord2f(1.0, 0.0); glVertex3f(resX+50,resY+resY/2,0);
		glTexCoord2f(1.0, -1.0); glVertex3f(resX+50,resY/2+38,0);                        
		glTexCoord2f(0.0, -1.0); glVertex3f(resX,resY/2+38,0);
	glEnd();

glEndList();
}

int hit1,hit2;
void resetFunc()
{
if(gameover==0)
{
highscore=(highscore<score)?score:highscore;
hit1=0;hit2=0;
movementY=0;
groundX=0;
skyX=0;
treeX=0;
treeX2=0;
obstacleBrick.clear();
score=0;
insidebrick=0;
startFlag=0;
}
else
{
gameoverAnimation();
}
}

void hitDetection()
{
	if(gameover==0)
	{	
	for(i=0;i<obstacleBrick.size();i++)
	{		
			//Closest Brick X                      Further Brick X
		if( (resX+obstacleBrick[i].objdisp)<=30 && (resX+obstacleBrick[i].objdisp)>=-50 )
		{
		 	insidebrick=1;
				//Bottom Brick Y original=(movementY+resY/2) 				Top Brick Y	 original=(movementY+resY/2+25)				                           
			if( (movementY+(resY/2)+10) >= ( ((resY/2)-38)+ obstacleBrick[i].y) && (movementY+(resY/2)+30-5) <= ( ((resY/2)+38) +obstacleBrick[i].y) )
			{
				hit1++;				
	 		}
			else 
			{
				hit2++;
			}
				
		}	
		if(hit2>=1)
		{	
			gameover=1;
			resetFunc();
		}
		if(movementY<-(resY/2-30))
		{
			gameover=1;	
			resetFunc();
		}

	}
	}
}


GLvoid *font_style = GLUT_STROKE_ROMAN;
void renderStrokeFont(int x,int y,int z,const char* temp)
{
  glPushMatrix();
  glTranslatef(x,y,z);
  glLineWidth(2);
  glScalef(0.1,0.1,0.1);
  const char *c;
  
  for (c=temp; *c != '\0'; c++) {
    glutStrokeCharacter(font_style, *c);
  }

  glPopMatrix();
}


int opt1;
void draw()
{

	glClearColor (1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if(opt1==0)
	{
		init();
		initialiseList();
		staticBrick();
		staticGround();
		staticBird();
		staticSky();
		staticTrees();
		staticTrees_2();
		opt1=1;
	}
	else
	{

	//...SKY	
	glPushMatrix();
	glTranslatef(skyX,0,0);
	glBindTexture(GL_TEXTURE_2D, texBac[0]);
	glCallList(base+2);
	glPopMatrix();

	//...SCORE & TEXT
	glColor3f(0.5,0.5,0.5);
	
	string str2=">FLOPPY BIRD >Movement: SPACEBAR >Exit: ESC ";
	if(startFlag==0)
	{
	const char * t2 = str2.c_str();
	renderStrokeFont(100,400,1,t2);
	}


	string str="Score: "+to_string(score)+"  HighScore: "+to_string(highscore);
	const char * c = str.c_str();
	renderStrokeFont(10,resY-25,0,c);
	glColor3f(1,1,1);

	//..TREES
	glPushMatrix();
	glTranslatef(treeX2,0,0);
	glBindTexture(GL_TEXTURE_2D, texObj[2]);
	glCallList(base+5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(treeX,0,0);
	glBindTexture(GL_TEXTURE_2D, texObj[0]);
	glCallList(base+3);
	glPopMatrix();
if(startFlag==1)
{
	//..BRICK GENERATION
	if(gameover==0)
	{	
		if(tmp==75)
		{
			tmp=0;
			obj.x=0;
			obj.y= -100+rand()%200;
			if( abs(obj.y-prevy)>100)
			{
				if(prevy<0)
				obj.y-=50;
				else if(prevy>0)
				obj.y+=50;	
			}				
			obj.objdisp=0;
			obstacleBrick.push_back(obj);
			prevy=obj.y;
		}
		else
		{
			tmp++;
		}
	}

	//..BRICK
	for(j=0;j<obstacleBrick.size();j++)
	{

	if(obstacleBrick[j].objdisp<-(resX+60))
	{
	score++;hit1=0;hit2=0;insidebrick=0;
	obstacleBrick.erase(obstacleBrick.begin()+j);
	}	

	if(gameover==0)	
	obstacleBrick[j].objdisp-=4;
	
	glPushMatrix();
	glTranslatef(obstacleBrick[j].objdisp,obstacleBrick[j].y,0);
	glBindTexture(GL_TEXTURE_2D, texObj[1]);
	glCallList(base+4);
	glPopMatrix();
	}
}
	//..GROUND	
	glPushMatrix();
	glTranslatef(groundX,0,0);
	glBindTexture(GL_TEXTURE_2D, texBac[1]);
	glCallList(base+1);
	glPopMatrix();

	//...BIRD
	glPushMatrix();
	glTranslatef(movementX,movementY,0);
	glBindTexture(GL_TEXTURE_2D, texBird[birdPhys]);
	glCallList(base+0);
	glPopMatrix();		
	
	}

	hitDetection();
//glFinish();
glutSwapBuffers();
}
