#include <stdio.h>

#define MIN(X, Y) (X < Y) ? X : Y
#define MAX 256

int changer(int aval_coins[], int amount);

int main()
{
    int avalible_coins[] = {1, 2, 5, 10};
	int amount;
	printf("Insert the amount: ");
	scanf("%d", &amount);

	int result = changer(avalible_coins, amount);
    printf("Are needed %d coins\n", result);
}

int changer(int aval_coins[], int amount)
{
    int total_aval_coins = 4; // use sizeof to make it dinamic
	int req_coins[amount+1];
	req_coins[0] = 0;

    for(int i=1; i<=amount; i++)
    {
		req_coins[i] = MAX;
		int aux = MAX;

		for(int j=0; j<total_aval_coins; j++)
		{
            if((i-aval_coins[j]) >= 0)
				aux = req_coins[i-aval_coins[j]];
			if(aux != MAX)
				req_coins[i] = MIN(req_coins[i], (aux+1));
		}
	}

	int change = req_coins[amount];
	return change;
}
