#include "../include/StockModel.h"

StockModel::StockModel():
csvHandler()
{
}

StockModel::~StockModel()
{
}

bool StockModel::AddTransaction(std::string symbol, int quantity, int price, TransactionType type)
{
    return true;
}

bool StockModel::RemoveTransaction(std::string symbol, int quantity, int price, TransactionType type)
{
    return true;
}

std::vector<TransactionType> StockModel::GetTransactions(std::string symbol)
{
    std::vector<TransactionType> foo;
    return foo;
}

TransactionType StockModel::GetStockData(std::string symbol)
{
    TransactionType foo;
    return foo;
}

int StockModel::CalculatePerformance()
{
    return 1;
}


