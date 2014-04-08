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
    laSocketDuClient->write("Connection établie !");

}
void MainWindow::repondreAuClient()
{
    QString messageClient=laSocketDuClient->readAll();
    ui->listWidgetMessagerie->addItem("MOI - "+messageClient);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonEnvoyer_clicked()
{
    QString message=ui->lineEditReponseAuClient->text();
    laSocketDuClient->write(message.toLatin1());
    ui->listWidgetMessagerie->addItem("CLIENT - "+ui->lineEditReponseAuClient->text());
    ui->lineEditReponseAuClient->clear();
}

void MainWindow::on_action_Quitter_triggered()
{
    this->close();
}

void MainWindow::on_action_Nouvelle_conversation_triggered()
{
    ui->lineEditReponseAuClient->clear();
    ui->listWidgetMessagerie->clear();
}
