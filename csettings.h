#ifndef CSETTINGS_H
#define CSETTINGS_H

//singleton

enum EPattern
{
    Pattern_Null,
    Pattern_Rectangle,
    Pattern_Circle,
    Pattern_Cloud,

    Pattern_Count
};

class CSettings
{
public:
    CSettings(){ m_pattern = Pattern_Null; }

private:
    EPattern m_pattern;


public:
    CSettings* Instance() const;

    void SetPattern( EPattern pattern );
    EPattern GetPattern();
};

#endif // CSETTINGS_H
