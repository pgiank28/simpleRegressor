using namespace std;

struct point{
    float x;
    float y;
};

struct cline{
    float a;
    float b;
    float c;
};

struct list{
    list* next;
    point* cur;
};

typedef point* dot;
typedef cline* line;

dot readTupple(string input,dot tup);

//Calculation of the perpendicular distance between a given point and a line
//in the x-y plane.
float perpendicularDistance(dot tupple,line curRegr);

//Calculation of the horizontal distance between a given point and a line
//in the x-y plane.
float horizontalDistance(dot tupple,line curRegr);

//Calculation of the vertical distance between a given point and a line
//int the x-y plane.
float verticalDistance(dot tupple,line curRegr);

//Calculation of the distance between a given point and the horizontal line
//y=avg, where avg is the mean y of all the given points at the plane.
float rSquaredDistance(dot tupple,line curRegr );

//The core linear regressor.Given a line L,it adapts the line so the distance between the line and
//the given points reduces,using gradient descent.It returns the best fit line.
line minimizeVerticalDistance(line L,int a,dot points,int numOfPoints,float ab);
