#ifndef STOCKMODEL_H
#define STOCKMODEL_H

#include <vector>
#include <iostream>

#include "./StockCsvHandler.h"

/**
 * @brief The StockModel class
 */
class StockModel {

public:

    StockModel();
    
    ~StockModel();
    ///Adds a transaction to the internal model
    bool AddTransaction(std::string symbol, int quantity, int price, std::string date, std::string type);
    ///Removes transaction form the internal model
    bool RemoveTransaction(std::string symbol, int quantity, int price, std::string type);
    ///Returns all transactions
    std::vector<TransactionType> GetTransactions() { return transactions; }
    ///Reads in CSV and populates the internal model
    std::vector<TransactionType> GetTransactionsFromCSV(std::string filePath);
    ///Setter for the export CSV path
    void SetExportCSVPath(std::string filePath);

private:
    ///private csvHandler instance
    StockCsvHandler csvHandler;
    ///structure to hold all transacations
    std::vector<TransactionType> transactions;
};

#endif
