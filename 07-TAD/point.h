struct tpoint 
{
    int x,y;
}; typedef struct tpoint Point;

Point setPoint(int, int);
Point getPoint(Point);
int getX(Point);
int getY(Point);
void printPoint(Point, int);
float distancePoint (Point, Point);