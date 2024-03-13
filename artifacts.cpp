#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int pieceType = rand() % 5;
int pieceLevel = 0;
int typeOfMainstat;
double mainstat;
int numOfSubs = 0;
int substatType[5];
char substatName[5][20];
double substats[5];
int substatToLevel;
bool hasFlatHP = false; // 1
bool hasFlatAtk = false; // 2
bool hasFlatDef = false; // 3
bool hasHPPerc = false; // 4
bool hasAtkPerc = false; // 5
bool hasDefPerc = false; // 6
bool hasEleMastery = false; // 7
bool hasEnergyRecharge = false; // 8
bool hasCritRate = false; // 9
bool hasCritDmg = false; // 10
bool hasEleDmg = false; // 11
bool hasPhysDmg = false; // 12
bool hasHealingBonus = false; // 13

/*
Elemental DMG Goblet List
	Pyro 14
	Electro 15
	Cryo 16
	Hydro 17
	Dendro 18
	Anemo 19
	Geo 20
*/



void levelFlower(){
	if(pieceLevel == 0){
		mainstat = 1530;
		pieceLevel = 4;
	} else if(pieceLevel == 4){
		mainstat = 2342;
		pieceLevel = 8;
	} else if(pieceLevel == 8){
		mainstat = 3155;
		pieceLevel = 12;
	} else if(pieceLevel == 12){
		mainstat = 3967;
		pieceLevel = 16;
	} else {
		mainstat = 4780;
		pieceLevel = 20;
	}	
}

void levelFeather(){
	if(pieceLevel == 0){
		mainstat = 100;
		pieceLevel = 4;
	} else if(pieceLevel == 4){
		mainstat = 152;
		pieceLevel = 8;
	} else if(pieceLevel == 8){
		mainstat = 205;
		pieceLevel = 12;
	} else if(pieceLevel == 12){
		mainstat = 258;
		pieceLevel = 16;
	} else {
		mainstat = 311;
		pieceLevel = 20;
	}	
}

void level70Scaler(){
	if(pieceLevel == 0){
		mainstat = 14.9;
		pieceLevel = 4;
	} else if(pieceLevel == 4){
		mainstat = 22.8;
		pieceLevel = 8;
	} else if(pieceLevel == 8){
		mainstat = 30.8;
		pieceLevel = 12;
	} else if(pieceLevel == 12){
		mainstat = 38.7;
		pieceLevel = 16;
	} else {
		mainstat = 46.6;
		pieceLevel = 20;
	}	
}

void level87Scaler(){
	if(pieceLevel == 0){
		mainstat = 18.6;
		pieceLevel = 4;
	} else if(pieceLevel == 4){
		mainstat = 28.6;
		pieceLevel = 8;
	} else if(pieceLevel == 8){
		mainstat = 38.5;
		pieceLevel = 12;
	} else if(pieceLevel == 12){
		mainstat = 48.4;
		pieceLevel = 16;
	} else {
		mainstat = 58.3;
		pieceLevel = 20;
	}	
}

void levelEM(){
	if(pieceLevel == 0){
		mainstat = 59.7;
		pieceLevel = 4;
	} else if(pieceLevel == 4){
		mainstat = 91.4;
		pieceLevel = 8;
	} else if(pieceLevel == 8){
		mainstat = 123.1;
		pieceLevel = 12;
	} else if(pieceLevel == 12){
		mainstat = 154.8;
		pieceLevel = 16;
	} else {
		mainstat = 186.5;
		pieceLevel = 20;
	}	
}

void levelER(){
	if(pieceLevel == 0){
		mainstat = 16.6;
		pieceLevel = 4;
	} else if(pieceLevel == 4){
		mainstat = 25.4;
		pieceLevel = 8;
	} else if(pieceLevel == 8){
		mainstat = 34.2;
		pieceLevel = 12;
	} else if(pieceLevel == 12){
		mainstat = 43.0;
		pieceLevel = 16;
	} else {
		mainstat = 51.8;
		pieceLevel = 20;
	}	
}

void levelCR(){
	if(pieceLevel == 0){
		mainstat = 9.9;
		pieceLevel = 4;
	} else if(pieceLevel == 4){
		mainstat = 15.2;
		pieceLevel = 8;
	} else if(pieceLevel == 8){
		mainstat = 20.5;
		pieceLevel = 12;
	} else if(pieceLevel == 12){
		mainstat = 25.8;
		pieceLevel = 16;
	} else {
		mainstat = 31.1;
		pieceLevel = 20;
	}	
}

void levelCD(){
	if(pieceLevel == 0){
		mainstat = 19.9;
		pieceLevel = 4;
	} else if(pieceLevel == 4){
		mainstat = 30.5;
		pieceLevel = 8;
	} else if(pieceLevel == 8){
		mainstat = 41.0;
		pieceLevel = 12;
	} else if(pieceLevel == 12){
		mainstat = 51.6;
		pieceLevel = 16;
	} else {
		mainstat = 62.2;
		pieceLevel = 20;
	}	
}

void levelHB(){
	if(pieceLevel == 0){
		mainstat = 11.5;
		pieceLevel = 4;
	} else if(pieceLevel == 4){
		mainstat = 17.6;
		pieceLevel = 8;
	} else if(pieceLevel == 8){
		mainstat = 23.7;
		pieceLevel = 12;
	} else if(pieceLevel == 12){
		mainstat = 29.8;
		pieceLevel = 16;
	} else {
		mainstat = 35.9;
		pieceLevel = 20;
	}	
}

void menu(){
    printf("Choose your artifact set:\n");
    printf("1. Emblem of Severed Fate\n");
    printf(">> ");
}

void addFlatHP(){
    substats[numOfSubs] += (double)((rand() % 4) + 7) / 10 * 298.75;
    substatType[numOfSubs] = 1;
    strcpy(substatName[numOfSubs], "HP");
}

void addFlatAtk(){
    substats[numOfSubs] += (double)((rand() % 4) + 7) / 10 * 19.45;
    substatType[numOfSubs] = 2;
    strcpy(substatName[numOfSubs], "ATK");
}

void addFlatDef(){
    substats[numOfSubs] += (double)((rand() % 4) + 7) / 10 * 23.15;
    substatType[numOfSubs] = 3;
    strcpy(substatName[numOfSubs], "DEF");
}

void addHPPerc(){
    substats[numOfSubs] += (double)((rand() % 4) + 7) / 10 * 5.83;
    substatType[numOfSubs] = 4;
    strcpy(substatName[numOfSubs], "HP%");
}

void addAtkPerc(){
    substats[numOfSubs] += (double)((rand() % 4) + 7) / 10 * 5.83;
    substatType[numOfSubs] = 5;
    strcpy(substatName[numOfSubs], "ATK%");
}

void addDefPerc(){
    substats[numOfSubs] += (double)((rand() % 4) + 7) / 10 * 7.29;
    substatType[numOfSubs] = 6;
    strcpy(substatName[numOfSubs], "DEF%");
}

void addEleMastery(){
    substats[numOfSubs] += (double)((rand() % 4) + 7) / 10 * 23.31;
    substatType[numOfSubs] = 7;
    strcpy(substatName[numOfSubs], "Elemental Mastery");
}

void addEnergyRecharge(){
    substats[numOfSubs] += (double)((rand() % 4) + 7) / 10 * 6.48;
    substatType[numOfSubs] = 8;
    strcpy(substatName[numOfSubs], "Energy Recharge%");
}

void addCritRate(){
    substats[numOfSubs] += (double)((rand() % 4) + 7) / 10 * 3.89;
    substatType[numOfSubs] = 9;
    strcpy(substatName[numOfSubs], "CRIT Rate%");
}

void addCritDmg(){
    substats[numOfSubs] += (double)((rand() % 4) + 7) / 10 * 7.77;
    substatType[numOfSubs] = 10;
    strcpy(substatName[numOfSubs], "CRIT DMG%");
}

void randomizeSubs(){
    int totalWeight = 6 + 6 + 6 + 4 + 4 + 4 + 4 + 4 + 3 + 3;
    int distributionFlower;
    
    while(true){
        distributionFlower = rand() % totalWeight;
        
        if((distributionFlower >= 0 && distributionFlower < 6) && hasFlatHP == false){
            addFlatHP();
            hasFlatHP = true;
            printf("HP %.0f\n", substats[numOfSubs]);
            break;
        } else if((distributionFlower >= 6 && distributionFlower < 12) && hasFlatAtk == false){
            addFlatAtk();
            hasFlatAtk = true;
            printf("ATK %.0f\n", substats[numOfSubs]);
            break;
        } else if((distributionFlower >= 12 && distributionFlower < 18) && hasFlatDef == false){
            addFlatDef();
            hasFlatDef = true;
            printf("DEF %.0f\n", substats[numOfSubs]);
            break;
        } else if((distributionFlower >= 18 && distributionFlower < 22) && hasHPPerc == false){
            addHPPerc();
            hasHPPerc = true;
            printf("HP%% %.1f%%\n", substats[numOfSubs]);
            break;
        } else if((distributionFlower >= 22 && distributionFlower < 26) && hasAtkPerc == false){
            addAtkPerc();
            hasAtkPerc = true;
            printf("ATK%% %.1f%%\n", substats[numOfSubs]);
            break;
        } else if((distributionFlower >= 26 && distributionFlower < 30) && hasDefPerc == false){
            addDefPerc();
            hasDefPerc = true;
            printf("DEF%% %.1f%%\n", substats[numOfSubs]);
            break;
        } else if((distributionFlower >= 30 && distributionFlower < 34) && hasEleMastery == false){
            addEleMastery();
            hasEleMastery = true;
            printf("Elemental Mastery %.0f\n", substats[numOfSubs]);
            break;
        } else if((distributionFlower >= 34 && distributionFlower < 38) && hasEnergyRecharge == false){
            addEnergyRecharge();
            hasEnergyRecharge = true;
            printf("Energy Recharge%% %.1f%%\n", substats[numOfSubs]);
            break;
        } else if((distributionFlower >= 38 && distributionFlower < 41) && hasCritRate == false){
            addCritRate();
            hasCritRate = true;
            printf("CRIT Rate%% %.1f%%\n", substats[numOfSubs]);
            break;
        } else if(distributionFlower >= 41 && distributionFlower < 44 && hasCritDmg == false){
            addCritDmg();
            hasCritDmg = true;
            printf("CRIT DMG%% %.1f%%\n", substats[numOfSubs]);
            break;
        }       
    }
}

void startingSubs(){
    int threeLineStart = rand() % 2;
    
    if(threeLineStart == 0){
        for(int i = 1; i <= 3; i++){
            randomizeSubs();
            numOfSubs += 1;
        }
    } else {
        for(int i = 1; i <= 4; i++){
            randomizeSubs();
            numOfSubs += 1;
        }
    }
}

void randomizeSands(){
	int sandsMainstat = rand() % 30;
	
	if(sandsMainstat < 8){
		mainstat = 7.0;
		hasHPPerc = true;
		typeOfMainstat = 4;
		printf("HP%% %.1f%%\n\n", mainstat);
	} else if(sandsMainstat < 16){
		mainstat = 7.0;
		hasAtkPerc = true;
		typeOfMainstat = 5;
		printf("ATK%% %.1f%%\n\n", mainstat);
	} else if(sandsMainstat < 24){
		mainstat = 8.7;
		hasDefPerc = true;
		typeOfMainstat = 6;
		printf("DEF%% %.1f%%\n\n", mainstat);
	} else if(sandsMainstat < 27){
		mainstat = 28;
		hasEleMastery = true;
		typeOfMainstat = 7;
		printf("Elemental Mastery %.0f\n\n", mainstat);
	} else {
		mainstat = 7.8;
		hasEnergyRecharge = true;
		typeOfMainstat = 8;
		printf("Energy Recharge%% %.1f%%\n\n", mainstat);
	}
}

void randomizeGoblet(){
	int gobMainstat = rand() % 400;
	
	if(gobMainstat < 77){
		mainstat = 7.0;
		hasHPPerc = true;
		typeOfMainstat = 4;
		printf("HP%% %.1f%%\n\n", mainstat);
	} else if(gobMainstat < 154){
		mainstat = 7.0;
		hasAtkPerc = true;
		typeOfMainstat = 5;
		printf("ATK%% %.1f%%\n\n", mainstat);
	} else if(gobMainstat < 230){
		mainstat = 8.7;
		hasDefPerc = true;
		typeOfMainstat = 6;
		printf("DEF%% %.1f%%\n\n", mainstat);
	} else if(gobMainstat < 250){
		mainstat = 7.0;
		hasEleDmg = true;
		typeOfMainstat = 14;
		printf("Pyro DMG Bonus%% %.1f%%\n\n", mainstat);
	} else if(gobMainstat < 270){
		mainstat = 7.0;
		hasEleDmg = true;
		typeOfMainstat = 15;
		printf("Electro DMG Bonus%% %.1f%%\n\n", mainstat);
	} else if(gobMainstat < 290){
		mainstat = 7.0;
		hasEleDmg = true;
		typeOfMainstat = 16;
		printf("Cryo DMG Bonus%% %.1f%%\n\n", mainstat);
	} else if(gobMainstat < 310){
		mainstat = 7.0;
		hasEleDmg = true;
		typeOfMainstat = 17;
		printf("Hydro DMG Bonus%% %.1f%%\n\n", mainstat);
	} else if(gobMainstat < 330){
		mainstat = 7.0;
		hasEleDmg = true;
		typeOfMainstat = 18;
		printf("Dendro DMG Bonus%% %.1f%%\n\n", mainstat);
	} else if(gobMainstat < 350){
		mainstat = 7.0;
		hasEleDmg = true;
		typeOfMainstat = 19;
		printf("Anemo DMG Bonus%% %.1f%%\n\n", mainstat);
	} else if(gobMainstat < 370){
		mainstat = 7.0;
		hasEleDmg = true;
		typeOfMainstat = 20;
		printf("Geo DMG Bonus%% %.1f%%\n\n", mainstat);
	} else if(gobMainstat < 390){
		mainstat = 8.7;
		hasEleDmg = true;
		typeOfMainstat = 12;
		printf("Physical DMG Bonus%% %.1f%%\n\n", mainstat);
	} else {
		mainstat = 28;
		hasEleMastery = true;
		typeOfMainstat = 7;
		printf("Elemental Mastery %.0f\n\n", mainstat);
	}
}

void randomizeCirclet(){
	int hatMainstat = rand() % 50;
	
	if(hatMainstat < 11){
		mainstat = 7.0;
		hasHPPerc = true;
		typeOfMainstat = 4;
		printf("HP%% %.1f%%\n\n", mainstat);
	} else if(hatMainstat < 22){
		mainstat = 7.0;
		hasAtkPerc = true;
		typeOfMainstat = 5;
		printf("ATK%% %.1f%%\n\n", mainstat);
	} else if(hatMainstat < 33){
		mainstat = 8.7;
		hasDefPerc = true;
		typeOfMainstat = 6;
		printf("DEF%% %.1f%%\n\n", mainstat);
	} else if(hatMainstat < 38){
		mainstat = 4.7;
		hasCritRate = true;
		typeOfMainstat = 9;
		printf("CRIT Rate%% %.1f%%\n\n", mainstat);
	} else if(hatMainstat < 43){
		mainstat = 9.3;
		hasCritDmg = true;
		typeOfMainstat = 10;
		printf("CRIT DMG%% %.1f%%\n\n", mainstat);
	} else if(hatMainstat < 48){
		mainstat = 5.4;
		hasHealingBonus = true;
		typeOfMainstat = 13;
		printf("Healing Bonus%% %.1f%%\n\n", mainstat);
	} else {
		mainstat = 28;
		hasEleMastery = true;
		typeOfMainstat = 7;
		printf("Elemental Mastery %.0f\n\n", mainstat);
	}
}

void randomizePiece(){
	switch (pieceType){
		case 0: // flower
			printf("Flower of Life Lv. %d\n", pieceLevel);
			mainstat = 717;
			hasFlatHP = true;
			typeOfMainstat = 1;
			printf("HP %.0f\n\n", mainstat);
		
			startingSubs();
			
			break;
			
		case 1: // feather
			printf("Plume of Death Lv. %d\n", pieceLevel);
			mainstat = 47;
			hasFlatAtk = true;
			typeOfMainstat = 2;
			printf("ATK %.0f\n\n", mainstat);
		
			startingSubs();
			
			break;	
		
		case 2: // sands
			printf("Sands of Eon Lv. %d\n", pieceLevel);
			randomizeSands();
			
			startingSubs();
			
			break;	
		
		case 3:
			printf("Goblet of Eonothem Lv. %d\n", pieceLevel);
			randomizeGoblet();
			
			startingSubs();
			
			break;	
		
		case 4:
			printf("Circlet of Logos Lv. %d\n", pieceLevel);
			randomizeCirclet();
			
			startingSubs();
			
			break;	
		
		default:
			printf("Error\n");
			break;
	}
}

void levelSubstat(){
	if(numOfSubs < 4){
		randomizeSubs();
		numOfSubs += 1;
		return;
	}
	
	substatToLevel = rand() % 4;
	
	if(substatType[substatToLevel] == 1) substats[substatToLevel] += (double)((rand() % 4) + 7) / 10 * 298.75;
	else if(substatType[substatToLevel] == 2) substats[substatToLevel] += (double)((rand() % 4) + 7) / 10 * 19.45;
	else if(substatType[substatToLevel] == 3) substats[substatToLevel] += (double)((rand() % 4) + 7) / 10 * 23.15;
	else if(substatType[substatToLevel] == 4) substats[substatToLevel] += (double)((rand() % 4) + 7) / 10 * 5.83;
	else if(substatType[substatToLevel] == 5) substats[substatToLevel] += (double)((rand() % 4) + 7) / 10 * 5.83;
	else if(substatType[substatToLevel] == 6) substats[substatToLevel] += (double)((rand() % 4) + 7) / 10 * 7.29;
	else if(substatType[substatToLevel] == 7) substats[substatToLevel] += (double)((rand() % 4) + 7) / 10 * 23.31;
	else if(substatType[substatToLevel] == 8) substats[substatToLevel] += (double)((rand() % 4) + 7) / 10 * 6.48;
	else if(substatType[substatToLevel] == 9) substats[substatToLevel] += (double)((rand() % 4) + 7) / 10 * 3.89;
	else if(substatType[substatToLevel] == 10) substats[substatToLevel] += (double)((rand() % 4) + 7) / 10 * 7.77;
}

void displayArtifact(){
	switch (pieceType){
		case 0: // flower
			printf("Flower of Life Lv. %d\n", pieceLevel);
			printf("HP %.0f\n\n", mainstat);
			
			for(int i = 0; i < 3; i++){
				if(substatType[i] == 1 || substatType[i] == 2 || substatType[i] == 3 || substatType[i] == 7) printf("%s %.0f\n", substatName[i], substats[i]);
				else printf("%s %.1f%%\n", substatName[i], substats[i]);
			}
			
			if(numOfSubs == 3) break;
			
			if(substatType[3] == 1 || substatType[3] == 2 || substatType[3] == 3 || substatType[3] == 7) printf("%s %.0f\n", substatName[3], substats[3]);
			else printf("%s %.1f%%\n", substatName[3], substats[3]);
			
			break;
			
		case 1: // feather
			printf("Plume of Death Lv. %d\n", pieceLevel);
			printf("ATK %.0f\n\n", mainstat);
			
			for(int i = 0; i < 3; i++){
				if(substatType[i] == 1 || substatType[i] == 2 || substatType[i] == 3 || substatType[i] == 7) printf("%s %.0f\n", substatName[i], substats[i]);
				else printf("%s %.1f%%\n", substatName[i], substats[i]);
			}
			
			if(numOfSubs == 3) break;
			
			if(substatType[3] == 1 || substatType[3] == 2 || substatType[3] == 3 || substatType[3] == 7) printf("%s %.0f\n", substatName[3], substats[3]);
			else printf("%s %.1f%%\n", substatName[3], substats[3]);
			
			break;	
		
		case 2: // sands
			printf("Sands of Eon Lv. %d\n", pieceLevel);
			
			if(typeOfMainstat == 4) printf("HP%% %.1f%%\n\n", mainstat);
			else if(typeOfMainstat == 5) printf("ATK%% %.1f%%\n\n", mainstat);
			else if(typeOfMainstat == 6) printf("DEF%% %.1f%%\n\n", mainstat);
			else if(typeOfMainstat == 7) printf("Elemental Mastery %.0f\n\n", mainstat);
			else if(typeOfMainstat == 8) printf("Energy Recharge%% %.1f%%\n\n", mainstat);
			
			for(int i = 0; i < 3; i++){
				if(substatType[i] == 1 || substatType[i] == 2 || substatType[i] == 3 || substatType[i] == 7) printf("%s %.0f\n", substatName[i], substats[i]);
				else printf("%s %.1f%%\n", substatName[i], substats[i]);
			}
			
			if(numOfSubs == 3) break;
			
			if(substatType[3] == 1 || substatType[3] == 2 || substatType[3] == 3 || substatType[3] == 7) printf("%s %.0f\n", substatName[3], substats[3]);
			else printf("%s %.1f%%\n", substatName[3], substats[3]);
			
			break;	
		
		case 3:
			printf("Goblet of Eonothem Lv. %d\n", pieceLevel);
			
			if(typeOfMainstat == 4) printf("HP%% %.1f%%\n\n", mainstat);
			else if(typeOfMainstat == 5) printf("ATK%% %.1f%%\n\n", mainstat);
			else if(typeOfMainstat == 6) printf("DEF%% %.1f%%\n\n", mainstat);
			else if(typeOfMainstat == 7) printf("Elemental Mastery %.0f\n\n", mainstat);
			else if(typeOfMainstat == 12) printf("Physical DMG Bonus%% %.1f%%\n\n", mainstat);
			else if(typeOfMainstat == 14) printf("Pyro DMG Bonus%% %.1f%%\n\n", mainstat);
			else if(typeOfMainstat == 15) printf("Electro DMG Bonus%% %.1f%%\n\n", mainstat);
			else if(typeOfMainstat == 16) printf("Cryo DMG Bonus%% %.1f%%\n\n", mainstat);
			else if(typeOfMainstat == 17) printf("Hydro DMG Bonus%% %.1f%%\n\n", mainstat);
			else if(typeOfMainstat == 18) printf("Dendro DMG Bonus%% %.1f%%\n\n", mainstat);
			else if(typeOfMainstat == 19) printf("Anemo DMG Bonus%% %.1f%%\n\n", mainstat);
			else if(typeOfMainstat == 20) printf("Geo DMG Bonus%% %.1f%%\n\n", mainstat);
			
			for(int i = 0; i < 3; i++){
				if(substatType[i] == 1 || substatType[i] == 2 || substatType[i] == 3 || substatType[i] == 7) printf("%s %.0f\n", substatName[i], substats[i]);
				else printf("%s %.1f%%\n", substatName[i], substats[i]);
			}
			
			if(numOfSubs == 3) break;
			
			if(substatType[3] == 1 || substatType[3] == 2 || substatType[3] == 3 || substatType[3] == 7) printf("%s %.0f\n", substatName[3], substats[3]);
			else printf("%s %.1f%%\n", substatName[3], substats[3]);
			
			break;	
		
		case 4:
			printf("Circlet of Logos Lv. %d\n", pieceLevel);
			
			if(typeOfMainstat == 4) printf("HP%% %.1f%%\n\n", mainstat);
			else if(typeOfMainstat == 5) printf("ATK%% %.1f%%\n\n", mainstat);
			else if(typeOfMainstat == 6) printf("DEF%% %.1f%%\n\n", mainstat);
			else if(typeOfMainstat == 7) printf("Elemental Mastery %.0f\n\n", mainstat);
			else if(typeOfMainstat == 9) printf("CRIT Rate%% %.1f%%\n\n", mainstat);
			else if(typeOfMainstat == 10) printf("CRIT DMG%% %.1f%%\n\n", mainstat);
			else if(typeOfMainstat == 13) printf("Healing Bonus%% %.1f%%\n\n", mainstat);
			
			for(int i = 0; i < 3; i++){
				if(substatType[i] == 1 || substatType[i] == 2 || substatType[i] == 3 || substatType[i] == 7) printf("%s %.0f\n", substatName[i], substats[i]);
				else printf("%s %.1f%%\n", substatName[i], substats[i]);
			}
			
			if(numOfSubs == 3) break;
			
			if(substatType[3] == 1 || substatType[3] == 2 || substatType[3] == 3 || substatType[3] == 7) printf("%s %.0f\n", substatName[3], substats[3]);
			else printf("%s %.1f%%\n", substatName[3], substats[3]);
			
			break;	
		
		default:
			printf("Error\n");
			break;
	}
}

int totalArtifact = 0;
int goodArti = 0;
bool goodFlag = false;
void artifactCount(){
	printf("Total Artifacts rolled: %d\n", totalArtifact);
	printf("Good Artifacts rolled: %d\n\n", goodArti);
}

int main(){
    srand(time(NULL));
//    int artiChoice;
    int levelChoice;
    
    artifactCount();
    
//    menu();
    
//    scanf("%d", &artiChoice);
//    getchar();
//    
//    switch (artiChoice){
//        case 1:
//            break;
//            
//        default:
//            break;
//        
//    }
	
	reset:;
	
	randomizePiece();
    goodFlag = false;
    
    while(true){
    	puts("");
    	
	    printf("Reroll or Level:\n");
	    printf("1. Reroll\n");
	    if(pieceLevel != 20) printf("2. Level\n");
	    if(!goodFlag) printf("3. Label As Good Artifact\n");
	    printf(">> ");
	    scanf("%d", &levelChoice);
	    getchar();
	    
	    switch(levelChoice){
	    	case 1:
				pieceType = rand() % 5;
				pieceLevel = 0;
				typeOfMainstat = 1;
				mainstat = 0;
				numOfSubs = 0;
				for(int i = 0; i < 5; i++){
					substatType[i] = 0;
					strcpy(substatName[i], "");
					substats[i] = 0;
				}
				hasFlatHP = false; // 1
				hasFlatAtk = false; // 2
				hasFlatDef = false; // 3
				hasHPPerc = false; // 4
				hasAtkPerc = false; // 5
				hasDefPerc = false; // 6
				hasEleMastery = false; // 7
				hasEnergyRecharge = false; // 8
				hasCritRate = false; // 9
				hasCritDmg = false; // 10
				hasEleDmg = false; // 11
				hasPhysDmg = false; // 12
				hasHealingBonus = false; // 13
				
	    		system("cls");
	    		
	    		totalArtifact += 1;
	    		artifactCount();
	    		
				goto reset;
				
	    		break;
	    		
	    	case 2:
	    		if(pieceLevel != 20){
		    		if(typeOfMainstat == 1) levelFlower();
		    		else if(typeOfMainstat == 2) levelFeather();
		    		else if(typeOfMainstat == 4 || typeOfMainstat == 5 || typeOfMainstat == 11 || (typeOfMainstat >= 14 && typeOfMainstat <= 20)) level70Scaler();
		    		else if(typeOfMainstat == 6 || typeOfMainstat == 12) level87Scaler();
		    		else if(typeOfMainstat == 7) levelEM();
		    		else if(typeOfMainstat == 8) levelER();
		    		else if(typeOfMainstat == 9) levelCR();
		    		else if(typeOfMainstat == 10) levelCD();
		    		else if(typeOfMainstat == 13) levelHB();
		    		
		    		levelSubstat();
				}
	    		
	    		system("cls");
	    		
	    		artifactCount();
	    		
	    		displayArtifact();
	    		break;
	    	
			case 3:
				if(!goodFlag){
					goodArti += 1;
					goodFlag = true;
				}
				
				system("cls");
	    		
	    		artifactCount();
	    		
	    		displayArtifact();
	    		
				break;
	    	
	    	default:
				system("cls");
	    		
	    		artifactCount();
	    		
	    		displayArtifact();
	    		break;
		}
	}
    
    return 0;
}
