// Maznoon Mannan - Treasure Map
#include <iostream>
#include <string>
using namespace std;


int mapSize(int &size)
{
  do {
    cout << "Enter a map size between 5 and 9 inclusive: ";
    cin >> size;
    if(size < 5 || size > 9)
      cout << "Invalid map size." << endl;
    else
      cout << "\nMap size set to " << size << ". " << endl << endl;
  } while (size < 5 || size > 9);

  return size;
}


void treasureMap(int &size, int &row, int &col)
{

  for(int i = 0; i < size; i++)
  {
    cout << i << " ";

    for(int j = 0; j < size; j++)
    {
      if(i == row && j == col)
        cout << " X ";
      else
        cout << " - ";
    }

    cout << endl;
  }

  cout << "   ";

  for(int i=0 ; i < size; i++)
      cout << i << "  ";


  cout << endl << endl;

}


void coordinates(int &size, int &row, int &col)
{

  do
  {
    cout << "Location of X (row column): ";
    cin >> row >> col;
    if(row < 0 || row >= size || col < 0 || col >= size)
      cout << "Coordinates must be between 0 and " << size - 1 << "." << endl;
  } while(row < 0 || row >= size || col < 0 || col >= size);

  cout << "\nTreasure coordinates asigned to row " << row << " column " << col << "." << endl << endl;

  treasureMap(size, row, col);
}


void shift(int &size, int &row, int &col)
{
  char direction;
  int vector;
  int num_direc;
  int new_row = row;
  int new_col = col;
  bool good_input = true;

  do {
    good_input = true;

    cout << "Shift X (N,S,E,W) and unit number: ";
    cin >> direction >> vector;

    num_direc = static_cast<int>(direction);


      if(num_direc == 78 || num_direc == 110)   // shift North
      {
        new_row = row - vector;
      }
      else if(num_direc == 83 || num_direc == 115)  // shift South
      {
        new_row = row + vector;
      }
      else if(num_direc == 69 || num_direc == 101)  // shift East
      {
        new_col = col + vector;
      }
      else if(num_direc == 87 || num_direc == 119)  // shift West
      {
        new_col = col - vector;
      }
      else
        {
        good_input = false;
        cout << "Invalid Direction" << endl;
        }
 //cout << new_col << new_row << endl;
      if (good_input)
        {

        if (((new_row > 0) && (new_row  < size)) && ((new_col > 0) && (new_col  < size)))
            {
            row = new_row;
            col = new_col;
            }
        else
            {
            good_input = false;
            cout << "Treasure cannot move beyond the map." << endl;
            }
        }

  } while(good_input == false);


  treasureMap(size, row, col);

}


int menu(int &size, int &row, int &col)
{
  int option;

  while(option != 3) {
      cout << "1) Update treasure coordinates (row/column) " << endl;
      cout << "2) Shift X (N, S, E, W) " << endl;
      cout << "3) Exit Program " << endl; // exit option
      cout << "\nSelect: ";
      cin >> option;
      cout << endl;

      switch(option){
          case 1:
              coordinates(size, row, col);
              break;
          case 2:
              shift(size, row, col);
              break;
          case 3:
              cout << "Exiting Program." << endl;
              break;
          default:
              cout << "You did not select an available option, try again." << endl << endl;
      }
  }
  return option;
}


int main()
{
  int size;
  int row;
  int col;

  mapSize(size);

  coordinates(size, row, col);

  menu(size, row, col);

  return 0;
}
