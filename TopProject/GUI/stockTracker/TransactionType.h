#ifndef TRANSACTIONTYPE_H
#define TRANSACTIONTYPE_H
#include <ctime>
#include <iostream>

/**
 * @brief The TransactionType class
 */
class TransactionType {
public:
    ///Default constructor
    TransactionType();
    ///Parameter Constructor
    TransactionType(std::string _ticker, int _price, int _quantity, time_t _date, std::string type);
    ///Returns a CSV Ready string
    std::string ToCSV();
    ///Virtual function to format data for CSV export.
    virtual std::string formatForCSV();

    //Getter and Setters

    ///Getter for the price
    int GetPrice();
    ///Setter for the price
    void SetPrice(int _price) { price = _price;}
    ///Getter for the quantity
    int GetQuantity();
    ///Setter for the qunatity
    void SetQuantity(int _quantity) { quantity = _quantity; }
    ///Getter for the ticker
    std::string GetTicker();
    ///Setter for the ticker
    void SetTicker(std::string &_ticker) { ticker = _ticker; }
    ///Getter for the date
    time_t GetDate();
    ///Setter for the date
    void SetDate(time_t _date) { date = _date; }
    //Getter for the type
    std::string GetType();
    //Setter for the type
    void SetType(std::string _transaction ) { type = _transaction; }

protected:
    int price;              ///<Integer to store the price of stock at transaction
    int quantity;           ///<Integer to store the quantity of stock in transaction
    std::string ticker;    ///<String to store ticker symbol
    time_t date;        ///time_t to store date of transaction
    std::string type;

};

#endif
