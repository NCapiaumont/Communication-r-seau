#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socketServeur=new QTcpServer(this);
    //écoute sur toutes ses interfaces réseau et sur le port 6666
    socketServeur->listen(QHostAddress::Any,6666);
    connect(socketServeur,SIGNAL(newConnection()),this,SLOT(nouvelleConnexion()));
}
void MainWindow::nouvelleConnexion()
{
    laSocketDuClient=socketServeur->nextPendingConnection();
    connect(laSocketDuClient,SIGNAL(readyRead()),this,SLOT(repondreAuClient()));
    laSocketDuClient->write("NOM:");
}
void MainWindow::repondreAuClient()
{
    QString nomDuClient=laSocketDuClient->readAll();
    QString message="Bonjour "+nomDuClient;
    laSocketDuClient->write(message.toLatin1());
}

MainWindow::~MainWindow()
{
    delete ui;
}
