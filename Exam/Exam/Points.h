#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include <algorithm>
#include <span>

using namespace std;

class Points 
{
protected:
    int count_all;
    int count_it;
    int count_me;

public:
    Points();
    ~Points() {};

    void Set_count_all(int _count_all);
    void Set_count_me(int _count_me);
    void Set_count_it(int _count_it);

    int Get_count_all();
    int Get_count_it();
    int Get_count_me();

};