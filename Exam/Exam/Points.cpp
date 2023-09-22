
#include "Points.h"

Points::Points()
{
    count_all = 0;
    count_it = 0;
    count_me = 0;
}

void Points::Set_count_all(int _count_all)
{
    count_all = _count_all;
}

void Points::Set_count_me(int _count_me)
{
    count_me = _count_me;
}

void Points::Set_count_it(int _count_it)
{
    count_it = _count_it;
}

int Points::Get_count_all()
{
    return count_all;
}

int Points::Get_count_it()
{
    return count_it;
}

int Points::Get_count_me()
{
    return count_me;
}
