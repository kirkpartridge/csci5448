#include "./StockModel.h"

/**
 * @brief StockModel::StockModel
 */
StockModel::StockModel():
csvHandler(),
transactions()
{
}

/**
 * @brief StockModel::~StockModel
 */
StockModel::~StockModel()
{
}

/**
 * @brief StockModel::AddTransaction
 * @param symbol
 * @param quantity
 * @param price
 * @param date
 * @param type
 * @return
 */
bool StockModel::AddTransaction(std::string symbol, int quantity, int price, std::string date, std::string type)
{
    int startIndex;
    //Parse out date values
    //Assumes Month / Day / Year in mm/dd/yy format
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
    tm.tm_year = year + 2000;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    Stock toAdd(symbol, price, quantity, mktime(&tm), type);
    transactions.push_back(toAdd);
    return true;
}

/**
 * @brief StockModel::RemoveTransaction
 * @param symbol
 * @param quantity
 * @param price
 * @param type
 * @return
 */
bool StockModel::RemoveTransaction(std::string symbol, int quantity, int price, std::string type)
{
    return true;
}

/**
 * @brief StockModel::GetTransactionsFromCSV
 * @param filePath
 * @return
 */
std::vector<TransactionType> StockModel::GetTransactionsFromCSV(std::string filePath)
{
    csvHandler.setInputFilePath(filePath);
    transactions = csvHandler.ImportCSV();
    return transactions;
}

/**
 * @brief StockModel::SetExportCSVPath
 * @param filePath
 */
void StockModel::SetExportCSVPath(std::string filePath)
{
    csvHandler.setOutputFilePath(filePath);
    csvHandler.ExportCSV(transactions);
}
