#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

private slots:
    void on_action_Connecter_triggered();
    void traiterMessagesDuServeur();
    void on_pushButtonEnvoyer_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket * laSocketVersLeServeur;
};

#endif // MAINWINDOW_H
