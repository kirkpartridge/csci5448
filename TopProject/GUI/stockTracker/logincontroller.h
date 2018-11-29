#ifndef LOGINCONTOLLER
#define LOGINCONTOLLER

#include <QWidget>

#include "signupwindow.h"
#include "loginwindow.h"

class MasterController;
class StockModel;
class LoginController : public QWidget
{
    Q_OBJECT

public:
    LoginController(MasterController * _masterPtr, StockModel * _stockModelPtr,
                    QWidget *parent = 0);

    ~LoginController();

    /* Close all windows. Allows transition to other controller */
    void closeWindows();

private slots:
    ///Handle Sign up
    void handleSignUpButton();
    ///Load new sign up window
    void handleNewSignUpButton();
    ///Handle Login
    void handleLoginButton();
    ///Handle sign up cancel
    void handleCancelSignUp();

private:
    ///Private widgets
    SignUpWindow *signUpWindow;
    LoginWindow *loginWindow;
    int validateNewUser();
    MasterController * masterPtr;
    StockModel * stockModelPtr;
};

#endif // LOGINCONTOLLER
