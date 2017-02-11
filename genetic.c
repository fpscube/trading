#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define K_MAX_GENOM_PER_GENERATION 100
#define K_MAX_GENOM_KPI 100
#define K_MAX_GENOM_HIGH_SCORE 100


static int init=1;
static genomCounter=0;
static generationCounter=0;
double generationGenomTable[K_MAX_GENOM_PER_GENERATION][K_MAX_GENOM_KPI];
double highScoreGenomTable[K_MAX_GENOM_HIGH_SCORE][K_MAX_GENOM_KPI];
int highScoreTable[K_MAX_GENOM_HIGH_SCORE];
int lowestHighScoreId=0;

void genetic_getNextGen(int pScore,double **pGenTable)
{
	
	if (init)
	{
		//Init genom kpi with rand value
		srand(time(NULL));
		int i,y;
		for(i=0;i<K_MAX_GENOM_PER_GENERATION;i++){
		for(y=0;y<K_MAX_GENOM_KPI;y++){
			generationGenomTable[i][y]=rand();	
		}}	
		//Init highscore table with lowest value
		for(i=0;y<K_MAX_GENOM_HIGH_SCORE;y++){
			highScoreTable[i]=0x7FFFFFFF;	
		}
		init=0;		
	}
	else
	{
		int i;
		//If new best score replace lowest high score
		if (highScoreTable[lowestHighScoreId]<pScore)
		{
			for(i=0;i<K_MAX_GENOM_KPI;i++){	
				highScoreGenomTable[lowestHighScoreId][i]=generationGenomTable[genomCounter][i];
			}
		}
		//Search and save lowest high score
		int lowestScore=0xFFFFFFFF;
		for(i=0;i<K_MAX_GENOM_HIGH_SCORE;i++){
			if(lowestScore>highScoreTable[i])
			{
				lowestScore = highScoreTable[i];
				lowestHighScoreId=i;
			}
		}

		genomCounter++;
		
		if (genomCounter>=K_MAX_GENOM_PER_GENERATION)
		{
			genomCounter=0;
		}
			
	}
	
}
