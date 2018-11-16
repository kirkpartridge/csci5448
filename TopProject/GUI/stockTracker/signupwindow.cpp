#include "signupwindow.h"

#include <QtWidgets>

/**Creates sign up window. Includes necessary input fields.*/
SignUpWindow::SignUpWindow(QWidget *parent)
    : QWidget(parent)
{
    //Setup labels and inputs
    loginNameLabel = new QLabel(tr("UserName:"));
    loginNameEdit = new QLineEdit();
    passwordLabel = new QLabel(tr("Password:"));
    passwordEdit = new QLineEdit();
    passwordEdit->setEchoMode(QLineEdit::Password);
    repeatPasswordLabel = new QLabel(tr("Repeat Password:"));
    repeatPasswordEdit = new QLineEdit();
    repeatPasswordEdit->setEchoMode(QLineEdit::Password);
    signUpButton = new QPushButton(tr("Sign Up"));
    cancelButton = new QPushButton(tr("Cancel"));

    //Create Layout
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(loginNameLabel, 0, 0, 1, 1);
    layout->addWidget(loginNameEdit, 0, 1, 1, 1);
    layout->addWidget(passwordLabel, 1, 0, 1, 1);
    layout->addWidget(passwordEdit, 1, 1, 1, 1);
    layout->addWidget(repeatPasswordLabel, 2, 0, 1, 1);
    layout->addWidget(repeatPasswordEdit, 2, 1, 1, 1);
    layout->addWidget(cancelButton, 3, 0, 1, 1);
    layout->addWidget(signUpButton, 3, 1, 1, 1);
    setLayout(layout);

    setWindowTitle(tr("Sign Up"));
}

/**Return user provided login name.*/
std::string SignUpWindow::getLoginName()
{
    return loginNameEdit->text().toStdString();
}

/**Return user provided password.*/
std::string SignUpWindow::getPassword()
{
    return passwordEdit->text().toStdString();
}

/**Return user provided repeated password.*/
std::string SignUpWindow::getRepeatPassword()
{
    return repeatPasswordEdit->text().toStdString();
}
