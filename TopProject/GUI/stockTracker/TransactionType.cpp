
#include "TransactionType.h"

/**
 * @brief TransactionType::TransactionType
 */
TransactionType::TransactionType():
price(0),
quantity(0),
ticker(""),
date(time(0))
{
}

/**
 * @brief TransactionType::TransactionType
 * @param _ticker
 * @param _price
 * @param _quantity
 * @param _date
 * @param _type
 */
TransactionType::TransactionType(std::string _ticker, int _price, int _quantity, time_t _date, std::string _type)
{
    ticker = _ticker;
    price = _price;
    quantity = _quantity;
    date = _date;
    type = _type;
}

std::string TransactionType::formatForCSV()
{

}

std::string TransactionType::ToCSV()
{
    return formatForCSV();
}

/**
 * @brief TransactionType::GetPrice
 * @return
 */
int TransactionType::GetPrice()
{
    return price;
}

/**
 * @brief TransactionType::GetTicker
 * @return
 */
std::string TransactionType::GetTicker()
{
    return ticker;
}

/**
 * @brief TransactionType::GetQuantity
 * @return
 */
int TransactionType::GetQuantity()
{
    return quantity;
}

/**
 * @brief TransactionType::GetType
 * @return
 */
std::string TransactionType::GetType()
{
    return type;
}

/**
 * @brief TransactionType::GetDate
 * @return
 */
time_t TransactionType::GetDate()
{
    return date;
}

