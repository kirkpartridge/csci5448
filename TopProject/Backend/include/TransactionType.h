#include <ctime>
#include <iostream>

//////////////////////////////////////////
///The TransactionType class is a base class for sub types 
//////////////////////////////////////////
class TransactionType {
public:
    ///Default constructor
    TransactionType();
    //Default deconstructor
    ~TransactionType();
    ///Parameter Constructor
    TransactionType(std::string _ticker, int _price, int _quantity, time_t _date);
    ///Compares two TransactionType objects
    int CheckEquals(TransactionType other);
    ///Formats the object for csv export
    std::string ToCSV();

    //Getter and Setters

    ///Getter for the price
    int GetPrice();
    ///Setter for the price
    void SetPrice(int price);
    ///Getter for the quantity
    int GetQuantity();
    ///Setter for the qunatity
    void SetQuantity(int quantity);
    ///Getter for the ticker
    std::string GetTicker();
    ///Setter for the ticker
    void SetTicker(std::string &ticker);
    ///Getter for the date
    time_t GetDate();
    ///Setter for the date
    void SetDate(time_t date);

protected:
    int price;              ///<Integer to store the price of stock at transaction
    int quantity;           ///<Integer to store the quantity of stock in transaction
    std::string ticker;    ///<String to store ticker symbol
    time_t date;        ///time_t to store date of transaction

};
