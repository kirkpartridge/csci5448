#include <iostream>
#include "./Backend/include/StockModel.h"
int main( int argc, char **argv )
{
    TransactionType test;
    StockModel model;
    model.GetTransactionsFromCSV("/Users/kirkpartridge/Desktop/Stocks.csv");    
	return 1;
}
