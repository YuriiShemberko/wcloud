#ifndef CRECTANGLEPATTERNGENERATOR_H
#define CRECTANGLEPATTERNGENERATOR_H

#include <ipatterngenerator.h>
#include <QGraphicsRectItem>

class CRectanglePatternGenerator : public CNullPatternGenerator
{
public:
    CRectanglePatternGenerator();

    virtual void BorderPointAdded( QPointF point ) override;
    virtual void GeneratePattern() override;
    virtual void BorderPointPreview( QPointF point ) override;

private:
    QPointF m_topleft;
    QPointF m_botright;

    bool m_border_finished;
    QGraphicsRectItem m_imaginary;
};

#endif // CRECTANGLEPATTERNGENERATOR_H
