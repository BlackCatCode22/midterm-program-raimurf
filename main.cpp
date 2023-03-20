#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
using namespace std;

string genUniqueID(string species, int numOfSpecies) {

    string uniqueID;

    if (species == "hyena") {
        uniqueID = "Hy0" + to_string(numOfSpecies);
    }
    else if (species == "lion") {
        uniqueID = "Li0" + to_string(numOfSpecies);
    }
    else if (species == "tiger") {
        uniqueID = "Ti0" + to_string(numOfSpecies);
    }
    else if (species == "bear") {
        uniqueID = "Be0" + to_string(numOfSpecies);
    }
    else {
        uniqueID = "error";
    }

    return uniqueID;
}

string calcBirthdate(int years, string season) {
    int birthYear = 0;
    string birthDate;
    birthYear = 2023 - years;
    string monthDay;
    if (season == "spri") {
        monthDay = "Mar 21";
    }
    else if (season == "summ") {
        monthDay = "Jun 21";
    }
    else if (season == "fall") {
        monthDay = "Sep 21";
    }
    else if (season == "wint") {
        monthDay = "Dec 21";
    }
    else {
        monthDay = "Jan 1";
    }
    birthDate = monthDay + ", " + to_string(birthYear);
    return birthDate;
}


int main()
{
    cout << "initializing zoo program..."<< endl;

    int lineNum = 0;
    int position = 0;
    int startPos = 0;
    int endPos = 0;
    int numYears = 0;
    string birthSeason = "";
    string birthDay = "";
    string sex = "";
    string uniqueID = "";
    string species = "";
    string color = "";
    string outputLine = "";
    
    int numOfHyenas = 0;
    int numOfLions = 0;
    int numOfTigers = 0;
    int numOfBears = 0;
    
    cout <<"receiving animals..."<< endl;
    
    string line;
    ifstream myAnimalFile("arrivingAnimals.txt");
    
    if (myAnimalFile.is_open()) {
        while ( getline (myAnimalFile, line)) {
            cout << "\n File info: ";
            cout << line;
        }
        cout << "\n\n";
    }
    else {
        cout << "\n file is not open \n";
    }

    myAnimalFile.close();

    cout<<"Animals received..."<< endl;

    string hyenaNames[20];
    string lionNames[20];
    string tigerNames[20];
    string bearNames[20];
    
    string strHyenaNames = "";
    string strLionNames = "";
    string strTigerNames = "";
    string strBearNames = "";

    string name = "";
    string weight = "";
    string origin = "";
    string arrivalDate = "";


    ifstream myAnimalNames("animalNames.txt");
    
    if (myAnimalNames.is_open()) {
        lineNum = 0;
        while (getline(myAnimalNames, line)) {
            cout << "\n Animal Names retrieved: ";
            cout << line;
            if (lineNum == 2) {
                strHyenaNames = line;
            }
            else if (lineNum == 6) {
                strLionNames = line;
            }
            else if (lineNum == 10) {
                strBearNames = line;
            }
            else if (lineNum == 14) {
                strTigerNames = line;
            }
            lineNum++;
        }
        cout << "\n\n";
        cout << "hyena names: " << strHyenaNames << "\n";
        cout << "lion names: " << strLionNames << "\n";
        cout << "bear names: " << strBearNames << "\n";
        cout << "tiger names: " << strTigerNames << "\n";
    }
    else {
        cout << "\n file is not open \n";
    }

    myAnimalNames.close();

    cout<<"\n Organizing names..."<< endl;

    string animalName = "";
    int commaPos = 0;
    
    
    int indexOfAnimalName = 0;
    
    // Hyena names...
    indexOfAnimalName = 0;
    commaPos = 0;
    while (commaPos != string::npos) {
        commaPos = strHyenaNames.find(",");
        animalName = strHyenaNames.substr(0, commaPos);
        hyenaNames[indexOfAnimalName] = animalName;
        cout << "\n animalName = " << animalName;
       
        strHyenaNames = strHyenaNames.substr(commaPos + 2);
    
        indexOfAnimalName++;
    }
   
    for (int i = 0; i < 20; i++) {
        cout << "\n hyenaNames[" << i << "] is: " << hyenaNames[i];
    }
    
    // Lion names...
    indexOfAnimalName = 0;
    commaPos = 0;
    while (commaPos != string::npos) {
        commaPos = strLionNames.find(",");
        animalName = strLionNames.substr(0, commaPos);
        lionNames[indexOfAnimalName] = animalName;
        cout << "\n animalName = " << animalName;
      
        strLionNames = strLionNames.substr(commaPos + 2);
       
        indexOfAnimalName++;
    }
   
    for (int i = 0; i < 20; i++) {
        cout << "\n lionNames[" << i << "] is: " << lionNames[i];
    }

    // Bear names...
    indexOfAnimalName = 0;
    commaPos = 0;
    while (commaPos != string::npos) {
        commaPos = strBearNames.find(",");
        animalName = strBearNames.substr(0, commaPos);
        bearNames[indexOfAnimalName] = animalName;
        cout << "\n animalName = " << animalName;
      
        strBearNames = strBearNames.substr(commaPos + 2);
       
        indexOfAnimalName++;
    }
   
    for (int i = 0; i < 20; i++) {
        cout << "\n bearNames[" << i << "] is: " << bearNames[i];
    }

    // Tiger names...
    indexOfAnimalName = 0;
    commaPos = 0;
    while (commaPos != string::npos) {
        commaPos = strTigerNames.find(",");
        animalName = strTigerNames.substr(0, commaPos);
        tigerNames[indexOfAnimalName] = animalName;
        cout << "\n animalName = " << animalName;
       
        strTigerNames = strTigerNames.substr(commaPos + 2);
       
        indexOfAnimalName++;
    }
   
    for (int i = 0; i < 20; i++) {
        cout << "\n tigerNames[" << i << "] is: " << tigerNames[i];
    }
    
    cout <<"\n"<< endl;
    cout << "\n Names organized."<< endl;
    
    cout <<"\n arriving animals info extraction..."<< endl;
    
    string arrAnimals[16];
     
    myAnimalFile.open("arrivingAnimals.txt");

    lineNum = 0;
    if (myAnimalFile.is_open()) {
        while (getline(myAnimalFile, line)) {
            arrAnimals[lineNum] = line;
            lineNum++;
        }
        cout << "\n\n";
    }
    else {
        cout << "\n file is not open \n";
    }

    myAnimalFile.close();

    for (int lineNum = 0; lineNum < 16; lineNum++) {
        cout << arrAnimals[lineNum] << "\n";
    }
    
 
    for (int lineNum = 0; lineNum < 16; lineNum++) {

       numYears = stoi(arrAnimals[lineNum].substr(0, 2));
       cout << "\n numYears = " << numYears;

       position = arrAnimals[lineNum].find("born in");
       cout << "\n position = " << position;
       birthSeason = arrAnimals[lineNum].substr(position + 8, 4);
       cout << "\n birthSeason = " << birthSeason;

     
       cout << "\n Birth Date is... " << calcBirthdate(numYears, birthSeason);
       birthDay = calcBirthdate(numYears, birthSeason);
       cout << endl << endl;

       position = arrAnimals[lineNum].find(" ");
       position = arrAnimals[lineNum].find(" ", position + 1);
       position = arrAnimals[lineNum].find(" ", position + 1);
       startPos = position + 1;
       endPos = arrAnimals[lineNum].find(" ", startPos);
       sex = arrAnimals[lineNum].substr(startPos, endPos - startPos);
       cout << "\n sex is..." << sex;

       startPos = endPos + 1;
       endPos = arrAnimals[lineNum].find(",", startPos);
       species = arrAnimals[lineNum].substr(startPos, endPos - startPos);
       cout << "\n species is..." << species;


       if (species == "hyena") {
           numOfHyenas++;
           uniqueID = genUniqueID("hyena", numOfHyenas);
       }
       else if (species == "lion") {
           numOfLions++;
           uniqueID = genUniqueID("lion", numOfLions);
       }
       else if (species == "tiger") {
           numOfTigers++;
           uniqueID = genUniqueID("tiger", numOfTigers);
       }
       else if (species == "bear") {
           numOfBears++;
           uniqueID = genUniqueID("bear", numOfBears);
       }
       else {
           // error
           cerr<<"error"<<endl;
       }

       cout << "\n uniqueID is..." << uniqueID;

       if (species == "hyena") {
           name = hyenaNames[numOfHyenas - 1];
       }
       else if (species == "lion") {
           name = lionNames[numOfLions - 1];
       }
       else if (species == "tiger") {
           name = tigerNames[numOfTigers - 1];
       }
       else if (species == "bear") {
           name = bearNames[numOfBears - 1];
       }
       else {
           // error
           cerr<< "error"<< endl;
       }
       cout << "\n" << "name is: " << name;


       position = arrAnimals[lineNum].find(",");
       position = arrAnimals[lineNum].find(",", position + 1);
       startPos = position + 1;

       endPos = arrAnimals[lineNum].find(",", startPos);
       color = arrAnimals[lineNum].substr(startPos, endPos - startPos);
       cout << "\n color is..." << color;

       position = arrAnimals[lineNum].find(",");
       position = arrAnimals[lineNum].find(",", position + 1);
       position = arrAnimals[lineNum].find(",", position + 1);
       startPos = position + 1;
       
       endPos = arrAnimals[lineNum].find(",", startPos);
       weight = arrAnimals[lineNum].substr(startPos, endPos - startPos);
       cout << "\n weight is..." << weight;


       position = arrAnimals[lineNum].find(",");
       position = arrAnimals[lineNum].find(",", position + 1);
       position = arrAnimals[lineNum].find(",", position + 1);
       position = arrAnimals[lineNum].find(",", position + 1);
       startPos = position + 1;

       origin = arrAnimals[lineNum].substr(startPos);
       cout << "\n origin is..." << origin;
       cout << "\n\n";

       outputLine = uniqueID + "; " + name + "; " + to_string(numYears) + " years old;"
           + "birth date " + birthDay + "; " +
           color + "; " +
           sex + "; " +
           weight + "; " +
           origin + "; " +
           "arrived ";

       cout << "\n outputLine = " << outputLine << "\n\n";
   
    }
    
    



}

