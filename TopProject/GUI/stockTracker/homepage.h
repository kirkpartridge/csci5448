#ifndef HOMEPAGE_H
#define HOMEPAGE_H
#include <QWidget>
#include <QTableWidget>
#include <QMainWindow>
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
QT_END_NAMESPACE


/**QWidget for the homepage. Will populate a table with
 * stock date received from the CSV import
 * Calls the parent constructor (QWidget)*/
class Homepage : public QWidget
{
        //Q_OBJECT
public:
    Homepage(QWidget *parent = 0);
    ~Homepage();

    /** Populate table with provided transaction information */
    void setupTable(std::vector<TransactionType> transactions);

    ///Returns Push Button to export CSV
    QPushButton * getExportCSVButton() { return exportCSVButton; }
    ///Returns Push Button to import CSV
    QPushButton * getImportCSVButton() { return importCSVButton; }
    ///Returns Push Button to perform search
    QPushButton * getSearchButton() { return searchButton; }
    ///Returns Push button to bring up add transaction screen
    QPushButton * getAddTransactionButton() { return addTransactionButton; }
    ///Returns Edit line for search
    QLineEdit * getSearchEdit() { return searchEdit; }
    ///Returns vector of symbol buttons
    std::vector<QPushButton *> getTableButtons() { return tableButtons; }


private:
    ///Private widgets
    QTableWidget * stockTable;
    QPushButton * importCSVButton;
    QPushButton * exportCSVButton;
    QPushButton * searchButton;
    QPushButton * addTransactionButton;
    QLineEdit * searchEdit;

    std::vector<QPushButton *> tableButtons;

};

#endif // HOMEPAGE_H
