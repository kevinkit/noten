#include <stdlib.h>
#include <stdio.h>



int main(int argc, char* argv[])
{
	double noten[13];
	noten[0] = 1.0;
	noten[1] = 1.3;
	noten[2] = 1.7;
	noten[3] = 2.0;
	noten[4] = 2.3;
	noten[5] = 2.7;
	noten[6] = 3.0;
	noten[7] = 3.3;
	noten[8] = 3.7;
	noten[9] = 4.0;
	noten[10] = 4.3;
	noten[11] = 4.7;
	noten[12] = 5.0;

	int noten_anz = 0;
	int i = 0;
	int j = 0;
	int x = 0;
	int offset = 0;
	double gewicht_sum = 0;
	double noten_sum = 0;
	double schnitt;
	double schnitt_wunsch;
	double best = 0;

	printf("Wie viele Prüfungen hast du bisher geschrieben \n");
	scanf("%d", &noten_anz);
	if(noten_anz == 0)
	{
		printf("Komiker du hast noch alles in der hand ! \n");
	}


	double* noten_d = (double*) malloc(sizeof(double) * (noten_anz +1));
	double* gewicht_d = (double*) malloc(sizeof(double)*(noten_anz +1));
	for(i=0; i < noten_anz; i++)
	{
		printf("Was hast du in dem %d fach geschrieben? \n", i+1);
		scanf("%lf", &noten_d[i]);
		x = 0;
		for(j = 0; j <= 12; j++)
		{
			if(noten_d[i] == noten[j])
			{
				break;
			}
			{

				//	printf("Note die es hätte sein soll %f \t note die es war %f " , noten[j], noten_d[i]);
				x++;
			}
			if(x > 12)
			{
				printf("Keine gültige Note! \n Bitte erneut eingeben \n");
				i = i-1;

			}

		}				

		printf("Wie ist die Gewichtung dieses Faches? \n");
		scanf("%lf", &gewicht_d[i]);

		gewicht_sum += gewicht_d[i];
		noten_sum += noten_d[i] * gewicht_d[i];

	}

	schnitt = noten_sum/gewicht_sum;
	printf("Der schnitt ist %lf", schnitt);


	printf("Was ist der gewünschte Schnitt? \n");
	scanf("%lf" , &schnitt_wunsch);
	int neueanzahl;


	if(neueanzahl == 0)
	{
		printf("Komiker - you need a miracle \n");
			exit(1);
	}

	printf("was ist die beste Note die du schreiben kannst ?\n");
	scanf("%lf", &best);
	for(i=0; i < 12; i++)
	{
		if(best == noten[i])
		{
			offset = i;
			break;
		}


	}
	
	  printf("Wie viele Prüfungen hast du noch vor dir ? \n");
        scanf("%d", &neueanzahl);



	double* noten_w = (double*) malloc(sizeof(double) * (neueanzahl+1));
	double* gewicht_w = (double*) malloc(sizeof(double) * (neueanzahl + 1));


	for(i=0; i < neueanzahl; i++)
	{
		printf("Welche gewicht hat das %i Fach ? \n", i+1);
		scanf("%lf", &gewicht_w[i]);
	}
	int tau = 0;

	time_t t;

	time(&t);
	srand((unsigned int)t);
	double schnitt_w = 0;
	int notenholer = 12;
	for(i=0; i < 99;)
	{

		for(j = 0; j < neueanzahl; j++)
		{
			noten_w[j] = noten[rand() % notenholer + offset];
			printf("Note[%i] %lf \n",j ,noten_w[j]);
			if(noten_w[j] <= best)
			{
				j=j-1;
			}

			gewicht_sum += gewicht_w[j];				
			noten_sum += gewicht_w[j]*noten_w[j];


			tau++;
			if(tau > 100000)
			{
				notenholer = 11;
			}
			if(tau > 200000)
			{
				notenholer = 9;
			}
			if(tau > 300000)
			{
				notenholer = 6;
			}

			if(tau > 400000)
			{
				notenholer = 3;
			}
			if(tau > 500000)
			{
				notenholer = 2;
			}
			if(notenholer <= best)
				break;
		
		}
		schnitt_w = noten_sum/gewicht_sum;
		printf("schnitt versuch[%d] = %lf \n", tau, schnitt_w);

			if(0.5*(schnitt + schnitt_w) <= schnitt_wunsch  ||  0.5*(schnitt + schnitt_w) <= schnitt_wunsch + 0.1)
			{	
				printf("Du musst folgende Noten schreiben \n");
				for(x = 0; x < neueanzahl; x++)
				{

					printf("Gewicht: %f , Note %f \n", gewicht_w[x], noten_w[x]);
		

				}
			
			break;

			}



	}


	free(noten_d);
	free(gewicht_d);
	free(noten_w);
	free(gewicht_w);
	return;









}
