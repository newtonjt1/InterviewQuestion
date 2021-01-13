// InterviewQuestion.cpp 
//
// 1. Declare a class that holds two variables.
// 2. Read data in from CSV file.
// 3. Create objects from columns of data and store in a collection.
// 4. Output the data in a form such as "One | Apple".
//

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Fruit{								// Declared Fruit class, same as before
private:									//
	string number;							// 
	string fruit;							//
public:										//
	void setNumber(string);					//
	void setFruit(string);					//
	string getNumber();						//
	string getFruit();						//
											//
};											//
											//
void Fruit::setNumber(string n) {			//
	number = n;								//
}											//
											//
void Fruit::setFruit(string f) {			//
	fruit = f;								//
}											//
											//
string Fruit::getNumber() {					//
	return number;							//
}											//
											//
string Fruit::getFruit() {					//
	return fruit;							//
}											//


int main()
{
	string input, word1, word2, line1, line2;
	int i = 0;
	Fruit data[3];							// array of Fruit objects

	ifstream inputFile;
	inputFile.open("..\\..\\InterviewQuestion.csv", ios::in);
	
	// as I admitted the other day, I haven't worked a whole lot
	//  with reading from files and not familiar with this 'stringstream'
	//  class but every example I found for reading data from a csv file
	//  used it and the stringstream/getline combination definitely looks 
	//  a little more elegant than the for loop/if statement I was trying 
	//  to use to read the input the other day
	//
	// also, I was getting hung up thinking I would have to read in an
	//  entire line and hold on to that data before moving on to reading
	//  the next line, and then figure out away to correlate the columns
	//  of data again...took awhile to realize I could just read one word
	//  of each line and then move on to the next...much simpler than I 
	//  was trying to make it

	getline(inputFile, line1); 			// read in line 1 of csv file
	stringstream s(line1);				// 
	
	getline(inputFile, line2);			// read in line 2 of csv file
	stringstream t(line2);				//
	
	while (getline(s, word1, ',')) {	// while there are items left on line 1, read item
		getline(t, word2, ',');			// read item on line 2 also
		
		data[i].setNumber(word1);		// create new Fruit object in Fruit array using
		data[i].setFruit(word2);		//  data from row 1 & 2 of csv file
		i++;
	}
	
	inputFile.close();

	// couldn't recall exactly what was asked for on the output;
	//  this will output to the terminal but could be easily made
	//  to output to file
	
	for (int j=0; j < sizeof(data)/sizeof(data[0]); j++) 
		cout << data[j].getNumber() << "\t|  " << data[j].getFruit() << endl;

	return 0;
}
