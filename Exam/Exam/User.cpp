int id_count = 1;
#include "User.h"

User::User()
{
    //������ ��������������
    gender = "�� ��������";
    age = 18;
    city = "�� ��������";
    education = "�� ��������";
    interests = { "������", "������", "�����" };
    //����������
    gender_pref = "�� ��������";
    age_pref = 18;
    city_pref = "�� ��������";
    education_pref = "�� ��������";
    interests_pref = { "������", "������", "�����" };
}
User::User(int _user_id, string _gender, int _age, string _city, string _education, string _gender_pref, int _age_pref, string _city_pref, string _education_pref)
{
    vector<string> inter = { "������", "������", "�����", "����", "����������������", "������" };
    //������ ��������������
    if (_user_id == id_count)
    {
        user_id = id_count;
        id_count++;
    }
    else
    {
        cout << "�������" << endl;
    }
    gender = _gender;
    age = _age;
    city = _city;
    education = _education;
    random_shuffle(inter.begin(), inter.end());
    for (int i = 0; i < size_int; i++)
    {
        interests.push_back(inter[i]);
    }
    cout << endl;

    //����������
    gender_pref = _gender_pref;
    age_pref = _age_pref;
    city_pref = _city_pref;
    education_pref = _education_pref;

    random_shuffle(inter.begin(), inter.end());
    for (int i = 0; i < size_int; i++)
    {
        interests.push_back(inter[i]);
    }


}
User::User(string _gender, int _age, string _city, string _education, string _gender_pref, int _age_pref, string _city_pref, string _education_pref)
{
    vector<string> inter = { "������", "������", "�����", "����", "����������������", "������" };
    //������ ��������������
    user_id = id_count; id_count++;
    gender = _gender;
    age = _age;
    city = _city;
    education = _education;
    random_shuffle(inter.begin(), inter.end());
    for (int i = 0; i < size_int; i++)
    {
        interests.push_back(inter[i]);
    }

    //����������
    gender_pref = _gender_pref;
    age_pref = _age_pref;
    city_pref = _city_pref;
    education_pref = _education_pref;
    random_shuffle(inter.begin(), inter.end());
    for (int i = 0; i < size_int; i++)
    {
        interests_pref.push_back(inter[i]);
    }
}
User::User(int _user_id, string _gender, int _age, string _city, string _education, vector<string> _interests, string _gender_pref, int _age_pref, string _city_pref, string _education_pref, vector<string> _interests_pref)
{
    //������ ��������������
    user_id = _user_id;
    gender = _gender;
    age = _age;
    city = _city;
    education = _education;
    interests = _interests;

    //����������
    gender_pref = _gender_pref;
    age_pref = _age_pref;
    city_pref = _city_pref;
    education_pref = _education_pref;
    interests_pref = _interests_pref;
}

void User::printUserInfo(int x, int y)
{
    GotoXY(x, y + 1);
    cout << "__________________________________"; GotoXY(x, y + 2);
    cout << "|                                |"; GotoXY(x, y + 3);
    cout << "| ID: " << user_id; GotoXY(x + 33, y + 3); cout << "|"; GotoXY(x, y + 4);
    cout << "| ���: " << gender; GotoXY(x + 33, y + 4); cout << "|"; GotoXY(x, y + 5);
    cout << "| �������: " << age; GotoXY(x + 33, y + 5); cout << "|"; GotoXY(x, y + 6);
    cout << "| �����: " << city; GotoXY(x + 33, y + 6); cout << "|"; GotoXY(x, y + 7);
    cout << "| �����������: " << education; GotoXY(x + 33, y + 7); cout << "|"; GotoXY(x, y + 8);
    cout << "| ��������: "; GotoXY(x + 33, y + 8); cout << "|"; GotoXY(x, y + 9);
    cout << "| ";
    for (int i = 0; i < size_int; i++)
    {
        cout << interests[i] << " ";
    }GotoXY(x + 33, y + 9); cout << "|"; GotoXY(x, y + 10);
    cout << "|--------------------------------|"; GotoXY(x, y + 11);
    cout << "| ���: " << gender_pref; GotoXY(x + 33, y + 11); cout << "|"; GotoXY(x, y + 12);
    cout << "| �������: " << age_pref; GotoXY(x + 33, y + 12); cout << "|"; GotoXY(x, y + 13);
    cout << "| �����: " << city_pref; GotoXY(x + 33, y + 13); cout << "|"; GotoXY(x, y + 14);
    cout << "| �����������: " << education_pref; GotoXY(x + 33, y + 14); cout << "|"; GotoXY(x, y + 15);
    cout << "| ��������: "; GotoXY(x + 33, y + 15); cout << "|"; GotoXY(x, y + 16);
    cout << "| ";
    for (int i = 0; i < size_int; i++)
    {
        cout << interests_pref[i] << " ";
    }GotoXY(x + 33, y + 16); cout << "|"; GotoXY(x, y + 17);
    cout << "|________________________________|";
}

void User::printUserInfo_OnlyChar(int x, int y)
{
    GotoXY(x, y);
    cout << "ID: " << user_id << endl; GotoXY(x, y + 1);
    cout << "���: " << gender << endl; GotoXY(x, y + 2);
    cout << "�������: " << age << endl; GotoXY(x, y + 3);
    cout << "�����: " << city << endl; GotoXY(x, y + 4);
    cout << "�����������: " << education << endl; GotoXY(x, y + 5);
    cout << "��������: "; GotoXY(x, y + 6);
    for (int i = 0; i < size_int; i++)
    {
        cout << interests[i] << " ";
    }
}

void User::SetAllUserCharact(string _gender, int _age, string _city, string _education, vector<string> _interests, string _gender_pref, int _age_pref, string _city_pref, string _education_pref, vector<string> _interests_pref)
{
    string res = "";
    bool has_space = false;

    user_id = id_count; id_count++;
    gender = _gender;
    age = _age;

    transform(_city.begin(), _city.end(), _city.begin(), tolower);
    _city[0] = toupper(_city[0]);

    for (int i = 0; i < _city.size(); i++)
    {
        if (_city[i] != ' ')
        {
            res += _city[i];
            has_space = false;
        }

        else if (!has_space)
        {
            res += ' ';
            has_space = true;
        }
    }

    for (int i = 1; i < res.size(); i++)
    {
        if (res[i - 1] == ' ' or res[i - 1] == '-')
        {
            res[i] = toupper(res[i]);
        }
    }
    city = res;
    res.clear();
    has_space = false;

    education = _education;
    interests = _interests;

    gender_pref = _gender_pref;
    age_pref = _age_pref;

    transform(_city_pref.begin(), _city_pref.end(), _city_pref.begin(), tolower);
    _city_pref[0] = toupper(_city_pref[0]);

    for (int i = 0; i < _city_pref.size(); i++)
    {
        if (_city_pref[i] != ' ')
        {
            res += _city_pref[i];
            has_space = false;
        }

        else if (!has_space)
        {
            res += ' ';
            has_space = true;
        }
    }

    for (int i = 1; i < res.size(); i++)
    {
        if (res[i - 1] == ' ' or res[i - 1] == '-')
        {
            res[i] = toupper(res[i]);
        }
    }
    city_pref = res;

    education_pref = _education_pref;
    interests_pref = _interests_pref;
}

int User::GetUserID()
{
    return user_id;
}
string User::GetUserGender()
{
    return gender;
}
int User::GetUserAge()
{
    return age;
}
string User::GetUserCity()
{
    return city;
}
string User::GetUserEducation()
{
    return education;
}
string User::GetUserInterests(int _i)
{
    return interests[_i];
}
string User::GetUserGenderPref()
{
    return gender_pref;
}
int User::GetUserAgePref()
{
    return age_pref;
}
int User::GetIntSize()
{
    return size_int;
}
string User::GetUserCityPref()
{
    return city_pref;
}
string User::GetUserEducationPref()
{
    return education_pref;
}
string User::GetUserInterestsPref(int _i)
{
    return interests_pref[_i];
}