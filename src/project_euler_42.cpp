#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	int triangular[1000];
    for (int i=1; i<=1000; i++)
    {
        triangular[i-1] = i*(i+1)/2;
    }

    int count = 0;
    string word;

    ifstream file("./data/p042_words.txt");

    if (!file.is_open())
        return 1;

    while (!file.eof())
    {
        int value = 0;
        getline(file, word, ',');
        for (int i=0; i<word.length(); i++)
        {
            if (word[i] == '"')
                continue;
            value += int(word[i]) - 64;
        }
        int i = 0;
        for (i=0; triangular[i] < value; i++)
        {

        }
        count += (value == triangular[i]);
    }
    cout << count << endl;
    file.close();
}