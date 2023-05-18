/********************************************************************
 * File: project1.cpp
 * Lab: CMSC Lab 1, Fall 2020
 * Author: Matthew Green
 * Date: 24/09/2020
 * Section: Lecture Section 30, Discussion section 33
 * E-mail: mgreen11@gl.umbc.edu
 * 
 * Description: This program opens a file that has three words
 * and will determine if those words fufill the requirements of the 
 * puzzel, escalators. Where the first word is six letters long and the
 * next two words are one letter shorter than the previous word.
 * These words must also use the same letter combination minus one
 * as the previous word.
 *********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function Prototypes
string lengthValid(bool lengthCheck); // function to print reult if word length is valid
string letterValid(bool letterCheck); // function to print result if letter combination is valid
bool checkLength(int wordLengths[], int dataLens); // function to check if word length is good
bool checkLetter(string words[]); // function to check if letter combination is good
bool reRun(); // function to ask user if they want to rerun program
void fileReader(); // function to open and read from file

// Constants
const int HEIGHT = 6; // constant int for the height of the 2d array
const int WIDTH = 4; // constant int for the widthh of the 2d array

int main() {

    cout << "Welcome to Escalators" << endl;
    // do-while loop to run the program until the user gives the input not to
    do {   
        cout << "What is the file name of the list of words? (Include the file extention)" << endl;
        // executes the fileReader function
        fileReader();
        // executes the reRun() function and detemines to continue the loop based off of the user input
    } while (reRun());
    cout << "Thank you for playing Escalators" << endl;
    return 0;
}

// inplements the lengthValid funtion
string lengthValid(bool lengthCheck) {
    string lengthValidity = " "; // declares string to hold the validity message about the word lengths
    // string will be some output depending on the parameter value
    if (lengthCheck == true) {
        lengthValidity = "This list meets the word length requirements";
    } else if (lengthCheck == false) {
        lengthValidity = "This list does not meet the word legth requirements";
    }
    return lengthValidity;
}
// implements the letterValid function
string letterValid(bool letterCheck) {
    string letterValidity = " "; //declares string to hold the validity message about the letter frequency
    if (letterCheck == true) {
        letterValidity = "This list meets the letter combination requirements";
    } else {
        letterValidity = "This list does not meet the letter combination requirements";
    }
    return letterValidity;
}
 // implements the checkLength funtion
bool checkLength(int wordLengths[], int dataLens) {
    bool lengthCheck = true; // declares a boolean to determin the value of the function
    // for loop that uses the second parameter, which is the array size, 
    for (int x = 0; x < dataLens-1; x++) {
        // the array should not have more or less than 3 strings for the game
        if (dataLens > 3) {
            cout << "List can only have three words" << endl;
            lengthCheck = false;
        } else if (dataLens < 3) {
            cout << "List must have three words" << endl;
            lengthCheck = false;
            // according to the game, the first string should be 6 letters long, the second 5 letters, and the third 4
        } else if ((wordLengths[0] == 6) && (wordLengths[1] == 5) && (wordLengths[2] == 4)) {
            lengthCheck = true;
        } else {
            lengthCheck = false;
        }
    }
    return lengthCheck;
}

// implements the checkLetter function
bool checkLetter(string words[]) {
    string compare = " "; // declares a string to be used to compare letters against each other
    string letter = " "; // declares a string to be used to get a letter 
    string word1 = words[0]; // declares three strings equal to their array equvilance
    string word2 = words[1];
    string word3 = words[2];
    string letters[HEIGHT][WIDTH] = {}; // declares the 2d array
    int frequency1 = 0; // declars three int to track the frequency of a letter
    int frequency2 = 0;
    int frequency3 = 0;
    int total1 = 0; // declares three int to  find the sum of common letters between each word
    int total2 = 0;
    int total3 = 0;
    int length = word1.length(); // declares an int equal to the length of the first word
    bool letterCheck = true; // declares a boolean to be used to determine the value of the function

    // for loop to 
    for (int i = 0; i < HEIGHT; i++) {
        // sets compare to the letter that occupies the i-th spot
        compare = word1[i];
        // for loop to compare two letters and obtain the frequency of that letter
        for (int y = 0; y < HEIGHT; y++) {
            // prevents the frequency of duplicate letters from being counted twice
            if (compare == letters[y][0]) {
                // changes compare value so repeate letters are not counted
                compare = "SKIPPED";
            }
            // compares the compare string and some letter in a string as long as there are letters in the string to be compared
            if (y < length) {
                // sets letter to the letter in the y-th spot in the string being compared
                letter = word1[y];
                // increases the letter frequency by 1 if compare and letter are equivalent 
                if (letter == compare) {
                    frequency1++;
                }
            }
            // subtracts some value from length of the string, as that string should have that value less letters
            if (y < length - 1) {
                letter = word2[y];
                if (letter == compare) {
                    frequency2++;
                }
            }
            if (y < length - 2) {
                letter = word3[y];
                if (letter == compare) {
                    frequency3++;
                }
            }
        }
        // for loop to populate the 2d array
        for (int j = 0; j < WIDTH; j++) {
            // populates the first column with the letters that were used
            letters[i][0] = compare;
            // populates the following columns with the frequecny int values
            // which has to be turned into strings to go into the array
            letters[i][1] = to_string(frequency1);
            letters[i][2] = to_string(frequency2);
            letters[i][3] = to_string(frequency3);
        }
        // resets the value for finding the letter frequency
        frequency1 = 0;
        frequency2 = 0;
        frequency3 = 0;
    }
    // for loop to calcuate the sum of the frequecy in each column
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            // makes sure that the column being added is the correct column
            if (j == 0) {
                // adds the frequecy value to the total, the value has to be turned backed into an int
                total1 = total1 + stoi(letters[i][1]);
            }
            if ( j == 1) {
                total2 = total2 + stoi(letters[i][2]);
            }
            if (j == 2) {
                // checks if the frequecy of the letter being added to the total, was in the previous string
                if(stoi(letters[i][2]) > 0) {
                    total3 = total3 + stoi(letters[i][3]);
                }
            }
        }
    } // determines if the strings followed the subtract one letter rule
    if ((total1 - total2 == 1) && (total2 - total3 == 1) && (total1 -total3 == 2)) {
        letterCheck = true;
    } else {
        letterCheck = false;
    }
    return letterCheck;
}
// implements the reRun function
bool reRun() {
    string yesOrNo = " "; // declares a string to be used for user input;
    bool reRun = true; // declares a boolean that the function will return
    bool gate = true; // declares a boolean to make sure the user input is within the wated parameters
    cout << "Do you want to check another list? (Y or N)" << endl;
    // while loop to make sure user enters wanted value
    while (gate) {
        cin >> yesOrNo;
        if ((yesOrNo == "Y") || (yesOrNo == "y")) {
            reRun = true;
            gate = false;
            // clears the error flags
            cin.clear();
            // clears the buffer so multiple inputs can't be registered
            cin.ignore(256, '\n');
        } else if ((yesOrNo == "N") || (yesOrNo == "n")) {
            reRun = false;
            gate = false;
        } else {
            cout << "Please enter Y or N" << endl;
            cin.clear();
            cin.ignore(256, '\n');
        }
    }
    return reRun;
}
// implements the fileReader function
void fileReader() {
    string word = " "; // declares string to be used for each word in the file
    string fileName = " "; // declares a string for the user to input the filename
    string words[3] = {}; // declares a string array for each word in the file to be put in this array
    int numberWord = 0; // declares an int to keep track of which word is being output from the file
    int wordLength[3] = {}; // declares an int array to hold the length of each word from the file
    cin >> fileName;
    // opens a file stream to read the text of a file
    ifstream openFile(fileName);

    //do while loop to run as long as the file is open
    do {
        // prints messsage if a file was not able to be opened
        if (!openFile.is_open()) {
            cout << "File Does Not Exist" << endl;
            cin.clear();
            cin.ignore(256, '\n');
        }
        // while loop to output the words in the file
        while (openFile >> word) {
            cout << numberWord + 1 << ". " << word << " (" << word.length() << " letters)" << endl;
            words[numberWord] = word;
            wordLength[numberWord] = words[numberWord].length();
            // increase 
            numberWord += 1;
        }
        // executes all the checks to know if the list of words on the file is valid
        if (openFile.is_open()) {
            // prints wheather or not the length of the words on the file was valid or not
            cout << lengthValid(checkLength(wordLength, numberWord)) << endl;
            // does the letter check if the length check was passed
            if (checkLength(wordLength, numberWord)) {
                // prints wheather the words passed the letter check
                cout << letterValid(checkLetter(words)) << endl;
                if(checkLetter(words)) {
                    // outputs wheather the list was valid or invalid based on the checks
                    cout << "This list is valid" << endl;
                } else {
                    cout << "This list is not valid" << endl;
                }
            } else {
                cout << "This list is not valid" << endl;
            }
        }
        // closes the file
        openFile.close();
        // ends the do-while loop when file is closed
    } while (openFile.is_open());
}
