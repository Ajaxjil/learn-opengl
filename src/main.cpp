#include <stdio.h>

int main(int argc,char** argv)
{
    if(!initGL(argc, argv))
        return 0;

    glutMainLoop();

    return 0;
}

/*
* GLUT main initialization function
*/
bool initGL(int argc, char** argv)
{
    //Initialize GLUT
    glutInit(&argc, argv);
    glutInitContextVersion(3, 3);
	glutInitContextFlags(GLUT_FORWARD_COMPATIBLE);
	glutInitContextProfile(GLUT_CORE_PROFILE);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	//Set window size
	glutInitWindowSize(g_width, g_height);

	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

	int windowHandle = glutCreateWindow(WINDOW_TITLE);
	if( 1 > windowHandle)
	{
		fprintf(stderr, "ERROR Could not create new window\n");
		return false;
	}

	//GLUT functions
	glutReshapeFunc(reshape);
	glutDisplayFunc(render);
	glutIdleFunc(idle);
	glutTimerFunc(0, timer, 0);
	glutCloseFunc(cleanup);

	//Required when building for Linux.
	glewExperimental = GL_TRUE;

	//Glew initialization
	glewInitResult = glewInit();
	if(GLEW_OK != glewInitResult)
	{
		fprintf(stderr, "ERROR: %s\n", glewGetErrorString( glewInitResult));
		return false;
	}

	fprintf(stdout, "INFO OpenGL version: %s\n", glGetString( GL_VERSION));
	
	createShaders();
	createVBO();
	
	return true;
}
