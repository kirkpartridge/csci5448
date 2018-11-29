#include "homepage.h"

#include <QHeaderView>
#include <QGridLayout>
#include <QtWidgets>
#include <QHeaderView>

#include <ctime>
/**
 * @brief Homepage::Homepage
 * @param parent
 */
Homepage::Homepage(QWidget *parent)
: QWidget(parent),
  tableButtons()
{
    setWindowTitle(tr("Stock Tracker"));

    //Setup table
    stockTable = new QTableWidget(0, 5);
    stockTable->resize(700, 300);
    QStringList labels;
    labels << tr("Stock") << tr("Price") << tr("Quantity") << tr("Transaction Type") << tr("Transaction Date");
    stockTable->setHorizontalHeaderLabels(labels);
    stockTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    stockTable->setShowGrid(true);

    importCSVButton = new QPushButton(tr("Import CSV"));
    exportCSVButton = new QPushButton(tr("Export CSV"));
    searchButton = new QPushButton(tr("Search"));
    addTransactionButton = new QPushButton(tr("Add Transaction"));
    searchEdit = new QLineEdit();

    std::vector<TransactionType> foo;
    setupTable(foo);

    //Create Layout
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(importCSVButton, 0, 0, 1, 1);
    layout->addWidget(exportCSVButton, 0, 1, 1, 1);
    layout->addWidget(addTransactionButton, 0, 2, 1, 1);
    layout->addWidget(searchButton, 2, 0, 1, 1);
    layout->addWidget(searchEdit, 2, 1, 1, 1);
    layout->addWidget(stockTable, 3, 0, 1, 3);
    layout->setColumnStretch( 0, 1 ) ; // Give column 1 stretch ability of ratio 1
    layout->setColumnStretch( 1, 1 ) ; // Give column 1 stretch ability of ratio 1
    setLayout(layout);
}

/**
 * @brief Homepage::~Homepage
 */
Homepage::~Homepage()
{
    delete stockTable;
    delete importCSVButton;
    delete exportCSVButton;
    delete searchButton;
    delete addTransactionButton;
    delete searchEdit;
}

/**
 * @brief Homepage::setupTable
 * @param transactions
 */
void Homepage::setupTable(std::vector<TransactionType> transactions)
{
    //Clear table
    stockTable->setRowCount(0);
    //Clear table buttons vector
    tableButtons.clear();

    for(std::vector<TransactionType>::iterator it = transactions.begin(); it!= transactions.end(); ++it)
    {
        //Setup our table items
        QPushButton * symbolButton = new QPushButton(it->GetTicker().c_str());
        //connect(symbolButton, SIGNAL(released()),
        //        this, SLOT(handleSymbolButton()));
        QTableWidgetItem *priceItem = new QTableWidgetItem(std::to_string(it->GetPrice()).c_str());
        priceItem->setFlags(priceItem->flags() ^ Qt::ItemIsEditable);
        QTableWidgetItem *quantityItem = new QTableWidgetItem(std::to_string(it->GetQuantity()).c_str());
        quantityItem->setFlags(quantityItem->flags() ^ Qt::ItemIsEditable);
        QTableWidgetItem *typeItem = new QTableWidgetItem(it->GetType().c_str());
        typeItem->setFlags(typeItem->flags() ^ Qt::ItemIsEditable);

        //Insert new transaction into table
        stockTable->insertRow ( stockTable->rowCount() );
        stockTable->setIndexWidget(stockTable->model()->index(stockTable->rowCount()-1, 0), symbolButton);
        stockTable->setItem   ( stockTable->rowCount()-1,
                                 1,
                                 priceItem);
        stockTable->setItem   ( stockTable->rowCount()-1,
                                 2,
                                 quantityItem);
        stockTable->setItem   ( stockTable->rowCount()-1,
                                 3,
                                 typeItem);
        //Get Date information into correct string format
        char buff[20];
        struct tm * timeinfo;
        time_t date = it->GetDate();
        timeinfo = localtime (&date);
        strftime(buff, sizeof(buff), "%D", timeinfo);
        QTableWidgetItem *dateItem = new QTableWidgetItem(buff);
        dateItem->setFlags(dateItem->flags() ^ Qt::ItemIsEditable);
        stockTable->setItem   ( stockTable->rowCount()-1,
                                 4,
                                 dateItem);

        //Add our new button to the array
        tableButtons.push_back(symbolButton);
    }
}

