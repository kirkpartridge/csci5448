#ifndef STOCKCONTROLLER_H
#define STOCKCONTROLLER_H

#include <QWidget>
#include <QStackedWidget>
#include <QMainWindow>
#include "homepage.h"
#include "addtransactionpage.h"
#include "searchpage.h"

class MasterController;
class StockModel;

/**
 * @brief The StockController class - Extends QMainWindow
 */
class StockController : public QMainWindow
{
    Q_OBJECT
public:
    ///Constructor for the StockController.
    explicit StockController(MasterController * _masterPtr, StockModel * _stockModelPtr,
                             QWidget *parent = nullptr);
    ~StockController();
    //void show();


private slots:
    ///Handles the Import CSV Button
    void handleImportCSVButton();
    ///Handles the Export CSV Button
    void handleExportCSVButton();
    ///Brings up the new transaction window
    void handleAddTransactionButton();
    ///Returns to homepage
    void handleCancelAddTransactionButton();
    ///Handles add new transaction button
    void handleAddNewTransactionButton();

public slots:
    void handleSymbolButton();
    void handleBackButton();
    void handleSearchButton();

private:
    ///Private pointers
    MasterController * masterPtr;
    Homepage * homepagePtr;
    AddTransactionPage * addTransactionPtr;
    StockModel * stockModelPtr;
    QStackedWidget *stackedWidget;

    int validateNewTransaction(std::string symbol, std::string price,
                               std::string quantity);
    void remapSymbolButtons();
    void remapSearchSymbolButtons(SearchPage * searchPage);
};

#endif // STOCKCONTROLLER_H
