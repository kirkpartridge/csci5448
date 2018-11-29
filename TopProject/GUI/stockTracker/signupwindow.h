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

/** Sign up window. Populates needed edits.
 * */
class SignUpWindow : public QWidget
{
    Q_OBJECT

public:
    ///Constructor
    SignUpWindow(QWidget *parent = 0);
    ///Returns sign up button
    QPushButton * getSignUpButton() { return signUpButton; }
    ///Returns cancel button
    QPushButton * getCancelButton() { return cancelButton; }
    ///Returns user entered login name
    std::string getLoginName();
    ///Returns user entered password
    std::string getPassword();
    ///Returns user entered repeat password
    std::string getRepeatPassword();

private:
    ///Private QWidgets
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
