/****************************************************************************
**
****************************************************************************/

#include <QtWidgets>
#include "logincontroller.h"
#include "mastercontroller.h"

/**Constructor for the LoginController class.
 * Takes a pointer back to the master controller to allow communication back
 * Calls the parent constructor (QWidget)*/
LoginController::LoginController(MasterController * _masterPtr, QWidget *parent)
    : QWidget(parent)
{
    masterPtr = _masterPtr;
    loginWindow = new LoginWindow();
    signUpWindow = new SignUpWindow();
    loginWindow->show();
    connect(loginWindow->getLoginButton(), SIGNAL(released()),
            this, SLOT(handleLoginButton()));
    connect(loginWindow->getSignUpButton(), SIGNAL(released()),
            this, SLOT(handleSignUpButton()));
    connect(signUpWindow->getCancelButton(), SIGNAL(released()),
            this, SLOT(handleCancelSignUp()));
}

/**Deconstructor for the LoginController
 * Deletes both sub windows*/
LoginController::~LoginController()
{
    delete loginWindow;
    delete signUpWindow;
}

/**closeWindows function closes any open windows.
 * Called when login process is complete.*/
void LoginController::closeWindows()
{
    loginWindow->close();
    signUpWindow->close();
}

/**Check login credentials within the model
 * If succussfull, return control to master controller*/
void LoginController::handleLoginButton()
{
    //Login done, pass control back to master
    masterPtr->loginComplete();
}

/**Open sign up window to allow user to sign up*/
void LoginController::handleSignUpButton()
{
    loginWindow->hide();
    connect(signUpWindow->getSignUpButton(), SIGNAL(released()),
            this, SLOT(handleNewSignUpButton()));
    signUpWindow->show();
}

void LoginController::handleCancelSignUp()
{
    loginWindow->show();
    signUpWindow->hide();
}

/**Validate new user information and add to database*/
void LoginController::handleNewSignUpButton()
{
    int check = validateNewUser();
    switch(check)
    {
    case 0:
        loginWindow->show();
        signUpWindow->close();
        break;
    case 1:
        QMessageBox::warning(
            this,
            tr("Stock Tracker"),
            tr("Issue with User Name. Please try again") );
        break;
    case 2:
        QMessageBox::warning(
            this,
            tr("Stock Tracker"),
            tr("Issue with Password. Please try again") );
        break;
    default:
        QMessageBox::warning(
            this,
            tr("Stock Tracker"),
            tr("Passwords do not match. Please try again") );
    }
}

int LoginController::validateNewUser()
{
    std::string password1 = signUpWindow->getPassword();
    std::string password2 = signUpWindow->getRepeatPassword();
    std::string loginName = signUpWindow->getLoginName();
    if(loginName.empty())
    {
        return 1;
    }
    if (password1.empty())
    {
        return 2;
    }
    if (password1 != password2)
    {
        return 3;
    }
    return 0;
}

