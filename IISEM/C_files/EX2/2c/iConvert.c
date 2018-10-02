#include"hConvert.h"
void convert(long int ss)
{
 d=ss/(24*60*60);
 ss=ss%(24*60*60);
 h=ss/(60*60);
 ss=ss%(60*60);
 m=ss/60;
 ss=ss%60;
 s=ss;
}
