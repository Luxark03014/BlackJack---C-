#include <iostream>
#include <string>
using namespace std;

int Cards[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
string Suit[] = { "Spades", "Clubs", "Diamonds", "Hearts" };
int Spades[] = { 0, 0, 0, 0, 0 , 0, 0, 0, 0, 0, 0, 0, 0 };
int Clubs[] = { 0, 0, 0, 0, 0 , 0, 0, 0, 0, 0, 0, 0, 0 };
int Diamonds[] = { 0, 0, 0, 0, 0 , 0, 0, 0, 0, 0, 0, 0, 0 };
int Hearts[] = { 0, 0, 0, 0, 0 , 0, 0, 0, 0, 0, 0, 0, 0 };

int DeckValue = 0;
int DeckCroupierValue = 0;
int AsValue;
int CardValue;

int SuitNum; int CardNum;


int Card;
string decision;


void IntroGame() {

    cout << "Welcome to BlackJack\n";
    cout << "===================================================================================================================== \n";

}
int CardAction() {
    bool CardSelected = false;
    while (!CardSelected)
    {
        CardSelected = false;
        SuitNum = rand() % 4;
        CardNum = rand() % 13;
        if (SuitNum == 0 && Spades[CardNum] == 0)
        {

            Spades[CardNum] = 1;

            CardSelected = true;


        }
        else if (SuitNum == 1 && Clubs[CardNum] == 0)
        {

            Clubs[CardNum] = 1;

            CardSelected = true;

        }
        else if (SuitNum == 2 && Diamonds[CardNum] == 0)
        {

            Diamonds[CardNum] = 1;

            CardSelected = true;

        }
        else if (SuitNum == 3 && Hearts[CardNum] == 0)
        {

            Hearts[CardNum] = 1;

            CardSelected = true;

        }





    }

  
    Card = Cards[CardNum];
    return Card;
}

int CardCount(int Value, string Turn) {
    if (Turn == "Croupier")
    {
        if (Value > 1 && Value <= 10)
        {
            DeckCroupierValue += Card;

        }
        else if (Value == 1)
        {
            if (DeckCroupierValue + 11 > 21)
            {
                DeckCroupierValue += 1;
            }
            else
            {
                DeckCroupierValue += 11;
            }
        }
        else if (Value == 11 || Value == 12 || Value == 13)
        {
            DeckCroupierValue += 10;
        }
        return DeckCroupierValue;
    }
    else if (Turn == "Player")
    {
        if (Value > 1 && Value <= 10)
        {
            DeckValue += Card;

        }
        else if (Value == 1)
        {
            cout << "Do you want your Ace to count 1 or 11?\n";
            cin >> AsValue;
            if (AsValue == 1)
            {
                DeckValue += 1;
            }
            else if (AsValue == 11)
            {
                DeckValue += 11;
            }
        }
        else if (Value == 11 || Value == 12 || Value == 13)
        {
            DeckValue += 10;
        }
        return DeckValue;
    }



}

void youLose() {

    cout << "I'm sorry, you lost!";
}
void youWin() {

    cout << "Congratulations! You won!";
}






void ReadCard() {
    
    if (Cards[CardNum] == 1)
    {
        cout << "A";
    }
    else if (Cards[CardNum] == 11)
    {
        cout << "J";
    }
    else if (Cards[CardNum] == 12)
    {
        cout << "Q";
    }
    else if (Cards[CardNum] == 13)
    {
        cout << "K";
    }
    else
    {
        cout << Cards[CardNum];
    }
    cout << " Of " << Suit[SuitNum] << "\n";
}


int main() {
    srand(time(NULL));
    IntroGame();

 

    CardAction();
    cout << "Your card is ";
    ReadCard(); 
    
    CardCount(Card, "Player");

    CardAction();
    cout << "And your second card is ";
    ReadCard();
    cout << "You deck has a total of " << CardCount(Card, "Player") << " points.\n";
    
    CardAction();
    cout << "The croupier's card is ";
    ReadCard();
    cout << "Croupier has a total of " << CardCount(Card, "Croupier") << " points.\n";
    
    cout << "===================================================================================================================== \n";


    decision = "y";
    while (DeckValue <= 21 && decision == "y")
    {
        cout << "Do you want another card? (y/n)";
        cin >> decision;
        if (decision == "y")
        {
            CardAction();
            cout << "Your card is ";
            ReadCard();
            cout << "Your deck has a total of " << CardCount(Card, "Player") << " points.\n";



        }
        else if (decision == "n")
        {
            while (DeckCroupierValue < DeckValue || DeckCroupierValue < 17)
            {
                CardAction();
                cout << "The croupier's card is ";
                ReadCard(); 
                cout << "Croupier has a total of " << CardCount(Card, "Croupier") << " points.\n";

            }



        }
    }
    if (DeckValue == 21 && (DeckCroupierValue < 21 || DeckCroupierValue > 21))
    {
        youWin();
    }
    else if (DeckValue < 21 && DeckCroupierValue > 21)
    {
        youWin();
    }
    else if (DeckValue > 21)
    {
        youLose();
    }
    else if (DeckValue < 21 && (DeckCroupierValue <= 21 && DeckCroupierValue > DeckValue))
    {
        youLose();
    }
    else if (DeckValue == DeckCroupierValue)
    {
        cout << "You and the croupier both have " << DeckValue << " points:\n";
        youWin();

    }

}
