double x=0;
int counter=0;

void history_start(){counter=0;x=0;}
int history_isFinish(){return(counter>200);}

void history_getPrice(double *pBuy,double *pSell)
{
	x+=0.1;
	if(x>(2*3.14)) x=0;	
	*pBuy =x;
	counter++;
}
