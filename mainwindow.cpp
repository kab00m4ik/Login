#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "loginmanager.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_login_clicked()
{
    LoginManager lm;
    QString Email = ui->le_Email->text();
    QString Password = ui->le_Password->text();
    if(Email.isEmpty() || Password.isEmpty())
    {
        ui->l_LoginResult->setText("Enter more info!");
        return;
    }

    QString PasswordHash = getHashFrom(Password);
    QString ValidationResult = lm.AccountValidator(Email, PasswordHash);
    ui->l_LoginResult->setText(ValidationResult);
}

