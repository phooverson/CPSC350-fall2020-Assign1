#include "assign1.h"


Files::Files(){
  line="";
  sum = 0;
  mean = 0.0;
  variance = 0.0;
  numberOfLines = 0;
  lineSize = 0.0;
  standardDeviation = 0.0;
  numberOfBiagram = 0;
  probabilityOfA = 0.0;
  numberOfA = 0;
  probabilityOfC = 0.0;
  numberOfC = 0;
  probabilityOfT = 0.0;
  numberOfT = 0;
  probabilityOfG = 0.0;
  numberOfG = 0;
  probabilityOfAA = 0.0;
  probabilityOfAC = 0.0;
  probabilityOfAT = 0.0;
  probabilityOfAG = 0.0;
  probabilityOfCA = 0.0;
  probabilityOfCC = 0.0;
  probabilityOfCT = 0.0;
  probabilityOfCG = 0.0;
  probabilityOfTA = 0.0;
  probabilityOfTC = 0.0;
  probabilityOfTT = 0.0;
  probabilityOfTG = 0.0;
  probabilityOfGA = 0.0;
  probabilityOfGC = 0.0;
  probabilityOfGT = 0.0;
  probabilityOfGG = 0.0;
  numberOfAA = 0;
  numberOfAC = 0;
  numberOfAT = 0;
  numberOfAG = 0;
  numberOfCA = 0;
  numberOfCC = 0;
  numberOfCT = 0;
  numberOfCG = 0;
  numberOfTA = 0;
  numberOfTC = 0;
  numberOfTT = 0;
  numberOfTG = 0;
  numberOfGA = 0;
  numberOfGC = 0;
  numberOfGT = 0;
  numberOfGG = 0;
  numberOfFiles = 1;
  DValue = 0;
  srand(time(NULL)); //enables the ability of the rand() fuction to work
  fileExists = true;
}

Files::~Files(){
  //cout << "Bye Bye files" << endl;
}

// open users file
ifstream Files::openFiles(string fileName){
  ifstream myFile (fileName);
  return myFile;
}

// Calculate stats on file
void Files::calculateStatistics(string fileName){
  myFile = openFiles(fileName);
    if (myFile.is_open()){
      fileExists = true;
      while(getline(myFile,line)){
        if(lineValid(line)){
          numberOfLines += 1;
          calculateSum();
        }
      }
      myFile.close();
      calculateMean();
      calculateVariance(fileName);
      calculateStandardDeviation();
      calculateProbabilityNucleotide(fileName);
      calculateProbabilityNucleotideBigram(fileName);
    }
    else{
      fileExists = false;
      cout << "ERROR: File could not be found, or opened. Please try agian." << endl;
    }
}

//resets the stats to be 0, neccesary for when the users wants to calculate multiple files
void Files::resetStats(){
  line="";
  sum = 0;
  mean = 0.0;
  variance = 0.0;
  numberOfLines = 0;
  lineSize = 0.0;
  standardDeviation = 0.0;
  numberOfBiagram = 0;
  probabilityOfA = 0.0;
  numberOfA = 0;
  probabilityOfC = 0.0;
  numberOfC = 0;
  probabilityOfT = 0.0;
  numberOfT = 0;
  probabilityOfG = 0.0;
  numberOfG = 0;
  probabilityOfAA = 0.0;
  probabilityOfAC = 0.0;
  probabilityOfAT = 0.0;
  probabilityOfAG = 0.0;
  probabilityOfCA = 0.0;
  probabilityOfCC = 0.0;
  probabilityOfCT = 0.0;
  probabilityOfCG = 0.0;
  probabilityOfTA = 0.0;
  probabilityOfTC = 0.0;
  probabilityOfTT = 0.0;
  probabilityOfTG = 0.0;
  probabilityOfGA = 0.0;
  probabilityOfGC = 0.0;
  probabilityOfGT = 0.0;
  probabilityOfGG = 0.0;
  numberOfAA = 0;
  numberOfAC = 0;
  numberOfAT = 0;
  numberOfAG = 0;
  numberOfCA = 0;
  numberOfCC = 0;
  numberOfCT = 0;
  numberOfCG = 0;
  numberOfTA = 0;
  numberOfTC = 0;
  numberOfTT = 0;
  numberOfTG = 0;
  numberOfGA = 0;
  numberOfGC = 0;
  numberOfGT = 0;
  numberOfGG = 0;
}

//opens the output file
void Files::openOutputFile(string fileName){
  outputFile.open(fileName);
}

//Output the calculated stats to an output file
void Files::outputStatisticsToFile(string fileName){
  if (fileExists){
    if(numberOfFiles==1){ //Print this out to the output file if its the first file
      openOutputFile(fileName);
      outputFile << "Name: Patrick Hooverson" << endl;
      outputFile << "Student ID: 2346635" << endl;
      outputFile << "CPSC-350-02" << endl;
      outputFile << "Rene German" << endl;
      outputFile << "09/18/2020" << endl;
      outputFile << endl << endl;
    }

    //output all the information to the file
    outputFile << "----------------- File Number " << numberOfFiles << " -----------------" << endl << endl;
    outputFile << "The Sum of the length of the DNA strings is: " << sum << endl;
    outputFile << "The Mean of the length of the DNA strings is: " << mean << endl;
    outputFile << "The Variance of the length of the DNA strings is: " << variance << endl;
    outputFile << "The Standard Deviation of the length of the DNA strings is: " << standardDeviation << endl;
    outputFile << "Here is the relative probability of each nucleotide: " << endl << endl;
    outputFile << "A:       " << probabilityOfA << endl;
    outputFile << "C:       " << probabilityOfC << endl;
    outputFile << "T:       " << probabilityOfT << endl;
    outputFile << "G:       " << probabilityOfG << endl << endl;
    outputFile << "Here is the relative probability of each nucleotide biagram: " << endl << endl;
    outputFile << "AA:      " << probabilityOfAA << endl;
    outputFile << "AC:      " << probabilityOfAC << endl;
    outputFile << "AT:      " << probabilityOfAT << endl;
    outputFile << "AG:      " << probabilityOfAG << endl;
    outputFile << "CA:      " << probabilityOfCA << endl;
    outputFile << "CC:      " << probabilityOfCC << endl;
    outputFile << "CT:      " << probabilityOfCT << endl;
    outputFile << "CG:      " << probabilityOfCG << endl;
    outputFile << "TA:      " << probabilityOfTA << endl;
    outputFile << "TC:      " << probabilityOfTC << endl;
    outputFile << "TT:      " << probabilityOfTT << endl;
    outputFile << "TG:      " << probabilityOfTG << endl;
    outputFile << "GA:      " << probabilityOfGA << endl;
    outputFile << "GC:      " << probabilityOfGC << endl;
    outputFile << "GT:      " << probabilityOfGT << endl;
    outputFile << "GG:      " << probabilityOfGG << endl << endl;
    numberOfFiles += 1;
  }
}

//output the 1000 lines
void Files::outputGaussianDistribution(){
  if (fileExists){
    outputFile << "1000 lines for file " << numberOfFiles-1 << ": "<< endl;
    string outputLine;
    //loop through the 1000 lines
    for(int i=1; i<=1000; ++i){
      calculateValueOfD();
      outputLine = calculateString();
      outputFile << outputLine << endl;
    }
    resetStats(); //resets the stats to be 0, neccesary for when the users wants to calculate multiple files
  }
}

//calculate the string for the 1000 line output
string Files::calculateString(){
  string outputString = "";
  float randomNumber = 0;
  while (outputString.size() < DValue){
    randomNumber = (float)rand()/RAND_MAX; //generate a random number for to calculate what letter we write
    if(randomNumber < probabilityOfA)
      outputString += 'A';
    else if (randomNumber < probabilityOfA + probabilityOfC)
      outputString += 'C';
    else if (randomNumber < probabilityOfA + probabilityOfC + probabilityOfT)
      outputString += 'T';
    else if (randomNumber < probabilityOfA + probabilityOfC + probabilityOfT + probabilityOfG)
      outputString += 'G';
    else
      return "ERROR";
  }
  return outputString;
}

//calculate D for the 1000 lines
void Files::calculateValueOfD(){
  float C;
  float pi = 3.14159;
  float a;
  float b;
  a = (float)rand()/RAND_MAX;
  b = (float)rand()/RAND_MAX;
  C = (sqrt(-2*log(a))*cos(2*(pi)*(b)));
  DValue = standardDeviation*C + mean;
  roundD();
}

//round D so we can pick an appropriate length for the strings
void Files::roundD(){
  int Dint = (int)DValue;
  DValue -= Dint;
  if (DValue < 0.5)
    DValue = Dint;
  else
    DValue = Dint+1;
}

//close the opened output file
void Files::closeOpenFile(){
  outputFile.close();
}

//calculate the sum
void Files::calculateSum(){
  for(int i=0; i < line.size(); ++i){
    sum += 1;
  }
  sum -= 1; //subtract the white space at the end of the line
}

//calculate the mean
void Files::calculateMean(){
  mean = ((float)(sum)/(float)(numberOfLines));
}

//calculate the variance
void Files::calculateVariance(string fileName){
  myFile = openFiles(fileName);
  if (myFile.is_open()){
    float varianceNumerator = 0;
    while(getline(myFile, line)){
      if(lineValid(line)){
        lineSize = float(line.size());
        lineSize -= 1.0;
        varianceNumerator += pow((lineSize-mean), 2);
      }
  }
  variance = varianceNumerator/numberOfLines;
  }
  myFile.close();
}

//calculate the standard deviation
void Files::calculateStandardDeviation(){
  standardDeviation = sqrt(variance);
}

//calculate the probability of each letter
void Files::calculateProbabilityNucleotide(string fileName){
  myFile = openFiles(fileName);
  if(myFile.is_open()){
    while(getline(myFile, line)){
      if(lineValid(line)){
        for(int i=0; i<=line.size();++i){ //loop through the string to account for every nucleotide
          sumNumberOfChar(line[i]);
        }
      }
    }
  }
  probabilityOfA = float(numberOfA)/float(sum);
  probabilityOfC = float(numberOfC)/float(sum);
  probabilityOfT = float(numberOfT)/float(sum);
  probabilityOfG = float(numberOfG)/float(sum);
  myFile.close();
}

//add a char to its total sum
void Files::sumNumberOfChar(char charInLine){
  if(tolower(charInLine) == 'a')
    numberOfA += 1;
  else if(tolower(charInLine) == 't')
    numberOfT += 1;
  else if(tolower(charInLine) == 'c')
    numberOfC += 1;
  else if(tolower(charInLine) == 'g')
    numberOfG += 1;
}

//optatin the probability of the bigrams
void Files::calculateProbabilityNucleotideBigram(string fileName){
  myFile = openFiles(fileName);
  if(myFile.is_open()){
    while(getline(myFile, line)){
      if(lineValid(line)){
        calculateWhichBigram(line);
      }
    }
  }
  calculateBigramProbabilty();
  myFile.close();
}

//the math behide the bigram probability calculation
void Files::calculateBigramProbabilty(){
  probabilityOfAA = float(numberOfAA)/float(numberOfBiagram);
  probabilityOfAC = float(numberOfAC)/float(numberOfBiagram);
  probabilityOfAT = float(numberOfAT)/float(numberOfBiagram);
  probabilityOfAG = float(numberOfAG)/float(numberOfBiagram);
  probabilityOfCA = float(numberOfCA)/float(numberOfBiagram);
  probabilityOfCC = float(numberOfCC)/float(numberOfBiagram);
  probabilityOfCT = float(numberOfCT)/float(numberOfBiagram);
  probabilityOfCG = float(numberOfCG)/float(numberOfBiagram);
  probabilityOfTA = float(numberOfTA)/float(numberOfBiagram);
  probabilityOfTC = float(numberOfTC)/float(numberOfBiagram);
  probabilityOfTT = float(numberOfTT)/float(numberOfBiagram);
  probabilityOfTG = float(numberOfTG)/float(numberOfBiagram);
  probabilityOfGA = float(numberOfGA)/float(numberOfBiagram);
  probabilityOfGC = float(numberOfGC)/float(numberOfBiagram);
  probabilityOfGT = float(numberOfGT)/float(numberOfBiagram);
  probabilityOfGG = float(numberOfGG)/float(numberOfBiagram);
}

//calculate which of the 16 bigrams we currently have
void Files::calculateWhichBigram(string line){
  int k = 1;
  string currentBigram = "";
  line.pop_back();
  for(int i = 0; i < line.size(); i += 2){
    k = i+1;
    currentBigram = "";
    currentBigram += tolower(line[i]);
    if(i==line.size()-1){
      currentBigram += tolower(line[0]);
    }
    else{
      currentBigram += tolower(line[k]);
    }
    addBiagramCount(currentBigram);
    numberOfBiagram += 1;
  }
}

//sum the total of each biagram
void Files::addBiagramCount(string currentBigram){
  if(currentBigram == "aa")
    numberOfAA += 1;
  else if(currentBigram == "ac")
    numberOfAC += 1;
  else if(currentBigram == "at")
    numberOfAT += 1;
  else if(currentBigram == "ag")
    numberOfAG += 1;
  else if(currentBigram == "ca")
    numberOfCA += 1;
  else if(currentBigram == "cc")
    numberOfCC += 1;
  else if(currentBigram == "ct")
    numberOfCT += 1;
  else if(currentBigram == "cg")
    numberOfCG += 1;
  else if(currentBigram == "ta")
    numberOfTA += 1;
  else if(currentBigram == "tc")
    numberOfTC += 1;
  else if(currentBigram == "tt")
    numberOfTT += 1;
  else if(currentBigram == "tg")
    numberOfTG += 1;
  else if(currentBigram == "ga")
    numberOfGA += 1;
  else if(currentBigram == "gc")
    numberOfGC += 1;
  else if(currentBigram == "gt")
    numberOfGT += 1;
  else if(currentBigram == "gg")
    numberOfGG += 1;
  else{
    cout << "ERROR: invalid biagram, " << currentBigram << endl;
    numberOfBiagram -= 1;
  }
}

//check if a line is valid or not
bool Files::lineValid(string line){
  for (int i=0; i < line.size()-1; ++i){
    if(charValid(tolower(line[i])))
      continue;
    else
      return false;
  }
  return true;
}

//check if a char is valid or not
bool Files::charValid(char ch){
  string str = "actg";
  if(str.find(ch)==std::string::npos)
    return false;
  return true;
}
