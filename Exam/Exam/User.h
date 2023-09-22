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

#include "Points.h"

using namespace std;

enum ConsoleColor;

void SetColor(int text, int background);

void GotoXY(int X, int Y);




class User : Points
{
protected:
    int size_int = 3;

    int user_id;
    string gender;
    int age;
    string city;
    string education;
    vector<string> interests;

    string gender_pref;
    int age_pref;
    string city_pref;
    string education_pref;
    vector<string> interests_pref;

public:
    Points data_for_svaha;
    User();
    User(int _user_id, string _gender, int _age, string _city, string _education, string _gender_pref, int _age_pref, string _city_pref, string _education_pref);
    User(string _gender, int _age, string _city, string _education, string _gender_pref, int _age_pref, string _city_pref, string _education_pref);
    User(int _user_id, string _gender, int _age, string _city, string _education, vector<string> _interests, string _gender_pref, int _age_pref, string _city_pref, string _education_pref, vector<string> _interests_pref);
    ~User() {};

    void printUserInfo(int x, int y);
    void printUserInfo_OnlyChar(int x, int y);

    void SetAllUserCharact(string _gender, int _age, string _city, string _education, vector<string> _interests, string _gender_pref, int _age_pref, string _city_pref, string _education_pref, vector<string> _interests_pref);
 
    int GetUserID();
    string GetUserGender();
    int GetUserAge();
    string GetUserCity();
    string GetUserEducation();
    string GetUserInterests(int _i);
    string GetUserGenderPref();
    int GetUserAgePref();
    int GetIntSize();
    string GetUserCityPref();
    string GetUserEducationPref();
    string GetUserInterestsPref(int _i);
};