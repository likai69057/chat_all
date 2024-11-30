#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置窗口大小
    setFixedSize(300, 500);

    //设置窗口图标
    setWindowIcon(QIcon(":/res/title.png"));

    //登录界面
    _login_dlg = new LoginDialog();
    setCentralWidget(_login_dlg);
    _login_dlg->show();

    //注册界面
    connect(_login_dlg, &LoginDialog::switchRegister, this, &MainWindow::SlotSwitchReg);
    _reg_dlg = new RegisterDialog();

}

MainWindow::~MainWindow()
{
    delete ui;
    if(_login_dlg){
        delete _login_dlg;
        _login_dlg = nullptr;
    }
    if(_reg_dlg){
        delete _reg_dlg;
        _reg_dlg = nullptr;
    }
}

