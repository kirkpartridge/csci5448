#include <fstream>

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
    std::vector<TransactionType> transactions;
    if(inputFilePath.empty())
    {
        std::cerr << "Please specify an input file path\n";
        return transactions;
    }

    std::ifstream inputFile(inputFilePath);
    std::string line;
    if (inputFile.is_open())
    {
        while(getline(inputFile, line))
        {
            if (line.find("Symbol") != std::string::npos)
            {
                //Skip Header
                continue;
            }
            //Lets find the values we need.
            int price, quantity;
            std::string symbol, type, date;
            int startIndex = line.find(",");
            symbol = line.substr(0, startIndex);
            line.erase(0, startIndex + 1);
            startIndex = line.find(",");
            price = std::stoi(line.substr(0, startIndex));
            line.erase(0, startIndex + 1);
            startIndex = line.find(",");
            quantity = std::stoi(line.substr(0, startIndex));
            line.erase(0, startIndex + 1);
            startIndex = line.find(",");
            type = line.substr(0, startIndex);
            line.erase(0, startIndex + 1);
            startIndex = line.find(",");
            date = line.substr(0, startIndex);
            line.erase(0, startIndex + 1);

            //Parse out date values
            //Assumes Month / Day / Year
            int month, day, year;
            startIndex = date.find("/");
            month = std::stoi(date.substr(0,startIndex));
            date.erase(0, startIndex + 1);
            startIndex = date.find("/");
            day = std::stoi(date.substr(0,startIndex));
            date.erase(0, startIndex + 1);
            startIndex = date.find("/");
            year = std::stoi(date.substr(0,startIndex));

            struct tm  tm;
            time_t rawtime;
            time ( &rawtime );
            tm = *localtime ( &rawtime );
            tm.tm_year = year - 1900;
            tm.tm_mon = month - 1;
            tm.tm_mday = day;

            //Create Transaction Types...
            Stock newStock(symbol, price, quantity, mktime(&tm));
            transactions.push_back(newStock);
        }
    } 
    else
    {
        std::cerr << "File is not open " << inputFilePath;
    }    
    return transactions;
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
