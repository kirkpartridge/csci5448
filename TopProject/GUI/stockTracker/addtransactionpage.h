#ifndef ADDTRANSACTIONPAGE_H
#define ADDTRANSACTIONPAGE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QComboBox;
class QDataWidgetMapper;
class QLabel;
class QLineEdit;
class QPushButton;
class QStandardItemModel;
class QStringListModel;
class QTextEdit;
class QCalendarWidget;
QT_END_NAMESPACE

class AddTransactionPage : public QWidget
{
public:
    AddTransactionPage(QWidget *parent);

    void clearValues();

    std::string getSymbol();
    std::string getPrice();
    std::string getQuantity();
    std::string getTransaction();
    std::string getDate();

    QPushButton * getSubmitButton();
    QPushButton * getCancelButton();
private:
    ///Private QWidgets
    QLabel *symbolLabel;
    QLabel *priceLabel;
    QLabel *quantityLabel;
    QLabel *transactionLabel;
    QLabel *dateLabel;
    QLineEdit *symbolEdit;
    QLineEdit *priceEdit;
    QLineEdit *quantityEdit;
    QComboBox *transactionEdit;
    QCalendarWidget *dateEdit;
    QPushButton *submitButton;
    QPushButton *cancelButton;
};

#endif // ADDTRANSACTIONPAGE_H
