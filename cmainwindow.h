#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class CMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CMainWindow( QWidget *parent = 0 );
    ~CMainWindow();

    QGraphicsScene* Scene();

private:
    Ui::MainWindow *ui;

protected:
    virtual bool eventFilter( QObject *obj, QEvent *ev ) override;


signals:
    void graphicsSceneClicked( QPointF pos );
    void graphicsSceneHover( QPointF pos );
    void buttonClearClicked();
    void buttonRectClicked();
    void buttonCircleClicked();
    void buttonCloudClicked();
    void buttonGenerateClicked();
    void saveToFileClicked();
};

#endif // MAINWINDOW_H
