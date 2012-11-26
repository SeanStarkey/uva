/**
 * UVa Online Judge - Problem 181
 */

#include <string>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>

struct Card {
    int suit;
    int rank;
};

bool hands[5][4][13];
bool won[5][4][13];
int trumpSuit;
int currentPlayer;

void dumpHands()
{
    for (int player=0; player<5; player++)
    {
        for (int suit=0; suit<4; suit++)
        {
            for (int rank=0; rank<13; rank++)
            {
                std::cout << hands[player][suit][rank] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << "trump: " << trumpSuit << std::endl;
}

Card convertStringToCard(std::string cardString)
{
    Card returnCard;

    switch (cardString[0])
    {
    case '2':
        returnCard.rank = 2;
        break;
    case '3':
        returnCard.rank = 3;
        break;
    case '4':
        returnCard.rank = 4;
        break;
    case '5':
        returnCard.rank = 5;
        break;
    case '6':
        returnCard.rank = 6;
        break;
    case '7':
        returnCard.rank = 7;
        break;
    case '8':
        returnCard.rank = 8;
        break;
    case '9':
        returnCard.rank = 9;
        break;
    case 'T':
        returnCard.rank = 10;
        break;
    case 'J':
        returnCard.rank = 11;
        break;
    case 'Q':
        returnCard.rank = 12;
        break;
    case 'K':
        returnCard.rank = 13;
        break;
    case 'A':
        returnCard.rank = 14;
        break;
    }

    switch (cardString[1])
    {
    case 'C':
        returnCard.suit = 0;
        break;
    case 'D':
        returnCard.suit = 1;
        break;
    case 'H':
        returnCard.suit = 2;
        break;
    case 'S':
        returnCard.suit = 3;
        break;
    }

    return returnCard;
}

void dealCards(Card cardDeck[52])
{
    memset(hands, 0, sizeof(hands));
    memset(won, 0, sizeof(won));

    for (int card=0; card<10; card++)
    {
        for (int player=0; player<5; player++)
        {
            int index = card*5 + player;
            int suit = cardDeck[index].suit;
            int rank = cardDeck[index].rank-2;
            hands[player][suit][rank] = true;
        }
    }

    // Determine trump
    if (cardDeck[50].rank > cardDeck[51].rank)
    {
        trumpSuit = cardDeck[50].suit;
    }
    else if (cardDeck[50].rank > cardDeck[51].rank)
    {
        trumpSuit = cardDeck[51].suit;
    }
    else
    {
        if (cardDeck[50].suit > cardDeck[51].suit)
        {
            trumpSuit = cardDeck[50].suit;
        }
        else
        {
            trumpSuit = cardDeck[51].suit;
        }
    }

    currentPlayer = 0;
}



void processStringDeck(std::string deckStrings[])
{
    Card cardDeck[52];
    for (int cnt=0; cnt<52; cnt++)
    {
        cardDeck[cnt] = convertStringToCard(deckStrings[cnt]);
    }

    dealCards(cardDeck);
}

void determineLead(int& suit, int& rank, bool& trump)
{
    trump = false;
    for (rank=12; rank>=0; rank--)
    {
        int currentRankCount = 0;
        int lastSuit;
        for (suit=0; suit<4; suit++)
        {
            if (hands[currentPlayer][suit][rank])
            {
                lastSuit = suit;
                currentRankCount++;
            }
        }
        if (currentRankCount == 1)
        {
            suit = lastSuit;
            if (suit == trumpSuit)
            {
                trump = true;
            }
            hands[currentPlayer][suit][rank] = false;
            return;
        }
        if (currentRankCount > 1)
        {
            if (hands[currentPlayer][trumpSuit][rank])
            {
                suit = trumpSuit;
                trump = true;
            }
            else
            {
                suit = lastSuit;
            }
            hands[currentPlayer][suit][rank] = false;
            return;
        }
    }
    if (suit == trumpSuit)
    {
        trump = true;
    }
    hands[currentPlayer][suit][rank] = false;
}

void determineCardToPlay(const int player, const int playedSuit, int& suit, int& rank, bool& trump)
{
    suit = playedSuit;
    trump = false;
    for (rank=12; rank>=0; rank--)
    {
        if (hands[player][suit][rank])
        {
            if (suit == trumpSuit)
            {
                trump = true;
            }
            hands[player][suit][rank] = false;
            return;
        }
    }

    for (rank=12; rank>=0; rank--)
    {
        if (hands[player][trumpSuit][rank])
        {
            suit = trumpSuit;
            trump = true;
            hands[player][suit][rank] = false;
            return;
        }
    }

    for (rank=12; rank>=0; rank--)
    {
        for (suit=3; suit>=0; suit--)
        {
            if (hands[player][suit][rank])
            {
                hands[player][suit][rank] = false;
                return;
            }
        }
    }
    exit(1);
}

void determineWinner(const int playedSuit, const int suitsPlayed[5], const int ranksPlayed[5],
                     const bool trumpsPlayed[5])
{
    int winner = -1;
    bool trump = false;
    int highestRank = -1;
    for (int player=0; player<5; player++)
    {
        if (trumpsPlayed[player])
        {
            if (ranksPlayed[player] > highestRank)
            {
                winner = player;
                highestRank = ranksPlayed[player];
            }
        }
    }
    if (winner == -1)
    {
        for (int player=0; player<5; player++)
        {
            if (playedSuit == suitsPlayed[player])
            {
                if (ranksPlayed[player] > highestRank)
                {
                    winner = player;
                    highestRank = ranksPlayed[player];
                }
            }
        }
    }
    /*
    for (int player=0; player<5; player++)
    {

        std::cout << "p: " << player << ((player == currentPlayer) ? "C" : " ")
                  << ((player == winner) ? "W" : " ")
                  << " s: " << suitsPlayed[player] << " r: " << std::setw(2) << ranksPlayed[player]
                  << " t: " << trumpsPlayed[player] << std::endl;
    }
    */
    currentPlayer = winner;

    for (int player=0; player<5; player++)
    {
        won[winner][suitsPlayed[player]][ranksPlayed[player]] = true;
    }
//    std::cout << std::endl;
}

void playCards()
{
    int suitsPlayed[5];
    int ranksPlayed[5];
    bool trumpsPlayed[5];

//    dumpHands();

    for (int cards=0; cards<10; cards++)
    {
        int suit;
        int rank;
        bool trump;
        determineLead(suit, rank, trump);
        suitsPlayed[currentPlayer] = suit;
        ranksPlayed[currentPlayer] = rank;
        trumpsPlayed[currentPlayer] = trump;
        int playedSuit = suit;
        for (int player=0; player<5; player++)
        {
            if (player != currentPlayer)
            {
                determineCardToPlay(player, playedSuit, suit, rank, trump);
                suitsPlayed[player] = suit;
                ranksPlayed[player] = rank;
                trumpsPlayed[player] = trump;
            }
        }

        determineWinner(playedSuit, suitsPlayed, ranksPlayed, trumpsPlayed);

        //       dumpHands();
    }
}

void displayScores()
{
    int score=0;
    for (int rank=0; rank<13; rank++)
    {
        if (won[4][2][rank])
        {
            score += rank + 2;
        }
    }
    std::cout << std::setw(3) << score;

    for (int player=0; player<4; player++)
    {
        score=0;
        for (int rank=0; rank<13; rank++)
        {
            if (won[player][2][rank])
            {
                score += rank + 2;
            }
        }
        std::cout << std::setw(3) << score;
    }
    std::cout << std::endl;
}

int main()
{
    std::string nextCard;
    int deckCounter = 0;
    std::string cardStrings[52];
    while (std::cin.good())
    {
        std::cin >> nextCard;
        if (std::cin.fail())
        {
            return 0;
        }
        if (nextCard == "#")
        {
            return 0;
        }
        if (deckCounter == 51)
        {
            processStringDeck(cardStrings);
            playCards();
            displayScores();
            deckCounter = 0;
        }
        else
        {
            cardStrings[deckCounter++] = nextCard;
        }
    }
    return 0;
}
