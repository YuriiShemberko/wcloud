#include "csettings.h"

CSettings* CSettings::Instance() const
{
    static CSettings instance;
    return &instance;
}

void CSettings::SetPattern( EPattern pattern )
{
    m_pattern = pattern;
}

EPattern CSettings::GetPattern()
{
    return m_pattern;
}
