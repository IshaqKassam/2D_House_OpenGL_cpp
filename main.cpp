#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>    

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

void drawSemiCircle(GLfloat x, GLfloat y, GLfloat radius, GLint numberOfSides);
void drawCircle(GLfloat x, GLfloat y, GLfloat radius, GLint numberOfSides);
void drawCircleFill(float cx, float cy, float r, int num_segments);

int main(void)
{
    GLFWwindow* window;

    // Initialize the library
    if (!glfwInit())
    {
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "House", NULL, NULL); // "Polygon" is title of window

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT); // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
    glMatrixMode(GL_PROJECTION); // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
    glLoadIdentity(); // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
    glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1); // essentially set coordinate system
    glMatrixMode(GL_MODELVIEW); // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
    glLoadIdentity(); // same as above comment
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    GLfloat polygonVertices[] =
    {
        200, 240, 0, // 1 
        160, 240, 0, // 2
        160, 300, 0, // 3
        480, 300, 0,// 4
        480, 240, 0,// 5
        440, 240, 0,// 6
        440, 120, 0,// 7
        200, 120, 0,// 8
    };
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glLineWidth(1);
    GLfloat door[] =
    {
        280, 120, 0,
        280, 220, 0, // X, Y , Z Format
        360, 220, 0,// Follows on from above point (1) in CLOCK-WISE MANNER
        360, 120, 0,
    };

    GLfloat window1[] =
    {
        220, 180, 0,
        220, 220, 0, // X, Y , Z Format
        260, 220, 0,// Follows on from above point (1) in CLOCK-WISE MANNER
        260, 180, 0,
    };

    GLfloat window2[] =
    {
        380, 180, 0,
        380, 220, 0, // X, Y , Z Format
        420, 220, 0,// Follows on from above point (1) in CLOCK-WISE MANNER
        420, 180, 0,
    };

    GLfloat line1_left[] =
    {
        240, 180, 0,
        240, 220, 0
    };

    GLfloat line2_left[] =
    {
        220, 200, 0,
        260, 200, 0
    };

    GLfloat line1_right[] =
    {
        400, 180, 0,
        400, 220, 0
    };

    GLfloat line2_right[] =
    {
        380, 200, 0,
        420, 200, 0
    };


    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // polygon drawing mode (GL_POINT, GL_LINE, GL_FILL)


    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        // render OpenGL here
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glEnableClientState(GL_VERTEX_ARRAY);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glColor3f(0.8, 0.0, 0.6);//purple
        glVertexPointer(3, GL_FLOAT, 0, polygonVertices);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawArrays(GL_POLYGON, 0, 8); // Number of points in polygon
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDisableClientState(GL_VERTEX_ARRAY);
        glColor3f(0.2, 0.2, 0.2);//blackish
        // render OpenGL here 
        glEnableClientState(GL_VERTEX_ARRAY);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glVertexPointer(3, GL_FLOAT, 0, door);
        glDrawArrays(GL_POLYGON, 0, 4);// Number of points in polygon
        glDisableClientState(GL_VERTEX_ARRAY);

        // render OpenGL here 
        glEnableClientState(GL_VERTEX_ARRAY);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glVertexPointer(3, GL_FLOAT, 0, window1);
        glDrawArrays(GL_POLYGON, 0, 4);// Number of points in polygon
        glDisableClientState(GL_VERTEX_ARRAY);

        // render OpenGL here 
        glEnableClientState(GL_VERTEX_ARRAY);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glVertexPointer(3, GL_FLOAT, 0, window2);
        glDrawArrays(GL_POLYGON, 0, 4);// Number of points in polygon
        glDisableClientState(GL_VERTEX_ARRAY);

        // Render OpenGL here
        glEnable(GL_LINE_SMOOTH);
        // glEnable( GL_LINE_STIPPLE );
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glPushAttrib(GL_LINE_BIT);
        glLineWidth(3);
        glLineStipple(1, 0x00FF);
        glEnableClientState(GL_VERTEX_ARRAY);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glVertexPointer(3, GL_FLOAT, 0, line1_left); // name of line
        glDrawArrays(GL_LINES, 0, 2);
        glDisableClientState(GL_VERTEX_ARRAY);
        glPopAttrib();
        glDisable(GL_LINE_STIPPLE);
        glDisable(GL_LINE_SMOOTH);

        // Render OpenGL here
        glEnable(GL_LINE_SMOOTH);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        // glEnable( GL_LINE_STIPPLE );
        glPushAttrib(GL_LINE_BIT);
        glLineWidth(3);
        glLineStipple(1, 0x00FF);
        glEnableClientState(GL_VERTEX_ARRAY);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        
        glVertexPointer(3, GL_FLOAT, 0, line2_left); // name of line
        glDrawArrays(GL_LINES, 0, 2);
        glDisableClientState(GL_VERTEX_ARRAY);
        glPopAttrib();
        glDisable(GL_LINE_STIPPLE);
        glDisable(GL_LINE_SMOOTH);

        // Render OpenGL here
        glEnable(GL_LINE_SMOOTH);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        // glEnable( GL_LINE_STIPPLE );
       
        glPushAttrib(GL_LINE_BIT);
        glLineWidth(3);
        glLineStipple(1, 0x00FF);
        glEnableClientState(GL_VERTEX_ARRAY);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glVertexPointer(3, GL_FLOAT, 0, line1_right); // name of line
        glDrawArrays(GL_LINES, 0, 2);
        glDisableClientState(GL_VERTEX_ARRAY);
        glPopAttrib();
        glDisable(GL_LINE_STIPPLE);
        glDisable(GL_LINE_SMOOTH);

        // Render OpenGL here
        glEnable(GL_LINE_SMOOTH);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        // glEnable( GL_LINE_STIPPLE );
        glPushAttrib(GL_LINE_BIT);
        glLineWidth(3);
        glLineStipple(1, 0x00FF);
        glEnableClientState(GL_VERTEX_ARRAY);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glVertexPointer(3, GL_FLOAT, 0, line2_right); // name of line
        glDrawArrays(GL_LINES, 0, 2);
        glDisableClientState(GL_VERTEX_ARRAY);
        glPopAttrib();
        glDisable(GL_LINE_STIPPLE);
        glDisable(GL_LINE_SMOOTH);

        // render OpenGL here - the semicircle on top
        glColor3f(0.8, 0.0, 0.6); //purple
        drawSemiCircle(320, 300, 120, 250); // movement on x axis, movement on y axis , size, 

        // render OpenGL here - door knob
        glColor3f(0.8, 0.0, 0.6); //purple
        glPolygonMode(GL_BACK, GL_FILL);
        drawCircleFill(350, 170, 5, 250); // movement on x axis, movement on y axis , radius, sides 
        

        
        
        glLineWidth(5);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glLineWidth(5);
        drawCircle(500, 400, 40, 360); // movement on x axis, movement on y axis , radius, sides
        glColor3f(0.8f, 0.6f, 0.2f); //Golden
        glLineWidth(5);
        drawCircleFill(500, 400, 40, 360); // movement on x axis, movement on y axis , radius, sides 
        glLineWidth(5);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glColor3f(1.0f, 1.0f, 1.0f); //white
        drawCircleFill(525, 410, 40, 360); // movement on x axis, movement on y axis , radius, sides 
        glColor3f(0.3, 0.3, 0.3);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        // Swap front and back buffers
        glfwSwapBuffers(window);
        glColor3f(0.3, 0.3, 0.3);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glLineWidth(1);
        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;

}


void drawSemiCircle(float cx, float cy, float r, int num_segments)
{
    float theta = 3.1415926 / float(num_segments);
    float tangetial_factor = tanf(theta);//calculate the tangential factor 

    float radial_factor = cosf(theta);//calculate the radial factor 

    float x = r;//we start at angle = 0 

    float y = 0;

    glBegin(GL_LINE_LOOP);
    for (int ii = 0; ii < num_segments; ii++)
    {
        glVertex2f(x + cx, y + cy);//output vertex 

        //calculate the tangential vector 
        //remember, the radial vector is (x, y) 
        //to get the tangential vector we flip those coordinates and negate one of them 

        float tx = -y;
        float ty = x;

        //add the tangential vector 

        x += tx * tangetial_factor;
        y += ty * tangetial_factor;

        //correct using the radial factor 

        x *= radial_factor;
        y *= radial_factor;
    }
    glEnd();
}

void drawCircle(float cx, float cy, float r, int num_segments)
{
    float theta = 3.1415926 * 2 / float(num_segments);
    float tangetial_factor = tanf(theta);//calculate the tangential factor 

    float radial_factor = cosf(theta);//calculate the radial factor 

    float x = r;//we start at angle = 0 

    float y = 0;
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    for (int ii = 0; ii < num_segments; ii++)
    {
        glVertex2f(x + cx, y + cy);//output vertex 

        //calculate the tangential vector 
        //remember, the radial vector is (x, y) 
        //to get the tangential vector we flip those coordinates and negate one of them 

        float tx = -y;
        float ty = x;

        //add the tangential vector 

        x += tx * tangetial_factor;
        y += ty * tangetial_factor;

        //correct using the radial factor 

        x *= radial_factor;
        y *= radial_factor;
    }
    glEnd();
}
void drawCircleFill(float cx, float cy, float r, int num_segments)
{
    float theta = 3.1415926 * 2 / float(num_segments);
    float tangetial_factor = tanf(theta);//calculate the tangential factor 
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    float radial_factor = cosf(theta);//calculate the radial factor 

    float x = r;//we start at angle = 0 

    float y = 0;

    //glClear(GL_COLOR_BUFFER_BIT);
    

    glBegin(GL_POLYGON);
    for (int ii = 0; ii < num_segments; ii++)
    {
        glVertex2f(x + cx, y + cy);//output vertex 
        
        //calculate the tangential vector 
        //remember, the radial vector is (x, y) 
        //to get the tangential vector we flip those coordinates and negate one of them 

        float tx = -y;
        float ty = x;

        //add the tangential vector 

        x += tx * tangetial_factor;
        y += ty * tangetial_factor;

        //correct using the radial factor 

        x *= radial_factor;
        y *= radial_factor;
    }
    glEnd();
}
