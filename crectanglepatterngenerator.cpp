#include "crectanglepatterngenerator.h"
#include <QDebug>

CRectanglePatternGenerator::CRectanglePatternGenerator(): m_topleft( 0, 0 ), m_botright( 0, 0 ), m_border_finished( false )
{

}

void CRectanglePatternGenerator::BorderPointAdded( QPointF point )
{   
    if( !m_border_finished)
    {
        if( m_topleft.isNull() )
        {
            m_topleft = point;
        }

        else
        {
            m_botright = point;
            m_border_finished = true;
        }
    }
}

void CRectanglePatternGenerator::GeneratePattern()
{
    //Q_ASSERT( m_border_specified );

    if( m_border_finished )
    {
        m_scene->addRect( QRectF( m_topleft, m_botright ), QPen( QColor( Qt::red ) ) );
    }
}

void CRectanglePatternGenerator::BorderPointPreview(QPointF point)
{
    qDebug() << point;

    if( !m_border_finished )
    {
        if( m_scene->items().contains(&m_imaginary) )
        {
            m_scene->removeItem( &m_imaginary );
        }

        m_imaginary.setRect( QRectF( m_topleft, point ) );
        m_scene->addItem(&m_imaginary);
    }
}
