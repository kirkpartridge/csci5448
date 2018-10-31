#include <sstream>
#include "../include/TransactionType.h"

TransactionType::TransactionType():
price(0),
quantity(0),
ticker(""),
date(time(0))
{
}

TransactionType::TransactionType(std::string _ticker, int _price, int _quantity, time_t _date)
{
    ticker = _ticker;
    price = _price;
    quantity = _quantity;
    date = _date;
}

TransactionType::~TransactionType()
{
}

int TransactionType::CheckEquals(TransactionType other)
{
    return 0;
}

/**This method outputs the object to a CSV format
 * Returns a string with the values comma delimited */
std::string TransactionType::ToCSV()
{
    std::ostringstream message;
    message << price << "," << quantity << ",";
    message << ticker << "," << date;
    return message.str();
}
