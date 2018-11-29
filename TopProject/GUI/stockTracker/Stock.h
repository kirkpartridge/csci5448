#include "./TransactionType.h"

class Stock: public TransactionType {
public:

    ///Default Contrsuctor
    Stock();
    //Default deConstructor
    ~Stock();
    ///Parameter Constructor
    Stock(std::string ticker, int price, int quantity, time_t date);
};



