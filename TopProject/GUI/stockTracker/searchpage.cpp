#include "searchpage.h"
#include <QtWidgets>

SearchPage::SearchPage(std::string _searchName, std::vector<TransactionType> transactions,
                     QWidget *parent)
    :QWidget (),
     tableButtons()
{

    searchName = _searchName;
    transform(searchName.begin(), searchName.end(), searchName.begin(), ::toupper);
    setWindowTitle(tr("Search"));

    //Setup table
    stockTable = new QTableWidget(0, 5);
    stockTable->resize(700, 300);
    QStringList labels;
    labels << tr("Stock") << tr("Price") << tr("Quantity") << tr("Transaction Type") << tr("Transaction Date");
    stockTable->setHorizontalHeaderLabels(labels);
    stockTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    stockTable->setShowGrid(true);

    backButton = new QPushButton(tr("Back"));
    stockLabel = new QLabel(tr(searchName.c_str()));
    priceLabel = new QLabel(tr("Price"));
    priceAmountLabel = new QLabel(tr("Many Dollars"));

    setupTable(transactions);

    //Create Layout
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(backButton, 0, 0, 1, 1);
    layout->addWidget(stockLabel, 2, 0, 1, 1);
    layout->addWidget(priceLabel, 3, 0, 1, 1);
    layout->addWidget(priceAmountLabel, 3, 1, 1, 1);
    layout->addWidget(stockTable, 4, 0, 1, 2);
    layout->setColumnStretch( 0, 1 ) ; // Give column 1 stretch ability of ratio 1
    layout->setColumnStretch( 1, 1 ) ; // Give column 1 stretch ability of ratio 1
    setLayout(layout);
}

/**
 * @brief Homepage::setupTable
 * @param transactions
 */
void SearchPage::setupTable(std::vector<TransactionType> transactions)
{
    tableButtons.clear();
    for(std::vector<TransactionType>::iterator it = transactions.begin(); it!= transactions.end(); ++it)
    {

        //Only take our stock transactions.
        if(it->GetTicker().find(searchName) == std::string::npos)
        {
            continue;
        }
        //Setup our table items
        QPushButton * symbolButton = new QPushButton(it->GetTicker().c_str());
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
