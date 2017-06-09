//============================================================================
// Name        : STL_ZadachaS_Map.cpp
// Author      : t
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;
//Dvumeren masiv grad/t
// kay         vector<int>
//-------------------------
//Sofia    12 35 46 15 18 36 ...
//Plovdiv  26 18 46 15 18 36 ...
//Varna     2 35 46 15 18 13 ...
//1. в кой град е боло най-топло : град
//2 в кой град е боло най-студено, за всеки от градовете
//  град-> най-ниска т
//3. петте най-висеки температури за страната : гред->т
//4.колко пъти във всеки град е било > 15: град->броика
//5.Колко дни е било <=10, колко дни е било <=20,
//   колко дни е било над 20 : брои дни => гранича температура
void write(vector<int> v) {
	cout << "v contains:";
	for (unsigned i = 0; i < v.size(); i++)
		cout << " " << v[i];
	cout << "\n\n";
}
void read(vector<int> &v, int n) {
	srand(time(0));
	for (int i = 1; i <= n; i++) {
		int p = rand() % 40 + 1;
		v.push_back(p);
	}
}
void HowManyDaysMinDout10(vector<int> v);

int main() {


		vector<int> sofia;
		vector<int> plovdiv;
		vector<int> varna;
		vector<int> lom;
		read(sofia, 3);
		read(plovdiv, 5);
		read(varna, 6);
		read(lom, 4);
		write(sofia);
		write(plovdiv);
		write(varna);
		write(lom);

	map<string, vector<int> > countryTemps;
	countryTemps["sofia"] = sofia;
	countryTemps["plovdov"] = plovdiv;
	countryTemps["varna"] = varna;
	countryTemps["lom"] = lom;

	sort(sofia.begin(), sofia.begin() + sofia.size());
	for (unsigned i = 0; i < sofia.size(); i++) {
		cout << sofia[i] << " ";
	}
	cout << endl;
	sort(plovdiv.begin(), plovdiv.begin() + plovdiv.size());
	for (unsigned i = 0; i < plovdiv.size(); i++) {
		cout << plovdiv[i] << " ";
	}
	cout << endl;
	sort(varna.begin(), varna.begin() + varna.size());
	for (unsigned i = 0; i < varna.size(); i++) {
		cout << varna[i] << " ";
	}
	cout << endl;
	sort(lom.begin(), lom.begin() + lom.size());
	for (unsigned i = 0; i < lom.size(); i++) {
		cout << lom[i] << " ";
	}
	cout << endl;
	map<string, vector<int> > tempSorted;

	map<string, int> tounToMax;
	map<string, int> tounToMin;

	tempSorted["sofia"] = sofia;
	tempSorted["plovdiv"] = plovdiv;
	tempSorted["varna"] = varna;
	tempSorted["lom"] = lom;
	cout << "1.в кой град е боло най-топло~~~~~~~~~~~~~\n";
	map<string, vector<int> >::iterator iter;
	// izvedoxme max t
	int maxTemp = -100;
	int minTemp = -100;
	vector<string> cities;
	string city;
	//-------------------------------------------------------------------------------
	//1. в кой град е боло най-топло : град
	for (iter = tempSorted.begin(); iter != tempSorted.end(); ++iter) {
		vector<int> t;
		t = iter->second;
		cout << " Max t is => " << t[t.size() - 1] << endl << endl;
		tounToMax[iter->first] = t[t.size() - 1];
		int maxx = t[t.size() - 1];
		if (maxx > maxTemp) {
			maxTemp = maxx;
			city = iter->first;
		}

	}
	for (iter = tempSorted.begin(); iter != tempSorted.end(); ++iter) {
		vector<int> t = iter->second;
		if (t[t.size() - 1] == maxTemp) {
			cities.push_back(iter->first);

		}
	}
	for (unsigned i = 0; i < cities.size(); i++) {

		cout << "city max t is :" << cities[i] << "|" << endl;
	}
	//2.в кой град е боло най-студено-------------------------------------------------------------------------------
	cout << "\n2. кой град е боло най-студено~~~~~~~~~~~~~~~~~~~~~~~~\n";
	for (iter = tempSorted.begin(); iter != tempSorted.end(); ++iter) {
		vector<int> t = iter->second;
		int minn = t[0];
		if (minn < minTemp) {
			minTemp = minn;
			city = iter->first;
		}
		tounToMin[iter->first] = t[0];
		cout << iter->first << " Min t is => " << t[0] << endl;
	}
	cout << "\n3 . петте най-висеки температури за страната~~~~~~~~~~~~~~~~~~~~~~~~\n";
	//-------------------------------------------------------------------------------
	//3. петте най-висеки температури за страната : гред->t
	vector<int> allt;
	for (iter = countryTemps.begin(); iter != countryTemps.end(); iter++) {
		vector<int> t = iter->second;
		allt.insert(allt.end(), t.begin(), t.end());
	}
	sort(allt.begin(), allt.end());

	for (vector<int>::iterator it = allt.begin(); it != allt.end(); ++it)
		cout << "|" << *it;
	vector<int> fiveMaxT;
	cout << endl;
	for (vector<int>::iterator it = allt.end()-1; it != allt.end()-6; it--)
		fiveMaxT.push_back(*it);
//	for (unsigned i = allt.size()-1; i >= (allt.size() - 5); i--) {
//		fiveMaxT.push_back(allt[i]);
//
//	}
//	fiveMaxT.push_back(allt.at(allt.size() - 5));
//	fiveMaxT.push_back(allt.at(allt.size() - 4));
//	fiveMaxT.push_back(allt.at(allt.size() - 3));
//	fiveMaxT.push_back(allt.at(allt.size() - 2));
//	fiveMaxT.push_back(allt.at(allt.size() - 1));

	for (vector<int>::iterator it = fiveMaxT.begin(); it != fiveMaxT.end();
			++it)
		cout << "/" << *it;

	cout << "\n\n";
	map<string, int> fiveMaxTMap;
	for (unsigned i = 0; i < fiveMaxT.size(); i++) {
		int a = fiveMaxT[i];
		for (map<string, vector<int> >::iterator iter = countryTemps.begin(); iter != countryTemps.end(); iter++) {
			vector<int> t = iter->second;
			for (unsigned j = 0; j < t.size(); j++) {
				if (t[j] == a) {
					fiveMaxTMap[iter->first] = t[j];
					cout << iter->first << "=>" << t[j] << endl;
				}
			}
		}
	}
//	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~\n";
//	for (map<string , int>::iterator it1 = fiveMaxTMap.begin(); it1 != fiveMaxTMap.end(); it1++) {
//
//		cout<< it1->first<<"=>"<<it1->second<<endl;
//	}
	cout << "\n4.колко пъти във всеки град е било > 15: град->броика~~~~~~~~~~~~~~~~~~~~~~~~\n";
//-------------------------------------------------------------------------------
	//4.колко пъти във всеки град е било > 15: град->броика
	vector<int> tempUp15;	//Peravime vector za >15
	for (unsigned i = 0; i < allt.size(); i++) {
		if (allt[i] > 15) {
			tempUp15.push_back(allt[i]);
		}
	}
	for (vector<int>::iterator it = tempUp15.begin(); it != tempUp15.end();
			++it)
		cout << "*" << *it;
	cout << "\n\n";
//imame vector ot >15
//---------------------------------------------------------------------------------
	map<string, int> tempUp15Map;	//pravime nov map za >15
	//int count = 0;

	for (iter = countryTemps.begin(); iter != countryTemps.end(); iter++) {
		vector<int> t = iter->second; //pomoshten vector

		for (unsigned j = 0; j < t.size(); j++) {

			for (unsigned i = 0; i < tempUp15.size(); i++) {
				int a = tempUp15[i];
				if (t[j] == a) {

					tempUp15Map[iter->first]++;
					break;
				}

			}

		}
	}
//------------------------------------------------------------------------------
	for (map<string, int>::iterator ite = tempUp15Map.begin();
			ite != tempUp15Map.end(); ite++) {
		cout << ite->first << "=>" << ite->second << endl;
	}
	cout << "\n5. Колко дни е било <=10, колко дни е било <=20~~~~~~~~~~~~~~~~~~~~~~~~\n";
//-------------------------------------------------------------------------------
	//5.Колко дни е било <=10, колко дни е било <=20,
	//колко дни е било над 20 : брои дни => гранича температура
	//Колко дни е било <=10
	cout << "Sofia\n";
	HowManyDaysMinDout10(sofia);
	cout << "Plovdiv\n";
	HowManyDaysMinDout10(plovdiv);
	cout << "Varna\n";
	HowManyDaysMinDout10(varna);
	cout << "Lom\n";
	HowManyDaysMinDout10(lom);
	//-------------------------------------------------------------------------------
	return 0;
}

void HowManyDaysMinDout10(vector<int> v) {
	int count = 0;
	map<int, int> doun10Map;

	for (vector<int>::iterator i = v.begin(); i != v.end(); i++) {
		if (*i <= 10) {
			vector<int> t5;
			t5.push_back(*i); //pomoshten vector
			for (unsigned j = 0; j < t5.size(); j++)
				doun10Map[count++] = t5[j];
		}
	}
	for (map<int, int>::iterator it = doun10Map.begin(); it != doun10Map.end();
			++it)
		//cout << "|" << it->first << "=>" << it->second << "|";
	cout << endl << count << " days <= 10 !!!\n";
}
