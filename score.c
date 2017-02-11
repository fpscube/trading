#include <math.h>

double score=0;

void score_setSin(double pX,double pY)
{
	
	double y=sin(pX);
	score += abs(y-pY);
}

void score_setBuy(double pValue){}
void score_setSell(double pValue){}


void score_getScore(int * pScore)
{
	*pScore = score*1000;
}