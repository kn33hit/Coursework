#include "Blackjack.h"

#define DEFAULT_MONEY 100
/*
 * default (no-arg) constructor: sets up a game with one player:
 *     "Jane", starting with $100
 */
Blackjack::Blackjack()
{
  // make player Jane and put he on player vector
  Player jane("Jane", DEFAULT_MONEY);
  m_players.push_back(jane);

  // make dealer
  m_dealer = Player("DEALER", DEFAULT_MONEY);
}

/*
 * Standard constructor: sets up a game with a collection of players,
 *   number specified by numPlayers, with given names.
 *   Each player is given a default $100
 */
Blackjack::Blackjack(char *names[], int numPlayers)
{
  // puts player into vector one by one
  for(int x = 0; x < numPlayers;x++)
    {
      //make a player
      Player person(names[x], DEFAULT_MONEY);
      //adds that player to the vector
      m_players.push_back(person);
    }

  // make dealer
  m_dealer = Player("DEALER", DEFAULT_MONEY);
}

/*
 * Return the number of registered players
 */
int Blackjack::GetNumPlayers()
{
  //uses the vector and just find the size of the vector
  int numPlayers = m_players.size();
  return numPlayers;
}

/*
 * Return the given player's name
 */
char* Blackjack::GetPlayerName(int player)
{
  // get the player
  Player person = m_players[player];
  // get name using player
  char[] name = person.GetName();
  return name;
}

/*
 * Return the given player's pool of available funds
 */
int Blackjack::GetPlayerFunds(int player)
{
  // get the player
  Player person = m_players[player];
  // get the funds
  int funds = person.GetFunds();
  return funds;
}

/*
 * Set the given player's pool of funds available for betting
 */
void Blackjack::SetPlayerFunds(int player, int amt)
{
  // get the player
  Player person = m_players[player];
  // set the funds
  person.SetFunds(amt);
}

/*
 * Set how much the player wants to bet in current round.
 * This must be compared against available funds, and rejected
 * if funds are insufficient.
 */
bool Blackjack::SetPlayerBet(int player, int amt)
{
  // get the player
  Player person = m_players[player];
  // gets the funds
  int personFunds = GetPlayerFunds(player);

  //check enough funds
  if(personFunds < amt)
    {
      // not enough
      return false;
    }
  // enough $ so set bet
  person.SetBet(amt);
  return true;
}

/*
 * Create a fresh Deck, shuffle it, and deal out 2 cards
 * to each player and the dealer, going around the circle
 * one card at a time, like most card games.
 */
void Blackjack::NewDeal()
{
  //loops make suit
  for(int suit = 0; suit <= 4; suit++)
    {
      // loops make rank
      for(int rank = 0; rank <= 13; rank++)
	{
	  // makes card
	  Card piece(rank, suit);
	  //puts card into vector
	  m_card.push_back(piece);
	}
    }
  // makes deck using cards
  Deck deck(m_cards);
  m_deck = deck;

  //shuffle the deck
  m_deck.Shuffle();

  //finds number of players
  numPlayers = m_players.size();

  //deal 2 cards per person
  for(int give = 0; give < 2; give++)
    {
      //goes thro each player
      for(int person = 0; person < numPlayers; person++)
	{
	  // gets a card from the deck
	  Card card = m_deck.DealCard();
	  // gets the player	  
	  Player currPlayer = m_players[person];
	  // get player hand
	  Hand handCards = currPlayer.GetHand();
	  // gives card to the player's hand
	  handCards.AddCard(card);
	}
    }
  // new deal done
}

/*
 * Display the player's hand
 * Note: just display cards; no label at start, no endl at end.
 */
void Blackjack::OutputPlayerHand(int player)
{
  // gets the player	  
  Player currPlayer = m_players[person];
  // get player hand
  Hand handCards = currPlayer.GetHand();
  // prints the hand
  handCards.PrintHand();
}

/*
 * Display the dealer's hand, hiding the hole card (the second card)
 * So, it should display something like "Ace of Spades, [hidden card]"
 * Note: just display cards; no label at start, no endl at end.
 */
void Blackjack::OutputDealerHand()
{
  Hand handCard = m_dealer.GetHand();
  cout << handCard.PrintHand();
}

/*
 * Deal the player another card.
 * Preconditions:
 *   Player must not have gone bust earlier; this is a precondition
 *   you are required to check for!
 * Postconditions:
 *   returns true if player is busted due to new card; false otherwise.
 *   (HINT: it would probably be helpful to record that the player went
 *    bust in some object.)
 */
bool Blackjack::HitPlayer(int player)
{
  // get the player
  Player currPlayer = m_players[player];

  // checks if the player busted
  if(currPlayer.IsBust())
    {
      return true;
    }

  // get the card
  Card cardHit = m_deck.DealCard();
  // get player hand
  Hand currHand = currPlayer.GetHand();
  // put card in player hand
  currHand.AddCard(cardHit);

  // checks if the player busted
  if(currHand.TotalValue > 21)
    {
      // make player busted
      currPlayer.GotBusted();
      return true;
    }

  // player never busted
  return false;
}

/*
 * Deal to the Dealer's hand until she stops (because she has
 * 17 or higher).
 * Postconditions:
 *   Dealer might have gone bust, or might have blackjack (in which
 *   case no cards were taken.)
 */
void DealerPlay()
{
  // gets the dealer's hand
  Hand dealerHand = m_dealer.GetHand();

  // check if the dealer had blackjack
  if(dealerHand.TotalValue() == 21)
    {
      cout << endl; //had to do something
    }
  else
    {
      // no blackjack so try to play
      while(dealerHand.TotalValue() < 17 && dealer.IsBust())
	{
	  // dealer plays until reach 17 or higher
	  
	  // gets next card to dealer
	  Card nxtCard = m_deck.DealCard();
	  dealerHand.AddCard(nxtCard);

	  // check if the dealer busted
	  if(dealerHand.TotalValue() > 21)
	    {
	      // make player busted
	      m_dealer.GotBusted();
	    }

	}// end while loop
    }
}

/*
 * At end of game, settle bet for given player:
 *   Compare player's hand to 
 */
int Blackjack::SettlePlayerBet(int player)
{
  // get the player
  Player currPlayer = m_players[player];

  // get player's total value
  int cardVal = currPlayer.GetTotalValue();

  // get dealer card value
  int dealerVal = m_dealer.GetTotalValue();

  if(currPlayer.IsBust() && m_dealer.IsBust())
    {
      // both busted so its a tie. no money gain or lost
      cout << currPlayer.GetName() << " has busted--tie" << endl;
    }

  else if(currPlayer.IsBust())
    {
      // player bust but dealer not. dealer win
      cout << currPlayer.GetName() << " has busted--Dealer wins" << endl;
      // gets money from fund
      currPlayer.WithdrawFunds(currPlayer.getBet());
    }

  else if(m_dealer.IsBust())
    {
      // dealer bust. player win
      cout << currPlayer.GetName() << " has " << cardVal;
      cout << "--" << currPlayer.GetName() << " wins" << endl;
      // gets winning money
      currPlayer.DepositFunds(currPlayer.getBet());
    }

  else if(cardVal > dealerVal)
    {
      // player wins. higher number
      cout << currPlayer.GetName() << " has " << cardVal << "--";
      cout << currPlayer.GetName() << " wins" << endl;

      // get winning money
      currPlayer.DepositFiunds(currPlayer.getBet());
    }

  else if(cardVal == dealerVal)
    {
      // both have same values
      cout << currPlayer.GetName() << " has " << cardVal << "--";
      cout << currPlayer.GetName() << " ties" << endl;

      // no money gain or lost
    }
  else if(dealerVal > cardVal)
    {
      // dealer closer to 21
      cout << currPlayer.GetName() << " has " << cardVal << "--";
      cout << currPlayer.GetName() << " lose" << endl;

      // player lost the bet money
      currPlayer.WithdrawFunds(currPlayer.getBet());
    }

  // sets all the bets to 0 again
  currPlayer.SetBet(0);
  return 0;
}
