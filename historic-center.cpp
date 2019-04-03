#include <SFML/Graphics.hpp>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include "texture.cpp"

#define PINK 1.0, 0.70, 0.75
#define PINK_HALL 1.0, 0.80, 0.75
#define WHITE 1.0, 1.0, 1.0
#define BLACK 0.0, 0.0, 0.0

GLUquadricObj *quadratic;

// Actual vector representing the camera's direction
float lx = 0.0f, lz = -1.0f;

// XZ position of the camera
float x = 0.0f, z = 7.0f;

// Angles
float door_angle = 0.0f;
float angle = 0.0f;

void init(void) {
    
    // sky color
    quadratic = gluNewQuadric();
    glClearColor(0.0, 0.7, 1.0, 1.0);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	loadTextures();

}


void drawHouse() {

    // Front side
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(PINK);

        glBindTexture(GL_TEXTURE_2D, texture_id[0]);
		glBegin(GL_QUADS);  // Floor 1
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-4, -1.25, 1);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(4, -1.25, 1);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(4, -1.25, -10);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-4, -1.25, -10);
		glEnd();

		glBegin(GL_QUADS);  // Roof 1
			glVertex3f(-4, 2.6, 1);
			glVertex3f(4, 2.6, 1);
			glVertex3f(4, 2.6, -10);
			glVertex3f(-4, 2.6, -10);
		glEnd();

        glBindTexture(GL_TEXTURE_2D, texture_id[1]);
        glBegin(GL_QUADS);  // Wall
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(0.3, 2.6, 1);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(4, 2.6, 1);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(4, -1.5, 1);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(0.3, -1.5, 1);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, texture_id[1]);
        glBegin(GL_QUADS);  // Wall
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-4,2.6,1);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(-0.3,2.6,1);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(-0.3,-1.5,1);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-4,-1.5,1);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, texture_id[1]);
        glBegin(GL_QUADS);  // Wall
            glTexCoord2f(0.0f, 1.0f);
		    glVertex3f(0.3, 2.6, 1);
            glTexCoord2f(1.0f, 1.0f);
		    glVertex3f(-0.3, 2.6, 1);
            glTexCoord2f(1.0f, 0.0f);
		    glVertex3f(-0.3, -0.25, 1);
            glTexCoord2f(0.0f, 0.0f);
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
        glBindTexture(GL_TEXTURE_2D, texture_id[3]);
        glBegin(GL_QUADS);  // Static Door 1
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-1, 0.3, 1.1);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(-2, 0.3, 1.1);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(-2, -1.5, 1.1);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-1, -1.5, 1.1);
        glEnd();

        glColor3f(WHITE);
        glBindTexture(GL_TEXTURE_2D, texture_id[3]);
        glBegin(GL_QUADS);  // Static Door 2
            glTexCoord2f(0.0f, 1.0f);            
            glVertex3f(-2.5, 0.3, 1.1);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(-3.5, 0.3, 1.1);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(-3.5, -1.5, 1.1);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-2.5, -1.5, 1.1);
        glEnd();

        glColor3f(WHITE);
        glBindTexture(GL_TEXTURE_2D, texture_id[3]);
        glBegin(GL_QUADS);  // Static Door 3
            glTexCoord2f(0.0f, 1.0f);            
            glVertex3f(1.0, 0.3, 1.1);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(2.0, 0.3, 1.1);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(2.0, -1.5, 1.1);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(1.0, -1.5, 1.1);
        glEnd();

        glColor3f(WHITE);
        glBindTexture(GL_TEXTURE_2D, texture_id[3]);
        glBegin(GL_QUADS);  // Static Door 4
            glTexCoord2f(0.0f, 1.0f);            
            glVertex3f(2.5, 0.3, 1.1);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(3.5, 0.3, 1.1);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(3.5, -1.5, 1.1);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(2.5, -1.5, 1.1);
        glEnd();

        // Front Windows
        glBindTexture(GL_TEXTURE_2D, texture_id[2]);
        glBegin(GL_QUADS);  // Static Window 1
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(2.5, 1.0, 1.1);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(3.5, 1.0, 1.1);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(3.5, 2.2, 1.1);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(2.5, 2.2, 1.1);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, texture_id[2]);
        glColor3f(WHITE);
        glBegin(GL_QUADS);  // Static Window 2
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(1.0, 1.0, 1.1);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(2.0, 1.0, 1.1);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(2.0, 2.2, 1.1);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(1.0, 2.2, 1.1);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, texture_id[2]);
        glColor3f(WHITE);
        glBegin(GL_QUADS);  // Static Window 3
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-2.5, 1.0, 1.1);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(-3.5, 1.0, 1.1);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(-3.5, 2.2, 1.1);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-2.5, 2.2, 1.1);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, texture_id[2]);
        glColor3f(WHITE);
        glBegin(GL_QUADS);  // Static Window 1
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-1, 1.0, 1.1);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(-2, 1.0, 1.1);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(-2, 2.2, 1.1);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-1, 2.2, 1.1);
        glEnd();

    glPopMatrix();

    // Back side
    glPushMatrix();
        glTranslatef(0.0f, 1.3f, 0.0f);
        glColor3f(PINK_HALL);
        glBindTexture(GL_TEXTURE_2D, texture_id[1]);
        glBegin(GL_QUADS);  // Wall 1
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-4, 2.6, -10.0);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(-0.88, 2.6, -10.0);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(-0.88, -1.5, -10.0);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-4, -1.5, -10.0);
        glEnd();

        glColor3f(PINK_HALL);
        glBindTexture(GL_TEXTURE_2D, texture_id[1]);
        glBegin(GL_QUADS);  // Wall 2
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(0.88, 2.6, -10.0);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(4, 2.6, -10.0);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(4, -1.5, -10.0);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(0.88, -1.5, -10.0);
        glEnd();
    glPopMatrix();

    // Right side
    glPushMatrix();
        glTranslatef(0.0f, 1.3f, 0.0f);
        glColor3f(PINK);
        glBindTexture(GL_TEXTURE_2D, texture_id[1]);
        glBegin(GL_QUADS);  // Wall
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(4,2.6,1);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(4,2.6,-10);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(4,-1.5,-10);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(4,-1.5,1);
        glEnd();
    glPopMatrix();

    // Left side
    glPushMatrix();
        glTranslatef(0.0f, 1.3f, 0.0f);
        glColor3f(PINK);
        glBindTexture(GL_TEXTURE_2D, texture_id[1]);
        glBegin(GL_QUADS);  // Wall
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-4,2.6,1);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(-4,2.6,-10);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(-4,-1.5,-10);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-4,-1.5,1);
        glEnd();
    glPopMatrix();

    // Hall
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, texture_id[0]);
		glBegin(GL_QUADS);  // Floor 2
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-1, 0.025, -15);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(1, 0.025, -15);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(1, 0.025, -10);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-1, 0.025, -10);
		glEnd();

		glBegin(GL_QUADS);  // Roof 2
			glVertex3f(-1, 3.9, -15);
			glVertex3f(1, 3.9, -15);
			glVertex3f(1, 3.9, -10);
			glVertex3f(-1, 3.9, -10);
		glEnd();

        glTranslatef(0.0f, 1.3f, 0.0f);
        glColor3f(PINK_HALL);
        glBindTexture(GL_TEXTURE_2D, texture_id[1]);
        glBegin(GL_QUADS);  // Right Hall Wall
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(0.88,2.6,-10.0);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(0.88,2.6,-15.0);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(0.88,-1.5,-15.0);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(0.88,-1.5,-10.0);
        glEnd();

        glColor3f(PINK_HALL);
        glBindTexture(GL_TEXTURE_2D, texture_id[1]);
        glBegin(GL_QUADS);  // Left Hall Wall
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-0.88,2.6,-10.0);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(-0.88,2.6,-15.0);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(-0.88,-1.5,-15.0);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-0.88,-1.5,-10.0);
        glEnd();
    glPopMatrix();

    // Second room
    glPushMatrix();

        glBindTexture(GL_TEXTURE_2D, texture_id[0]);
        glBegin(GL_QUADS);  // Floor 3
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-5, 0.025, -25);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(5, 0.025, -25);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(5, 0.025, -15);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-5, 0.025, -15);
		glEnd();

        glBegin(GL_QUADS);  // Roof 3
			glVertex3f(-5, 3.9, -25);
			glVertex3f(5, 3.9, -25);
			glVertex3f(5, 3.9, -15);
			glVertex3f(-5, 3.9, -15);
		glEnd();

        glTranslatef(0.0f, 1.3f, 0.0f);
        glColor3f(PINK);
        glBindTexture(GL_TEXTURE_2D, texture_id[1]);
        glBegin(GL_QUADS);  // Front Right wall
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(0.88, 2.6, -15);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(5, 2.6, -15);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(5, -1.5, -15);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(0.88, -1.5, -15);
        glEnd();

        glColor3f(PINK);
        glBindTexture(GL_TEXTURE_2D, texture_id[1]);
        glBegin(GL_QUADS);  // Front Left wall
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-0.88, 2.6, -15);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(-5, 2.6, -15);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(-5, -1.5, -15);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-0.88, -1.5, -15);
        glEnd();

        glColor3f(PINK);
        glBindTexture(GL_TEXTURE_2D, texture_id[1]);
        glBegin(GL_QUADS);  // Mid Left wall
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-5, 2.6, -15);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(-5, 2.6, -25);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(-5, -1.5, -25);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-5, -1.5, -15);
        glEnd();

        glColor3f(PINK);
        glBindTexture(GL_TEXTURE_2D, texture_id[1]);
        glBegin(GL_QUADS);  // Mid Right wall
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(5, 2.6, -15);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(5, 2.6, -25);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(5, -1.5, -25);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(5, -1.5, -15);
        glEnd();

        glColor3f(PINK);
        glBindTexture(GL_TEXTURE_2D, texture_id[1]);
        glBegin(GL_QUADS);  // Back Right wall
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-5, 2.6, -25);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(5, 2.6, -25);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(5, -1.5, -25);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-5, -1.5, -25);
        glEnd();
    glPopMatrix();


    // DETAILS
    // Pilaster 1
    glPushMatrix();
        glTranslatef(-2, 0, -2);
        glRotatef(-90, 1, 0, 0);
        glColor3f(0.78f, 0.823f, 0.824f);
        glBindTexture(GL_TEXTURE_2D, texture_id[4]);
        gluQuadricTexture(quadratic, GL_TRUE);
        gluCylinder(quadratic, 0.28, 0.28, 3, 30, 30);
    glPopMatrix();

    // Pilaster 2
    glPushMatrix();
        glTranslatef(-2, 0, -5);
        glRotatef(-90, 1, 0, 0);
        glColor3f(0.78f, 0.823f, 0.824f);
        glBindTexture(GL_TEXTURE_2D, texture_id[4]);
        gluQuadricTexture(quadratic, GL_TRUE);
        gluCylinder(quadratic, 0.28, 0.28, 3, 30, 30);
    glPopMatrix();

    // Pilaster 3
    glPushMatrix();
        glTranslatef(2, 0, -5);
        glRotatef(-90, 1, 0, 0);
        glColor3f(0.78f, 0.823f, 0.824f);
        glBindTexture(GL_TEXTURE_2D, texture_id[4]);
        gluQuadricTexture(quadratic, GL_TRUE);
        gluCylinder(quadratic, 0.28, 0.28, 3, 30, 30);
    glPopMatrix();

    // Pilaster 4
    glPushMatrix();
        glTranslatef(2, 0, -2);
        glRotatef(-90, 1, 0, 0);
        glColor3f(0.78f, 0.823f, 0.824f);
        glBindTexture(GL_TEXTURE_2D, texture_id[4]);
        gluQuadricTexture(quadratic, GL_TRUE);
        gluCylinder(quadratic, 0.28, 0.28, 3, 30, 30);
    glPopMatrix();


    // OBJ 1
    glPushMatrix();
        glTranslatef(2, 0, -20);
        glRotatef(-90, 1, 0, 0);
        glColor3f(1, 0.8, 0.89); //change color after
        glBindTexture(GL_TEXTURE_2D, texture_id[4]);
        gluQuadricTexture(quadratic, GL_TRUE);
        gluCylinder(quadratic, 0.28, 0.28, 1.5, 30, 30);
    glPopMatrix();

    // Cannon 1
    glPushMatrix();
        glTranslatef(1, 0.1, -20.5);
        glRotatef(-20, 10, 0, 0);
        glBindTexture(GL_TEXTURE_2D, texture_id[5]);
        gluQuadricTexture(quadratic, GL_TRUE);
        gluCylinder(quadratic, 0.28, 0.1, 1.5, 30, 30);
    glPopMatrix();

    // Cannon 2
    glPushMatrix();
        glTranslatef(3, 0.1, -20.5);
        glRotatef(-20, 1, 0, 0);
        glBindTexture(GL_TEXTURE_2D, texture_id[5]);
        gluQuadricTexture(quadratic, GL_TRUE);
        gluCylinder(quadratic, 0.28, 0.1, 1.0, 30, 30);
    glPopMatrix();

    // Cannon 3
    // glPushMatrix();
    //    glTranslatef(1.9, 0.2, -18.8);
    //    glRotatef(-20, -30, 45, 0);
    //    glColor3f(BLACK);
    //    glBindTexture(GL_TEXTURE_2D, texture_id[5]);
    //    gluQuadricTexture(quadratic, GL_TRUE);
    //    gluCylinder(quadratic, 0.18, 0.05, 0.5, 30, 30);
    // glPopMatrix();

}


void drawDoor() {

    glPushMatrix();
		glTranslatef(-0.3f, 0.5f, 1);
        glRotatef (door_angle, 0,1,0);
    	glTranslatef(0.3f, 0, 0);
        glColor3f(WHITE);
        glScalef(0.6, 1.1, 0.1f);
        glEnable(GL_TEXTURE_GEN_S); // Enable texture coordinate generation
        glEnable(GL_TEXTURE_GEN_T);
        glBindTexture(GL_TEXTURE_2D, texture_id[1]);
        glutSolidCube(1.0);
        glDisable(GL_TEXTURE_GEN_S); // Disable texture coordinate generation
        glDisable(GL_TEXTURE_GEN_T);
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
