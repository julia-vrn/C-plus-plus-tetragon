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
float area(Point pArr[]);
float perimeter(Point pArr[]);
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

   float p = perimeter(pArray);
   float a = area(pArray);
    writeFile(pArray, p, a);

   float testP = perimeter(testArr);
   float testA = area(testArr);
   writeFile(testArr, testP, testA);



    return 0;
}


float distance(Point a, Point b){

    float dis = sqrt(pow((b.x-a.x), 2)+pow((b.y-a.y), 2));

    //cout << "The distance between target points is " << dis << ";" << endl;
    return dis;
}

float perimeter(Point pArr[]){
    float per = distance(pArr[0],pArr[1])+distance(pArr[1], pArr[2])+distance(pArr[2], pArr[3])+distance(pArr[3], pArr[0]);
    cout<<"The perimeter of the tetragon is " << per << ";" << endl;
    return per;
}

float area(Point pArr[]){
    float area = abs(0.5*((pArr[0].x*pArr[1].y-pArr[1].x*pArr[0].y)+(pArr[1].x*pArr[2].y-pArr[2].x*pArr[1].y)+(pArr[2].x*pArr[3].y-pArr[3].x*pArr[2].y)+
            (pArr[3].x*pArr[0].y-pArr[0].x*pArr[3].y)));
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








