// dll_a.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <conio.h>
#include "dlltest.h"
using namespace std;
void line();
float the_bigest_triangle(int n);
void circle_most_points();
void circle_all_points();

int main()
{ 
	Section a1,a2,a3;
instructions();
short choice;short n;
cin>>choice;
while (choice !=10) {
switch(choice){
case 1 : 
	 getX_Y();
	 break;
case 2:
	length();
	break;
case 3:
	cout<<"Enter points of line"<<endl;
	a1=getX_Y();
	a2=getX_Y();
	cout<<"Enter point"<<endl;
	a3=getX_Y();
	
	if(point_to_line(a1,a2,a3)){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
	break;
case 4:
	cout<<"Enter points of line"<<endl;
	a1=getX_Y();
	a2=getX_Y();
	cout<<"Enter point"<<endl;
	a3=getX_Y();
	if(point_on_one_line(a1,a2,a3)){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	break;
case 5:
	cout<<"The square is"<<Square()<<endl;
	break;
case 6:
	cout<<"How many triangle do you want to enter "<<endl;
	cin>>n;
	cout<<"The bigest one is "<<the_bigest_triangle(n)<<endl;
	break;
case 7:
	line();
	break;
case 8:
	circle_most_points();
	break;
case 9:
	circle_all_points();
	break;
	default:
		cout<<"Invalid choice."<<endl<<endl; instructions(); break; }
		cin>> choice; }
		cout<<"End of run."<<endl;
		return 0;
}
float the_bigest_triangle(int n){
	float max=0;float s;
	for(int i=0;i<n;i++){
		s=Square();
		cout<<"The square of triangle "<<i+1<<" is "<<s<<endl;
		if(s>max){
			max=s;
		}
	}
	return max;
}
void line(){
	int n;
	cout<<"Enter number of points";
	cin>>n;
	Section *A;
	A= new Section [n];
	for(int i=0;i<n;i++){
		A[i]=getX_Y();
	}
	Section q,q1;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int z=j+1;z<n;z++){
				if(point_on_one_line(A[i],A[j],A[z])){
					q=A[i];
					q1=A[z];
				}
			}
		}
	}
	delete []A;
	A=NULL;
	cout<<"Ax "<<q.a.x<<"Ay "<<q.a.y<<endl;
	cout<<"Bx "<<q1.a.x<<"By "<<q1.a.y<<endl;

}
void circle_most_points(){
int n,n1;
Section *Circle;
Section *A;

	cout<<"Enter number of points";
	cin>>n;
	A= new Section [n];
	for(int i=0;i<n;i++){
		A[i]=getX_Y();
	}
	cout<<"Enter number of circles ";
	cin>>n1;
	int *m=new int[n1];
	int *points=new int[n1];
	Circle=new Section [n1];
	for(int i=0;i<n1;i++){
		cout<<"Enter center of the circle ";
		Circle[i]=getX_Y();
		cout<<"Enter radius ";
		cin>>m[i];
		points[i]=0;
	}
	for(int i=0;i<n1;i++){
		for(int j=0;j<n;j++){
			if(sqrt(powf (Circle[i].a.x-A[j].a.x,2)+powf(Circle[i].a.y-A[j].a.y,2))<=m[i])
			{
				points[i]++;
			}
		}
	}
	int max=points[0];
	int pos=0;
	for(int i=1;i<n1;i++){
		if(points[i]>max){
			max=points[i];
			pos=i;
		}
	}
	cout<<"The circle which has the most points is "<<pos+1<<endl;
}
void circle_all_points(){
int n,n1;
Section *Circle;
Section *A;

	cout<<"Enter number of points";
	cin>>n;
	A= new Section [n];
	for(int i=0;i<n;i++){
		A[i]=getX_Y();
	}
	cout<<"Enter number of circles ";
	cin>>n1;
	int *m=new int[n1];
	int *points=new int[n1];
	Circle=new Section [n1];
	for(int i=0;i<n1;i++){
		cout<<"Enter center of the circle ";
		Circle[i]=getX_Y();
		cout<<"Enter radius ";
		cin>>m[i];
		points[i]=0;
	}
	for(int i=0;i<n1;i++){
		for(int j=0;j<n;j++){
			if(sqrt(powf (Circle[i].a.x-A[j].a.x,2)+powf(Circle[i].a.y-A[j].a.y,2))<=m[i])
			{
				points[i]++;
			}
		}
	}
	int pos=-1;
	for(int i=0;i<n1;i++){
		if(points[i]==n){
			pos=i;
		}
	}
	if(pos<0){
		cout<<"There is no such circle"<<endl;
	}else{
		cout<<"The circle which has all points is "<<pos+1<<endl;}
}








