#include <iostream>

using namespace std;

int main()
{
    int arr[10] = {5, 7, -2, 10, 22, -2, 0, 5, 22, 1};
    int key;
    bool found = false; // Variable to keep track of whether key is found or not
    cout << "Enter the key to find in the array: " << endl;
    cin >> key;
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == key)
        {
            found = true; // Key is found
            break;
        }
    }
    if (found == true)
    {
        cout << key << " is present" << endl;
    }
    else
    {
        cout << key << " is not present" << endl;
    }
}
