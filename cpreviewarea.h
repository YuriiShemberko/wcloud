#ifndef CPREVIEWAREA_H
#define CPREVIEWAREA_H

#include <QObject>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QResizeEvent>

class CPreviewArea : public QGraphicsView
{
    Q_OBJECT
public:
    CPreviewArea(QWidget* parent = Q_NULLPTR);

protected:
    virtual void mouseMoveEvent(QMouseEvent* ev);
    virtual void mousePressEvent(QMouseEvent* ev);
    virtual void resizeEvent(QResizeEvent*);

signals:
    void clicked( QPointF point );
    void mouseMove( QPointF point );
};

#endif // CPREVIEWAREA_H
