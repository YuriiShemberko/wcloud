#ifndef CAPPCONTROLLER_H
#define CAPPCONTROLLER_H

#include <crectanglepatterngenerator.h>
#include <csettings.h>

#include <QObject>

class CMainWindow;

class CAppController: public QObject
{
    Q_OBJECT

public:
    CAppController( QObject* parent = nullptr );
    void ConnectToGui( CMainWindow* mw );

public slots:
    void OnSceneClicked( QPointF point );
    void OnClearRequested();
    void OnGenerateRequested();

    void OnCirclePatternRequested();
    void OnRectPatternRequested();
    void OnCloudPatternRequested();

private:
    CSettings m_settings;
    CMainWindow* m_gui;
    IPatternGenerator* m_generator;

    void ResetGenerator( EPattern pattern );
};

#endif // CAPPCONTROLLER_H
