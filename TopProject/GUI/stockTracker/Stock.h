#ifndef STOCK_H
#define STOCK_H

#include "./TransactionType.h"
/**
 * @brief The Stock class - Externs transaction type
 */
class Stock: public TransactionType {
public:

    ///Default Contrsuctor
    Stock();
    // conversion from TransactionType (constructor):
    Stock(TransactionType& x);
    //Default deConstructor
    ~Stock();
    ///Parameter Constructor
    Stock(std::string ticker, int price, int quantity, time_t date, std::string type);
    ///Format Stock for CSV writing.
    std::string formatForCSV() override;
};


#endif
