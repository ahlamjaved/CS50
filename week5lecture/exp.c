#include <stdio.h>
#include "exp.h"

int main (void)
{
    Transaction yesterdaysTransaction;
    yesterdaysTransaction.cost = -40.39;
    yesterdaysTransaction.store = "Target";

    printf("yesterdays Transaction had a cost of %f from store %s", yesterdaysTransaction.cost, yesterdaysTransaction.store);

    Transaction transactions[50];
    transactions[0].cost = .39;

}

