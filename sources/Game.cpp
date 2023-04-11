#include "player.hpp"
#include "game.hpp"
#include "card.hpp"
#include <algorithm>
#include <random>

namespace ariel {
using namespace  std;
    Game::Game(Player& player1, Player& player2):player1(player1),player2(player2)
    {
        this -> draws = 0;
        /// making the cards
        std::vector<Card> cards;

        for(int i=1; i<14;i++)
        {
            cards.push_back(Card(i,"diamond"));
            cards.push_back(Card(i,"heart"));
            cards.push_back(Card(i,"clover"));
            cards.push_back(Card(i,"leaf"));
        }

        /// making random prep
        std::random_device rd;
        std::mt19937 random_generator(rd());
        std::shuffle(cards.begin(), cards.end(), random_generator); /// shuffle the cards.

        /// split the cards for 2 players.
        for(unsigned int i=0 ; i<52 ; i+=2)
            {
            player1.add_card(cards[i]);
            player2.add_card(cards[i+1]);
            }

        }

        ///printing the last turn
        void Game::printLastTurn()
            {
                cout << logs.back();
            }

        ///play all the game.
        void Game::playAll()
            {
                while (player1.stacksize()>0 || player2.stacksize()>0)
                {
                    playTurn();
                }
            }

        /// printing the logs.
        void Game::printLog()
        {
            for (const auto& log : logs)
            {
                cout << log << endl;
            }
        }

        /// printing the winner if we have.
        void Game::printWiner()
        {
            if(player1.cardesTaken()>player2.cardesTaken())
            {
                cout<<player1.getName()+" won"<< endl;
            }
            else if(player1.cardesTaken()<player2.cardesTaken())
            {
                cout << player2.getName() + " won" << endl;
            }
            else
            {
                cout<< "there is a tie"<< endl;
            }

        }

        /// printing the status of the game.
        void Game::printStats()
        {
            int rounds = player1.get_numbers_rounds();
            double  draw_rate = double(draws)/double (rounds);
            cout << "number of ties :"<<draws << endl;
            cout << "rate of ties :"<<draw_rate << endl;
            cout << player1.to_string() <<endl;
            cout << player2.to_string() <<endl;
        }

        /// play round.
        void Game::playTurn()
        {
            /// same player at one game.
            if (&player1 == &player2)
            {
                throw std::runtime_error("The players are the same");
            }

            ///finish all the cards.
            if (player1.stacksize()==0 || player2.stacksize()==0)
            {
                throw "dont have cards";
            }

            Card player1_card(0,"a");///define card for player1
            Card player2_card(0,"a");///define card for player2
            bool tie = true;
            string log = "";
            int rounds = 0;
            int cards_to_winner = 0;
            while(tie)
            {
                tie = false;
                rounds++;
                if(player1.stacksize()>0)
                {
                    player1_card = player1.pull_card();
                    player2_card = player2.pull_card();
                    cards_to_winner +=2;
                    log += "Round number:" + ::to_string(player1.get_numbers_rounds() + 1)+"\n";
                    log += "player1 is:" +player1.getName() +","+ player1_card.to_String() +"\n";
                    log += "player2 is:"+ player2.getName() +","+ player2_card.to_String() +"\n";
                }
                /// we need to split the cards we have.
                else
                {
                    log += "we split the cards equals \n";
                    player1.play_round(cards_to_winner/2);
                    player2.play_round(cards_to_winner/2);
                    break;
                }
                /// check if there is a tie
                if(player1_card.get_number() == player2_card.get_number())
                {
                    tie = true;
                    this ->draws++; /// we have tie
                    log +="there is a tie \n";
                    if(player1.stacksize()>0)
                    {
                        player1.pull_card();///the card we put and dont see.
                        player2.pull_card();///the card we put and dont see.
                        cards_to_winner +=2;
                    }
                    /// we need to split the cards we have.
                    else
                    {
                        log += "we split the cards equals \n";
                        player1.play_round(cards_to_winner/2);
                        player2.play_round(cards_to_winner/2);
                        break;
                    }

                }
                /// As lose to 2 player1 < player2
                else if(player1_card.get_number()==1 && player2_card.get_number()==2)
                {
                    player2.play_round(cards_to_winner);
                    player1.play_round(0);
                    log += "this round " +player2.getName()+" wins"+"\n";
                    this -> logs.push_back(log);
                    break;
                }
                /// As lose to 2 player1 > player2
                else if(player1_card.get_number()==2 && player2_card.get_number()==1)
                {
                    player1.play_round(cards_to_winner);
                    player2.play_round(0);
                    log += "this round " +player1.getName()+" wins"+"\n";
                    this -> logs.push_back(log);
                    break;
                }
                ///card player1 bigger
                else if(player1_card.get_number()>player2_card.get_number())
                {

                    ///player2 has AC he wins
                    if(player2_card.get_number()==1)
                    {
                        player2.play_round(cards_to_winner);
                        player1.play_round(0);
                        log += "this round " +player2.getName()+" wins"+"\n";
                        this -> logs.push_back(log);
                        break;
                    }
                    else
                    {
                        player1.play_round(cards_to_winner);
                        player2.play_round(0);
                        log += "this round " +player1.getName()+" wins"+"\n";
                        this -> logs.push_back(log);
                        break;
                    }
                }
                /// card player2 bigger
                else if(player1_card.get_number()<player2_card.get_number())
                {
                    ///player1 has AC he wins
                    if(player1_card.get_number()==1)
                        {
                            player1.play_round(cards_to_winner);
                            player2.play_round(0);
                            log += "this round " +player1.getName()+" wins"+"\n";
                            this -> logs.push_back(log);
                            break;
                        }
                        ///player2 wins
                        else
                        {
                            player2.play_round(cards_to_winner);
                            player1.play_round(0);
                            log += "this round " +player2.getName()+" wins"+"\n";
                            this -> logs.push_back(log);
                            break;
                        }
                }
            }
    }
}