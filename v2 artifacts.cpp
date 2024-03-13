#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <time.h>
#include <cstdlib>
#include <random>

using namespace std;

int pieceType = rand() % 5; // type of piece, 0 = flower, 1 = feather, 2 = sands, 3 = goblet, 4 = circlet
int mainstatType = 0; // type of mainstat, 0-1 = flat, 2-4 = %, 5 = em, 6 = er, 7-14 = ele dmg%, 15-16 = crit, 17 = hb
int pieceLevel = 0;
int lines = 1; // current substat lines, 0 = 3 lines, 1 = 4 lines;
int r = -1;
vector<string>::iterator del;
vector<pair<string, double>> currentSubstats; // substat name, substat value

vector<string> artifactTypeName {"Flower of Life", "Plume of Death", "Sands of Eon", "Goblet of Eonothem", "Circlet of Logos"};
vector<string> mainstatTypeName {"HP", "ATK", "HP%", "ATK%", "DEF%", "Elemental Mastery", "Energy Recharge%",
								 "Anemo DMG Bonus%", "Geo DMG Bonus%", "Electro DMG Bonus%", "Dendro DMG Bonus%", "Hydro DMG Bonus%",
								 "Pyro DMG Bonus%", "Cryo DMG Bonus%", "Physical DMG Bonus%", "CRIT Rate%", "CRIT DMG%", "Healing Bonus%"};
vector<double> sandsMainstatWeight {0, 0, 0.2668, 0.2666, 0.2666, 0.1, 0.1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
vector<double> gobletMainstatWeight {0, 0, 0.1925, 0.1925, 0.19, 0.025, 0, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0, 0, 0};
vector<double> circletMainstatWeight {0, 0, 0.22, 0.22, 0.22, 0.04, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.1, 0.1, 0.1};

vector<double> substatRolls {298.75, 19.45, 23.15, 5.83, 5.83, 7.29, 23.31, 6.48, 3.89, 7.77};
vector<pair<string, int>> substatTypePairs {{"HP", 6},  // substat name, substat weight
											{"ATK", 6},
											{"DEF", 6},
											{"HP%", 4},
											{"ATK%", 4},
											{"DEF%", 4},
											{"Elemental Mastery", 4},
											{"Energy Recharge%", 4},
											{"CRIT Rate%", 3},
											{"CRIT DMG%", 3}};
											
unordered_map<string, double> substatValues = {{"HP", 298.75},  // substat name, substat value
											   {"ATK", 19.45},
											   {"DEF", 23.15},
											   {"HP%", 5.83},
											   {"ATK%", 5.83},
											   {"DEF%", 7.29},
											   {"Elemental Mastery", 23.31},
											   {"Energy Recharge%", 6.48},
											   {"CRIT Rate%", 3.89},
											   {"CRIT DMG%", 7.77}};

vector<string> availableSubstats;

vector<vector<double>> mainstatStats {{717, 1530, 2342, 3155, 3967, 4780},
									  {47, 100, 152, 205, 258, 311},
									  {7.0, 14.9, 22.8, 30.8, 38.7, 46.6},
									  {7.0, 14.9, 22.8, 30.8, 38.7, 46.6},
									  {8.7, 18.6, 28.6, 38.5, 48.4, 58.3},
									  {28.0, 60, 91, 123, 155, 187},
									  {7.8, 16.6, 25.4, 34.2, 43.0, 51.8},
									  {7.0, 14.9, 22.8, 30.8, 38.7, 46.6},
									  {7.0, 14.9, 22.8, 30.8, 38.7, 46.6},
									  {7.0, 14.9, 22.8, 30.8, 38.7, 46.6},
									  {7.0, 14.9, 22.8, 30.8, 38.7, 46.6},
									  {7.0, 14.9, 22.8, 30.8, 38.7, 46.6},
									  {7.0, 14.9, 22.8, 30.8, 38.7, 46.6},
									  {7.0, 14.9, 22.8, 30.8, 38.7, 46.6},
									  {8.7, 18.6, 28.6, 38.5, 48.4, 58.3},
									  {4.7, 9.9, 15.2, 20.5, 25.8, 31.1},
									  {9.3, 19.9, 30.5, 41.0, 51.6, 62.2},
									  {5.4, 11.5, 17.6, 23.7, 29.8, 35.9}};

int totalArtifact = 0;
int goodArti = 0;
bool goodFlag = false;

int randomizeMainstat(){
	// coding weights sucks
	
	vector<int> availableIndexes; // valid mainstats that can be used by this piece type
	vector<double> weightsToConsider; // weights of the valid mainstats above
	
	if(pieceType == 0) return 0;
	else if(pieceType == 1) return 1;
	else if(pieceType == 2){
		availableIndexes = {2, 3, 4, 5, 6};
	
		for(int i = 0; i < availableIndexes.size(); i++){
			int currIdx = availableIndexes[i];
			double currWeight = sandsMainstatWeight[currIdx] * 10000; // multiply by 10000 to avoid decimals
			
			if(i != 0) currWeight += weightsToConsider[i-1]; // prefix sum (how exciting)
			
			weightsToConsider.push_back(currWeight);
		}
	} else if(pieceType == 3){
		availableIndexes = {2, 3, 4, 5, 7, 8, 9, 10, 11, 12, 13, 14};
	
		for(int i = 0; i < availableIndexes.size(); i++){
			int currIdx = availableIndexes[i];
			double currWeight = gobletMainstatWeight[currIdx] * 10000; // multiply by 10000 to avoid decimals
			
			if(i != 0) currWeight += weightsToConsider[i-1]; // prefix sum (how exciting)
			
			weightsToConsider.push_back(currWeight);
		}
	} else if(pieceType == 4){
		availableIndexes = {2, 3, 4, 5, 15, 16, 17};
	
		for(int i = 0; i < availableIndexes.size(); i++){
			int currIdx = availableIndexes[i];
			double currWeight = circletMainstatWeight[currIdx] * 10000; // multiply by 10000 to avoid decimals
			
			if(i != 0) currWeight += weightsToConsider[i-1]; // prefix sum (how exciting)
			
			weightsToConsider.push_back(currWeight);
		}
	}
	
	int randNumber = rand() % 10000;
	
	// pick a mainstat after weighting
	for(int i = 0; i < weightsToConsider.size(); i++){
		if(i == 0){
			if(randNumber >= 0 && randNumber < weightsToConsider[i]) return availableIndexes[i];
		} else {
			if(randNumber >= weightsToConsider[i-1] && randNumber < weightsToConsider[i]) return availableIndexes[i];
		}
	}
	
	puts("didn't pick mainstat successfully uhhhh");
	return -1;
}

void randomizeSubstat(vector<string>& availableSubstats){
	vector<int> weights;
	
	// get the weights we need
	for(int i = 0; i < availableSubstats.size(); i++){
		for(int j = 0; j < substatTypePairs.size(); j++){
			if(availableSubstats[i] == substatTypePairs[j].first){
				weights.push_back(substatTypePairs[j].second);
				break;
			}
		}
	}
	
	// prefix sum (very exciting)
	for(int k = 1; k < weights.size(); k++){
		weights[k] += weights[k-1];
	}
	
	int totalWeight = weights[weights.size() - 1];
	int randNumber = rand() % totalWeight;
	
	int chooseIdx = -1;
	
	// pick a substat after weighting
	for(int i = 0; i < weights.size(); i++){
		if(i == 0){
			if(randNumber >= 0 && randNumber < weights[i]){
				chooseIdx = i;
				break;
			}
		} else {
			if(randNumber >= weights[i-1] && randNumber < weights[i]){
				chooseIdx = i;
				break;
			}
		}
	}
	
	string chosenSubstatName = availableSubstats[chooseIdx];
	
	int randMultiplier = rand() % 4 + 7;
	double startingValue = substatValues[chosenSubstatName] * randMultiplier / 10;
	
	currentSubstats.push_back({chosenSubstatName, startingValue});
	
	del = find(availableSubstats.begin(), availableSubstats.end(), chosenSubstatName);
	if(del != availableSubstats.end()) availableSubstats.erase(del);
}

void levelUpSubstat(int substatToLevel){
	int randMultiplier = rand() % 4 + 7;
	
	double addedStats = substatValues[currentSubstats[substatToLevel].first] * randMultiplier / 10;
	
	currentSubstats[substatToLevel].second += addedStats;
}

void displayArtifact(){
	cout << artifactTypeName[pieceType] << " Lv. " << pieceLevel * 4 << "\n"; // display piece name and level accordingly
	
	string mainName = mainstatTypeName[mainstatType];
	double mainValue = mainstatStats[mainstatType][pieceLevel];
	cout << mainName << " "; // display mainstat
	
	if(mainName != "HP" && mainName != "ATK" && mainName != "Elemental Mastery"){
		printf("%.1f%%\n", mainValue);
	} else {
		printf("%.0f\n", mainValue);
	}
	
	puts("");
	
	for(auto p : currentSubstats){
		cout << p.first << " ";
		
		if(p.first != "HP" && p.first != "ATK" && p.first != "DEF" && p.first != "Elemental Mastery"){
			printf("%.1f%%\n", p.second);
		} else {
			printf("%.0f\n", p.second);
		}
	}
	
	puts("");
}

void artifactCount(){
	cout << "Total Artifacts rolled: " << totalArtifact << "\n";
	cout << "Good Artifacts rolled: " << goodArti << "\n";
}

void start(vector<string>& availableSubstats){
	pieceType = rand() % 5;
	pieceLevel = 0;
	mainstatType = randomizeMainstat();
	
	del = find(availableSubstats.begin(), availableSubstats.end(), mainstatTypeName[mainstatType]);
	if(del != availableSubstats.end()) availableSubstats.erase(del);
	
	lines = rand() % 2;
	
	for(int i = 1; i <= lines + 3; i++){
		randomizeSubstat(availableSubstats);
	}
}

int main(){
	srand(time(NULL));
	
	reset:;
	goodFlag = false;
	currentSubstats.clear();
	availableSubstats.clear();
	
	for(auto& p : substatTypePairs){
		availableSubstats.push_back(p.first);
	}
	
	int optionChoice = 0;
	start(availableSubstats);
	while(true){
		artifactCount();
		
		puts("");
		
		displayArtifact();
		
		cout << "Reroll or Level:\n";
		cout << "1. Reroll\n";
		cout << "2. Level\n";
		cout << "3. Label as Good Artifact\n";
		
		cout << ">> ";
		cin >> optionChoice;
		
		switch(optionChoice){
			case 1:
				start(availableSubstats);
				
				system("cls");
				totalArtifact++;
				
				goto reset;
				
				break;
			case 2:
				// lv 20 check
				if(pieceLevel >= 5) break;
				
				pieceLevel++;
				
				// 3 starting lines check
				if(lines == 0){
					randomizeSubstat(availableSubstats);
					lines = 1;
					break;
				}
				
				r = rand() % 4;
				
				levelUpSubstat(r);
				
				break;
			case 3:
				if(!goodFlag){
					goodArti += 1;
					goodFlag = true;
				}
				
				break;
			default:
				break;
		}
		
		system("cls");
	}
	
	return 0;
}
