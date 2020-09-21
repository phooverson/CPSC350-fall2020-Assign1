#include "assign1.h"

using namespace std;

int main(int argc, char** argv){

  //check if they input a file
  if(argc != 2){
    cout << "invalid input: please input file name, make sure you input a single file" << endl;
    return -1;
  }

  Files *file = new Files(); //opens to heap
  bool hasAnswer = true;
  string answer;
  string fileName;

  //These three methods are the program
  file->calculateStatistics(argv[1]);
  file->outputStatisticsToFile("phooverson.out");
  file->outputGaussianDistribution();

  //while loop to loop through the program unitll the user is done
  while (hasAnswer){
    cout << "Would you like to do another file? (Yes or No) " << endl;
    cin >> answer;
    if (answer == "Yes"){
      cout << "What file would you like to use? " << endl;
      cin >> fileName;
      file->calculateStatistics(fileName);
      file->outputStatisticsToFile("phooverson.out");
      file->outputGaussianDistribution();
    }
    else if (answer == "No"){
      hasAnswer = false;
    }
    else{
      cout << "Invalid answer, please try again. (The answer can be Yes or No)" << endl;
    }
  }

  cout << "Have a good day!!" << endl;
  file->closeOpenFile();
  delete file;
  return 0;
}
