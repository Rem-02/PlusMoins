/*
 * main.c
 *
 *  Created on: 3 sept. 2018
 *      Author: rem
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <time.h>

int protectedIntScan()
{
	int intScanned = 0;
	char trash[256];
	int matched = 0;

	matched = scanf("%d", &intScanned);
	if(matched == 0)
	{
		/* A int hasn't been inserted */
		printf("What ?\n");
		scanf("%s", trash);
	}

	return intScanned;
}

int main()
{
	/* Vars */
	int max = 1;
	bool setting = true;
	int random = 1;
	int nbEssais = 0;
	int essai = 0;

	/* Welcome message */
	printf("Salut ! C'est parti pour le jeu du plus ou moins !\n");
	printf("Générer un nombre entre 1 et ? : ");
	while(setting)
	{
		max = protectedIntScan();
		if(max <= 0)
		{
			printf("Le nombre doit être supérieur à 1 !\n");
		}
		else
		{
			/* Succesfully load an int */
			setting = false;
		}
	}

	/* Generate number */
	srand(time(NULL));
	random = (rand() % max)+1;

	/* Let's play ! */
	printf("C'est parti !\n");
	while(essai != random)
	{
		essai = protectedIntScan();
		if(essai <= 0)
		{
			printf("Le nombre doit être supérieur ou égal à 1 !\n");
			continue;
		}
		else if(essai > max)
		{
			printf("Le nombre doit être inférieur ou égal à %d !\n", max);
			continue;
		}
		/* Try */
		nbEssais++;
		if(essai < random)
		{
			printf("C'est plus !\n");
		}
		else if(essai > random)
		{
			printf("C'est moins !\n");
		}
	}

	if(nbEssais == 1)
	{
		printf("Sacré coup de bol !\n");
	}
	else
	{
		printf("GG tu as trouvé en %d essais !\n", nbEssais);
	}

	return 0;
}
