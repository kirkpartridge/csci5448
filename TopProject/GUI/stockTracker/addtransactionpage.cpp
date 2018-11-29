#include "addtransactionpage.h"
#include <QtWidgets>

AddTransactionPage::AddTransactionPage(QWidget *parent)
    :QWidget ()
{
    setWindowTitle(tr("Add New Transaction"));

    symbolLabel = new QLabel(tr("Symbol"));
    priceLabel = new QLabel("Price");
    quantityLabel = new QLabel("Quantity");
    transactionLabel = new QLabel("Transaction Type");
    dateLabel = new QLabel("Date");

    symbolEdit = new QLineEdit();
    priceEdit = new QLineEdit();
    quantityEdit = new QLineEdit();
    dateEdit = new QCalendarWidget();
    transactionEdit = new QComboBox();
    transactionEdit->addItem(QString("Buy"));
    transactionEdit->addItem(QString("Sell"));

    submitButton = new QPushButton("Submit");
    cancelButton = new QPushButton("Cancel");

    //Create Layout
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(symbolLabel, 0, 0, 1, 1, Qt::AlignRight);
    layout->addWidget(symbolEdit, 0, 1, 1, 1);
    layout->addWidget(priceLabel, 1, 0, 1, 1, Qt::AlignRight);
    layout->addWidget(priceEdit, 1, 1, 1, 1);
    layout->addWidget(quantityLabel, 2, 0, 1, 1, Qt::AlignRight);
    layout->addWidget(quantityEdit, 2, 1, 1, 1);
    layout->addWidget(dateLabel, 3, 0, 1, 1, Qt::AlignRight);
    layout->addWidget(dateEdit, 3, 1, 1, 1);
    layout->addWidget(transactionLabel, 4, 0, 1, 1, Qt::AlignRight);
    layout->addWidget(transactionEdit, 4, 1, 1, 1);
    layout->addWidget(cancelButton, 5, 0, 1, 1);
    layout->addWidget(submitButton, 5, 1, 1, 1);
    layout->setColumnStretch( 0, 1 ) ; // Give column 1 stretch ability of ratio 1
    layout->setColumnStretch( 1, 1 ) ; // Give column 1 stretch ability of ratio 1
    setLayout(layout);

    resize(400,400);
}

/**
 * @brief AddTransactionPage::getCancelButton
 * @return
 */
QPushButton * AddTransactionPage::getCancelButton()
{
    return cancelButton;
}

/**
 * @brief AddTransactionPage::getSubmitButton
 * @return
 */
QPushButton * AddTransactionPage::getSubmitButton()
{
    return submitButton;
}

/**
 * @brief AddTransactionPage::getSymbol
 * @return
 */
std::string AddTransactionPage::getSymbol()
{
    return symbolEdit->text().toStdString();
}

/**
 * @brief AddTransactionPage::getPrice
 * @return
 */
std::string AddTransactionPage::getPrice()
{
    return priceEdit->text().toStdString();
}

/**
 * @brief AddTransactionPage::getQuantity
 * @return
 */
std::string AddTransactionPage::getQuantity()
{
    return quantityEdit->text().toStdString();
}

/**
 * @brief AddTransactionPage::getTransaction
 * @return
 */
std::string AddTransactionPage::getTransaction()
{
    return transactionEdit->currentText().toStdString();
}

/**
 * @brief AddTransactionPage::getDate
 * @return
 */
std::string AddTransactionPage::getDate()
{
    return dateEdit->selectedDate().toString(Qt::SystemLocaleShortDate).toStdString();
}

void AddTransactionPage::clearValues()
{
    symbolEdit->clear();
    priceEdit->clear();
    quantityEdit->clear();
}
