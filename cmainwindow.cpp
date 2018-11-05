#include "cmainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QGraphicsRectItem>
#include <QDebug>

CMainWindow::CMainWindow( QWidget *parent ) :
    QMainWindow( parent ),
    ui( new Ui::MainWindow )
{
    ui->setupUi( this );
    ui->picture_preview_area->installEventFilter( this );

    connect( ui->btn_clear,     SIGNAL( clicked(bool) ), this, SIGNAL( buttonClearClicked() ) );
    connect( ui->btn_rect,      SIGNAL( clicked(bool) ), this, SIGNAL( buttonRectClicked() ) );
    connect( ui->btn_circle,    SIGNAL( clicked(bool) ), this, SIGNAL( buttonCircleClicked() ) );
    connect( ui->btn_cloud,     SIGNAL( clicked(bool) ), this, SIGNAL( buttonCloudClicked() ) );
    connect( ui->btn_generate,  SIGNAL( clicked(bool) ), this, SIGNAL( buttonGenerateClicked() ) );

    ui->btn_rect->setChecked(true);

    QGraphicsScene* scene = new QGraphicsScene();
    scene->setSceneRect( QRectF(0,0,640,480) );
    scene->addRect(100,100,100,100, QPen(QColor(Qt::red)));

    ui->picture_preview_area->setScene(scene);
}

CMainWindow::~CMainWindow()
{
    delete ui;
}

QGraphicsScene* CMainWindow::Scene()
{
    return ui->picture_preview_area->scene();
}

bool CMainWindow::eventFilter (QObject *obj, QEvent *ev )
{
    if( obj == ui->picture_preview_area)
    {
        switch( ev->type() )
        {
            case QEvent::MouseButtonPress:
            {
                QMouseEvent* mouse_ev = static_cast<QMouseEvent*>( ev );
                qDebug() << mouse_ev->posF();
                emit graphicsSceneClicked( mouse_ev->posF() );
                return true;
                break;
            }
        }

    }

    return false;
}
