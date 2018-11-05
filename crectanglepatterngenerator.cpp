#include "crectanglepatterngenerator.h"
#include <QDebug>

CRectanglePatternGenerator::CRectanglePatternGenerator(): m_topleft( 0, 0 ), m_botright( 0, 0 ), m_border_specified( false )
{

}

void CRectanglePatternGenerator::BorderPointAdded( QPointF point )
{   
    qDebug() << point;

    if( !m_border_specified)
    {
        if( m_topleft.isNull() )
        {
            m_topleft = point;
        }

        else
        {
            m_botright = point;
            m_border_specified = true;
        }
    }
}

void CRectanglePatternGenerator::GeneratePattern( QGraphicsScene *scene )
{
    //Q_ASSERT( m_border_specified );

    qDebug() << m_border_specified;

    if( m_border_specified )
    {
        scene->addRect( QRectF( m_topleft, m_botright ), QPen( QColor( Qt::red ) ) );
    }
}
