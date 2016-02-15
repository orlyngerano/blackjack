
#include <iostream>
#include <string>
#include <vector>
#include <random>


namespace Cards {
    
    enum Card{
        no_card=0x00,
        clubs_ace=0x01,clubs_two=0x02,clubs_three=0x03,clubs_four=0x04,clubs_five=0x05,clubs_six=0x06,clubs_seven=0x07,clubs_eight=0x08,clubs_nine=0x09,clubs_ten=0x0A,clubs_jack=0x0B,clubs_queen=0x0C,clubs_king=0x0D,
        diamonds_ace=0x11,diamonds_two=0x12,diamonds_three=0x13,diamonds_four=0x14,diamonds_five=0x15,diamonds_six=0x16,diamonds_seven=0x17,diamonds_eight=0x18,diamonds_nine=0x19,diamonds_ten=0x1A,diamonds_jack=0x1B,diamonds_queen=0x1C,diamonds_king=0x1D,
        hearts_ace=0x21,hearts_two=0x22,hearts_three=0x23,hearts_four=0x24,hearts_five=0x25,hearts_six=0x26,hearts_seven=0x27,hearts_eight=0x28,hearts_nine=0x29,hearts_ten=0x2A,hearts_jack=0x2B,hearts_queen=0x2C,hearts_king=0x2D,
        spades_ace=0x31,spades_two=0x32,spades_three=0x33,spades_four=0x34,spades_five=0x35,spades_six=0x36,spades_seven=0x37,spades_eight=0x38,spades_nine=0x39,spades_ten=0x3A,spades_jack=0x3B,spades_queen=0x3C,spades_king=0x3D
    };
    
    
    
    std::string getCardName(Card card){
        std::string name;
        switch(card){
            case clubs_ace:
                name="ace of clubs";
                break;
            case clubs_two:
                name="two of clubs";
                break;
            case clubs_three:
                name="three of clubs";
                break;
            case clubs_four:
                name="four of clubs";
                break;
            case clubs_five:
                name="five of clubs";
                break;
            case clubs_six:
                name="six of clubs";
                break;
            case clubs_seven:
                name="seven of clubs";
                break;
            case clubs_eight:
                name="eight of clubs";
                break;
            case clubs_nine:
                name="nine of clubs";
                break;
            case clubs_ten:
                name="ten of clubs";
                break;
            case clubs_jack:
                name="jack of clubs";
                break;
            case clubs_queen:
                name="queen of clubs";
                break;
            case clubs_king:
                name="king of clubs";
                break;
            case diamonds_ace:
                name="ace of diamonds";
                break;
            case diamonds_two:
                name="two of diamonds";
                break;
            case diamonds_three:
                name="three of diamonds";
                break;
            case diamonds_four:
                name="four of diamonds";
                break;
            case diamonds_five:
                name="five of diamonds";
                break;
            case diamonds_six:
                name="six of diamonds";
                break;
            case diamonds_seven:
                name="seven of diamonds";
                break;
            case diamonds_eight:
                name="eight of diamonds";
                break;
            case diamonds_nine:
                name="nine of diamonds";
                break;
            case diamonds_ten:
                name="ten of diamonds";
                break;
            case diamonds_jack:
                name="jack of diamonds";
                break;
            case diamonds_queen:
                name="queen of diamonds";
                break;
            case diamonds_king:
                name="king of diamonds";
                break;
            case hearts_ace:
                name="ace of hearts";
                break;
            case hearts_two:
                name="two of hearts";
                break;
            case hearts_three:
                name="three of hearts";
                break;
            case hearts_four:
                name="four of hearts";
                break;
            case hearts_five:
                name="five of hearts";
                break;
            case hearts_six:
                name="six of hearts";
                break;
            case hearts_seven:
                name="seven of hearts";
                break;
            case hearts_eight:
                name="eight of hearts";
                break;
            case hearts_nine:
                name="nine of hearts";
                break;
            case hearts_ten:
                name="ten of hearts";
                break;
            case hearts_jack:
                name="jack of hearts";
                break;
            case hearts_queen:
                name="queen of hearts";
                break;
            case hearts_king:
                name="king of hearts";
                break;
            case spades_ace:
                name="ace of spades";
                break;
            case spades_two:
                name="two of spades";
                break;
            case spades_three:
                name="three of spades";
                break;
            case spades_four:
                name="four of spades";
                break;
            case spades_five:
                name="five of spades";
                break;
            case spades_six:
                name="six of spades";
                break;
            case spades_seven:
                name="seven of spades";
                break;
            case spades_eight:
                name="eight of spades";
                break;
            case spades_nine:
                name="nine of spades";
                break;
            case spades_ten:
                name="ten of spades";
                break;
            case spades_jack:
                name="jack of spades";
                break;
            case spades_queen:
                name="queen of spades";
                break;
            case spades_king:
                name="king of spades";
                break;
            default:
                break;
        }
        return name;
    }
    
    unsigned char getCardValue(Card card){
        unsigned char unmaskCard = 0x0f & card;
        return unmaskCard > 10 ? 10:unmaskCard;
    }
}


class Player{
    std::string name;
    std::vector<Cards::Card> cards;
    bool betOnCards;
public:
    Player(std::string name): name(name){}
    
    void addCard(Cards::Card card){
        cards.push_back(card);
    }
    
    void emptyCards(){
        cards.clear();
    }
    
    std::vector<Cards::Card> getCards(){
        return cards;
    }
    
    unsigned char getCardsPoints(){
        unsigned char points=0;
        for(auto const& card: cards){
            points+=getCardValue(card);
        }
        return points;
    }
    
    std::string getName(){
        return name;
    }
    
    bool isBetOnCards(){
        return betOnCards;
    }
    
    void setBetOnCards(bool betOnCards){
        this->betOnCards=betOnCards;
    }
};


class BlackJack{

    
public:
    
    enum GameRoundResult{
        PLAYER_BUSTED,
        DEALER_BUSTED,
        PLAYER_WON,
        DEALER_WON,
        DRAW
    };
    
    enum State{
        GAME_START,
        GAME_END,
        GAME_ROUND_START,
        GAME_ROUND_END,
        PLAYER_TURN,
        DEALER_TURN
    };
    
    BlackJack(Player player): dealer("Anthony"), player(player), state(GAME_START){
       
    }
    

    void endGame(){
        state=State::GAME_END;
    }
    
    void endGameRound(){
        state=State::GAME_ROUND_END;
    }
    
    Player getDealer(){
        return dealer;
    }
    
    Player getPlayer(){
        return player;
    }
    
    State getState(){
        return state;
    }
    
    GameRoundResult getWinner(){
        unsigned char playerPoints = player.getCardsPoints();
        unsigned char dealerPoints = dealer.getCardsPoints();
        
        if(playerPoints > 21){
            return GameRoundResult::PLAYER_BUSTED;
        }else if(dealerPoints > 21){
            return GameRoundResult::DEALER_BUSTED;
        }else if(playerPoints > dealerPoints){
            return GameRoundResult::PLAYER_WON;
        }else if(playerPoints < dealerPoints){
            return GameRoundResult::DEALER_WON;
        }else{
            return GameRoundResult::DRAW;
        }
    }
    
    void playerHitCard(){
        if(state!=State::PLAYER_TURN){
            return;
        }
        
        Cards::Card card = getNextCardFromDeck();
        player.addCard(card);
        state=State::DEALER_TURN;
        
        dealersTurn();
    }
    
    void playerStand(){
        if(state!=State::PLAYER_TURN){
            return;
        }
        
        player.setBetOnCards(true);
        state=State::DEALER_TURN;
        
        dealersTurn();
    }
    
    void startGame(){
        setCardDeck();
        state=State::GAME_START;
    }
    
    void startGameRound(){
        
        player.emptyCards();
        dealer.emptyCards();
        player.setBetOnCards(false);
        dealer.setBetOnCards(false);
        
        state=State::GAME_ROUND_START;
        
        player.addCard(getNextCardFromDeck());
        dealer.addCard(getNextCardFromDeck());
        player.addCard(getNextCardFromDeck());
        dealer.addCard(getNextCardFromDeck());
        
        state=State::PLAYER_TURN;
    }
    
private:
    State state;
    Player dealer;
    Player player;
    std::vector<Cards::Card> cardDeck;
    unsigned char const DEALER_SOFTPOINTS = 17;
    
    
    void dealerHitCard(){
        dealer.addCard(getNextCardFromDeck());
    }
    
    void dealersTurn(){
        if(state!=State::DEALER_TURN){
            return;
        }
        
        if(isDealerWantToHit()){
            dealerHitCard();
        }else{
            dealer.setBetOnCards(true);
        }
        
        if(player.getCardsPoints()>21 || dealer.getCardsPoints()>21){
            endGameRound();
        }else{
            if(player.isBetOnCards() && dealer.isBetOnCards()){
                endGameRound();
            }else{
                if(player.isBetOnCards()){
                    dealersTurn();
                }else{
                    state=State::PLAYER_TURN;
                }
            }
        }
    }
    
    Cards::Card getNextCardFromDeck(){
        if(cardDeck.empty()){
            setCardDeck();
        }
        Cards::Card card = cardDeck.front();
        cardDeck.erase(cardDeck.begin());
        return card;
    }
    

    
    bool isDealerWantToHit(){
        return (dealer.getCardsPoints() < DEALER_SOFTPOINTS) ? true : false;
    }
    
    
    void setCardDeck(){
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
    
    
    void shuffleDeck(){
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle(cardDeck.begin(), cardDeck.end(), std::default_random_engine(seed));
    }
    
    
};


class BlackJackConsole{
    Player player;
    BlackJack blackJack;
public:
    BlackJackConsole(std::string playerName):player(playerName),blackJack(player){
    }
    
    void play(){
        showGreetings();
        blackJack.startGame();
        
        while(blackJack.getState() != BlackJack::State::GAME_END){
            if(askPlayerPlay()){
                blackJack.startGameRound();
                while(blackJack.getState() != BlackJack::State::GAME_ROUND_END){
                   showPlayerCardMessage();
                   if(askPlayerPlayToHitOrStand()){
                     blackJack.playerHitCard();
                   }else{
                     blackJack.playerStand();
                   }
                }
                showPlayerCardMessage();
                showGameRoundResultMessage();
            }else{
                blackJack.endGame();
            }
         }
        
        showExitMessage();
    }
    
    
    
private:
    
    bool askPlayerPlayToHitOrStand(){
        std::cout << "Press 'h' for Hit and 's' for Stand"<< std::endl;
        std::string keyInput;
        std::cin >> keyInput;
        if(keyInput == "h" || keyInput == "H"){
            return true;
        }else if(keyInput == "s" || keyInput == "S"){
            return false;
        }else{
            return askPlayerPlayToHitOrStand();
        }
    }
    
    bool askPlayerPlay(){
        std::cout << "Want to continue play? Press 'y' for yes and 'n' for no." << std::endl;
        std::string  keyInput;
        std::cin >> keyInput;
        if(keyInput == "n" || keyInput == "N"){
            return false;
        }else if(keyInput == "y" || keyInput == "Y"){
            return true;
        }else{
            return askPlayerPlay();
        }
    }
    
    void showGreetings(){
        std::cout << "Black Jack Game" << std::endl;
        std::cout << "Welcome "<< blackJack.getPlayer().getName() << std::endl;
        std::cout << "I am "<< blackJack.getDealer().getName() << ", Your Dealer. Lets play!" << std::endl;
    }
    
    void showExitMessage(){
        std::cout << "Thanks for playing. Bye "<< blackJack.getPlayer().getName() << std::endl;
    }
    

    void showPlayerCardMessage(){
        std::vector<Cards::Card> cards = blackJack.getPlayer().getCards();
        std::string message;
        for(auto const& card: cards){
            message+=getCardName(card)+"="+std::to_string((int)getCardValue(card))+",";
        }
        
        std::cout << "Your card in hand: "<< message << std::endl;
    }
    
    void showGameRoundResultMessage(){
        std::cout << "-----Game Result-----"<< std::endl;
        std::string winner;
        switch(blackJack.getWinner()){
            case BlackJack::PLAYER_BUSTED:
                winner="Player busted. Dealer Wins";
                break;
            case BlackJack::DEALER_BUSTED:
                winner="Dealer busted. Player Wins";
                break;
            case BlackJack::PLAYER_WON:
                winner="Player won. Player:"+std::to_string((int)blackJack.getPlayer().getCardsPoints())+" Dealer:"+std::to_string((int)blackJack.getDealer().getCardsPoints());
                break;
            case BlackJack::DEALER_WON:
                winner="Dealer won. Dealer:"+std::to_string((int)blackJack.getDealer().getCardsPoints())+" Player:"+ std::to_string((int)blackJack.getPlayer().getCardsPoints());
                break;
            case BlackJack::DRAW:
                winner="Draw. Dealer:"+std::to_string((int)blackJack.getDealer().getCardsPoints())+" Player:"+ std::to_string((int)blackJack.getPlayer().getCardsPoints());
                break;
                
            default:
                break;
        }
        
        std::cout << winner << std::endl;
      
    }
};

int main(int argc, const char * argv[]) {
   
    BlackJackConsole blackJackConsole("Orlyn");
    blackJackConsole.play();
    
    return 0;
}
