void history_start();
int  history_isFinish();
void history_getPrice(double *pBuy,double *pSell);

void indicator_setPrice(double pBuy,double pSell);
void indicator_getMobileAverage(double *pBuy,double *pSell,int pPeriod);

void perceptron_setEnter(int pId,int pValue); 
void perceptron_getOutput(int pId, double * pOutput);
void perceptron_setGen(double *pGenTable);
void perceptron_execute();

void score_setSin(double pX,double pY);
void score_setBuy(double pValue);
void score_setSell(double pValue);
void score_setSin(double pX,double pY);
void score_getScore(int * pScore);

void genetic_getNextGen(int pScore,double **pGenTable);


