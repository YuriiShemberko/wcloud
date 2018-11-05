#include "cmainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QGraphicsRectItem>
#include <QDebug>
#include <QDesktopWidget>

CMainWindow::CMainWindow( QWidget *parent ) :
    QMainWindow( parent ),
    ui( new Ui::MainWindow )
{
    ui->setupUi( this );
    ui->picture_preview_area->installEventFilter( this );

    connect( ui->btn_clear,     SIGNAL( clicked(bool) ),    this, SIGNAL( buttonClearClicked() ) );
    connect( ui->btn_rect,      SIGNAL( clicked(bool) ),    this, SIGNAL( buttonRectClicked() ) );
    connect( ui->btn_circle,    SIGNAL( clicked(bool) ),    this, SIGNAL( buttonCircleClicked() ) );
    connect( ui->btn_cloud,     SIGNAL( clicked(bool) ),    this, SIGNAL( buttonCloudClicked() ) );
    connect( ui->btn_generate,  SIGNAL( clicked(bool) ),    this, SIGNAL( buttonGenerateClicked() ) );
    connect( ui->actionSave,    SIGNAL( triggered(bool) ),  this, SIGNAL( saveToFileClicked() ) );

    ui->btn_rect->setChecked(true);

    QGraphicsScene* scene = new QGraphicsScene();
    qDebug() << ui->picture_preview_area->size();

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
                emit graphicsSceneClicked( mouse_ev->pos() );
                return true;
                break;
            }

            case QEvent::MouseMove:
            {
                QMouseEvent* mouse_ev = static_cast<QMouseEvent*>( ev );
                emit graphicsSceneHover( mouse_ev->pos() );
                return true;
                break;
            }

            case QEvent::Resize:
            {
               ui->picture_preview_area->scene()->setSceneRect( QRectF(0,0,ui->picture_preview_area->width() - 5, ui->picture_preview_area->height() - 5) );
               break;
            }
        }

    }

    return false;
}
