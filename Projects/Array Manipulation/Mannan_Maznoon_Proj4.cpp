// Maznoon Mannan - Project 4: Array Manipulation

#include <iostream>
using namespace std;

void output(const int numbers[], const int& numElements)
{
  cout << "Array: ";
  for(int i=0; i<numElements; i++)
  {
    cout << numbers[i] << " ";
  }
  cout << "  Size: " << numElements << endl << endl;
}

int getIndex(int numbers[], const int& CAPACITY, int& numElements, int val, int& position)
{
  for(int i=0; i < numElements; i++)
  {
    if (numbers[i] == val)
    {
      position = i;
      return position;
    }
  }
  return -1; // not found
}

bool isFull(const int& CAPACITY, int& numElements)
{
  if(numElements >= CAPACITY)
    return true;

  return false;
}

void append(int numbers[], int& numElements, const int& CAPACITY, int val)
{
  bool full = isFull(CAPACITY, numElements);

  if(full == false)
  {
    numbers[numElements] = val;
    numElements++;
  }
}

void insertAt(int numbers[], const int& CAPACITY, int& numElements, int val, int position)
{
  bool full = isFull(CAPACITY, numElements);

  if(full == false && position <= numElements)
  {
    numElements++;
    for(int i = numElements-1; i>=position; i--)
    {
      numbers[i] = numbers[i-1];
    }
    numbers[position] = val;
    output(numbers, numElements);
  }
  else
    cout << "Position exceeds the array." << endl;
}

bool isEmpty(int& numElements)
{
  if(numElements == 0)
  {
    return true;
  }

  return false;
}

bool removeElement(int numbers[], const int& CAPACITY, int& numElements, int val, int position)
{
  cout << "Enter a number to remove: ";
  cin >> val;

  int exist = getIndex(numbers, CAPACITY, numElements, val, position);

  if(exist != -1)
  {
    for(int j = position; j < numElements; j++)
    {
      numbers[j] = numbers[j+1];
    }
    numElements--;
    output(numbers, numElements);
    return true;
  }
  else
    cout << "Number not found. " << endl;

  return false;
}

int removeFirst(int numbers[], int& numElements, bool& empty, int& cut)
{
  empty = isEmpty(numElements);

  if(empty == true)
    return -1;
  else
  {
    cut = numbers[0];

    for(int i=0; i < numElements-1; i++)
      numbers[i] = numbers[i+1];

    numElements--;
  }

  return cut;
}

int removeLast(int numbers[], int& numElements, bool& empty, int& cut)
{
  empty = isEmpty(numElements);

  if(empty == true)
    return -1;
  else
  {
    cut = numbers[numElements-1];
    numElements--;
  }

  return cut;
}

int menu(int numbers[], const int& CAPACITY, int& numElements, int val, int position)
{
  int option;
  int cut;
  bool empty;

  while(option!=8)
  {
    cout << "\n1. Get Index\n"
         << "2. Append\n"
         << "3. Insert\n"
         << "4. Remove\n"
         << "5. Remove First\n"
         << "6. Remove Last\n"
         << "7. Output\n"
         << "8. Exit Program\n\n"
         << "Select: ";
    cin >> option;
    cout << endl;

    switch(option)
    {
      case 1:
      {
        cout << "Enter number to find the index of: ";
        cin >> val;
        cout << "Index: " << getIndex(numbers, CAPACITY, numElements, val, position) << endl;
        break;
      }
      case 2:
      {
        cout << "Enter a number to add to the array: ";
        cin >> val;
        append(numbers, numElements, CAPACITY, val);
        output(numbers, numElements);
        break;
      }
      case 3:
      {
        cout << "Enter number and position(number, index): ";
        cin >> val >> position;
        cout << endl;
        insertAt(numbers, CAPACITY, numElements, val, position);
        break;
      }
      case 4:
      {
        removeElement(numbers, CAPACITY, numElements, val, position);
        break;
      }
      case 5:
      {
        cout << "Removed: " << removeFirst(numbers, numElements, empty, cut) << endl << endl;
        if(empty == false)
          output(numbers, numElements);
        break;
      }
      case 6:
      {
        cout << "Removed: " << removeLast(numbers, numElements, empty, cut) << endl << endl;
        if(empty == false)
          output(numbers, numElements);
        break;
      }
      case 7:
        output(numbers, numElements);
        break;
      case 8:
          cout << "Ending Program." << endl;
          break;
      default:
          cout << "Invalid option. " << endl << endl;

    }

  }
  return option;
}

int main()
{
  const int CAPACITY = 100;
  int numbers[CAPACITY];
  int numElements = 0;
  int val;
  int position;

  cout << "Array Manipulation: " << endl;
  cout << "------------------" << endl;

  append(numbers, numElements, CAPACITY, 10);
  append(numbers, numElements, CAPACITY, 20);
  append(numbers, numElements, CAPACITY, 30);
  append(numbers, numElements, CAPACITY, 40);
  append(numbers, numElements, CAPACITY, 50);
  append(numbers, numElements, CAPACITY, 60);
  append(numbers, numElements, CAPACITY, 70);
  append(numbers, numElements, CAPACITY, 80);
  append(numbers, numElements, CAPACITY, 90);
  append(numbers, numElements, CAPACITY, 100);

  output(numbers, numElements);

  menu(numbers, CAPACITY, numElements, val, position);


  return 0;
}
