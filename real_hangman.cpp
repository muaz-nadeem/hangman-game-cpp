#include <iostream>
using namespace std;
#include <ctime>
#include <cctype>

int misses = 0;
int tries = 8;

void hangMan();
int checkGuess(char, string, string&);

string message = "You have 8 chances";

int main()
{
    char letter;
    string country;

    string countries[90] = {"argentina", "australia", "brazil", "canada", "china", "colombia", "denmark", "egypt", "france", "germany",
        "india", "indonesia", "italy", "japan", "kenya", "mexico", "netherlands", "newzealand", "nigeria", "norway", "pakistan", 
        "peru", "philippines", "poland", "portugal", "russia", "saudiarabia", "southafrica", "southkorea", "spain", "sweden", 
        "switzerland", "thailand", "turkey", "ukraine", "unitedarabemirates", "unitedkingdom", "unitedstates", "vietnam",
        "algeria", "bangladesh", "belgium", "chile", "czechrepublic","finland", "greece", "hungary", "ireland", "israel",
        "malaysia", "morocco", "singapore", "taiwan", "venezuela","austria", "bahrain", "bulgaria", "croatia", "cyprus",
        "estonia", "ethiopia", "fiji", "ghana", "guatemala","honduras", "iceland", "jamaica", "jordan", "kuwait","latvia", "lithuania", 
        "luxembourg", "malta", "mauritius", "monaco", "montenegro", "namibia", "oman", "panama","paraguay", "qatar", "romania", "serbia",
        "slovakia","slovenia", "tunisia", "uganda", "uruguay", "zimbabwe"};

    srand (time(NULL));
    int country_number = rand() % 91;

    country = countries[country_number];

    string hide_country(country.length(), '_');
    system ("cls");


    while (misses != 8)
    {
        hangMan();               //calling the hangman function

        cout << endl;
        cout << "\n\n\n\nLife : " << tries << endl;
        cout << hide_country << endl;

        cout << "\nGuess a letter : ";
        cin >> letter;

        letter = tolower(letter);

        if(checkGuess(letter, country, hide_country) == 0)
        {
            message = "Incorrect Letter";

            misses++;
            tries--;
            
            cout << message;
        }

        else 
        {
            message = "Correct Guess";
            cout << message;
        }

        if(hide_country == country)
        {
            message = "You are Free!";
            cout << message;

            hangMan();
            cout<<endl;
            cout << "\nLife : " << tries << endl;

            cout<<endl;
            cout << "\n\nHurrah! You guessed it!"<<endl;
            cout << "The country is : " << country <<endl;
            break;
        }

         
    }

    if(misses == 8)
    {
        message = "You are Hanged!";
        hangMan();

        cout << "\n\nLife : " << tries << endl;
        cout << "The country is " << country <<endl;
    }

    return 0;
}



int checkGuess(char guess, string country, string &hide_country)
{
    int matches = 0;
    int length = country.length();
    
    for(int i=0; i < length; i++)
    {
        if(guess == hide_country[i])            //this is the hidden version of the country
         {
           cout << "Letter already entered";
         }

        if(guess == country[i])            //this is real country means the country guessed by the program
        {
            hide_country[i] = guess;
            matches++;
        }
    }

    return matches;
}


void hangMan()
{
    system("cls");
    switch (misses)
    {
        case 0:
        cout << " ------------ \n";
        cout << " |          | \n";
        cout << "            | \n";
        cout << "            | \n";
        cout << "            | \n";
        cout << "            | \n";
        cout << "            | \n";
        break;
        system("cls");


        case 1:
        cout << " ------------ \n";
        cout << " |          | \n";
        cout << " |          | \n";
        cout << "            | \n";
        cout << "            | \n";
        cout << "            | \n";
        cout << "            | \n";
        break;
        system("cls");
        

        case 2:
        cout << " ------------ \n";
        cout << " |          | \n";
        cout << " |          | \n";
        cout << " |          | \n";
        cout << "            | \n";
        cout << "            | \n";
        cout << "            | \n";
        break;
        system("cls");
        

        case 3:
        cout << " ------------ \n";
        cout << " |          | \n";
        cout << " |          | \n";
        cout << " |          | \n";
        cout << " O          | \n";
        cout << "            | \n";
        cout << "            | \n";
        break;
        system("cls");
        
        case 4:
        cout << " ------------ \n";
        cout << " |          | \n";
        cout << " |          | \n";
        cout << " |          | \n";
        cout << " O          | \n";
        cout << "/           | \n";
        cout << "            | \n";
        break;
        system("cls");

        case 5:
        cout << " ------------ \n";
        cout << " |          | \n";
        cout << " |          | \n";
        cout << " |          | \n";
        cout << " O          | \n";
        cout << "/ \\         | \n";
        cout << "            | \n";
        break;
        system("cls");
        

        case 6:
        cout << " ------------ \n";
        cout << " |          | \n";
        cout << " |          | \n";
        cout << " |          | \n";
        cout << " O          | \n";
        cout << "/ \\         | \n";
        cout << " |          | \n";
        break;
        system("cls");
        
        case 7:
        cout << " ------------ \n";
        cout << " |          | \n";
        cout << " |          | \n";
        cout << " |          | \n";
        cout << " O          | \n";
        cout << "/ \\         | \n";
        cout << " |          | \n";
        cout << "/           | \n";
        break;
        system("cls");
    
        case 8:
        cout << " ------------ \n";
        cout << " |          | \n";
        cout << " |          | \n";
        cout << " |          | \n";
        cout << " O          | \n";
        cout << "/ \\         | \n";
        cout << " |          | \n";
        cout << "/ \\         | \n";
        break;
        system("cls");

    }
}

