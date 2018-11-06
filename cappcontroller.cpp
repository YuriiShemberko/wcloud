#include "cappcontroller.h"
#include "cmainwindow.h"
#include <QDebug>
#include <QGraphicsView>
#include <QtSvg/QSvgGenerator>

CAppController::CAppController( QObject *parent ) : QObject( parent ), m_settings( CSettings() )
{
    m_generator = CNullPatternGenerator::Instance() ;
}


void CAppController::ConnectToGui(CMainWindow *mw)
{
    connect( mw, SIGNAL( graphicsSceneClicked( QPointF ) ), this,    SLOT( OnSceneClicked( QPointF ) ) );
    connect( mw, SIGNAL( graphicsSceneHover( QPointF ) ),   this,    SLOT( OnSceneHover( QPointF ) ) );
    connect( mw, SIGNAL( buttonClearClicked() ),            this,    SLOT( OnClearRequested() ) );
    connect( mw, SIGNAL( buttonCircleClicked() ),           this,    SLOT( OnCirclePatternRequested() ) );
    connect( mw, SIGNAL( buttonRectClicked() ),             this,    SLOT( OnRectPatternRequested() ) );
    connect( mw, SIGNAL( buttonCloudClicked() ),            this,    SLOT( OnCloudPatternRequested() ) );
    connect( mw, SIGNAL( buttonGenerateClicked() ),         this,    SLOT( OnGenerateRequested() ) );
    connect( mw, SIGNAL( saveToFileClicked() ),             this,    SLOT( OnSaveToFileRequested() ) );

    m_gui = mw;
    ResetGenerator( m_settings.GetPattern() );
}

void CAppController::OnGenerateRequested()
{
    m_generator->GeneratePattern( m_gui->Text() );
}

void CAppController::OnSceneClicked( QPointF point )
{
    m_generator->BorderPointAdded(point);
}

void CAppController::OnClearRequested()
{
    ResetGenerator( m_settings.GetPattern() );
}

void CAppController::OnCirclePatternRequested()
{
    m_settings.SetPattern( Pattern_Circle );
    ResetGenerator( Pattern_Circle );
}

void CAppController::OnRectPatternRequested()
{
    m_settings.SetPattern( Pattern_Rectangle );
    ResetGenerator( Pattern_Rectangle );
}

void CAppController::OnCloudPatternRequested()
{
    m_settings.SetPattern( Pattern_Cloud );
    ResetGenerator( Pattern_Cloud );
}

void CAppController::OnSaveToFileRequested()
{
    bool svg = false;

    QGraphicsScene* scene = m_gui->Scene();

    if(svg)
    {

        QSvgGenerator generator;
            generator.setFileName("C:/Users/Shemberko/Desktop/test.svg");
            generator.setSize(QSize(200, 200));
            generator.setViewBox(QRect(0, 0, 200, 200));
            generator.setTitle(tr("SVG Generator Example Drawing"));
            generator.setDescription(tr("An SVG drawing created by the SVG Generator "
                                        "Example provided with Qt."));

            QPainter painter(&generator);
            scene->render(&painter);
    }

    else
    {
        QImage image(scene->sceneRect().size().toSize(), QImage::Format_ARGB32);  // Create the image with the exact size of the shrunk scene
        image.fill(Qt::transparent);                                              // Start all pixels transparent

        QPainter painter(&image);
        scene->render(&painter);
        image.save("C:/Users/Shemberko/Desktop/test.svg");
    }
}

void CAppController::OnSceneHover( QPointF point )
{
    m_generator->BorderPointPreview(point);
}

void CAppController::ResetGenerator( EPattern pattern )
{
    if( m_generator != CNullPatternGenerator::Instance() )
    {
        delete m_generator;
    }

    switch( pattern )
    {
        case Pattern_Rectangle:
            m_generator = new CRectanglePatternGenerator();
        break;

        default:
            m_generator = CNullPatternGenerator::Instance();
        break;
    }


    if (!m_gui->Scene()->items().empty())
    {
        m_gui->Scene()->clear();
    }

    m_generator->SetScene(m_gui->Scene());
}
