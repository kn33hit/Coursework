#include <vector>
#include "Player.h"
#include "Hand.h"
#include "Deck.h"

class Blackjack {
  public:
 
 
  /*
   * default (no-arg) constructor: sets up a game with one player:
   *   "Jane", starting with $100
   */
  Blackjack();

  /*
   * Standard constructor: sets up a game with a collection of players,
   *   number specified by numPlayers, with given names.
   *   Each player is given a default $100
   */
  Blackjack(char *names[], int numPlayers);
  /*
   * Return the number of registered players
   */
    
  int GetNumPlayers();
  /*
   * Return the given player's name
   */
    
  char *GetPlayerName(int player);
  /*
   * Return the given player's pool of available funds
   */
  
  int GetPlayerFunds(int player);
  /*
   * Set the given player's pool of funds available for betting
   */
  
  void SetPlayerFunds(int player, int amt);
  /*
   * Set how much the player wants to bet in current round.
   * This must be compared against available funds, and rejected
   * if funds are insufficient.
   * Postconditions:
   *   amount of bet is recorded for the player
   *   returns true if bet is valid; false if insufficient funds.
   */
  bool SetPlayerBet(int player, int amt);
  /*
   * Create a fresh Deck, shuffle it, and deal out 2 cards
   * to each player and the dealer, going around the circle
   * one card at a time, like most card games.
   */
  void NewDeal();
  /*
   * Display the player's hand
   * Note: just display cards; no label at start, no endl at end.
   */
  void OutputPlayerHand(int player);
  /*
   * Display the dealer's hand, hiding the hole card (the second card)
   * So, it should display something like "Ace of Spades, [hidden card]"
   * Note: just display cards; no label at start, no endl at end.
   */
  void OutputDealerHand();
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
  bool HitPlayer(int player);
  /*
   * Deal to the Dealer's hand until she stops (because she has
   * 17 or higher).
   * Postconditions:
   *   Dealer might have gone bust, or might have blackjack (in which
   *   case no cards were taken.)
   */
  void DealerPlay();
  /*
   * At end of game, settle bet for given player:
   *   Compare player's hand to 
   */
  int SettlePlayerBet(int player);
   
 private:

  /*
   * ADD YOUR DATA MEMBERS HERE
   * The following are just examples; feel free to modify or delete
   */
  int m_numberOfPlayer;
  std::vector<Player> m_player;
  
  Deck m_deck;
  Hand m_playerHand;
  Hand m_dealerHand;
  Player m_dealer;
  //std::vector<Player> m_player;
  
};
