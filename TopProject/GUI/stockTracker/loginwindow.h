#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H
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
class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = 0);
    QPushButton * getLoginButton() { return loginButton; }
    QPushButton * getSignUpButton() { return signUpButton; }

    std::string getLogin();
    std::string getPassword();

private:
    void setupModel();

    QLabel *loginNameLabel;
    QLabel *passwordLabel;
    QLabel *loginButtonLabel;
    QLineEdit *nameEdit;
    QLineEdit *passwordEdit;
    QPushButton *loginButton;
    QPushButton *signUpButton;
};

#endif // LOGINWINDOW_H
