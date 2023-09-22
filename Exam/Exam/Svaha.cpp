#include "Svaha.h"

Svaha::Svaha(vector<User> _users, User _you, int _size_users)
{
    users = _users;
    you = _you;
    size_users = _size_users;
}

void Svaha::printBestMatch()
{
    int count_of_str = 0;
    string line_cons(120, '_');
    int x = 2, y = 20;
    GotoXY(x - 2, y);
    cout << line_cons; GotoXY(x, y + 2);
    cout << "ËÓ×ØÈÅ ÑÎÂÏÀÄÅÍÈß ÏÎ ÂÀØÅÌÓ ÇÀÏÐÎÑÓ " << endl;
    for (int i = 0; i < best_matches.size(); i++)
    {
        best_matches[i].printUserInfo(x, y + 3);
        x = x + 38;
		count_of_str++;
        if (count_of_str == 3)
        {
            count_of_str = 0;
            x = x - (38*3) ;
            y = y + 18;
        }
        
    }
}

void Svaha::count_me_counter()
{
	best_matches.clear();
	int max_points = -1;

	for (int i = 0; i < size_users; i++)
	{
		int points = 0;

		if (you.GetUserGenderPref() == users[i].GetUserGender())
		{
			points++;
		}

		if (you.GetUserAgePref() >= users[i].GetUserAge() - 5 && you.GetUserAgePref() <= users[i].GetUserAge() + 5)
		{
			points++;
		}

		if (you.GetUserCityPref() == users[i].GetUserCity())
		{
			points++;
		}

		if (you.GetUserEducationPref() == users[i].GetUserEducation())
		{
			points++;
		}

		for (int j = 0; j < you.GetIntSize(); j++)
		{
			for (int k = 0; k < users[i].GetIntSize(); k++)
			{
				if (you.GetUserInterestsPref(j) == users[i].GetUserInterests(k))
				{
					points++;
					break;
				}
			}
		}

		users[i].data_for_svaha.Set_count_me(points);
	}
}

void Svaha::thebest_match_by_mypref_and_itpref()
{
    best_matches.clear();
    int max_points = -1;

    for (int i = 0; i < size_users; i++)
    {
        int points_me = 0;
        int points_it = 0;

        if (you.GetUserGenderPref() == users[i].GetUserGender()) { points_me++; }
        if (you.GetUserGender() == users[i].GetUserGenderPref()) { points_it++; }

        if (you.GetUserAgePref() >= users[i].GetUserAge() - 5 && you.GetUserAgePref() <= users[i].GetUserAge() + 5) { points_me++; }
        if (you.GetUserAge() >= users[i].GetUserAgePref() - 5 && you.GetUserAge() <= users[i].GetUserAgePref() + 5) { points_it++; }

        if (you.GetUserCityPref() == users[i].GetUserCity()) { points_me++; }
        if (you.GetUserCity() == users[i].GetUserCityPref()) { points_it++; }

        if (you.GetUserEducationPref() == users[i].GetUserEducation()) { points_me++; }
        if (you.GetUserEducation() == users[i].GetUserEducationPref()) { points_it++; }

        for (int j = 0; j < you.GetIntSize(); j++)
        {
            for (int k = 0; k < users[i].GetIntSize(); k++)
            {
                if (you.GetUserInterestsPref(j) == users[i].GetUserInterests(k))
                {
                    points_me++;
                    break;
                }
            }
        }
        for (int j = 0; j < you.GetIntSize(); j++)
        {
            for (int k = 0; k < users[i].GetIntSize(); k++)
            {
                if (you.GetUserInterests(j) == users[i].GetUserInterestsPref(k))
                {
                    points_it++;
                    break;
                }
            }
        }

        users[i].data_for_svaha.Set_count_me(points_me);
        users[i].data_for_svaha.Set_count_it(points_it);
        users[i].data_for_svaha.Set_count_all(points_me + points_it);

        if (points_me + points_it > max_points)
        {
            max_points = points_me + points_it;
        }
    }

    for (int i = 0; i < size_users; i++)
    {
        cout << users[i].data_for_svaha.Get_count_all() << " ";
    }

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].data_for_svaha.Get_count_all() == max_points)
        {
            best_matches.push_back(users[i]);
        }
    }
    
    cout << endl;
}

void Svaha::match_by_my_pref()
{
    best_matches.clear();
    int max_points = -1;

    for (int i = 0; i < size_users; i++)
    {
        int points = 0;

        if (you.GetUserGenderPref() == users[i].GetUserGender())
        {
            points++;
        }

        if (you.GetUserAgePref() >= users[i].GetUserAge() - 5 && you.GetUserAgePref() <= users[i].GetUserAge() + 5)
        {
            points++;
        }

        if (you.GetUserCityPref() == users[i].GetUserCity())
        {
            points++;
        }

        if (you.GetUserEducationPref() == users[i].GetUserEducation())
        {
            points++;
        }

        for (int j = 0; j < you.GetIntSize(); j++)
        {
            for (int k = 0; k < users[i].GetIntSize(); k++)
            {
                if (you.GetUserInterestsPref(j) == users[i].GetUserInterests(k))
                {
                    points++;
                    break;
                }
            }
        }

        users[i].data_for_svaha.Set_count_me(points);

        if (points > max_points)
        {
            max_points = points;
        }
    }

    for (int i = 0; i < size_users; i++)
    {
        cout << users[i].data_for_svaha.Get_count_me() << " ";
    }

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].data_for_svaha.Get_count_me() == max_points)
        {
            best_matches.push_back(users[i]);
        }
    }
    cout << endl;
}

bool pred_for_sort (User& a, User& b)
{
	return a.data_for_svaha.Get_count_me() > b.data_for_svaha.Get_count_me();
}

void Svaha::sort_all()
{
	count_me_counter();
	best_matches = users;
	sort(best_matches.begin(), best_matches.end(), pred_for_sort);
}

vector<User> Svaha::GetBestM()
{
    return best_matches;
}
