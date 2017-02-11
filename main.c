#include "main.h"
#include <stdio.h>

void main()
{	
	
	int lCounter = 0;
	int lScore=0;
	double lBuy,lSell;
	double lBuyAvg[8];
	double lSellAvg[8];
	double lOutputBuy,lOutputSell;
	double *lGenTable;
	while(1)
	{
		history_start();
		genetic_getNextGen(lScore,&lGenTable);
		printf("#NewGen\n");
		
		while(!history_isFinish())
		{
			history_getPrice(&lBuy,&lSell);
			printf("Price:%f\n",lBuy);
			
			indicator_setPrice(lBuy,lSell);
			indicator_getMobileAverage(&lBuyAvg[0],&lSellAvg[0],1);
			indicator_getMobileAverage(&lBuyAvg[1],&lSellAvg[1],2);
			indicator_getMobileAverage(&lBuyAvg[2],&lSellAvg[2],3);
			indicator_getMobileAverage(&lBuyAvg[3],&lSellAvg[3],4);
			indicator_getMobileAverage(&lBuyAvg[4],&lSellAvg[4],5);
			indicator_getMobileAverage(&lBuyAvg[5],&lSellAvg[5],6);
			indicator_getMobileAverage(&lBuyAvg[6],&lSellAvg[6],7);
			indicator_getMobileAverage(&lBuyAvg[7],&lSellAvg[7],8);

			perceptron_setEnter(0,lBuyAvg[0]>lBuy); 
			perceptron_setEnter(1,lBuyAvg[1]>lBuy); 
			perceptron_setEnter(2,lBuyAvg[2]>lBuy); 
			perceptron_setEnter(3,lBuyAvg[3]>lBuy); 
			perceptron_setEnter(4,lBuyAvg[4]>lBuy); 
			perceptron_setEnter(5,lBuyAvg[5]>lBuy); 
			perceptron_setEnter(6,lBuyAvg[6]>lBuy); 
			perceptron_setEnter(7,lBuyAvg[7]>lBuy);

			
			perceptron_execute(lGenTable);		
			perceptron_getOutput(1,&lOutputBuy);
			perceptron_getOutput(2,&lOutputSell);
		
			score_setBuy(lOutputBuy);
			score_setSell(lOutputSell);
		}
		
		score_getScore(&lScore);
			
		lCounter++;
		if (lCounter%10000000==0)	printf("It:%d#Score:%d\n",lCounter,lScore);
	}
}