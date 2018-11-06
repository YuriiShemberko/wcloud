#include "crectanglepatterngenerator.h"
#include <QDebug>
#include <QFont>

CRectanglePatternGenerator::CRectanglePatternGenerator(): m_topleft( 0, 0 ), m_botright( 0, 0 ), m_border_finished( false ), m_imaginary(nullptr)
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
            if( m_scene->items().contains( m_imaginary ) )
            {
                m_scene->removeItem( m_imaginary );
            }

            m_botright = point;
            m_border_finished = true;

            m_scene->addRect( QRectF( m_topleft, m_botright ), QPen( QColor( Qt::red ) ) );
        }
    }
}

QGraphicsTextItem* GetWord( QString text )
{
    QGraphicsTextItem* item = new QGraphicsTextItem( text );

    item->setFont( QFont( "Arial", 8 ) );//(6 + qrand() % 9) ); //6 - 15

    return item;
}

void CRectanglePatternGenerator::GeneratePattern( QString text )
{
    Q_ASSERT( !text.isEmpty() && m_border_finished );
    int spacing = 20;

    QGraphicsTextItem* item = nullptr;

    for( int y = m_topleft.y() + spacing; ; y += spacing )
    {
        for( int x = m_topleft.x() + spacing; x ; x += spacing )
        {
            //item = GetWord( text );
            //item->setPos( x, y );

            break; //TODO
        }
    }
}

void CRectanglePatternGenerator::BorderPointPreview(QPointF point)
{
    if( !m_border_finished && !m_topleft.isNull() )
    {
        if( m_scene->items().contains( m_imaginary ) )
        {
            m_scene->removeItem( m_imaginary );
        }

        m_imaginary = new QGraphicsRectItem( QRectF( m_topleft, point ) );
        m_scene->addItem(m_imaginary);
    }
}
