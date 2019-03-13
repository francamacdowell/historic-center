#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

#define PINK 1.0, 0.70, 0.75
#define WHITE 1.0, 1.0, 1.0

// actual vector representing the camera's direction
float lx=0.0f, lz=-1.0f;

// XZ position of the camera
float x=0.0f, z=7.0f;

float door_angle = 0.0f;

// angle for rotating
float angle = 0.0f;

void init(void) {
    // sky color
    glClearColor(0.0, 0.7, 1.0, 1.0);
}

void drawHouse(){

    // Front side
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(PINK);

        glBegin(GL_QUADS);  // Wall
            glVertex3f(0.3, 2.6, 1);
            glVertex3f(4, 2.6, 1);
            glVertex3f(4, -1.5, 1);
            glVertex3f(0.3, -1.5, 1);
        glEnd();

        glBegin(GL_QUADS);  // Wall
            glVertex3f(-4,2.6,1);
            glVertex3f(-0.3,2.6,1);
            glVertex3f(-0.3,-1.5,1);
            glVertex3f(-4,-1.5,1);
        glEnd();

        glBegin(GL_QUADS);  // Wall
		glVertex3f(0.3, 2.6, 1);
		glVertex3f(-0.3, 2.6, 1);
		glVertex3f(-0.3, -0.25, 1);
		glVertex3f(0.3,-0.25, 1);
	glEnd();

        // glColor3f(0.4f, 0.0f, 0.0f);
        // glBegin(GL_QUADS);  // Roof
        //     glVertex3f(-2.2,0.5,0);
        //     glVertex3f(2.2,0.5,0);
        //     glVertex3f(2.2,-0.1,1.25);
        //     glVertex3f(-2.2,-0.1,1.25);
        // glEnd();

        glColor3f(WHITE);
        glBegin(GL_QUADS);  // Static Door 1
            glVertex3f(-1, 0.3, 1.1);
            glVertex3f(-2, 0.3, 1.1);
            glVertex3f(-2, -1.5, 1.1);
            glVertex3f(-1, -1.5, 1.1);
        glEnd();

        glColor3f(WHITE);
        glBegin(GL_QUADS);  // Static Door 2
            glVertex3f(-2.5, 0.3, 1.1);
            glVertex3f(-3.5, 0.3, 1.1);
            glVertex3f(-3.5, -1.5, 1.1);
            glVertex3f(-2.5, -1.5, 1.1);
        glEnd();

        glColor3f(WHITE);
        glBegin(GL_QUADS);  // Static Door 3
            glVertex3f(1.0, 0.3, 1.1);
            glVertex3f(2.0, 0.3, 1.1);
            glVertex3f(2.0, -1.5, 1.1);
            glVertex3f(1.0, -1.5, 1.1);
        glEnd();

        glColor3f(WHITE);
        glBegin(GL_QUADS);  // Static Door 4
            glVertex3f(2.5, 0.3, 1.1);
            glVertex3f(3.5, 0.3, 1.1);
            glVertex3f(3.5, -1.5, 1.1);
            glVertex3f(2.5, -1.5, 1.1);
        glEnd();

        // Front Windows

        glColor3f(WHITE);
        glBegin(GL_QUADS);  // Static Window 1
            glVertex3f(2.5, 1.0, 1.1);
            glVertex3f(3.5, 1.0, 1.1);
            glVertex3f(3.5, 2.2, 1.1);
            glVertex3f(2.5, 2.2, 1.1);
        glEnd();

        glColor3f(WHITE);
        glBegin(GL_QUADS);  // Static Window 2
            glVertex3f(1.0, 1.0, 1.1);
            glVertex3f(2.0, 1.0, 1.1);
            glVertex3f(2.0, 2.2, 1.1);
            glVertex3f(1.0, 2.2, 1.1);
        glEnd();

        glColor3f(WHITE);
        glBegin(GL_QUADS);  // Static Window 3
            glVertex3f(-2.5, 1.0, 1.1);
            glVertex3f(-3.5, 1.0, 1.1);
            glVertex3f(-3.5, 2.2, 1.1);
            glVertex3f(-2.5, 2.2, 1.1);
        glEnd();


        glColor3f(WHITE);
        glBegin(GL_QUADS);  // Static Window 1
            glVertex3f(-1, 1.0, 1.1);
            glVertex3f(-2, 1.0, 1.1);
            glVertex3f(-2, 2.2, 1.1);
            glVertex3f(-1, 2.2, 1.1);
        glEnd();



    glPopMatrix();

    // Back side
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
        glColor3f(PINK);
        glBegin(GL_QUADS);  // Wall 1
            glVertex3f(-4,2.6,-10.0);
            glVertex3f(-0.88,2.6,-10.0);
            glVertex3f(-0.88,-1.5,-10.0);
            glVertex3f(-4,-1.5,-10.0);
        glEnd();

        glColor3f(PINK);
        glBegin(GL_QUADS);  // Wall 2
            glVertex3f(0.88,2.6,-10.0);
            glVertex3f(4,2.6,-10.0);
            glVertex3f(4,-1.5,-10.0);
            glVertex3f(0.88,-1.5,-10.0);
        glEnd();

        glColor3f(0.4f, 0.0f, 0.0f);
        glBegin(GL_QUADS);  // Roof
            glVertex3f(-2.2,0.5,0);
            glVertex3f(2.2,0.5,0);
            glVertex3f(2.2,-0.1,-1.25);
            glVertex3f(-2.2,-0.1,-1.25);
        glEnd();

    glPopMatrix();

    // Right side
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
        glColor3f(PINK);
        glBegin(GL_QUADS);  // Wall
             glVertex3f(4,2.6,1);
             glVertex3f(4,2.6,-10);
            glVertex3f(4,-1.5,-10);
             glVertex3f(4,-1.5,1);
        glEnd();

    glPopMatrix();

    // Left side
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
        glColor3f(PINK);
        glBegin(GL_QUADS);  // Wall
                glVertex3f(-4,2.6,1);
                glVertex3f(-4,2.6,-10);
               glVertex3f(-4,-1.5,-10);
                glVertex3f(-4,-1.5,1);
        glEnd();
    
    glPopMatrix();

    // Hall
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);

        glColor3f(PINK);
        glBegin(GL_QUADS);  // Right Hall Wall
            glVertex3f(0.88,2.6,-10.0);
            glVertex3f(0.88,2.6,-15.0);
            glVertex3f(0.88,-1.5,-15.0);
            glVertex3f(0.88,-1.5,-10.0);
        glEnd();

        glColor3f(PINK);
        glBegin(GL_QUADS);  // Left Hall Wall
            glVertex3f(-0.88,2.6,-10.0);
            glVertex3f(-0.88,2.6,-15.0);
            glVertex3f(-0.88,-1.5,-15.0);
            glVertex3f(-0.88,-1.5,-10.0);
        glEnd();
    glPopMatrix();

    // Second room
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
        glColor3f(PINK);
        glBegin(GL_QUADS);  // Front Right wall
            glVertex3f(0.88, 2.6, -15);
            glVertex3f(5, 2.6, -15);
            glVertex3f(5, -1.5, -15);
            glVertex3f(0.88, -1.5, -15);
        glEnd();

        glColor3f(PINK);
        glBegin(GL_QUADS);  // Front Left wall
            glVertex3f(-0.88, 2.6, -15);
            glVertex3f(-5, 2.6, -15);
            glVertex3f(-5, -1.5, -15);
            glVertex3f(-0.88, -1.5, -15);
        glEnd();

        glColor3f(PINK);
        glBegin(GL_QUADS);  // Mid Left wall
            glVertex3f(-5, 2.6, -15);
            glVertex3f(-5, 2.6, -25);
            glVertex3f(-5, -1.5, -25);
            glVertex3f(-5, -1.5, -15);
        glEnd();

        glColor3f(PINK);
        glBegin(GL_QUADS);  // Mid Right wall
            glVertex3f(5, 2.6, -15);
            glVertex3f(5, 2.6, -25);
            glVertex3f(5, -1.5, -25);
            glVertex3f(5, -1.5, -15);
        glEnd();

        glColor3f(PINK);
        glBegin(GL_QUADS);  // Back Right wall
            glVertex3f(-5, 2.6, -25);
            glVertex3f(5, 2.6, -25);
            glVertex3f(5, -1.5, -25);
            glVertex3f(-5, -1.5, -25);
        glEnd();

    glPopMatrix();
}

void drawDoor() {

    glPushMatrix();
		glTranslatef(-0.3f, 0.5f, 1);
        glRotatef (door_angle, 0,1,0);
    	glTranslatef(0.3f, 0, 0);
        glColor3f(WHITE);
        glScalef(0.6, 1.1, 0.1f);
        glutSolidCube(1.0);
    glPopMatrix();

}

void changeSize(int w, int h){

    // Prevent a divide by zero, when window is too short
    // (you cant make a window of zero width).
    if (h == 0) h = 1;
    float ratio = w * 1.0 / h;

    // Use the Projection Matrix
    glMatrixMode(GL_PROJECTION);

    // Reset Matrix
    glLoadIdentity();

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Set the correct perspective.
    gluPerspective(45.0f, ratio, 0.1f, 100.0f);

    // Get Back to the Modelview
    glMatrixMode(GL_MODELVIEW);
}

void renderScene(void){

    // Para ver os objetos em modo polígono (somente os traços)	
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // Clear Color and Depth Buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity();

    // Set the camera
    gluLookAt(x, 1.0f, z, x+lx, 1.0f, z+lz, 0.0f, 1.0f, 0.0f);

    // Draw ground
    glColor3f(0.5, 0.5, 0.5);
        glBegin(GL_QUADS);
        glVertex3f(-100.0f, 0.0f, -100.0f);
        glVertex3f(-100.0f, 0.0f, 100.0f);
        glVertex3f( 100.0f, 0.0f, 100.0f);
        glVertex3f( 100.0f, 0.0f, -100.0f);
    glEnd();

    drawHouse();
    drawDoor();

    glFlush();
    glutSwapBuffers();
}


void processNormalKeys(unsigned char key, int x, int y) {
    switch(key){
        case 'o':
            if(door_angle <= 118.0f) door_angle += 2.0f;
            glutPostRedisplay();
        break;

        case 'c':
            if(door_angle >= 2.0f) door_angle -= 2.0f;
            glutPostRedisplay();
        break;

        case 27:
            exit(0);
        break;
    }
}


void processSpecialKeys(int key, int xx, int yy){

float fraction = 0.5f;

    switch (key) {

        case GLUT_KEY_LEFT :
            angle -= 0.05f;
            lx = sin(angle);
            lz = -cos(angle);
        break;
        case GLUT_KEY_RIGHT :
            angle += 0.05f;
            lx = sin(angle);
            lz = -cos(angle);
        break;
        case GLUT_KEY_UP :
            x += lx * fraction;
            z += lz * fraction;
        break;
        case GLUT_KEY_DOWN :
            x -= lx * fraction;
            z -= lz * fraction;
        break;
    }
}

int main(int argc, char **argv){

    // init GLUT and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(800,600);
    glutCreateWindow("House 3D");

    init();

    // register callbacks
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);

    // OpenGL init
    glEnable(GL_DEPTH_TEST);

    // enter GLUT event processing cycle
    glutMainLoop();

    return 1;
}