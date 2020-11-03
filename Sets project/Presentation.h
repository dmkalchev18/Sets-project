#pragma once
#include <iostream>
#include <string>
#include<Windows.h>
#include <vector>

using namespace std;



void displayBorder();
void greetings();
void goodbyeMessage();

void horizontalBorder(int n);
void printUpperSide(int n, bool isEnd , char indicator);
void printStars(int n);
void printSpace(int n);
void displayDownSide(int n, bool isEnd , char indicator );
void printSideForDifference(int n);
void printSideForSubset(int n);
void displaySide(int n, char indicator);
void printUpperSideToSideDifference(int n);
void printDownSideToSideDifference(int n);
void printMiddleSideToSideDifference(char indicator );
void printMiddleSideToSideSubset(char indicator);
void showSideToSide(int n, char indicator);
void displayDifferenceFigure();
void displaySubsetFigure();
void displaySectionFigure();
void displayUnionFigure();
void displaySimetricDifferenceFigure();
bool areTheVectorsFull();

void showSetsOfNumbers();
void showTheSubsets();
void showTheUnion();
void showTheSections();
void showTheDifference();
void showTheSimetricDifference();
void showTheSubsets();
void setInputInt();
bool isShowingSetsFromNumbersMenu();
void setInputString();
void showSetsOfWords();
void showTheSubsetsFromWords();
void showTheUnionFromWords();
void showTheSectionsFromWords();
void showTheDifferenceFromWords();
void showTheSimetricDifferenceFromWords();
bool isShowingSetsFromWordsMenu();

bool isDisplayingMenu();
void showFileContent(string fileName);
