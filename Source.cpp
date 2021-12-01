#include <iostream>
#include <gl/glut.h>
#include <stdio.h>


void translateTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int dx, int dy)
{
	int xend1, yend1; // P1
	int xend2, yend2; // P2
	int xend3, yend3; // P#

	xend1 = x1 + dx;
	yend1 = y1 + dy;
	xend2 = x2 + dx;
	yend2 = y2 + dy;
	xend3 = x3 + dx;
	yend3 = y3 + dy;

	glColor3d(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2i(xend1, yend1);
	glVertex2i(xend2, yend2);
	glVertex2i(xend3, yend3);
	glEnd();
}



void myDisplayFunction(void)						 // this is your function
{




	glClear(GL_COLOR_BUFFER_BIT);					// clear the screen

	
		// Triangle
	glColor3f(0.0,0.0,1.0);
			glBegin(GL_POLYGON);
				
				glVertex2i(50, 75);
				
				glVertex2i(75, 125);
				
				glVertex2i(100, 75);
			glEnd();

			
		

		

	glFlush();							// send all output to display
	
}


void mouse(int button, int state, int x, int y) 
{	

	glClear(GL_COLOR_BUFFER_BIT);					// clear the screen

	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
		{
			
			translateTriangle(50, 75, 75, 125, 100, 75, 100, 120);
		
			
		}
		glFlush();
		break;

	
	}
	
	
}

void main(int argc, char** argv)					// start of main program
{


	glutInit(&argc, argv);						// initialize the GLUT library
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);		        // set the display mode
	glutInitWindowSize(512, 512);						// set window screen size
	glutInitWindowPosition(100, 100);					// set window position on screen
	glutCreateWindow("Isaiah White-Booth");				// open the screen window with title


	 glutDisplayFunc(myDisplayFunction);					// register the callback function

	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);				// set white background color
	glColor3d(0.0, 0.0, 0.0);							// set black drawing color
	gluOrtho2D(0.0, 511.0, 0.0, 511.0);					// specify screen coordinates
									  // bottom left = (0,0)
									  // top right = (511, 511)

	glutMouseFunc(mouse);
	glutMainLoop();							// go into a perpetual loop

}
