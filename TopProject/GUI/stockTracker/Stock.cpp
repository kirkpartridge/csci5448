#include "Stock.h"
#include <sstream>

/**
 * @brief Stock::Stock
 * @param ticker
 * @param price
 * @param quantity
 * @param date
 * @param type
 */
Stock::Stock(std::string ticker, int price, int quantity, time_t date, std::string type):
TransactionType(ticker, price, quantity, date, type)
{
}

/**
 * @brief Stock::Stock
 */
Stock::Stock():
TransactionType()
{
}

Stock::Stock(TransactionType& x)
{
    ticker = x.GetTicker();
    price = x.GetPrice();
    date = x.GetDate();
    quantity = x.GetQuantity();
    type = x.GetType();
}

/**
 * @brief Stock::~Stock
 */
Stock::~Stock()
{
}

/**
 * @brief Stock::formatForCSV
 * @return
 */
std::string Stock::formatForCSV()
{
    std::ostringstream message;
    message << ticker << ",";
    message << price << ",";
    message << quantity << ",";
    message << type << ",";

    //Get Date information into correct string format
    char buff[20];
    struct tm * timeinfo;
    timeinfo = localtime (&date);
    strftime(buff, sizeof(buff), "%D", timeinfo);

    message << buff << "\n";

    return message.str();
}


