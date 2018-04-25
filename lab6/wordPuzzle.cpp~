// Justin Choi (jc8mc) 
// March 14th 2017
// CS 2150 Lab 6: Hashing
// The big theta run time for this hash table is n^4 since it has 4 nested for loops

#include <fstream>
#include "hashTable.h"
#include "timer.h"

using namespace std;

#define MAXROWS 500
#define MAXCOLS 500

char table[MAXROWS][MAXCOLS];

// Forward declarations for given code to read and get 
bool readInTable (string filename, int &rows, int &cols);
char* getWordInTable (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols);


int main(int argc, char* argv[]) {
  int num_find = 0;
  string fromDictionary = argv[1];
  string temp;
  ifstream theFile(fromDictionary.c_str() );
  while(getline(theFile, temp)) {
    num_find++;
  }
  theFile.close();
    
  hashTable *myHashTable = new hashTable(num_find);

  ifstream openDictionary(fromDictionary.c_str());
  while(getline(openDictionary, temp)) {
    if(temp.length() >= 3) {
      myHashTable -> add(temp);
    }
  }
  openDictionary.close();
    
  string search = argv[2];
  ifstream theSearch(search.c_str());
  int rows;
  int columns;
  if(!readInTable(search.c_str(), rows, columns)) {
    cout<< "File cannot be opened." << endl;
  }
    
  int total_found = 0;
  string direction;
  timer tictoc;
  tictoc.start();
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns; j++) {
      for(int d = 0; d < 8; d++) {
	for(int w = 3; w < 23; w++) {
	  string word(getWordInTable(i, j, d, w, rows, columns));
	  if(w > word.length()) break;
	  if(myHashTable -> contain(word)) {
	    total_found++;
	    if(d == 0){
	      direction = "N";
	    }
	    else if(d == 1) {
	      direction = "NE";
	    }
	    else if(d == 2) {
	      direction = "E";
	    }
	    else if(d == 3) {
	      direction = "SE";
	    }
	    else if(d == 4) {
	      direction = "S";
	    }
	    else if(d == 5) {
	      direction = "SW";
	    }
	    else if(d == 6) {
	      direction = "W";
	    }
	    else if(d == 7) {
	      direction = "NW";
	    } 
	          
	    cout << direction << " (" << i << ", " << j << "):\t" << word << endl;
	  }
	}
      }
    }
  }
  tictoc.stop();
  int total_time = tictoc.getTime() * 1000;  
  cout << total_found << " words found" << endl;
  cout << "Found all words in " << total_time << " seconds" << endl;
  cout << total_time; 
}

/** This function will read in a grid file, as per the format in the
 * CS 2150 lab 6 document, into a global table[][] array.  It uses C++
 * file streams, and thus requires the the <fstream> #include header.
 *
 * @return true or false, depending on whether the file was
 *         successfully opened.
 * @param filename The file name to read in -- it's assumed to be in
 *                 the file format described in the lab document.
 * @param rows The number of rows as specified in the input file;
 *             as this is a reference, it is set by the function.
 * @param cols The number of columnss as specified in the input file;
 *             as this is a reference, it is set by the function.
 */
bool readInTable (string filename, int &rows, int &cols) {
  // a C++ string to hold the line of data that is read in
  string line;
  // set up the file stream to read in the file (takes in a C-style
  // char* string, not a C++ string object)
  ifstream file(filename.c_str());
  // upon an error, return false
  if ( !file.is_open() )
    return false;
  // the first line is the number of rows: read it in
  file >> rows;
  getline (file,line); // eats up the return at the end of the line
  // the second line is the number of cols: read it in and parse it
  file >> cols;
  getline (file,line); // eats up the return at the end of the line
  // the third and last line is the data: read it in
  getline (file,line);
  // close the file
  file.close();
  // convert the string read in to the 2-D grid format into the
  // table[][] array.  In the process, we'll print the table to the
  // screen as well.
  int pos = 0; // the current position in the input data
  for ( int r = 0; r < rows; r++ ) {
    for ( int c = 0; c < cols; c++ ) {
      table[r][c] = line[pos++];
      //cout << table[r][c];
    }
    //cout << endl;
  }
  // return success!
  return true;
}



/** This function will retrieve a word in a grid of letters in a given
 * direction.  If the end of the grid is encountered before the length
 * of the desired string is reached, then a shorter string will be
 * returned.  The data is retrieved from a global char table[][]
 * array, which is assumed to be defined (and in scope).  NOTE: The
 * return value is a static char[][] variable (for efficiency
 * reasons), so a successive return value will overwrite a previous
 * return value.
 *
 * @return A char* containing the letters in the provided direction
 *         (NOTE: it is returned in a static char array).
 * @param startRow The starting (row,col) position to find the word.
 * @param startCol The starting (row,col) position to find the word.
 * @param dir The direction to move: 0 is north (upwards), 1 is
 *            northeast, and it rotates around clockwise until it
 *            reaches 7 for northwest.
 * @param len The length of the string to return (assuming the edge of
 *            the grid is not reached).
 * @param numRows The number of rows in the global char table[][]
 *                array .
 * @param numCols The number of columns in the global char table[][]
 *                array.
 */
char* getWordInTable (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
  // the static-ness of this variable prevents it from being
  // re-declared upon each function invocataion.  It also prevents it
  // from being deallocated between invocations.  It's probably not
  // good programming practice, but it's an efficient means to return
  // a value.
  static char output[256];
  // make sure the length is not greater than the array size.
  if ( len >= 255 )
    len = 255;
  // the position in the output array, the current row, and the
  // current column
  int pos = 0, r = startRow, c = startCol;
  // iterate once for each character in the output
  for ( int i = 0; i < len; i++ ) {
    // if the current row or column is out of bounds, then break
    if ( (c >= numCols) || (r >= numRows) || (r < 0) || (c < 0) )
      break;
    // set the next character in the output array to the next letter
    // in the table
    output[pos++] = table[r][c];
    // move in the direction specified by the parameter
    switch (dir) { // assumes table[0][0] is in the upper-left
    case 0:
      r--;
      break; // north
    case 1:
      r--;
      c++;
      break; // north-east
    case 2:
      c++;
      break; // east
    case 3:
      r++;
      c++;
      break; // south-east
    case 4:
      r++;
      break; // south
    case 5:
      r++;
      c--;
      break; // south-west
    case 6:
      c--;
      break; // west
    case 7:
      r--;
      c--;
      break; // north-west
    }
  }
  // set the next character to zero (end-of-string)
  output[pos] = 0;
  // return the string (a C-style char* string, not a C++ string
  // object)
  return output;
}
