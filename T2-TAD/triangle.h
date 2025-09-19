
struct ttriangle
{
    int lado_a, lado_b, lado_c; 
};typedef struct ttriangle trngl;

void setTriangle(trngl *, int , int, int );
int getType(trngl );
void showTriangle(trngl );
int getPerimeter(trngl );
float getArea(trngl );
float cosA(trngl);
float cosB(trngl);
int isSimilar(trngl, trngl);


