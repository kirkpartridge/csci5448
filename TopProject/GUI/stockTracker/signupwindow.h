#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H

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
QT_END_NAMESPACE

//! [Window definition]
class SignUpWindow : public QWidget
{
    Q_OBJECT

public:
    SignUpWindow(QWidget *parent = 0);
    QPushButton * getSignUpButton() { return signUpButton; }
    QPushButton * getCancelButton() { return cancelButton; }
    std::string getLoginName();
    std::string getPassword();
    std::string getRepeatPassword();

private:

    QLabel *loginNameLabel;
    QLabel *passwordLabel;
    QLabel *repeatPasswordLabel;
    QLabel *submitLabel;
    QLineEdit *loginNameEdit;
    QLineEdit *passwordEdit;
    QLineEdit *repeatPasswordEdit;
    QPushButton *signUpButton;
    QPushButton *cancelButton;
};

#endif // SIGNUPWINDOW_H
