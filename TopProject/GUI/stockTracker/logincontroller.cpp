/****************************************************************************
**
****************************************************************************/

#include <QtWidgets>
#include "logincontroller.h"
#include "mastercontroller.h"

/**Constructor for the LoginController class.
 * Takes a pointer back to the master controller to allow communication back
 * Calls the parent constructor (QWidget)*/
LoginController::LoginController(MasterController * _masterPtr, StockModel * _stockModelPtr,
                                 QWidget *parent)
    : QWidget(parent)
{
    masterPtr = _masterPtr;
    stockModelPtr = _stockModelPtr;
    loginWindow = new LoginWindow();
    signUpWindow = new SignUpWindow();
    loginWindow->show();
    connect(loginWindow->getLoginButton(), SIGNAL(released()),
            this, SLOT(handleLoginButton()));
    connect(loginWindow->getSignUpButton(), SIGNAL(released()),
            this, SLOT(handleSignUpButton()));
    connect(signUpWindow->getCancelButton(), SIGNAL(released()),
            this, SLOT(handleCancelSignUp()));
    connect(signUpWindow->getSignUpButton(), SIGNAL(released()),
            this, SLOT(handleNewSignUpButton()));
}


/**
 * @brief LoginController::~LoginController
 */
LoginController::~LoginController()
{
   // delete loginWindow;
   // delete signUpWindow;
}

/**
 * @brief LoginController::closeWindows
 */
void LoginController::closeWindows()
{
    loginWindow->close();
    signUpWindow->close();
}

/**
 * @brief LoginController::handleLoginButton
 * Check login credentials within the model
 * If succussfull, return control to master controller
 */
void LoginController::handleLoginButton()
{
    //Login done, pass control back to master
    masterPtr->loginComplete();
}

/**Open sign up window to allow user to sign up*/
void LoginController::handleSignUpButton()
{
    loginWindow->hide();
    signUpWindow->show();
}

/**
 * @brief LoginController::handleCancelSignUp
 */
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
        QMessageBox::warning(
            this,
            tr("Stock Tracker"),
            tr("User added. Please Login."));
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

/**
 * @brief LoginController::validateNewUser
 * @return status
 */
int LoginController::validateNewUser()
{
    //Check values to ensure they were entered
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

