#ifndef IPATTERNGENERATOR_H
#define IPATTERNGENERATOR_H

#include <QGraphicsScene>
#include <QPointF>

//virtual
class IPatternGenerator
{
public:
    virtual void GeneratePattern( QGraphicsScene* scene ) = 0;
    virtual void BorderPointAdded( QPointF point ) = 0;
};

class CNullPatternGenerator : public IPatternGenerator
{
private:
    CNullPatternGenerator() {}
public:
    static CNullPatternGenerator* Instance()
    {
        static CNullPatternGenerator instance;
        return &instance;
    }
    virtual void GeneratePattern(QGraphicsScene*) override {}
    virtual void BorderPointAdded(QPointF) override {}
};

#endif // IPATTERNGENERATOR_H
