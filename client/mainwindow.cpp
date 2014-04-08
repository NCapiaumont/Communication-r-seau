#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_Connecter_triggered()
{
    //on va le connecter
    bool ok;
    QString adresseDuServeur=QInputDialog::getText(this,"Superbe client réseau","Adresse du serveur",QLineEdit::Normal,"127.0.0.1",&ok);
    if(ok)
    {
        laSocketVersLeServeur=new QTcpSocket(this);
        laSocketVersLeServeur->connectToHost(adresseDuServeur,6666);
        connect(laSocketVersLeServeur,SIGNAL(readyRead()),this,SLOT(traiterMessagesDuServeur()));
    }
}
void MainWindow::traiterMessagesDuServeur()
{
    QString donneesRecues=laSocketVersLeServeur->readAll();
    ui->labelMessageServeur->setText(donneesRecues);
}
void MainWindow::on_pushButtonEnvoyer_clicked()
{
    QString message=ui->lineEditMessage->text();
    laSocketVersLeServeur->write(message.toLatin1());
}
