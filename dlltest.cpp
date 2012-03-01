#include "dlltest.h"
#include <math.h>

using namespace std;

//встановити координати точки
extern "C" __declspec(dllexport) Section getX_Y(){
	Section A;
	cout<<"Enter x ";
	cin>>A.a.x;
	cout<<"Enter y ";
	cin>>A.a.y;
	return A;
}
//знайти довжину лінії
extern "C" __declspec(dllexport) int length(){
	Section a;
	Section b;
	a=getX_Y();
	b=getX_Y();
	float s;
	s=abs(sqrt(powf(a.a.x-b.a.x,2)+powf(a.a.y-b.a.y,2)));
	cout<<"Length of line is "<<s;
	return static_cast <int>(s);
}
//чи лежить точка на одній прямій з відрізком
extern "C" __declspec(dllexport) bool point_to_line(Section a1,Section a2,Section a3)
{
	if(((a3.a.y-a1.a.y)/(a3.a.x-a1.a.x))==((a2.a.y-a1.a.y)/(a2.a.x-a1.a.x)))
	{
		return true;
	}
	return false;
}
//інструкції
extern "C" __declspec(dllexport) void instructions()
{
	cout<<"Choose what do you want\n"
		"1 - set points\n"
		"2 - set line\n"
		"4- if point belong to line\n"
		"3- whether point belongs to straight\n"
	    "5-triangle square\n"
		"6-The bigest triangle square\n"
		"7-the bigest line\n"
		"8-circle which has the greatest number of points\n"
		"9-circle which has all of points\n"
		"10-end of the program\n";
}
//чи належить точка відрізку
extern "C" __declspec(dllexport) bool point_on_one_line(Section a1,Section a2,Section a3)
{
	
	if(((a2.a.y-a1.a.y)/(a2.a.x-a1.a.x))==((a3.a.y-a1.a.y)/(a3.a.x-a1.a.x))){
		return true;
	}
	return false;
}
//площа трикутника
extern "C" __declspec(dllexport) float Square(){
	float S;
	Section a1,a2,a3;
	a1=getX_Y();
	a2=getX_Y();
	a3=getX_Y();

	S=(abs((a1.a.x-a3.a.x)*(a2.a.y-a3.a.y)-(a2.a.x-a3.a.x)*(a1.a.y-a3.a.y)))/2;
	return S;
}