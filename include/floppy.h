// Function declarations & global variables.
extern double queuedMilliseconds,prev0,fps,responseTime;
extern int resX,resY,movementX,insidebrick,gameover,startFlag,god;
extern double movementY;

void adjustBrick();
void draw();
void resetFunc();
void gameoverAnimation();
void mixedStepLoop();
void update(double);
void updateSynchronised();
void processSpecialKeys(int , int , int );
void movePhysics();
