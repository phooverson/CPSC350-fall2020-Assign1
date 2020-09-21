#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Files{

public:
  Files();//default constructor
  ~Files();//destructor
  void calculateStatistics(string fileName);
  void outputStatisticsToFile(string fileName);
  void outputGaussianDistribution();
  void closeOpenFile();

private:
  void openOutputFile(string fileName);
  void calculateVariance(string fileName);
  ifstream openFiles(string fileName);
  void calculateSum();
  void calculateMean();
  void calculateStandardDeviation();
  void calculateProbabilityNucleotide(string fileName);
  void calculateProbabilityNucleotideBigram(string fileName);
  bool lineValid(string line);
  bool charValid(char ch);
  void sumNumberOfChar(char charInLine);
  void calculateWhichBigram(string line);
  void addBiagramCount(string currentBigram);
  void calculateBigramProbabilty();
  void roundD();
  void calculateValueOfD();
  string calculateString();
  void resetStats();

  bool fileExists;
  int sum;
  float DValue;
  float mean;
  float lineSize;
  float standardDeviation;
  int numberOfLines;
  float variance;
  string line;
  ifstream myFile;
  float probabilityOfA;
  int numberOfA;
  float probabilityOfC;
  int numberOfC;
  float probabilityOfT;
  int numberOfT;
  float probabilityOfG;
  int numberOfG;
  int numberOfBiagram;
  int numberOfFiles;
  ofstream outputFile;


  float probabilityOfAA;
  float probabilityOfAC;
  float probabilityOfAT;
  float probabilityOfAG;
  float probabilityOfCA;
  float probabilityOfCC;
  float probabilityOfCT;
  float probabilityOfCG;
  float probabilityOfTA;
  float probabilityOfTC;
  float probabilityOfTT;
  float probabilityOfTG;
  float probabilityOfGA;
  float probabilityOfGC;
  float probabilityOfGT;
  float probabilityOfGG;
  int numberOfAA;
  int numberOfAC;
  int numberOfAT;
  int numberOfAG;
  int numberOfCA;
  int numberOfCC;
  int numberOfCT;
  int numberOfCG;
  int numberOfTA;
  int numberOfTC;
  int numberOfTT;
  int numberOfTG;
  int numberOfGA;
  int numberOfGC;
  int numberOfGT;
  int numberOfGG;
};
