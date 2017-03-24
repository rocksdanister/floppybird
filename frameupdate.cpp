#include <GL/glut.h>
#include <floppy.h>

void mixedStepLoop()
{
    double now = glutGet(GLUT_ELAPSED_TIME);
    double timeElapsedMs =(now-prev0);
    queuedMilliseconds += timeElapsedMs;
    update(timeElapsedMs);
    while(queuedMilliseconds >= responseTime) 
    {
        updateSynchronised();
        movePhysics();
        queuedMilliseconds -= responseTime;
        glutPostRedisplay();
    }
    prev0=now;
}

