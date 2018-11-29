#ifndef STOCKPAGE_H
#define STOCKPAGE_H

#include <QWidget>

#include "TransactionType.h"

QT_BEGIN_NAMESPACE
class QComboBox;
class QDataWidgetMapper;
class QLabel;
class QLineEdit;
class QPushButton;
class QStandardItemModel;
class QStringListModel;
class QTextEdit;
class QTableWidget;
QT_END_NAMESPACE

class StockPage : public QWidget
{
public:
    StockPage(std::string _stockName, std::vector<TransactionType> transactions, QWidget *parent=0);

    /** Populate table with provided transaction information */
    void setupTable(std::vector<TransactionType> transactions);

    QPushButton * getBackButton() { return backButton; }


private:
    QPushButton * backButton;
    QLabel * stockLabel;
    QLabel * priceLabel;
    QLabel * priceAmountLabel;

    QTableWidget * stockTable;

    std::string stockName;

};

#endif // STOCKPAGE_H
