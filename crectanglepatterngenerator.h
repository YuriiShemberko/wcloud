#ifndef CRECTANGLEPATTERNGENERATOR_H
#define CRECTANGLEPATTERNGENERATOR_H

#include <ipatterngenerator.h>

class CRectanglePatternGenerator : public IPatternGenerator
{
public:
    CRectanglePatternGenerator();

    virtual void BorderPointAdded( QPointF point ) override;
    virtual void GeneratePattern(QGraphicsScene* scene) override;

private:
    QPointF m_topleft;
    QPointF m_botright;

    bool m_border_specified;
};

#endif // CRECTANGLEPATTERNGENERATOR_H
