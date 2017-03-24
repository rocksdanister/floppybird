#include <GL/glut.h>
#include <stdio.h>
#include <vector>
#include <floppy.h>
using namespace std;

vector<char> inputKey; 
double g,v,tmp2;
int cnt;

void gameoverAnimation()
{

	inputKey.push_back('U');
	v=1.1;
	
}

void movePhysics()
{
int ii;
g=10;
for(ii=0;ii<inputKey.size();ii++)	
	{

		if(inputKey[ii]=='U')
			{
				if((movementY+(resY/2)+50)<resY)
				movementY+=4;
				cnt++;
			}	
		if(cnt>=7)
			{	
				cnt=0;	
				inputKey.erase(inputKey.begin()+ii);
			}		
		
	}
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
movementY-= v*v/2*g;
}

}

void processSpecialKeys(int key, int xx, int yy)
{
	switch (key) 
	{
		case GLUT_KEY_UP :
			if(gameover==0)	
			inputKey.push_back('U');
			break;
	}
}
