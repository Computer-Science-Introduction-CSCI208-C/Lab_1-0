/*******************************************
 * BY: Jessica Dosseh 
 * CLASS: CSCI 208 001
 * LABNAME: Lab 1
 * DESCRIPTION: This lab is a refresher of 207 concepts you will use repeatedly in this course, including file I/O.
 * INPUT: months.txt
 * OUTPUT: output.txt
*********************************************/

#include <iostream>
#include <fstream>
#include <string> 

using namespace std; 

// PROTOTYPES AND CONSTANTS 
const int filesize = 6; 
void output (string monthsArray[filesize], int tempArray[filesize]);

int main() 
{

  // VARIABLE DECLARATION 
  ifstream inFS; 
  ofstream outFS;
  string months; 
  string monthsArray[filesize]; 
  int temp; 
  int tempArray[filesize]; 

  // 1. READ THE FILE AND PASS TO ARRAY
  inFS.open("months.txt");
  if (!inFS.is_open())
  {
    cout << "could not open file." << endl;
    return 1; 
  }

  while(!inFS.eof())
  {
    for (int i = 0; i < filesize; i++)
    {
      inFS >> monthsArray[i];
      inFS >> tempArray[i]; 
    }
  }
  // 2. PASS ARRAY TO OUTPUT FUNCTION
  output(monthsArray, tempArray); 

  // 3. READ THROUGH THE FILE AGAIN 
  // PASS THE INFORMATION DIRECTLY TO THE OUTPUT FILE
  outFS.open("output.txt", std::ios_base::app); 

  inFS.clear();
  inFS.seekg(0, ios::beg);

  outFS << "------- DATA PASSED FROM FILE -------" << endl;
  outFS << endl;

    for (int i = 0; i < filesize; i++)
    {
      inFS >> months;
      inFS >> temp; 

      outFS << months << ": " << temp << endl;
    }

  outFS.close();


// 4. CLOSE DATA FILE 
  inFS.close(); 

  return 0; 
}

void output (string monthsArray[filesize], int tempArray[filesize])
{
  ofstream outFS; 
  outFS.open("output.txt"); 

  outFS << "------- DATA PASSED FROM ARRAY -------" << endl;
  outFS << endl;

  for (int i = 0; i < filesize; i++)
  {
    outFS << monthsArray[i] << ": " << tempArray[i] << endl;
  }

  outFS << endl;
  outFS.close();
}

