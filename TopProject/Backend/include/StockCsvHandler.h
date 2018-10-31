#include <vector>

#include "./Stock.h"

class StockCsvHandler {

 public:

    ///Constructor
    StockCsvHandler();
    ///Deconstructor
    ~StockCsvHandler();
    ///Import CSV from input file path. 
    std::vector<TransactionType> ImportCSV();
    ///Export CSV to output file path.
    bool ExportCSV(std::vector<TransactionType> transactions);

    ///Setter for input file path
    void setInputFilePath(std::string path) { inputFilePath = path; };
    ///Getter for input file path
    std::string getInputFilePath() { return inputFilePath; };
    ///Setter for output file path
    void setOutputFilePath(std::string path) { outputFilePath = path; };
    ///Getter for output file path
    std::string getOutputFilePath() { return outputFilePath; };
private:

    ///Private member for input file path.
    std::string inputFilePath;
    ///Private member for output file path.
    std::string outputFilePath;
};
