#include"hamming.h"
int lookUp[4][8]={{1,3,5,7,9,11,13,15},
                  {2,3,6,7,10,11,14,15},
                  {4,5,6,7,12,13,14,15},
                  {8,9,10,11,12,13,14,15}};
int calcTolBit(int size)
{
    if(size==1)
        return 2+size;
    else if(size <=4)
        return 3+size;
    else if(size<=8)
        return 4+size;
}

void computeHamming(int* transData,int totSize)
{
    int loc,it,in,hamming,flag;
    for(it=1,loc=0;it<totSize;it=pow(2,++loc))
    {
        hamming=0;
        for(in=0;in<8;in++)
        {
            flag = lookUp[loc][in];
            if(flag<=totSize)
                hamming^=transData[flag-1];
        }
        transData[it-1]=hamming;
    }
}
