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

#include "User.h"

class Svaha : public User
{
private:
    User you;
    vector<User> users;
    vector<User> best_matches{};
    int size_users;
public:
    Svaha(vector<User> _users, User _you, int _size_users);
    ~Svaha() {}
    void printBestMatch();

	void count_me_counter();

    void thebest_match_by_mypref_and_itpref();
    void match_by_my_pref();
	void sort_all();

    vector <User> GetBestM();
};

