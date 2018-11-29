#include <vector>
#include <iostream>

#include "./StockCsvHandler.h"
class StockModel {

public:

    StockModel();
    
    ~StockModel();

    bool AddTransaction(std::string symbol, int quantity, int price, TransactionType type);

    bool RemoveTransaction(std::string symbol, int quantity, int price, TransactionType type);

    std::vector<TransactionType> GetTransactions(std::string symbol);

    TransactionType GetStockData(std::string symbol);

    int CalculatePerformance();
    
    void GetTransactionsFromCSV(std::string filePath);

    void SetImportCSVPath(std::string filePath) { csvHandler.setInputFilePath(filePath); }

    std::string GetImportCSVPath() { return csvHandler.getInputFilePath(); }

    void SetExportCSVPath(std::string filePath) { csvHandler.setOutputFilePath(filePath); }

    std::string GetExportCSVPath() { return csvHandler.getOutputFilePath(); }
private:

    StockCsvHandler csvHandler;
};
