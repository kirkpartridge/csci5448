#ifndef LOGINCONTOLLER
#define LOGINCONTOLLER

#include <QWidget>

#include "signupwindow.h"
#include "loginwindow.h"

class MasterController;
class LoginController : public QWidget
{
    Q_OBJECT

public:
    LoginController(MasterController * _masterPtr, QWidget *parent = 0);

    ~LoginController();

    void closeWindows();

private slots:
    void handleSignUpButton();
    void handleNewSignUpButton();
    void handleLoginButton();
    void handleCancelSignUp();

private:
    SignUpWindow *signUpWindow;
    LoginWindow *loginWindow;
    int validateNewUser();
    MasterController * masterPtr;
};

#endif // LOGINCONTOLLER
