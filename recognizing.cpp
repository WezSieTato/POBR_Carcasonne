#include "recognizing.h"

#define between(a, b, c) if(!(a >= b && a <= c)) return false;
#define zero(a) if(a == 0) return true;
bool isZero(const MatInfo &info){
    zero(info.S);
    zero(info.L);
    zero(info.M1);
    zero(info.M2);
    zero(info.M3);
    zero(info.M4);
    zero(info.M5);
    zero(info.M6);
    zero(info.M7);
    zero(info.M8);
    zero(info.M9);
    zero(info.M10);

    return false;
}

bool isSheep(const MatInfo &info)
{
    if(isZero(info))
        return false;

    between(info.S, 1420 , 1520);
    between(info.L, 100, 160);
    between(info.M1, 0.196f, 0.20065f);
    between(info.M2, 0.0416f, 0.048f);
    between(info.M8, -0.0025f, 0.0016f);
//    between(info.M9, -0.00051f, 0.00045f);

    return true;

}


bool isPig(const MatInfo &info)
{
    if(isZero(info))
        return false;
    between(info.S, 1600 , 1783);
    between(info.L, 150, 210);
    between(info.M1, 0.19f, 0.22f);
    between(info.M2, 0.038f, 0.06f);
//    between(info.M7, 0.0066f, 0.0074f);
    between(info.M9, -0.00023f, 0.00032f);

    return true;
}
