#include "mastercontroller.h"

/**Constructor for the MasterController Object
 * Creates two sub controllers to handle control flow
 * LoginController and StockController */
MasterController::MasterController(QWidget *parent)
    :QWidget(parent)
{
    stockModel = new StockModel();
    loginController = new LoginController(this, stockModel, parent);
    stockController = new StockController(this, stockModel, parent);
}

/**Deconstructor for the MasterController Object
 * Deletes the two internal sub controllers*/
MasterController::~MasterController()
{
    delete loginController;
    delete stockController;
}

/**Called when the login controller has completed its tasks
 * Happens once the user has logged in*/
void MasterController::loginComplete()
{
    //Open stockController
    stockController->show();

    //close loginController
    loginController->closeWindows();
}
