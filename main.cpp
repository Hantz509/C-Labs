#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

int main()
{
    unsigned int i, j, z;
    int number_of_run=0;
    int maximum2=0;
    int max_count=0;
    int counter=1;
    int longest_letter_run_lenght[256]= {0};  //since the ASCII table has 256 characters so I give
    int counter2 =0;                          // the size of the array the value of 256.
    int n;
    int distribution[256] = {0};

    struct structure    // I use this function in order to create a string array because I will enter many string.
    {
        string S;
    };
    structure str[1000];


    cin >>n;

    for (z=0 ; z<n ; z++)
    {
        cin >> str[z].S;
        /* since uppercase letter and lowercase letter are treated as the same so I convert all uppercase letters to lowercase letters to make it easier.*/
        for (i=0 ; i< str[z].S.length() ; i++)
        {
            str[z].S[i] = tolower(str[z].S[i]);
        }

        for (i=0 ; i< str[z].S.length() ; i++)
        {
            if (str[z].S[i] != str[z].S[i+1])
                number_of_run++;
        }
        cout << "# Number of runs= " << number_of_run << endl;


        for (i=0 ; i<str[z].S.length() ; i++)
        {
            if (str[z].S[i]==str[z].S[i+1])
                counter +=1;
            else
                counter=1;
            if (counter>max_count)
                max_count=counter;
        }
        cout << "# Longest run length= ";
        cout << max_count << endl;


        for (j=0; j<str[z].S.length() ; j++)
        {
            char currentChar = str[z].S[j];
            while (currentChar == str[z].S[j])
            {
                j++;
                counter2++;
            }

            distribution[counter2]++;
            counter2 = 0;
            j--;

        }
        for (int i = 255; i >= 0; i--)
            if (distribution[i] != 0)
            {
                cout << "# Number of longest runs= ";
                cout << distribution[i] <<endl;
                break;
            }

        int increment=0;


        for (i=0 ; i<str[z].S.length() ; i++)
        {
            if (isalpha(str[z].S[i]))
                longest_letter_run_lenght[i] = increment++;
            else
                increment=0;

            maximum2 = max(maximum2, increment);
        }
        cout << "# Longest letter run length= ";
        cout << maximum2 <<endl;

        number_of_run=0;
        maximum2=0;
        max_count=0;
        counter=1;
        longest_letter_run_lenght[256]= {0};
        counter2 =0;
        for (int i = 0; i <=256; i++)
        distribution[i] = 0;


    }
    return 0;

}
