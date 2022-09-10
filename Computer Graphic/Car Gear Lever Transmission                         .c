#include<windows.h>
#include<GL/glut.h>
#include<math.h>

GLfloat r=6;
int num =-1;
int col[6] = {0,0,0,0,0,0};

void key(unsigned char ch,int x, int y)
{
    int i;
    if(ch=='1')
    {
        num=1;
        for(i=0; i<6; i++)
            col[i]=0;
        col[0]=1;
    }
    if(ch=='2')
    {
        num=2;
        for(i=0; i<6; i++)
            col[i]=0;
        col[1]=1;
    }
    if(ch=='3')
    {
        num=3;
        for(i=0; i<6; i++)
            col[i]=0;
        col[2]=1;
    }
    if(ch=='4')
    {
        num=4;
        for(i=0; i<6; i++)
            col[i]=0;
        col[3]=1;
    }
    if(ch=='5')
    {
        num=5;
        for(i=0; i<6; i++)
            col[i]=0;
        col[4]=1;
    }
    if(ch=='r')
    {
        num=6;
        for(i=0; i<r; i++)
            col[i]=0;
        col[5]=1;
    }
    if(ch=='a')
        num=-1;

    glutPostRedisplay();
}

void colorBox()
{
    glPushMatrix(); //first
    if(col[0]==1)
        glColor3f(1,0,1);
    else
        glColor3f(1,1,1);
    glTranslatef(-0.75,0.55,0);
    glScalef(0.1,0.1,0);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix(); //second
    if(col[1]==1)
        glColor3f(1,0.5,0);
    else
        glColor3f(1,1,1);
    glTranslatef(-0.75,0.45,0);
    glScalef(0.1,0.1,0);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix(); //third
    if(col[2]==1)
        glColor3f(1.68,1.369,0);
    else
        glColor3f(1,1,1);
    glTranslatef(-0.65,0.55,0);
    glScalef(0.1,0.1,0);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix(); //fourth
    if(col[3]==1)
        glColor3f(0,0.25,1);
    else
        glColor3f(1,1,1);
    glTranslatef(-0.65,0.45,0);
    glScalef(0.1,0.1,0);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix(); //fifth
    if(col[4]==1)
        glColor3f(0.68,1.85,0.33);
    else
        glColor3f(1,1,1);
    glTranslatef(-0.55,0.55,0);
    glScalef(0.1,0.1,0);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix(); //reverse
    if(col[5]==1)
        glColor3f(1,0,0);
    else
        glColor3f(1,1,1);
    glTranslatef(-0.55,0.45,0);
    glScalef(0.1,0.1,0);
    glutSolidCube(1);
    glPopMatrix();

    glBegin(GL_LINE_LOOP);
    glColor3f(1,0,0);
    glVertex2f(-0.8, 0.4);
    glVertex2f(-0.8, 0.6);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(1,0,0);
    glVertex2f(-0.5, 0.4);
    glVertex2f(-0.499, 0.6);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(1,0,0);
    glVertex2f(-0.8, 0.6);
    glVertex2f(-0.5, 0.6);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(1,0,0);
    glVertex2f(-0.8, 0.399);
    glVertex2f(-0.5, 0.399);
    glEnd();

}

void gear()
{
    glPushMatrix(); //base cube
    glColor3f(0.2,0.2,0.2);
    glScalef(1,0.03,1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix(); //1 cube
    glColor3f(0.25,0.25,0.25);
    glTranslatef(0,0.1,0);
    glScalef(0.1,0.1,0.1);
    glutSolidCube(1.5);
    glPopMatrix();

    //Angle of gear movement
    if(num==-1)
        glRotated(0,0,0,0); //at origin state by default
    else if(num==1)
        glRotated(15,0,0,1); //  z->axis for 1st gear
    else if(num==2)
        glRotated(15,0,0,-1); //  -z->Axis for 2nd gear
    else if(num==3)
        glRotated(20,-1,0,1); //  z->Axis & -x->Axis 3rd gear
    else if(num==4)
        glRotated(20,-1,0,-1); //  -x->Axis & -z->Axis 4th gear
    else if(num==5)
        glRotated(25,-2,0,2); //  -x->Axis & z->Axis 5th gear
    else
        glRotated(25,-2,0,-2); //  -x->Axis & -z->Axis Reverse gear)


    glPushMatrix(); //rod
    glColor3f(0.43,0.43,0.43);
    glTranslatef(0,0.3,0);
    glScalef(0.05,0.5,0.05);
    glutSolidCube(1.3);
    glPopMatrix();

    glPushMatrix(); //sphere
    glColor3f(0.69,0.69,0.69);
    glTranslatef(0,0.75,0);
    glScalef(0.05,0.1,0.05);
    glutSolidSphere(2,25,25);
    glPopMatrix();

}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt(2,1,2,0,0,0,0,1,0);

    colorBox();
    gear();
    glutSwapBuffers();
}

void MyInit()
{
    glClearColor(0.08,1,1,1);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1,1,-1,1,2,10);
    glMatrixMode(GL_MODELVIEW);

}
int main(int c, char *v[])
{
    glutInit(&c,v);
    glutInitWindowSize(1000,500);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Car Gear Lever 3D Transmission");
    glLoadIdentity();
    glutDisplayFunc(Draw);
    glutKeyboardFunc(key);
    MyInit();
    glutMainLoop();
    return 0;
} 
