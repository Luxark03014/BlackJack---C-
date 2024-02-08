#include <iostream>
#include <string>
using namespace std;

    int Cards[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
    string Suit[] = {"Spades", "Clubs", "Diamonds", "Hearts"};
    int Spades[] = { 0, 0, 0, 0, 0 , 0, 0, 0, 0, 0, 0, 0, 0 };
    int Clubs[] = { 0, 0, 0, 0, 0 , 0, 0, 0, 0, 0, 0, 0, 0 };
    int Diamonds[] = { 0, 0, 0, 0, 0 , 0, 0, 0, 0, 0, 0, 0, 0 };
    int Hearts[] = { 0, 0, 0, 0, 0 , 0, 0, 0, 0, 0, 0, 0, 0 };
    int randomNum;
    int DeckValue = 0;
    int DeckCroupierValue = 0;
    int AsValue;
    int CardValue;
    bool CardTurn = false;
    int SuitNum;int CardNum;
    bool itsAnAs;
    int Card;
    string decision;
    string Turn;
   
void IntroGame(){

    cout << "Bienvenido al BlackJack\n";
    cout << "===================================================================================================================== \n";

}
int CardAction() {
   
    do
    {
        SuitNum = rand() % 3;
        if (SuitNum == 0)
        {
            CardNum = rand() % 12;
            Spades[CardNum] = 1;
            Card = Cards[CardNum];


        }
        else if (SuitNum == 1)
        {
            CardNum = rand() % 12;
            Clubs[CardNum] = 1;
            Card = Cards[CardNum];
        }
        else if (SuitNum == 2)
        {
            CardNum = rand() % 12;
            Diamonds[CardNum] = 1;
            Card = Cards[CardNum];
        }
        else if (SuitNum == 3)
        {
            CardNum = rand() % 12;
            Hearts[CardNum];
            Card = Cards[CardNum];
        }




      
    }
    
        while (Hearts[CardNum] != 0 && Diamonds[CardNum] != 0 && Clubs[CardNum] != 0 && Spades[CardNum] != 0);
   
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
            if (DeckCroupierValue + 11 >= 21)
            {
                DeckCroupierValue += 1;
            }
            else if (DeckCroupierValue + 11 < 21)
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
    else if(Turn == "Player")
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








int main() {
    srand(time(NULL));
    IntroGame();

    //your card
   
        
        cout << "Your card is " << CardAction() << " Of " << Suit[SuitNum] << "\n";
        CardCount(Card, "Player");
       
      
        cout << "And your second card is " << CardAction() << " Of " << Suit[SuitNum] << "\n";
        cout << "You deck has a total of " << CardCount(Card, "Player") << " points.\n";
        Turn = "Croupier";
        cout << "The croupier's card is " << CardAction() << " of " << Suit[SuitNum] << "\n";
        cout << "Croupier has a total of " << CardCount(Card, "Croupier") << " points.\n";
        Turn = "Player";
    //croupier card
        cout << "===================================================================================================================== \n";
        
        
        decision = "y";
        while (DeckValue < 21 && decision == "y")
        {
            cout << "Do you want another card? (y/n)";
            cin >> decision;
            if (decision == "y")
            {

                cout << "Your card is " << CardAction() << " Of " << Suit[SuitNum] << "\n";
                cout << "Your deck has a total of " << CardCount(Card, "Player") << " points.\n";
                while (DeckCroupierValue < DeckValue)
                {
                    cout << "The croupier's card is " << CardAction() << " of " << Suit[SuitNum] << "\n";
                    cout << "Croupier has a total of " << CardCount(Card, "Croupier") << " points.\n";

                }

            }
            else if (decision == "n")
            {
                while (DeckCroupierValue < DeckValue || DeckCroupierValue < 21)
                {
                    cout << "The croupier's card is " << CardAction() << " of " << Suit[SuitNum] << "\n";
                    cout << "Croupier has a total of " << CardCount(Card, "Croupier") << " points.\n";

                }



            }
        }
        if( DeckCroupierValue > 21)
        {
            youWin();
        }
        else if (DeckValue > 21)
        {
            youLose();
        }
        else if (DeckValue == DeckCroupierValue == 21)
        {
            cout << "You and the croupier both have " << DeckValue << " points:\n";
            youLose();

        }
        
}
