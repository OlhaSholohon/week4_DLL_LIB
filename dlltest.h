#ifndef _DLLTEST_H_
#define _DLLTEST_H_

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>
using namespace std;


extern "C"{struct point{
	float x;
	float y;
};
}
extern "C"{
typedef struct Section
{
	point a;
} Line;
}
 extern "C" __declspec(dllexport) int length();
 extern "C" __declspec(dllexport) bool point_to_line(Section,Section,Section);
 extern "C" __declspec(dllexport) void instructions();
 extern "C" __declspec(dllexport) bool point_on_one_line(Section,Section,Section);
 extern "C" __declspec(dllexport) float Square();
 extern "C" __declspec(dllexport) Section getX_Y();
 
#endif