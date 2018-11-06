#include "cpreviewarea.h"
#include <QDebug>

CPreviewArea::CPreviewArea(QWidget *parent) : QGraphicsView( new QGraphicsScene(), parent )
{
    setMouseTracking(true);
}

void CPreviewArea::mouseMoveEvent(QMouseEvent *ev)
{
    emit mouseMove( ev->pos() );
}

void CPreviewArea::mousePressEvent(QMouseEvent *ev)
{
    emit clicked( ev->pos() );
}

void CPreviewArea::resizeEvent(QResizeEvent *)
{
    scene()->setSceneRect(0, 0, width(), height());
}
