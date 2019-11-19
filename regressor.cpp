#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <cmath>
#include "regressor.h"
#include <cassert>

#define assertm(exp, msg) assert(((void)msg, exp))


float perpendicularDistance(dot tupple,line curRegr){
    float numerator = std::abs(curRegr->a*tupple->x + curRegr->b*tupple->y + curRegr->c);
    float denominator = std::sqrt(pow(curRegr->a,2.0) + pow(curRegr->b,2.0));
    return numerator/denominator;
}

float horizontalDistance(dot tupple,line curRegr){
    float lineX = (-curRegr->b/curRegr->a)*tupple->y - (curRegr->c/curRegr->a);
    return std::abs(lineX - tupple->x);
}

float verticalDistance(dot tupple,line curRegr){
    float lineY = (-curRegr->a/curRegr->b)*tupple->x - (curRegr->c/curRegr->b);
    return std::abs(lineY - tupple->y);
}

float rSquaredDistance(dot tupple,line curRegr){
    assertm((curRegr->a) == 0,"Given line must be an horizontal line of the average y values");
    return std::abs((tupple->y) - (-(curRegr->b/curRegr->c)));
}

line minimizeVerticalDistance(line L,int a,dot points,int numOfPoints,float ab){

    int currentError = 0;
    int i=0;

    for(i=0;i<numOfPoints;i++){
	       currentError = currentError + verticalDistance(&points[i],L);
    }

    cline* newL = (cline*)malloc(sizeof(struct cline));
    newL->a = L->a + ab;
    newL->b = L->b + ab;
    newL->c = L->c + ab;


    std::cout << "cur err " << currentError << "\n";

    currentError = 0;
    for(i=0;i<numOfPoints;i++){
        std::cout << "ver " << currentError << "\n";
	currentError = currentError + verticalDistance(&points[i],newL);
    }
    return newL;
}


//Function that helps on the point reading of a file.
dot readTupple(string input,dot tup){
    string x = input.substr(0,input.find(':'));

    string y = input.substr(input.find(':')+1);

    stringstream ex(x);
    stringstream ey(y);

    ex >> tup->x;
    ey >> tup->y;

    return tup;
}
