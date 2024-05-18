#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#define pi 3.14159265358979323846


GLfloat angle, fAspect,eyex, eyey, eyez;
GLfloat t_terra = 0.0, t_mercurio = 0.0, t_venus = 0.0, t_marte = 0.0, t_jupiter = 0.0, t_saturno = 0.0, t_urano = 0.0, t_netuno = 0.0, r_lua = 0.0;
GLfloat r_sol = 20.0, r_mercurio = 5.0, r_venus = 7.0, r_terra = 10.0, r_marte = 8.0, r_jupiter = 15.0, r_saturno = 13.0, r_urano = 12.0, r_netuno = 11.0, t_lua = 0.0;

void myInit(void){
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    angle= 45;
    eyex = 0.0;
    eyey = 200.0;
    eyez = 100.0;
}

void idle(void){
    glutPostRedisplay();
}   

void cam(void){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(angle,fAspect,0.1,500);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyex,eyey,eyez, 0,0,0, 0,1,0);
}

static void timer(int x){
    r_sol += 0.5;
    r_mercurio += 0.3;
    r_terra += 0.4;
    r_venus += 0.3;
    r_marte += 0.3;
    r_jupiter += 0.2;
    r_saturno += 0.2;
    r_urano += 0.2;
    r_netuno += 0.2;
    r_lua += 0.5;

    t_mercurio += 5.0;
    t_venus += 3.0;
    t_terra += 2.0;
    t_jupiter += 0.5;
    t_saturno += 0.3;
    t_urano += 0.2;
    t_netuno += 0.1;
    t_lua += 2.0;
    glutTimerFunc(25, timer,0);
}

void sphere(GLfloat radius){
    glutSolidSphere(radius, 25 , 25);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
        glColor3f(0.5f, 0.5f, 0.5f);
        glBegin(GL_LINE_LOOP);
            for(int i = 0; i < 360; i++){
                float theta = i * pi / 180;
                glVertex3f(20 * cos(theta), 20 * sin(theta), 0);
            }
        glEnd();
        glBegin(GL_LINE_LOOP);
            for(int i = 0; i < 360; i++){
                float theta = i * pi / 180;
                glVertex3f(30 * cos(theta), 30 * sin(theta), 0);
            }
        glEnd();
        glBegin(GL_LINE_LOOP);
            for(int i = 0; i < 360; i++){
                float theta = i * pi / 180;
                glVertex3f(40 * cos(theta), 40 * sin(theta), 0);
            }
        glEnd();
        glBegin(GL_LINE_LOOP);
            for(int i = 0; i < 360; i++){
                float theta = i * pi / 180;
                glVertex3f(52 * cos(theta), 52 * sin(theta), 0);
            }
        glEnd();
        glBegin(GL_LINE_LOOP);
            for(int i = 0; i < 360; i++){
                float theta = i * pi / 180;
                glVertex3f(65 * cos(theta), 65 * sin(theta), 0);
            }
        glEnd();
        glBegin(GL_LINE_LOOP);
            for(int i = 0; i < 360; i++){
                float theta = i * pi / 180;
                glVertex3f(80 * cos(theta), 80 * sin(theta), 0);
            }
        glEnd();
        glBegin(GL_LINE_LOOP);
            for(int i = 0; i < 360; i++){
                float theta = i * pi / 180;
                glVertex3f(100 * cos(theta), 100 * sin(theta), 0);
            }
        glEnd();
        glBegin(GL_LINE_LOOP);
            for(int i = 0; i < 360; i++){
                float theta = i * pi / 180;
                glVertex3f(110 * cos(theta), 110 * sin(theta), 0);
            } 
        glEnd();
        glRotatef(r_sol, 0, 0, 1.0);
        glColor3f(1.0f, 1.0f, 0.0f);
        sphere(14);
    glPopMatrix();
    
    glPushMatrix();
        glRotatef(r_mercurio, 0, 0, 1.0);
         glTranslatef(20*cos(t_mercurio*pi/180),20*sin(t_mercurio*pi/180),0);
         glColor3f(0.54f, 0.27f, 0.07f);
        sphere(0.9);
    glPopMatrix();

    glPushMatrix();
        glRotatef(r_venus, 0, 0, 1.0);
        glTranslatef(30*cos(t_venus*pi/180),30*sin(t_venus*pi/180),0);
        glColor3f(0.8f, 0.5f, 0.2f);
        sphere(1.5);
    glPopMatrix();

    glPushMatrix();
        glRotatef(r_terra, 0, 0, 1.0);
        glTranslatef(40*cos(t_terra*pi/180),40*sin(t_terra*pi/180),0);
        glColor3f(0.0f, 0.0f, 1.0f);
        sphere(2.5);
        
        glTranslatef(5*cos(t_lua*pi/180),5*sin(t_lua*pi/180),0);
        glRotatef(r_lua, 0, 0, 1.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        sphere(0.5);
    glPopMatrix();

    if((int) t_terra % 360 < 100 ){
         glPushMatrix();
            glRotatef(r_sol, 0, 0, 1.0);
            glColor3f(1.0f, 1.0f, 0.0f);
            sphere(14);
        glPopMatrix();
    }

    glPushMatrix();
        glRotatef(r_marte, 0, 0, 1.0);
        glTranslatef(52*cos(t_marte*pi/180),52*sin(t_marte*pi/180),0);
        glColor3f(1.0f, 0.0f, 0.0f);
        sphere(2);
    glPopMatrix();

    glPushMatrix();
        glRotatef(r_jupiter, 0, 0, 1.0);
        glTranslatef(65*cos(t_jupiter*pi/180),65*sin(t_jupiter*pi/180),0);
        glColor3f(0.5f, 0.5f, 0.5f);
        sphere(7);
    glPopMatrix();

    glPushMatrix();
        glRotatef(r_saturno, 0, 0, 1.0);
        glTranslatef(80*cos(t_saturno*pi/180),80*sin(t_saturno*pi/180),0);
        glColor3f(0.5f, 0.5f, 0.5f);
        sphere(6.5);

        glColor3f(0.9f, 0.9f, 0.97f);
        glLineWidth(5.0);
        glBegin(GL_LINE_LOOP);
            for(int i = 0; i < 360; i++){
                float theta = i * pi / 180;
                glVertex3f(11 * cos(theta), 11 * sin(theta), 0);
            }
        glEnd();

        glColor3f(0.84f, 0.87f, 0.87f);
        glLineWidth(3.0);
        glBegin(GL_LINE_LOOP);
            for(int i = 0; i < 360; i++){
                float theta = i * pi / 180;
                glVertex3f(13 * cos(theta), 13 * sin(theta), 0);
            }
        glEnd();
        glLineWidth(0.5);
    glPopMatrix();
    
    glPushMatrix();
        glRotatef(r_urano, 0, 0, 1.0);
        glTranslatef(100*cos(t_urano*pi/180),100*sin(t_urano*pi/180),0);
        glColor3f(0.0f, 0.0f, 0.7f);
        sphere(4);
    glPopMatrix();

    glPushMatrix();
        glRotatef(r_netuno, 0, 0, 1.0);
        glTranslatef(110*cos(t_netuno*pi/180),110*sin(t_netuno*pi/180),0);
        glColor3f(0.0f, 0.0f, 1.0f);
        sphere(4);
    glPopMatrix();



    glutSwapBuffers();
}


void reshape (GLsizei w, GLsizei h){
    if ( h == 0 ) h = 1;
    glViewport(0, 0, w, h);
    fAspect = (GLfloat)w/(GLfloat)h;
    cam();
}


/*Programa principal */
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (2000, 900);
    glutInitWindowPosition (100, 100);

    glutCreateWindow ("Sistema solar");
    myInit();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutTimerFunc(25, timer,0);
    glutMainLoop();
    return 0;
}
