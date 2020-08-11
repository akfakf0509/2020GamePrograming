#include "DataMager.h"

DataMager::DataMager()
{
}

DataMager* DataMager::instance()
{
    static DataMager inst;
    return &inst;
}

int DataMager::getLevel()
{
    return level;
}
