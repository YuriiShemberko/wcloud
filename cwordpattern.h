#ifndef SPATTERN_H
#define SPATTERN_H

#include <vector>

#include <QString>
#include <QColor>
#include <QRect>

struct SWordImage
{
    QString text;
    QColor color;
    QRect position;
};

class CWordPattern : public std::vector<SWordImage>
{};

#endif // SPATTERN_H
