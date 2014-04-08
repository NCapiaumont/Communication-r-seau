#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTcpServer * socketServeur;
    QTcpSocket * laSocketDuClient;
private slots:
    void nouvelleConnexion();
    void repondreAuClient();

    void on_pushButtonEnvoyer_clicked();
    void on_action_Quitter_triggered();
    void on_action_Nouvelle_conversation_triggered();
};

#endif // MAINWINDOW_H
