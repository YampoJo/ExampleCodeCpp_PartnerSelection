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

#include "Svaha.h"

enum ConsoleColor
{
    Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
    LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};

void SetColor(int text, int background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void GotoXY(int X, int Y)
{
    HANDLE hConsole;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { X, Y };
    SetConsoleCursorPosition(hStdOut, coord);
}

using namespace std;

void saveToFile(string filename, vector<User> users)
{
    ofstream file(filename);
    if (file.is_open())
    {
        for (int i = 0; i < users.size(); i++)
        {
            file << users[i].GetUserID() << endl;
            file << users[i].GetUserGender() << endl;
            file << users[i].GetUserAge() << endl;
            file << users[i].GetUserCity() << endl;
            file << users[i].GetUserEducation() << endl;
            file << users[i].GetIntSize() << endl;
            for (int j = 0; j < users[i].GetIntSize(); j++)
            {
                file << users[i].GetUserInterests(j) << endl;
            }
            file << users[i].GetUserGenderPref() << endl;
            file << users[i].GetUserAgePref() << endl;
            file << users[i].GetUserCityPref() << endl;
            file << users[i].GetUserEducationPref() << endl;
            file << users[i].GetIntSize() << endl;
            for (int j = 0; j < users[i].GetIntSize(); j++)
            {
                file << users[i].GetUserInterestsPref(j) << endl;
            }
            file << endl << endl;
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file!" << endl;
    }
}
void readFromFile(string filename, vector<User> &new_users, int _size_users)
{
    ifstream file(filename);
    if (file.is_open())
    {
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

        for (int i = 0; i < _size_users; i++)
        {
            file >> user_id;
            file.ignore();
            getline(file, gender);
            file >> age;
            file.ignore();
            getline(file, city);
            getline(file, education);
            int numInterests;
            file >> numInterests;
            file.ignore();
            interests.resize(numInterests);
            for (int i = 0; i < numInterests; i++)
            {
                getline(file, interests[i]);
            }
            getline(file, gender_pref);
            file >> age_pref;
            file.ignore();
            getline(file, city_pref);
            getline(file, education_pref);
            int numInterestsPref;
            file >> numInterestsPref;
            file.ignore();
            interests_pref.resize(numInterestsPref);
            for (int i = 0; i < numInterestsPref; i++)
            {
                getline(file, interests_pref[i]);
            }

            User tmp(user_id, gender, age, city, education, interests, gender_pref, age_pref, city_pref, education_pref, interests_pref);
            new_users.push_back(User(tmp));
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file!" << endl;
    }

}
void appendToFile(User& users, string filename)
{
    ofstream file(filename, ios_base::app);
    if (!file.is_open())
    {
        cerr << "Could not open file " << filename << " for writing." << endl;
        return;
    }
    else
    {
        file << users.GetUserID() << endl;
        file << users.GetUserGender() << endl;
        file << users.GetUserAge() << endl;
        file << users.GetUserCity() << endl;
        file << users.GetUserEducation() << endl;
        file << users.GetIntSize() << endl;
        for (int j = 0; j < users.GetIntSize(); j++)
        {
            file << users.GetUserInterests(j) << endl;
        }
        file << users.GetUserGenderPref() << endl;
        file << users.GetUserAgePref() << endl;
        file << users.GetUserCityPref() << endl;
        file << users.GetUserEducationPref() << endl;
        file << users.GetIntSize() << endl;
        for (int j = 0; j < users.GetIntSize(); j++)
        {
            file << users.GetUserInterestsPref(j) << endl;
        }
        file << endl << endl;
    }
    file.close();
    
}

void menu_login(vector<User> &new_users, int size_users, User &you);

void login_design_print_buttons(int action, int x, int y);

void about_program();
void login_area(vector<User>& new_users, int size_users, User& you);

void general_area(vector<User>& new_users, int size_users, User& you);

void general_print_all_users(vector<User> new_users, int size_users, int x, int y);

void general_design_print_buttons(int action, int x, int y);

void match_change_design_print_buttons(int action, int x, int y);

void match_area(vector<User> new_users, int size_users, User& you);

void log(string& gender, int& age, string& city, string& education, vector<string>& interests, int flag);

void free_area(vector<User>& new_users, int size_users, User& you);

void print_title_anketa(int flag);

void loading();

void check_lit(int& val);

void pause();


void main() 
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //system("mode con cols=120 lines=50");
    srand(time(NULL));

    int size_users = 9;

    User you;
   
    User user1("Ìóæñêîé", 25, "Ìîñêâà", "Ñğåäíåå", "Æåíñêèé", 25, "Ìîñêâà", "Ñğåäíåå");
    User user2("Æåíñêèé", 18, "Ñàíêò-Ïåòåğáóğã", "Îáùåå", "Ìóæñêîé", 18, "Ñàíêò-Ïåòåğáóğã", "Âûñøåå");
    User user3("Æåíñêèé", 21, "Ìîñêâà", "Âûñøåå", "Ìóæñêîé", 21, "Ìîñêâà", "Îáùåå");
    User user4("Æåíñêèé", 19, "Ñàğàòîâ", "Âûñøåå", "Ìóæñêîé", 19, "Ñàğàòîâ", "Ñğåäíåå");
    User user5("Ìóæñêîé", 37, "Íèæíèé Íîâãîğîä", "Ñğåäíåå", "Æåíñêèé", 37, "Íèæíèé Íîâãîğîä", "Âûñøåå");
    User user6("Æåíñêèé", 40, "Ïğèáğåæíîå", "Îáùåå", "Ìóæñêîé", 40, "Ñàğàòîâ", "Îáùåå");
    User user7("Ìóæñêîé", 19, "Ñàğàòîâ", "Âûñøåå", "Æåíñêèé", 21, "Ñàğàòîâ", "Ñğåäíåå");
    User user8("Ìóæñêîé", 37, "Íèæíèé Íîâãîğîä", "Ñğåäíåå", "Æåíñêèé", 35, "Ìîñêâà", "Âûñøåå");
    User user9("Æåíñêèé", 40, "Íèæíèé Íîâãîğîä", "Îáùåå", "Ìóæñêîé", 20, "Ïğèáğåæíîå", "Îáùåå");

    vector<User> users = { user1, user2, user3, user4, user5, user6, user7, user8, user9 };
    saveToFile("Users.txt", users);

    vector<User> new_users;
    readFromFile("Users.txt", new_users, size_users);

    loading();
    GotoXY(40, 13);
    cout << "ÄÀÍÍÛÅ ÓÑÏÅØÍÎ ÇÀÏÈÑÀÍÛ È Ñ×ÈÒÀÍÛ" << endl;
    pause();
    menu_login(new_users, size_users, you);
}

void menu_login(vector<User>& new_users, int size_users, User &you)
{
    string line_cons(120, '_');
    for (int button_key = 0, action = 0; true; button_key = _getch())
    {
        if (button_key == 72)
        {
            action--;
            if (action < 0)
            {
                action = 2;
            }
        }
        if (button_key == 80)
        {
            action++;
            if (action > 2)
            {
                action = 0;
            }
        }

        if (button_key == 13)
        {
            switch (action)
            {
                case 0: { about_program(); } break;
                case 1: { login_area(new_users, size_users, you); } break;
                case 2: { exit(0); } break;
            }
        }
        system("cls");

        cout << line_cons << endl << endl;
        cout << "                                                 İÊÇÀÌÅÍÀÖÈÎÍÍÀß ĞÀÁÎÒÀ" << endl;
        cout << line_cons << endl;

        login_design_print_buttons(action, 51, 5);
    }
}

void login_area(vector<User>& new_users, int size_users, User& you)
{

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

    system("cls");
    log(gender, age, city, education, interests, 0);

    log(gender_pref, age_pref, city_pref, education_pref, interests_pref, 1);

    you.SetAllUserCharact(gender, age, city, education, interests, gender_pref, age_pref, city_pref, education_pref, interests_pref);
    appendToFile(you, "Users.txt");

    system("cls");
    GotoXY(5, 2);
    cout << "ÂÀØÀ ÀÍÊÅÒÀ";
    you.printUserInfo(5, 3);
    pause();

    general_area(new_users, size_users, you);
}
void about_program()
{
    string line_cons(120, '_');
    system("cls");
    cout << line_cons << endl << endl;
    cout << "                                                  Î ÏĞÎÃĞÀÌÌÅ" << endl;
    cout << line_cons << endl << endl;
    cout << "                                      İÊÇÀÌÅÍÀÖÈÎÍÍÀß ĞÀÁÎÒÀ ßÌÏÎËÜÖÅÂÀ ÄÀÍÈËÀ" << endl;
    cout << endl;
    cout << "                             ÏĞÎÃĞÀÌÌÀ ĞÅÀËÈÇÓÅÒ ÁÀÇÎÂÓŞ ÈÌÌÈÒÀÖÈŞ ĞÀÁÎÒÛ ÑÅÒÈ ÇÍÀÊÎÌÑÒÂ" << endl;
    cout << line_cons << endl;
    cout << endl << endl;
    cout << "                                  ÂÀØÀ ÀÍÊÅÒÀ                          ×ÓÆÀß ÀÍÊÅÒÀ  " << endl;
    cout << "                              __________________                    __________________" << endl;
    cout << "                              |                |  "; SetColor(10, 0); cout << "===\\"; SetColor(15, 0); cout <<"        "; SetColor(11, 0); cout << "/==="; SetColor(15, 0); cout << "  |                |" << endl;
    cout << "                              |      ÂÀØÈ      |      "; SetColor(10, 0); cout << "\\"; SetColor(15, 0); cout << "      "; SetColor(11, 0); cout << "/"; SetColor(15, 0); cout << "      |      ×ÓÆÈÅ     | " << endl;
    cout << "                              |                |       "; SetColor(10, 0); cout << "\\"; SetColor(15, 0); cout << "    "; SetColor(11, 0); cout << "/"; SetColor(15, 0); cout << "       |                |" << endl;
    cout << "                              |     ÄÀÍÍÛÅ     |                    |     ÄÀÍÍÛÅ     |" << endl;
    cout << "                              |________________|    "; SetColor(13, 0); cout << "/ |] [| ] |"; SetColor(15, 0); cout << "     |________________|" << endl;
    cout << "                              |                |    "; SetColor(13, 0); cout << "\\ |] /| ] |]"; SetColor(15, 0); cout << "    |                |" << endl;
    cout << "                              |     ÄÀÍÍÛÅ     |                    |     ÄÀÍÍÛÅ     |" << endl;
    cout << "                              |                |       "; SetColor(11, 0); cout << "/"; SetColor(15, 0); cout << "    "; SetColor(10, 0); cout << "\\"; SetColor(15, 0); cout << "       |                |" << endl;
    cout << "                              |     ÏÎÈÑÊÀ     |      "; SetColor(11, 0); cout << "/"; SetColor(15, 0); cout << "      "; SetColor(10, 0); cout << "\\"; SetColor(15, 0); cout << "      |     ÏÎÈÑÊÀ     |" << endl;
    cout << "                              |________________|  "; SetColor(11, 0); cout << "<==/"; SetColor(15, 0); cout << "        "; SetColor(10, 0); cout << "\\==>"; SetColor(15, 0); cout << "  |________________|" << endl;


    pause();
}

void general_area(vector<User>& new_users, int size_users, User& you)
{
    for (int button_key = 0, action = 0; true; button_key = _getch())
    {
        if (button_key == 72)
        {
            action--;
            if (action < 0)
            {
                action = 2;
            }
        }
        if (button_key == 80)
        {
            action++;
            if (action > 2)
            {
                action = 0;
            }
        }

        if (button_key == 13)
        {
            switch (action)
            {
                case 0: 
                { 
                    free_area(new_users, size_users, you);

                } break;
                case 1: 
                { 
                    match_area(new_users, size_users, you); 
                } break;
                case 2: 
                { 
                    exit(0); 
                } break;
            }
        }
        system("cls");
        //general_print_all_users(new_users, size_users, 2, 26);
        general_design_print_buttons(action, 2, 2);
        cout << endl << endl;
        you.printUserInfo(60, 2);
    }
}

void general_print_all_users(vector<User> new_users, int size_users, int x, int y)
{
    int count_of_col = 0;
    for (int i = 0; i < size_users ; i++)
    { 
        new_users[i].printUserInfo_OnlyChar(x, y);
        y = y + 8;
        count_of_col++;
        if (count_of_col == 3)
        {
            count_of_col = 0;
            x = x + 32;
            y = y - (8 * 3);
        }
    }
    cout << endl;
}

void login_design_print_buttons(int action, int x, int y)
{
    if (action == 0)
    {
        GotoXY(x, y); SetColor(13, 0);
        cout << " +-------------+" << endl; GotoXY(x, y + 1);
        cout << " | "; SetColor(15, 0); cout << "Î ÏĞÎÃĞÀÌÌÅ"; SetColor(13, 0); cout << " |" << endl; GotoXY(x, y + 2);
        cout << " +-------------+" << endl; SetColor(15, 0); GotoXY(x, y + 3);
        cout << "      ÂÎÉÒÈ" << endl; GotoXY(x, y + 4);
        cout << endl; GotoXY(x, y + 5);
        cout << "      ÂÛÉÒÈ" << endl; GotoXY(x, y + 6);
        cout << endl;
    }

    if (action == 1)
    {
        GotoXY(x, y);
        cout << endl; GotoXY(x, y + 1);
        cout << "   Î ÏĞÎÃĞÀÌÌÅ" << endl; SetColor(13, 0); GotoXY(x, y + 2);
        cout << " +-------------+" << endl; GotoXY(x, y + 3);
        cout << " |    "; SetColor(15, 0); cout << "ÂÎÉÒÈ"; SetColor(13, 0); cout << "    |" << endl; GotoXY(x, y + 4);
        cout << " +-------------+" << endl; SetColor(15, 0); GotoXY(x, y + 5);
        cout << "      ÂÛÉÒÈ" << endl; GotoXY(x, y + 6);
        cout << endl; GotoXY(x, y);
    }

    if (action == 2)
    {
        GotoXY(x, y);
        cout << endl; GotoXY(x, y + 1);
        cout << "   Î ÏĞÎÃĞÀÌÌÅ" << endl; GotoXY(x, y + 2);
        cout << endl; GotoXY(x, y + 3);
        cout << "      ÂÎÉÒÈ" << endl; SetColor(13, 0); GotoXY(x, y + 4);
        cout << " +-------------+" << endl; GotoXY(x, y + 5);
        cout << " |     "; SetColor(15, 0); cout << "ÂÛÉÒÈ"; SetColor(13, 0); cout << "   |" << endl; GotoXY(x, y + 6);
        cout << " +-------------+" << endl; SetColor(15, 0);
        cout << endl;
    }
}

void general_design_print_buttons(int action, int x, int y)
{
    if (action == 0)
    {
        GotoXY(x, y); SetColor(13, 0);
        cout << " +--------------+"; GotoXY(x, y + 1);
        cout << " |  "; SetColor(15, 0); cout << "ÂÑÅ ÀÍÊÅÒÛ"; SetColor(13, 0); cout << "  |"; GotoXY(x, y + 2);
        cout << " +--------------+"; SetColor(15, 0); GotoXY(x, y + 3);
        cout << "   ÌÅÍŞ ÏÎÄÁÎĞÀ"; GotoXY(x, y + 4);
        cout << endl; GotoXY(x, y + 5);
        cout << "      ÂÛÕÎÄ"; GotoXY(x, y + 6);
        cout << endl;
    }

    if (action == 1)
    {
        GotoXY(x, y);
        cout << endl; GotoXY(x, y + 1);
        cout << "    ÂÑÅ ÀÍÊÅÒÛ"; SetColor(13, 0); GotoXY(x, y + 2);
        cout << " +--------------+"; GotoXY(x, y + 3);
        cout << " | "; SetColor(15, 0); cout << "ÌÅÍŞ ÏÎÄÁÎĞÀ"; SetColor(13, 0); cout << " |"; GotoXY(x, y + 4);
        cout << " +--------------+"; SetColor(15, 0); GotoXY(x, y + 5);
        cout << "      ÂÛÕÎÄ"; GotoXY(x, y + 6);
        cout << endl;
    }

    if (action == 2)
    {
        GotoXY(x, y);
        cout << endl; GotoXY(x, y + 1);
        cout << "    ÂÑÅ ÀÍÊÅÒÛ"; GotoXY(x, y + 2);
        cout << endl; GotoXY(x, y + 3);
        cout << "   ÌÅÍŞ ÏÎÄÁÎĞÀ"; SetColor(13, 0); GotoXY(x, y + 4);
        cout << " +--------------+"; GotoXY(x, y + 5);
        cout << " |    "; SetColor(15, 0); cout << "ÂÛÕÎÄ"; SetColor(13, 0); cout << "     |"; GotoXY(x, y + 6);
        cout << " +--------------+"; SetColor(15, 0);
        cout << endl;
    }
}

void match_change_design_print_buttons(int action, int x, int y)
{
    if (action == 0)
    {
        GotoXY(x, y); SetColor(13, 0);
        cout << " +---------------------------+"; GotoXY(x, y + 1);
        cout << " | "; SetColor(15, 0); cout << "ÈÄÅÀË ÏÎ ËÈ×ÍÛÌ ÊĞÈÒÅĞÈßÌ"; SetColor(13, 0); cout << " |"; GotoXY(x, y + 2);
        cout << " +---------------------------+"; SetColor(15, 0); GotoXY(x, y + 3);
        cout << "   ÈÄÅÀË ÏÎ ÎÁÙÈÌ ÊĞÈÒÅĞÈßÌ"; GotoXY(x, y + 4);
        cout << endl; GotoXY(x, y + 5);
        cout << "             ÑÎĞÒ"; GotoXY(x, y + 6);
		cout << endl; GotoXY(x, y + 7);
		cout << "            ÂÛÕÎÄ"; GotoXY(x, y + 8);
        cout << endl;

    }

    if (action == 1)
    {
        GotoXY(x, y);
        cout << endl; GotoXY(x, y + 1);
        cout << "   ÈÄÅÀË ÏÎ ËÈ×ÍÛÌ ÊĞÈÒÅĞÈßÌ"; SetColor(13, 0); GotoXY(x, y + 2);
        cout << " +---------------------------+"; GotoXY(x, y + 3);
        cout << " | "; SetColor(15, 0); cout << "ÈÄÅÀË ÏÎ ÎÁÙÈÌ ÊĞÈÒÅĞÈßÌ"; SetColor(13, 0); cout << "  |"; GotoXY(x, y + 4);
        cout << " +---------------------------+"; SetColor(15, 0); GotoXY(x, y + 5);
        cout << "             ÑÎĞÒ"; GotoXY(x, y + 6);
        cout << endl; GotoXY(x, y + 7);
		cout << "            ÂÛÕÎÄ"; GotoXY(x, y + 8);
		cout << endl;
    }

    if (action == 2)
    {
        GotoXY(x, y);
        cout << endl; GotoXY(x, y + 1);
        cout << "   ÈÄÅÀË ÏÎ ËÈ×ÍÛÌ ÊĞÈÒÅĞÈßÌ"; GotoXY(x, y + 2);
        cout << endl; GotoXY(x, y + 3);
        cout << "   ÈÄÅÀË ÏÎ ÎÁÙÈÌ ÊĞÈÒÅĞÈßÌ"; SetColor(13, 0); GotoXY(x, y + 4);
        cout << " +---------------------------+"; GotoXY(x, y + 5);
        cout << " |           "; SetColor(15, 0); cout << "ÑÎĞÒ"; SetColor(13, 0); cout << "            |"; GotoXY(x, y + 6);
        cout << " +---------------------------+"; SetColor(15, 0); GotoXY(x, y + 7);
		cout << "            ÂÛÕÎÄ"; GotoXY(x, y + 8);
		cout << endl;
    }

	if (action == 3)
	{
		GotoXY(x, y);
		cout << endl; GotoXY(x, y + 1);
		cout << "   ÈÄÅÀË ÏÎ ËÈ×ÍÛÌ ÊĞÈÒÅĞÈßÌ"; GotoXY(x, y + 2);
		cout << endl; GotoXY(x, y + 3);
		cout << "   ÈÄÅÀË ÏÎ ÎÁÙÈÌ ÊĞÈÒÅĞÈßÌ"; SetColor(13, 0); GotoXY(x, y + 4);
		cout << endl; GotoXY(x, y + 5); SetColor(15, 0);
		cout << "             ÑÎĞÒ"; SetColor(13, 0); GotoXY(x, y + 6);
		cout << " +---------------------------+"; GotoXY(x, y + 7);
		cout << " |          "; SetColor(15, 0); cout << "ÂÛÕÎÄ"; SetColor(13, 0); cout << "            |"; GotoXY(x, y + 8);
		cout << " +---------------------------+"; SetColor(15, 0);
		cout << endl;
	}
}

void match_area(vector<User> new_users, int size_users, User& you)
{
    Svaha matches(new_users, you, size_users);
    for (int button_key = 0, action = 0; true; button_key = _getch())
    {
        if (button_key == 72)
        {
            action--;
            if (action < 0)
            {
                action = 2;
            }
        }
        if (button_key == 80)
        {
            action++;
            if (action > 3)
            {
                action = 0;
            }
        }

        if (button_key == 13)
        {
            switch (action)
            {
                case 0:
                {
                    matches.match_by_my_pref();
                    matches.printBestMatch();
                    saveToFile("match_by_my_pref.txt", matches.GetBestM());
                    pause();
                } break;
                case 1:
                {
                    matches.thebest_match_by_mypref_and_itpref();
                    matches.printBestMatch();
                    saveToFile("thebest_match_by_mypref_and_itpref.txt", matches.GetBestM());
                    pause();
                } break;
				case 2:
				{
					matches.sort_all();
					matches.printBestMatch();
					saveToFile("sort_by_syn_.txt", matches.GetBestM());
					pause();
				}
                case 3:
                {
                    general_area(new_users, size_users, you);
                } break;
            }
        }
        
        system("cls");
        //general_print_all_users(new_users, size_users, 2, 26);
        match_change_design_print_buttons(action, 2, 2);
        cout << endl << endl;
        you.printUserInfo(40, 2);
    }
    //

    
    pause();
}

void check_lit(int& val)
{
    if (val <= 0 || val >= 3)
    {
        val = 0;
        cin.clear();
        cin.ignore(100, '\n');
    }
}

void log(string &gender, int &age, string &city, string &education, vector<string> &interests, int flag)
{
    string line_cons(120, '_');
    vector<string> inter = { "Ìóçûêà", "Ôèëüìû", "Êíèãè", "Èãğû", "Ïğîãğàììèğîâàíèå", "Äèçàéí" };
    vector<string> genders = { "Æåíñêèé", "Ìóæñêîé" };
    vector<string> educations = { "Âûñøåå", "Ñğåäíåå", "Îáùåå" };

    cout << "Çàïîëíèòå" << endl;
    int gender_pos = 0;
    int education_pos = 0;
    int nexts = 0;

    do
    {
        try
        {
            if (nexts <= 0)
            {
                print_title_anketa(flag);
                cout << line_cons << endl;
                cout << "                                               |                  |" << endl;
                cout << "                                               |   ÂÛÁÅĞÈÒÅ ÏÎË   |" << endl;
                cout << "                                               |__________________|" << endl << endl;
                cout << "                                               ";
                SetColor(13, 0);
                for (int i = 0; i < genders.size(); i++)
                {
                    cout << genders[i] << "      ";
                    SetColor(9, 0);
                }
                SetColor(13, 0);
                

                cout << "\n\n                                   "; cout << "1"; SetColor(15, 0); cout << " / "; SetColor(9, 0); cout << "2"; SetColor(15, 0); cout << " >>> "; cin >> gender_pos; gender_pos--;

                if (gender_pos < 0 or gender_pos > 1)
                {
                    check_lit(gender_pos);
                    throw gender_pos;
                }
                gender = genders[gender_pos];
                nexts++;
            }
            
            if (nexts <= 1)
            {
                print_title_anketa(flag);
                cout << line_cons << endl;
                cout << "                                             |                       |" << endl;
                cout << "                                             |    ÂÂÅÄÈÒÅ ÂÎÇĞÀÑÒ    |" << endl;
                cout << "                                             |_______________________|" << endl; SetColor(10, 0);
                cout << "\n                                   "; cout << "îò 18"; SetColor(15, 0); cout << " - "; SetColor(10, 0); cout << "äî 99"; SetColor(15, 0); cout << " >>> "; cin >> age;

                if (age < 18 or age > 99)
                {
                    check_lit(age);
                    throw age;
                }
                nexts++;
            } 

            if (nexts <= 2)
            {
                print_title_anketa(flag);
                cout << line_cons << endl;
                cout << "                                             |                       |" << endl;
                cout << "                                             |     ÂÂÅÄÈÒÅ ÃÎĞÎÄ     |" << endl;
                cout << "                                             |_______________________|" << endl;
                cout << "\n                                    >>> "; cin.ignore(); getline(cin, city);
                nexts++;
            }
            

            if (nexts <= 3)
            {
                print_title_anketa(flag);
                cout << line_cons << endl;
                cout << "                                           |                          |" << endl;
                cout << "                                           |   ÂÛÁÅĞÈÒÅ ÎÁĞÀÇÎÂÀÍÈÅ   |" << endl;
                cout << "                                           |__________________________|" << endl << endl;
                cout << "                                          "; SetColor(12, 0);
                for (int i = 0; i < educations.size(); i++)
                {
                    cout << educations[i] << "      ";
                }
                cout << "\n\n                                     1"; SetColor(15, 0); cout << " / "; SetColor(12, 0); cout << "2"; SetColor(15, 0); cout << " / "; SetColor(12, 0); cout << "3 "; SetColor(15, 0); cout << ">>> "; cin >> education_pos;  education_pos--;
              
                if (education_pos < 0 or education_pos > 2)
                {
                    //check_lit(education_pos);
                    throw education_pos;
                }
                education = educations[education_pos];
                nexts++;
            }

            for (int i = 0; i < 3; i++)
            {
                print_title_anketa(flag);
                cout << line_cons << endl;
                cout << "                                             |                       |" << endl;
                cout << "                                             |   ÂÛÁÅĞÈÒÅ ÈÍÒÅĞÅÑÛ   |" << endl;
                cout << "                                             |_______________________|" << endl << endl;
                cout << "                             ";

                int j = 0;
                SetColor(11, 0);
                for (int i = 0; i < inter.size(); i++)
                {
                    cout << inter[i] << "   ";
                }
                cout << "\n\n                             ÂÛÁÈĞÀÉÒÅ ÏÎ ÍÎÌÅĞÓ "; SetColor(15, 0); cout << ">>> "; cin >> j; j--;
                if (j < 0) { j = 0; }
                if (j > inter.size()) { j = inter.size() - 1; }
                cout << endl;

                interests.push_back(inter[j]);
                vector<string>::iterator iter = inter.begin();
                inter.erase(iter + j);
            }
        }
        catch (int j)
        {
            SetColor(4, 0);
            cout << "\n                                                   ÎØÈÁÊÀ ÂÂÎÄÀ\n";
            SetColor(15, 0);
            pause();
        }
        catch (string j)
        {
            SetColor(4, 0);
            cout << "\n                                                   ÎØÈÁÊÀ ÂÂÎÄÀ\n";
            SetColor(15, 0);
            pause();
        }
    } while (gender_pos < 0 or gender_pos > 1 or age < 18 or education_pos < 0 or education_pos > 2);
}

void print_title_anketa(int flag)
{
    string line_cons(120, '_');
    system("cls");
    cout << line_cons << endl << endl;
    switch (flag)
    {
    case 0:
        cout << "                                            ÂÂÅÄÈÒÅ ÄÀÍÍÛÅ ÑÂÎÅÉ ÀÍÊÅÒÛ" << endl;
        break;
    case 1:
        cout << "                                     ÂÂÅÄÈÒÅ ÄÀÍÍÛÅ ÄËß ÏÎÈÑÊÀ ÏÎÄÕÎÄßÙÅÉ ÀÍÊÅÒÛ " << endl;
        break;
    }
    
}

void free_area(vector<User>& new_users, int size_users, User& you)
{
	int color1 = 15, color2 = 15;

    for (int button_key = 0, action = 0; true; button_key = _getch())
    {
		color1 = 15, color2 = 15;
        if (button_key == 75)
        {
			color1 = 14;
            action--;
            if (action < 0)
            {
                action = new_users.size() - 1;
            }
        }
        if (button_key == 77)
        {
			color2 = 14;
            action++;
            if (action > new_users.size() - 1)
            {
                action = 0;
            }
        }

        if (button_key == 13)
        {
            general_area(new_users, size_users, you);
        }
        system("cls");
        new_users[action].printUserInfo(40, 2);

        SetColor(color2, 0);
        GotoXY(80, 10);
        cout << "  right \\"; GotoXY(80, 11);
        cout << "=========>"; GotoXY(80, 12);
        cout << "        /"; 
		SetColor(15, 0);


		SetColor(color1, 0);
        GotoXY(20, 10);
        cout << " /  left  "; GotoXY(20, 11);
        cout << "<========="; GotoXY(20, 12);
        cout << " \\       ";
		SetColor(15, 0);
    }
}

void loading()
{
    string line_cons(120, '_');
    string load_line(88, '_');
    int loading_time = 150;
    int x = 15, y = 7;
    cout << line_cons << endl;
    cout << "\n\n\n                                                ÇÀÃĞÓÇÊÀ ÄÀÍÍÛÕ";

    GotoXY(15, 6);
    cout << load_line;
    
    GotoXY(15, 10);
    cout << load_line;

    for (int i = 0; i < 22; i++)
    {
        GotoXY(x, y);
        SetColor(10, 0);
        cout << "    "; GotoXY(x, y + 1);
        cout << "===="; GotoXY(x, y + 2);
        cout << "===="; 
        Sleep(loading_time);
        x = x + 4;
    } 
    SetColor(15, 0);
}

void pause()
{
    //cout << " Äëÿ òîãî ÷òîáû âåğíóòüñÿ â ìåíş\n Íàæìèòå ëşáóş êíîïêó";
    system("pause >> null");
}