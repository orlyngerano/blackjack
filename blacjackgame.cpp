#include "cards.h"
#include "player.h"
#include <iostream>
#include <random>
#include <string>
#include <vector>

class BlackJack
{

public:
  enum GameRoundResult
  {
    PLAYER_BUSTED,
    DEALER_BUSTED,
    PLAYER_WON,
    DEALER_WON,
    DRAW
  };

  enum State
  {
    GAME_START,
    GAME_END,
    GAME_ROUND_START,
    GAME_ROUND_END,
    PLAYER_TURN,
    DEALER_TURN
  };

  BlackJack(Player player)
    : dealer("Anthony")
    , player(player)
    , state(GAME_START)
  {}

  void endGame() { state = State::GAME_END; }

  void endGameRound() { state = State::GAME_ROUND_END; }

  Player getDealer() { return dealer; }

  Player getPlayer() { return player; }

  State getState() { return state; }

  GameRoundResult getWinner()
  {
    unsigned char playerPoints = player.getCardsPoints();
    unsigned char dealerPoints = dealer.getCardsPoints();

    if (playerPoints > 21) {
      return GameRoundResult::PLAYER_BUSTED;
    } else if (dealerPoints > 21) {
      return GameRoundResult::DEALER_BUSTED;
    } else if (playerPoints > dealerPoints) {
      return GameRoundResult::PLAYER_WON;
    } else if (playerPoints < dealerPoints) {
      return GameRoundResult::DEALER_WON;
    } else {
      return GameRoundResult::DRAW;
    }
  }

  void playerHitCard()
  {
    if (state != State::PLAYER_TURN) {
      return;
    }

    Cards::Card card = getNextCardFromDeck();
    player.addCard(card);
    state = State::DEALER_TURN;

    dealersTurn();
  }

  void playerStand()
  {
    if (state != State::PLAYER_TURN) {
      return;
    }

    player.setBetOnCards(true);
    state = State::DEALER_TURN;

    dealersTurn();
  }

  void startGame()
  {
    setCardDeck();
    state = State::GAME_START;
  }

  void startGameRound()
  {

    player.emptyCards();
    dealer.emptyCards();
    player.setBetOnCards(false);
    dealer.setBetOnCards(false);

    state = State::GAME_ROUND_START;

    player.addCard(getNextCardFromDeck());
    dealer.addCard(getNextCardFromDeck());
    player.addCard(getNextCardFromDeck());
    dealer.addCard(getNextCardFromDeck());

    state = State::PLAYER_TURN;
  }

private:
  State state;
  Player dealer;
  Player player;
  std::vector<Cards::Card> cardDeck;
  unsigned char const DEALER_SOFTPOINTS = 17;

  void dealerHitCard() { dealer.addCard(getNextCardFromDeck()); }

  void dealersTurn()
  {
    if (state != State::DEALER_TURN) {
      return;
    }

    if (isDealerWantToHit()) {
      dealerHitCard();
    } else {
      dealer.setBetOnCards(true);
    }

    if (player.getCardsPoints() > 21 || dealer.getCardsPoints() > 21) {
      endGameRound();
    } else {
      if (player.isBetOnCards() && dealer.isBetOnCards()) {
        endGameRound();
      } else {
        if (player.isBetOnCards()) {
          dealersTurn();
        } else {
          state = State::PLAYER_TURN;
        }
      }
    }
  }

  Cards::Card getNextCardFromDeck()
  {
    if (cardDeck.empty()) {
      setCardDeck();
    }
    Cards::Card card = cardDeck.front();
    cardDeck.erase(cardDeck.begin());
    return card;
  }

  bool isDealerWantToHit()
  {
    return (dealer.getCardsPoints() < DEALER_SOFTPOINTS) ? true : false;
  }

  void setCardDeck()
  {
    cardDeck.clear();

    cardDeck.push_back(Cards::Card::clubs_ace);
    cardDeck.push_back(Cards::Card::clubs_two);
    cardDeck.push_back(Cards::Card::clubs_three);
    cardDeck.push_back(Cards::Card::clubs_four);
    cardDeck.push_back(Cards::Card::clubs_five);
    cardDeck.push_back(Cards::Card::clubs_six);
    cardDeck.push_back(Cards::Card::clubs_seven);
    cardDeck.push_back(Cards::Card::clubs_eight);
    cardDeck.push_back(Cards::Card::clubs_nine);
    cardDeck.push_back(Cards::Card::clubs_ten);
    cardDeck.push_back(Cards::Card::clubs_jack);
    cardDeck.push_back(Cards::Card::clubs_queen);
    cardDeck.push_back(Cards::Card::clubs_king);
    cardDeck.push_back(Cards::Card::diamonds_ace);
    cardDeck.push_back(Cards::Card::diamonds_two);
    cardDeck.push_back(Cards::Card::diamonds_three);
    cardDeck.push_back(Cards::Card::diamonds_four);
    cardDeck.push_back(Cards::Card::diamonds_five);
    cardDeck.push_back(Cards::Card::diamonds_six);
    cardDeck.push_back(Cards::Card::diamonds_seven);
    cardDeck.push_back(Cards::Card::diamonds_eight);
    cardDeck.push_back(Cards::Card::diamonds_nine);
    cardDeck.push_back(Cards::Card::diamonds_ten);
    cardDeck.push_back(Cards::Card::diamonds_jack);
    cardDeck.push_back(Cards::Card::diamonds_queen);
    cardDeck.push_back(Cards::Card::diamonds_king);
    cardDeck.push_back(Cards::Card::hearts_ace);
    cardDeck.push_back(Cards::Card::hearts_two);
    cardDeck.push_back(Cards::Card::hearts_three);
    cardDeck.push_back(Cards::Card::hearts_four);
    cardDeck.push_back(Cards::Card::hearts_five);
    cardDeck.push_back(Cards::Card::hearts_six);
    cardDeck.push_back(Cards::Card::hearts_seven);
    cardDeck.push_back(Cards::Card::hearts_eight);
    cardDeck.push_back(Cards::Card::hearts_nine);
    cardDeck.push_back(Cards::Card::hearts_ten);
    cardDeck.push_back(Cards::Card::hearts_jack);
    cardDeck.push_back(Cards::Card::hearts_queen);
    cardDeck.push_back(Cards::Card::hearts_king);
    cardDeck.push_back(Cards::Card::spades_ace);
    cardDeck.push_back(Cards::Card::spades_two);
    cardDeck.push_back(Cards::Card::spades_three);
    cardDeck.push_back(Cards::Card::spades_four);
    cardDeck.push_back(Cards::Card::spades_five);
    cardDeck.push_back(Cards::Card::spades_six);
    cardDeck.push_back(Cards::Card::spades_seven);
    cardDeck.push_back(Cards::Card::spades_eight);
    cardDeck.push_back(Cards::Card::spades_nine);
    cardDeck.push_back(Cards::Card::spades_ten);
    cardDeck.push_back(Cards::Card::spades_jack);
    cardDeck.push_back(Cards::Card::spades_queen);
    cardDeck.push_back(Cards::Card::spades_king);

    shuffleDeck();
  }

  void shuffleDeck()
  {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(cardDeck.begin(), cardDeck.end(), std::default_random_engine(seed));
  }
};

class BlackJackConsole
{
  Player player;
  BlackJack blackJack;

public:
  BlackJackConsole(std::string playerName)
    : player(playerName)
    , blackJack(player)
  {}

  void play()
  {
    showGreetings();
    blackJack.startGame();

    while (blackJack.getState() != BlackJack::State::GAME_END) {
      if (askPlayerPlay()) {
        blackJack.startGameRound();
        while (blackJack.getState() != BlackJack::State::GAME_ROUND_END) {
          showPlayerCardMessage();
          if (askPlayerPlayToHitOrStand()) {
            blackJack.playerHitCard();
          } else {
            blackJack.playerStand();
          }
        }
        showPlayerCardMessage();
        showGameRoundResultMessage();
      } else {
        blackJack.endGame();
      }
    }

    showExitMessage();
  }

private:
  bool askPlayerPlayToHitOrStand()
  {
    std::cout << "Press 'h' for Hit and 's' for Stand" << std::endl;
    std::string keyInput;
    std::cin >> keyInput;
    if (keyInput == "h" || keyInput == "H") {
      return true;
    } else if (keyInput == "s" || keyInput == "S") {
      return false;
    } else {
      return askPlayerPlayToHitOrStand();
    }
  }

  bool askPlayerPlay()
  {
    std::cout << "Want to continue play? Press 'y' for yes and 'n' for no."
              << std::endl;
    std::string keyInput;
    std::cin >> keyInput;
    if (keyInput == "n" || keyInput == "N") {
      return false;
    } else if (keyInput == "y" || keyInput == "Y") {
      return true;
    } else {
      return askPlayerPlay();
    }
  }

  void showGreetings()
  {
    std::cout << "Black Jack Game" << std::endl;
    std::cout << "Welcome " << blackJack.getPlayer().getName() << std::endl;
    std::cout << "I am " << blackJack.getDealer().getName()
              << ", Your Dealer. Lets play!" << std::endl;
  }

  void showExitMessage()
  {
    std::cout << "Thanks for playing. Bye " << blackJack.getPlayer().getName()
              << std::endl;
  }

  void showPlayerCardMessage()
  {
    std::vector<Cards::Card> cards = blackJack.getPlayer().getCards();
    std::string message;
    for (auto const& card : cards) {
      message += Cards::getCardName(card) + "=" +
                 std::to_string((int)Cards::getCardValue(card)) + ",";
    }

    std::cout << "Your card in hand: " << message << std::endl;
  }

  void showGameRoundResultMessage()
  {
    std::cout << "-----Game Result-----" << std::endl;
    std::string winner;
    switch (blackJack.getWinner()) {
      case BlackJack::PLAYER_BUSTED:
        winner = "Player busted. Dealer Wins";
        break;
      case BlackJack::DEALER_BUSTED:
        winner = "Dealer busted. Player Wins";
        break;
      case BlackJack::PLAYER_WON:
        winner = "Player won. Player:" +
                 std::to_string((int)blackJack.getPlayer().getCardsPoints()) +
                 " Dealer:" +
                 std::to_string((int)blackJack.getDealer().getCardsPoints());
        break;
      case BlackJack::DEALER_WON:
        winner = "Dealer won. Dealer:" +
                 std::to_string((int)blackJack.getDealer().getCardsPoints()) +
                 " Player:" +
                 std::to_string((int)blackJack.getPlayer().getCardsPoints());
        break;
      case BlackJack::DRAW:
        winner = "Draw. Dealer:" +
                 std::to_string((int)blackJack.getDealer().getCardsPoints()) +
                 " Player:" +
                 std::to_string((int)blackJack.getPlayer().getCardsPoints());
        break;

      default:
        break;
    }

    std::cout << winner << std::endl;
  }
};

int
main(int argc, const char* argv[])
{

  BlackJackConsole blackJackConsole("Orlyn");
  blackJackConsole.play();

  return 0;
}