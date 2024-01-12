#include <iostream>
#include <string>
using namespace std;

    int Cards[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    // string Suit[] = {"Spades", "Clubs", "Diamonds", "Hearts"};
    int Suit[] = { 1, 2, 3, 4 };
    int randomNum;
    int DeckValue = 0;
    int AsValue;
    
   
void IntroGame(){

    cout << "Bienvenido al BlackJack\n";

}
int CardAction() {
   
   int i = rand() % 9;
    
  
   
    
    return Cards[i];


}
int SuitAction() {
    int n = rand() % 3;

    return Suit[n];
    
}
bool itsAnAs() {
    if (CardAction() == 1)
    {
        return true;
    }
    else {
        return false;
    }

}
//int ValueCards() {



//}
int main() {
    IntroGame();
   


        cout << "Your card is " << CardAction() << "\n";
        cout << "Of " << SuitAction();
        if (itsAnAs() == true)
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
        else if (itsAnAs() == false)
        {
            DeckValue = CardAction();
            cout << "At the moment your Deck has a total of " << DeckValue << " points\n";
        }

    
}
