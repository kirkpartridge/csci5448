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

/** Login Window class
 * Creates login window
 * */
class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    ///Login Window constructor
    LoginWindow(QWidget *parent = 0);
    ///Returns the Login Button
    QPushButton * getLoginButton() { return loginButton; }
    ///Returns the sign up button
    QPushButton * getSignUpButton() { return signUpButton; }
    ///Returns user entered login
    std::string getLogin();
    ///Returns user entered password
    std::string getPassword();

private:
    ///Private Qwidgets
    QLabel *loginNameLabel;
    QLabel *passwordLabel;
    QLabel *loginButtonLabel;
    QLineEdit *nameEdit;
    QLineEdit *passwordEdit;
    QPushButton *loginButton;
    QPushButton *signUpButton;
};

#endif // LOGINWINDOW_H
