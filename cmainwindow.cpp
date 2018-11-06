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

    connect( ui->btn_clear,     SIGNAL( clicked(bool) ),    this, SIGNAL( buttonClearClicked() ) );
    connect( ui->btn_rect,      SIGNAL( clicked(bool) ),    this, SIGNAL( buttonRectClicked() ) );
    connect( ui->btn_circle,    SIGNAL( clicked(bool) ),    this, SIGNAL( buttonCircleClicked() ) );
    connect( ui->btn_cloud,     SIGNAL( clicked(bool) ),    this, SIGNAL( buttonCloudClicked() ) );
    connect( ui->btn_generate,  SIGNAL( clicked(bool) ),    this, SIGNAL( buttonGenerateClicked() ) );
    connect( ui->actionSave,    SIGNAL( triggered(bool) ),  this, SIGNAL( saveToFileClicked() ) );

    connect( ui->picture_preview_area, SIGNAL( clicked( QPointF ) ), this, SIGNAL( graphicsSceneClicked( QPointF ) ) );
    connect( ui->picture_preview_area, SIGNAL( mouseMove( QPointF ) ), this, SIGNAL( graphicsSceneHover( QPointF ) ) );
    connect( ui->word_edit, SIGNAL( textChanged( QString ) ), this, SLOT( OnTextChanged( QString ) ) );

    ui->btn_rect->setChecked(true);
    ui->btn_generate->setEnabled(false);
}

void CMainWindow::OnTextChanged( QString text )
{
    ui->btn_generate->setEnabled( !text.isEmpty() );
}

CMainWindow::~CMainWindow()
{
    delete ui;
}

QGraphicsScene* CMainWindow::Scene()
{
    return ui->picture_preview_area->scene();
}

QString CMainWindow::Text()
{
    return ui->word_edit->text();
}
