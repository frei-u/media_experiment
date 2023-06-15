#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#ifdef _MSC_VER
#define _USE_MATH_DEFINES
#endif
#include <math.h>

float xpos, ypos, zpos = 0.0;
float ry, rz;
int width, height;

GLdouble vertex[][3] = {
  { 0.0, 0.0, 0.0 },
  { 0.5, 0.0, 0.0 },
  { 0.5, 0.5, 0.0 },
  { 0.0, 0.5, 0.0 },
  { 0.0, 0.0, 0.5 },
  { 0.5, 0.0, 0.5 },
  { 0.5, 0.5, 0.5 },
  { 0.0, 0.5, 0.5 }
};

GLdouble trtex[][3] = {
  { 0.25, 0.7, 0.25 },
  { -0.02, 0.5, -0.02 },
  { 0.52, 0.5, -0.02 },
  { 0.52, 0.5, 0.52 },
  { -0.02, 0.5, 0.52 },
};

int face[][4] = {
  { 0, 1, 2, 3 }, /* A-B-C-D を結ぶ面 */
  { 1, 5, 6, 2 }, /* B-F-G-C を結ぶ面 */
  { 5, 4, 7, 6 }, /* F-E-H-G を結ぶ面 */
  { 4, 0, 3, 7 }, /* E-A-D-H を結ぶ面 */
  { 4, 5, 1, 0 }, /* E-F-B-A を結ぶ面 */
  { 3, 2, 6, 7 }  /* D-C-G-H を結ぶ面 */
};

int trface[][3] = { //三角錐（一軒家の屋根）
  { 0, 1, 2 },
  { 0, 2, 3 },
  { 0, 3, 4 },
  { 0, 4, 1 },
  { 1, 2, 3 },
  { 1, 2, 4 }
};

GLdouble normal[][3] = {
  { 0.0, 0.0,-1.0 },
  { 1.0, 0.0, 0.0 },
  { 0.0, 0.0, 1.0 },
  {-1.0, 0.0, 0.0 },
  { 0.0,-1.0, 0.0 },
  { 0.0, 1.0, 0.0 }
};

GLdouble builtex1[][3] = {
{ 0.0, 0.0, 0.0 },
{ 1.5, 0.0, 0.0 },
{ 1.5, 3.0, 0.0 },
{ 0.0, 3.0, 0.0 },
{ 0.0, 0.0, 1.5 },
{ 1.5, 0.0, 1.5 },
{ 1.5, 3.0, 1.5 },
{ 0.0, 3.0, 1.5 }
};

GLdouble builtex2[][3] = {
{ 0.0, 0.0, 0.0 },
{ 1.0, 0.0, 0.0 },
{ 1.0, 2.0, 0.0 },
{ 0.0, 2.0, 0.0 },
{ 0.0, 0.0, 1.0 },
{ 1.0, 0.0, 1.0 },
{ 1.0, 2.0, 1.0 },
{ 0.0, 2.0, 1.0 }
};

GLfloat light0pos[] = { 20.0, 15.0, 20.0, 1.0 };

GLfloat white[] = {1.0 ,1.0, 1.0, 1.0};
GLfloat green[] = { 0.0, 1.0, 0.0, 1.0 };
GLfloat red[] = { 0.8, 0.2, 0.2, 1.0 };
GLfloat blue[] = { 0.2, 0.2, 0.8, 1.0 };
GLfloat grey[] = { 0.6, 0.6, 0.6, 1.0 };

void buil(GLdouble b_tex[][3], GLfloat color[], GLdouble x, GLdouble y, GLdouble z)
{
    int i;
    int j;

    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color);
    glTranslated(x, y, z);
    glBegin(GL_QUADS);
    for (j = 0; j < 6; ++j) {
        glNormal3dv(normal[j]);
        for (i = 0; i < 4; ++i) {
            glVertex3dv(b_tex[face[j][i]]);
        }
    }
    glEnd();
    glPopMatrix();
}

void home(GLfloat color1[], GLfloat color2[], GLdouble x, GLdouble y, GLdouble z)
{
    int i;
    int j;

    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color1);
    glTranslated(x, y, z);
    glBegin(GL_QUADS);
    for (j = 0; j < 6; ++j) {
        glNormal3dv(normal[j]);
        for (i = 0; i < 4; ++i) {
            glVertex3dv(vertex[face[j][i]]);
        }
    }
    glEnd();

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color2);
    glBegin(GL_TRIANGLES);
    for (j = 0; j < 6; ++j) {
        glNormal3dv(normal[j]);
        for (i = 0; i < 3; ++i) {
            glVertex3dv(trtex[trface[j][i]]);
        }
    }
    glEnd();
    glPopMatrix();
}

void draw_home() {

    home(white, blue, -4.0, 0, 3.0);
    home(white, blue, 8.2, 0, 3.0);
    home(white, blue, -4.0, 0, 4.0);
    home(white, blue, 8.2, 0, 4.0);
    home(white, blue, -4.0, 0, 5.0);
    home(white, blue, 8.2, 0, 5.0);
    home(white, blue, -4.0, 0, 6.0);
    home(white, blue, 8.2, 0, 6.0);

    home(white, blue, 5.0, 0, 3.0);
    home(white, blue, 5.7, 0, 3.0);
    home(white, blue, 5.0, 0, 4.0);
    home(white, blue, 5.7, 0, 4.0);
    home(white, blue, 5.0, 0, 5.0);
    home(white, blue, 5.7, 0, 5.0);
    home(white, blue, 5.0, 0, 6.0);
    home(white, blue, 5.7, 0, 6.0);

    home(white, red, 2.5, 0, 3.0);
    home(white, red, 3.2, 0, 3.0);
    home(white, red, 2.5, 0, 4.0);
    home(white, red, 3.2, 0, 4.0);
    home(white, red, 2.5, 0, 5.0);
    home(white, red, 3.2, 0, 5.0);
    home(white, red, 2.5, 0, 6.0);
    home(white, red, 3.2, 0, 6.0);

    home(white, red, 2.5, 0, 8.0);
    home(white, red, 3.2, 0, 8.0);
    home(white, red, 2.5, 0, 9.0);
    home(white, red, 3.2, 0, 9.0);

    home(white, red, 2.5, 0, 3.0);
    home(white, red, 3.2, 0, 3.0);
    home(white, red, 2.5, 0, 4.0);
    home(white, red, 3.2, 0, 4.0);
    home(white, red, 2.5, 0, 5.0);
    home(white, red, 3.2, 0, 5.0);
    home(white, red, 2.5, 0, 6.0);
    home(white, red, 3.2, 0, 6.0);

    home(white, red, 0.0, 0, 3.0);
    home(white, red, 0.7, 0, 3.0);
    home(white, red, 0.0, 0, 4.0);
    home(white, red, 0.7, 0, 4.0);
    home(white, red, 0.0, 0, 5.0);
    home(white, red, 0.7, 0, 5.0);
    home(white, red, 0.0, 0, 6.0);
    home(white, red, 0.7, 0, 6.0);

    home(white, red, 2.5, 0, 3.0);
    home(white, red, 3.2, 0, 3.0);
    home(white, red, 2.5, 0, 4.0);
    home(white, red, 3.2, 0, 4.0);
    home(white, red, 2.5, 0, 5.0);
    home(white, red, 3.2, 0, 5.0);
    home(white, red, 2.5, 0, 6.0);
    home(white, red, 3.2, 0, 6.0);
}

void station(GLdouble x, GLdouble y, GLdouble z)
{
    int i;
    int j;
    GLdouble sttex[][3] = {
    { -10.1, 0.0, 0.0 },
    { 10.1,  0.0, 0.0 },
    { 10.1,  0.4, 0.0 },
    { -10.1, 0.4, 0.0 },
    { -10.1, 0.0, 2.0 },
    { 10.1,  0.0, 2.0 },
    { 10.1,  0.4, 2.0 },
    { -10.1, 0.4, 2.0 }
    };

    GLdouble ktex1[][3] = {
    { -10.1, 0.0, -0.4 },
    { -9.0,  0.0, -0.4 },
    { -9.0,  0.8, -0.4 },
    { -10.1, 0.8, -0.4 },
    { -10.1, 0.0, 2.4 },
    { -9.0,  0.0, 2.4 },
    { -9.0,  0.8, 2.4 },
    { -10.1, 0.8, 2.4 }
    };

    GLdouble ktex2[][3] = {
    { 10.1, 0.0, 0.0 },
    { 9.0,  0.0, 0.0 },
    { 9.0,  0.8, 0.0 },
    { 10.1, 0.8, 0.0 },
    { 10.1, 0.0, 2.0 },
    { 9.0,  0.0, 2.0 },
    { 9.0,  0.8, 2.0 },
    { 10.1, 0.8, 2.0 }
    };

    GLdouble ekibtex[][3] = {
    { 10.0, 0.0, 2.0 },
    { 2.0,  0.0, 2.0 },
    { 2.0,  3.3, 2.0 },
    { 10.0, 3.3, 2.0 },
    { 10.0, 0.0, 5.0 },
    { 2.0,  0.0, 5.0 },
    { 2.0,  3.3, 5.0 },
    { 10.0, 3.3, 5.0 }
    };

    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, grey);
    glTranslated(x, y, z);
    glBegin(GL_QUADS);
    for (j = 0; j < 6; ++j) {
        glNormal3dv(normal[j]);
        for (i = 0; i < 4; ++i) {
            glVertex3dv(sttex[face[j][i]]);
        }
    }
    glEnd();

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, grey);
    glBegin(GL_QUADS);
    for (j = 0; j < 6; ++j) {
        glNormal3dv(normal[j]);
        for (i = 0; i < 4; ++i) {
            glVertex3dv(ktex1[face[j][i]]);
        }
    }
    glEnd();

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, grey);
    glBegin(GL_QUADS);
    for (j = 0; j < 6; ++j) {
        glNormal3dv(normal[j]);
        for (i = 0; i < 4; ++i) {
            glVertex3dv(ktex2[face[j][i]]);
        }
    }
    glEnd();

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, blue);
    glBegin(GL_QUADS);
    for (j = 0; j < 6; ++j) {
        glNormal3dv(normal[j]);
        for (i = 0; i < 4; ++i) {
            glVertex3dv(ekibtex[face[j][i]]);
        }
    }
    glEnd();
    glPopMatrix();
}

void rail(GLdouble x, GLdouble y, GLdouble z)
{

    int i;
    int j;
    GLdouble ritex[][3] = {
    { -15.0, 0.0,  0.0 },
    { 15.0,  0.0,  0.0 },
    { 15.0,  0.02, 0.0 },
    { -15.0, 0.02, 0.0 },
    { -15.0, 0.0,  0.015 },
    { 15.0,  0.0,  0.015 },
    { 15.0,  0.02, 0.015 },
    { -15.0, 0.02, 0.015 }
    };

    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, red);
    glTranslated(x, y, z);
    glTranslated(0.0, 0.0, 0.75);
    glBegin(GL_QUADS);
    for (j = 0; j < 6; ++j) {
        glNormal3dv(normal[j]);
        for (i = 0; i < 4; ++i) {
            glVertex3dv(ritex[face[j][i]]);
        }
    }
    glEnd();

    glTranslated(0.0, 0.0, 0.1);
    glBegin(GL_QUADS);
    for (j = 0; j < 6; ++j) {
        glNormal3dv(normal[j]);
        for (i = 0; i < 4; ++i) {
            glVertex3dv(ritex[face[j][i]]);
        }
    }
    glEnd();

    glTranslated(0.0, 0.0, 0.3);
    glBegin(GL_QUADS);
    for (j = 0; j < 6; ++j) {
        glNormal3dv(normal[j]);
        for (i = 0; i < 4; ++i) {
            glVertex3dv(ritex[face[j][i]]);
        }
    }
    glEnd();

    glTranslated(0.0, 0.0, 0.1);
    glBegin(GL_QUADS);
    for (j = 0; j < 6; ++j) {
        glNormal3dv(normal[j]);
        for (i = 0; i < 4; ++i) {
            glVertex3dv(ritex[face[j][i]]);
        }
    }
    glEnd();

    glPopMatrix();
}

void train()
{
    station(0.0, 0.0, -4.5);
    rail(0.0, 0.0, -4.5);
}

void idle(void)
{
    glutPostRedisplay();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* 光源の位置設定 */
    glLoadIdentity();
    
    gluLookAt(15.0, 0.3, 0.0, 0.0, 0.15, 0.0, 0.0, 1.0, 0.0);
    glTranslated(xpos, ypos, zpos);
    glRotated(ry, 0.0, 0.0, 1.0);
    glRotated(rz, 0.0, 1.0, 0.0);
    

    glLightfv(GL_LIGHT0, GL_POSITION, light0pos);

    /* 図形の描画 */
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, grey);
    glBegin(GL_POLYGON);
    glNormal3f(0, 1, 0);
    glVertex3d(-15.0, 0.0, 15.0);
    glVertex3d(15.0, 0.0, 15.0);
    glVertex3d(15.0, 0.0, -5.0);
    glVertex3d(-15.0, 0.0, -5.0);
    glEnd();

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, green);
    glBegin(GL_POLYGON);
    glNormal3f(0, 1, 0);
    glVertex3d(7.5, 0.001, 8.0);
    glVertex3d(7.5, 0.001, 10.0);
    glVertex3d(10.0, 0.001, 10.0);
    glVertex3d(10.0, 0.001, 8.0);
    glEnd();

    buil(builtex2, green, -6.0, 0, -1.1);
    
    draw_home();

    train();

    glutSwapBuffers();
}

void resize(int w, int h)
{
    glViewport(0, 0, w, h);

    /* 透視変換行列の設定 */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, (double)w / (double)h, 1.0, 100.0);

    /* モデルビュー変換行列の設定 */
    glMatrixMode(GL_MODELVIEW);
}

void mouse(int button, int state, int x, int y)
{

}

void keyboard(unsigned char key, int x, int y)
{
    float step = 0.1;
    float step_r = 1.0;

    switch (key) {
    case 'q':
    case 'Q':
    case '\033':  /* '\033' は ESC の ASCII コード */
        exit(0);
        break;
    case 'w':
    case 'W':
        xpos += step;
        break;
    case 's':
    case 'S':
        xpos -= step;
        break;
    case 'a':
    case 'A':
        zpos -= step;
        break;
    case 'd':
    case 'D':
        zpos += step;
        break;
    case 'r':
    case 'R':
        ry -= step_r;
        break;
    case 'f':
    case 'F':
        ry += step_r;
        break;
    case 'z':
    case 'Z':
        rz += step_r;
        break;
    case 'X':
    case 'x':
        rz -= step_r;
        break;

    default:
        break;
    }
    if (rz >= 360.0) rz -= 360.0;
    else if (rz < 0.0) rz += 360.0;
    if (ry >= 360.0) ry -= 360.0;
    else if (ry < 0.0) ry += 360.0;

    glutPostRedisplay();
}

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);

    glEnable(GL_DEPTH_TEST);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

int main(int argc, char* argv[])
{
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(320, 240);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();
    return 0;
}