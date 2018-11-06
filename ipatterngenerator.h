#ifndef IPATTERNGENERATOR_H
#define IPATTERNGENERATOR_H

#include <QGraphicsScene>
#include <QPointF>

//virtual
class IPatternGenerator
{
public:
    virtual void GeneratePattern( QString text ) = 0;
    virtual void BorderPointAdded( QPointF point ) = 0;
    virtual void BorderPointPreview( QPointF point ) = 0;
    virtual void SetScene( QGraphicsScene* scene )
    {
        m_scene = scene;
    }

protected:
    QGraphicsScene* m_scene;
};

class CNullPatternGenerator : public IPatternGenerator
{
protected:
    CNullPatternGenerator() {}
public:
    static CNullPatternGenerator* Instance()
    {
        static CNullPatternGenerator instance;
        return &instance;
    }
    virtual void GeneratePattern( QString ) override {}
    virtual void BorderPointAdded( QPointF ) override {}
    virtual void BorderPointPreview( QPointF ) override {}
};

#endif // IPATTERNGENERATOR_H
