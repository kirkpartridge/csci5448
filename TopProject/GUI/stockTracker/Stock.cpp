#include "../include/Stock.h"


Stock::Stock(std::string ticker, int price, int quantity, time_t date):
TransactionType(ticker, price, quantity, date)
{
}

Stock::Stock():
TransactionType()
{
}

Stock::~Stock()
{
}


