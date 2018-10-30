#include "../include/StockCsvHandler.h"

StockCsvHandler::StockCsvHandler():
inputFilePath(""),
outputFilePath("")
{
}

StockCsvHandler::~StockCsvHandler()
{
}

std::vector<TransactionType> StockCsvHandler::ImportCSV()
{
    std::vector<TransactionType> foo;
    if(inputFilePath.empty())
    {
        std::cerr << "Please specify an input file path\n";
        return foo;
    }
    
    return foo;
}


bool StockCsvHandler::ExportCSV(std::vector<TransactionType> transactions)
{
    if(outputFilePath.empty())
    {
        std::cerr << "Please specify an ouput file path\n";
        return false;
    }

    return true;
}
