#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCheckBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_submitInput_clicked();
    void updateOutputVisibility();
    void on_btnPage1_clicked();

private:
    Ui::MainWindow *ui;

    void setupOutputOptions();
    void updateLayoutSpacing();
};

#endif
