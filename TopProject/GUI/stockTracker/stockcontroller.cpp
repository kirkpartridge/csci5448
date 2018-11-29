#include "stockcontroller.h"
#include "mastercontroller.h"
#include "stockpage.h"

#include <QFileDialog>
#include <QtWidgets>

/**
 * @brief StockController::StockController
 * @param _masterPtr
 * @param _stockModelPtr
 * @param parent
 */
StockController::StockController(MasterController * _masterPtr, StockModel * _stockModelPtr,
                                 QWidget *parent)
    : QMainWindow(parent)
{
    masterPtr = _masterPtr;
    homepagePtr = new Homepage(this);
    addTransactionPtr = new AddTransactionPage(this);
    stockModelPtr = _stockModelPtr;

    connect(homepagePtr->getExportCSVButton(), SIGNAL(released()),
            this, SLOT(handleExportCSVButton()));
    connect(homepagePtr->getImportCSVButton(), SIGNAL(released()),
            this, SLOT(handleImportCSVButton()));
    connect(homepagePtr->getSearchButton(), SIGNAL(released()),
            this, SLOT(handleSearchButton()));
    connect(homepagePtr->getAddTransactionButton(), SIGNAL(released()),
            this, SLOT(handleAddTransactionButton()));
    connect(addTransactionPtr->getCancelButton(), SIGNAL(released()),
            this, SLOT(handleCancelAddTransactionButton()));
    connect(addTransactionPtr->getSubmitButton(), SIGNAL(released()),
            this, SLOT(handleAddNewTransactionButton()));


    stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(homepagePtr);
    stackedWidget->addWidget(addTransactionPtr);
    stackedWidget->setCurrentIndex(0);

    setCentralWidget(stackedWidget);

}

/**
 * @brief StockController::~StockController
 */
StockController::~StockController()
{

}

/**
 * @brief StockController::handleImportCSVButton
 */
void StockController::handleImportCSVButton()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Import CSV File"), "",
        tr("CSV (*.csv);;All Files (*)"));

    //stockModelPtr->SetImportCSVPath(fileName.toStdString());
    //std::vector<TransactionType> test(stockModelPtr->GetTransactionsFromCSV(fileName.toStdString()));
    homepagePtr->setupTable(stockModelPtr->GetTransactionsFromCSV(fileName.toStdString()));
    remapSymbolButtons();
}

/**
 * @brief StockController::handleExportCSVButton
 */
void StockController::handleExportCSVButton()
{
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Export CSV File"), "",
        tr("CSV (*.csv);;All Files (*)"));

    stockModelPtr->SetExportCSVPath(fileName.toStdString());
}

/**
 * @brief StockController::handleAddTransactionButton
 */
void StockController::handleAddTransactionButton()
{
    stackedWidget->setCurrentIndex(1);
}

/**
 * @brief StockController::handleCancelAddTransactionButton
 */
void StockController::handleCancelAddTransactionButton()
{
    addTransactionPtr->clearValues();
    stackedWidget->setCurrentIndex(0);
}

/**
 * @brief StockController::handleAddNewTransactionButton
 */
void StockController::handleAddNewTransactionButton()
{
    std::string symbol = addTransactionPtr->getSymbol();
    transform(symbol.begin(), symbol.end(), symbol.begin(), ::toupper);
    std::string price = addTransactionPtr->getPrice();
    std::string quantity = addTransactionPtr->getQuantity();
    std::string date = addTransactionPtr->getDate();
    std::string transactionType = addTransactionPtr->getTransaction();

    int result = validateNewTransaction(symbol, price, quantity);

    switch (result)
    {
    case 0:
        stockModelPtr->AddTransaction(symbol, std::stoi(quantity), std::stoi(price), date, transactionType);
        QMessageBox::warning(
            this,
            tr("Stock Tracker"),
            tr("Transaction Added!"));
        stackedWidget->setCurrentIndex(0);
        homepagePtr->setupTable(stockModelPtr->GetTransactions());
        remapSymbolButtons();
        addTransactionPtr->clearValues();
        break;
    case 1:
        QMessageBox::warning(
            this,
            tr("Stock Tracker"),
            tr("Issue With Symbol. Should be between 2 and 4 letters."));
        break;
    case 2:
        QMessageBox::warning(
            this,
            tr("Stock Tracker"),
            tr("Issue With Price. Please resubmit a number."));
        break;
    case 3:
        QMessageBox::warning(
            this,
            tr("Stock Tracker"),
            tr("Issue With Quantity. Please resubmit a number."));
        break;
    default:
        break;
    }
}

/**
 * @brief StockController::validateNewTransaction
 * @param symbol
 * @param price
 * @param quantity
 * @return
 */
int StockController::validateNewTransaction(std::string symbol, std::string price,
                                            std::string quantity)
{
    //Check symbol length
    if(symbol.length() < 2 || symbol.length() > 4)
    {
        return 1;
    }
    //Check price is a number
    std::string::const_iterator it = price.begin();
    while (it != price.end() && std::isdigit(*it)) ++it;
    if(price.empty() || it != price.end())
    {
        return 2;
    }
    //Check quantity is a number
    std::string::const_iterator it2 = quantity.begin();
    while (it2 != price.end() && std::isdigit(*it2)) ++it2;
    if(price.empty() || it != price.end())
    {
        return 3;
    }
    return 0;

}

/**
 * @brief StockController::remapSymbolButtons
 */
void StockController::remapSymbolButtons()
{
    std::vector<QPushButton *> buttons = homepagePtr->getTableButtons();
    for(std::vector<QPushButton *>::iterator it = buttons.begin(); it != buttons.end(); ++it)
    {
        connect(*it, SIGNAL(released()),
                this, SLOT(handleSymbolButton()));
    }
}

/**
 * @brief StockController::handleSymbolButton
 */
void StockController::handleSymbolButton()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    std::string buttonText = buttonSender->text().toStdString();
    StockPage * newPage = new StockPage(buttonText, stockModelPtr->GetTransactions());
    connect(newPage->getBackButton(),SIGNAL(released()),
            this, SLOT(handleBackButton()));
    stackedWidget->addWidget(newPage);
    stackedWidget->setCurrentWidget(newPage);
}

/**
 * @brief StockController::handleBackButton
 */
void StockController::handleBackButton()
{
    QWidget * oldPage = stackedWidget->currentWidget();
    stackedWidget->setCurrentIndex(0);
    stackedWidget->removeWidget(oldPage);
    delete oldPage;
}

/**
 * @brief StockController::handleSearchButton
 */
void StockController::handleSearchButton()
{
    SearchPage * searchPage = new SearchPage(homepagePtr->getSearchEdit()->text().toStdString(), stockModelPtr->GetTransactions(), this);
    connect(searchPage->getBackButton(),SIGNAL(released()),
            this, SLOT(handleBackButton()));
    remapSearchSymbolButtons(searchPage);
    stackedWidget->addWidget(searchPage);
    stackedWidget->setCurrentWidget(searchPage);
}

/**
 * @brief StockController::remapSearchSymbolButtons
 * @param searchPage
 */
void StockController::remapSearchSymbolButtons(SearchPage * searchPage)
{
    std::vector<QPushButton *> buttons = searchPage->getTableButtons();
    for(std::vector<QPushButton *>::iterator it = buttons.begin(); it != buttons.end(); ++it)
    {
        connect(*it, SIGNAL(released()),
                this, SLOT(handleSymbolButton()));
    }
}

