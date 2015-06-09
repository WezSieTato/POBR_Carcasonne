#include "recognizing.h"

#define between(a, b, c) if(!(a >= b && a <= c)) return false;

bool isSheep(const MatInfo &info)
{
    between(info.S, 1428 , 1500);
    between(info.L, 102, 160);
    between(info.M1, 0.196f, 0.2004f);

    return true;

}


bool isPig(const MatInfo &info)
{
    between(info.S, 1620 , 1783);
    between(info.L, 157, 203);

    return true;
}
