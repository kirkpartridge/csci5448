#include "loginwindow.h"

/****************************************************************************
**
****************************************************************************/

#include <QtWidgets>
#include "loginwindow.h"
#include "logincontroller.h"

/**Constructs the login window. Populates with
 * necessary labels and inputs*/
LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent)
{
    loginNameLabel = new QLabel(tr("UserName:"));
    nameEdit = new QLineEdit();
    passwordLabel = new QLabel(tr("Password:"));
    passwordEdit = new QLineEdit();
    passwordEdit->setEchoMode(QLineEdit::Password);
    //loginButtonLabel = new QLabel(tr("&Type:"));
    loginButton = new QPushButton(tr("Login"));
    signUpButton = new QPushButton(tr("Sign Up"));

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(loginNameLabel, 0, 0, 1, 1);
    layout->addWidget(nameEdit, 0, 1, 1, 1);
    layout->addWidget(passwordLabel, 1, 0, 1, 1);
    layout->addWidget(passwordEdit, 1, 1, 1, 1);
    layout->addWidget(loginButton, 2, 0, 1, 1);
    layout->addWidget(signUpButton, 2, 1, 1, 1);
    setLayout(layout);

    setWindowTitle(tr("Stock Tracker"));
}

/**Returns login name provided by user.*/
std::string LoginWindow::getLogin()
{
    return nameEdit->text().toStdString();
}

/**Returns password provided by user.*/
std::string LoginWindow::getPassword()
{
    return passwordEdit->text().toStdString();
}

