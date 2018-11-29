#ifndef SEARCHPAGE_H
#define SEARCHPAGE_H
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

class SearchPage : public QWidget
{
public:
    SearchPage(std::string _searchName, std::vector<TransactionType> transactions, QWidget *parent=0);

    /** Populate table with provided transaction information */
    void setupTable(std::vector<TransactionType> transactions);

    QPushButton * getBackButton() { return backButton; }
    ///Returns vector of symbol buttons
    std::vector<QPushButton *> getTableButtons() { return tableButtons; }


private:
    QPushButton * backButton;
    QLabel * stockLabel;
    QLabel * priceLabel;
    QLabel * priceAmountLabel;

    QTableWidget * stockTable;

    std::string searchName;
    std::vector<QPushButton *> tableButtons;

};

#endif // SEARCHPAGE_H
