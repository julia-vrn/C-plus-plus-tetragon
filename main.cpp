#include <QCoreApplication>
#include <iostream>
#include <QFile>
#include <QTextStream>

using namespace std;

struct Point{
    int x;
    int y;
};

float distance(Point a, Point b);
float area(Point pArr[], int l);
float perimeter(Point pArr[], int l);
void writeFile (Point pArr[], float &per, float &area);

int main()
{

    QFile resFile ("result.txt");
    resFile.remove();

    Point pArray[4];
    pArray[0].x = 0;
    pArray[0].y = 0;
    pArray[1].x = 0;
    pArray[1].y = 5;
    pArray[2].x = 5;
    pArray[2].y = 5;
    pArray[3].x = 5;
    pArray[3].y = 0;

    Point testArr[4];
    testArr[0].x = 2;
    testArr[0].y = 2;
    testArr[1].x = 4;
    testArr[1].y = 5;
    testArr[2].x = 6;
    testArr[2].y = 5;
    testArr[3].x = 5;
    testArr[3].y = 3;



   int len = sizeof(pArray)/sizeof (pArray[0]);
   float a = area(pArray, len);
   float p = perimeter(pArray, len);
   writeFile(pArray, p, a);

   int lenT = sizeof(testArr)/sizeof (testArr[0]);
   float testP = perimeter(testArr, lenT);
   float testA = area(testArr, lenT);
   writeFile(testArr, testP, testA);
   return 0;
}


float distance(Point a, Point b){
    float dis = sqrt(pow((b.x-a.x), 2)+pow((b.y-a.y), 2));
    return dis;
}


float perimeter(Point pArr[], int l){
    float per = 0;
    int i = 0;
    while(i<l-1){
        per = per + distance(pArr[i], pArr[i+1]);
        i++;
    }
    per = per + distance(pArr[i], pArr[0]);
    cout<<"The perimeter of the tetragon is " << per << ";" << endl;
    return per;
}

float area(Point pArr[], int l){
    /*float area = abs(0.5*((pArr[0].x*pArr[1].y-pArr[1].x*pArr[0].y)+(pArr[1].x*pArr[2].y-pArr[2].x*pArr[1].y)+(pArr[2].x*pArr[3].y-pArr[3].x*pArr[2].y)+
            (pArr[3].x*pArr[0].y-pArr[0].x*pArr[3].y)));*/
    int i = 0;
    float area = 0;
    while(i<l-1){
        area = area + (pArr[i].x*pArr[i+1].y-pArr[i+1].x*pArr[i].y);
        cout<<"Debug "<<area<<endl;
        i++;
    }
    area = abs(0.5*(area + (pArr[i].x*pArr[0].y-pArr[0].x*pArr[i].y)));
    cout << "The total area of the tatragon is " << area << ";" << endl;
    return area;
}

void writeFile (Point pArr[], float &per, float &area){
    QFile resFile ("result.txt");
    if (resFile.open(QFile::WriteOnly |QFile::Append )){
        QTextStream out(&resFile);
        out<<"Points coordinates\r\n";
        for (int i=0; i<4; i++){
            out<<"Point "<< i+1 <<": ["<<pArr[i].x<<";"<<pArr[i].y<<"]\r\n";
        }
        out << "The perimeter of the tetragon is "<< per << ";\r\n";
        out << "The total area of the tetragon is " << area << ";\r\n";

        out<<"\r\n";
    }}








