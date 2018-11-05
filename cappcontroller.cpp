#include "cappcontroller.h"
#include "cmainwindow.h"
#include <QDebug>

CAppController::CAppController( QObject *parent ) : QObject( parent ), m_settings( CSettings() ), m_generator( new CRectanglePatternGenerator() )
{}


void CAppController::ConnectToGui(CMainWindow *mw)
{
    connect( mw, SIGNAL( graphicsSceneClicked( QPointF ) ), this,    SLOT( OnSceneClicked( QPointF ) ) );
    connect( mw, SIGNAL( buttonClearClicked() ),            this,    SLOT( OnClearRequested() ) );
    connect( mw, SIGNAL( buttonCircleClicked() ),           this,    SLOT( OnCirclePatternRequested() ) );
    connect( mw, SIGNAL( buttonRectClicked() ),             this,    SLOT( OnRectPatternRequested() ) );
    connect( mw, SIGNAL( buttonCloudClicked() ),            this,    SLOT( OnCloudPatternRequested() ) );
    connect( mw, SIGNAL( buttonGenerateClicked() ),         this,    SLOT( OnGenerateRequested() ) );

    m_gui = mw;
}

void CAppController::OnGenerateRequested()
{
    m_generator->GeneratePattern( m_gui->Scene() );
}

void CAppController::OnSceneClicked( QPointF point )
{
    m_generator->BorderPointAdded(point);
}

void CAppController::OnClearRequested()
{
    ResetGenerator( m_settings.GetPattern() );

    if( !m_gui->Scene()->items().empty() )
    {
        m_gui->Scene()->clear();
        m_gui->Scene()->setSceneRect( QRectF(0,0,640,480) );
    }
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
}
