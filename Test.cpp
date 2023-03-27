#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <string>
using namespace ariel;
using namespace std;

Player player1("moshe");
Player player2("shai");
Card card(7,"hart");
Game my_game(player1, player2);

TEST_CASE("check start of the game")
{
    CHECK_NOTHROW(player1.getName());
    CHECK_EQ(player1.stacksize(),26);
    CHECK_EQ(player2.stacksize(),26);
    CHECK_NOTHROW(my_game.playTurn());
    CHECK_EQ(player1.stacksize(),25);
    CHECK_EQ(player2.stacksize(),25);

    }
TEST_CASE("play all the turns")
{
    for (int i=0;i<15;i++) {
        my_game.playTurn(); }
    CHECK_EQ(player1.cardesTaken(),10);
    CHECK_EQ(player2.cardesTaken(),6);
    CHECK(card.get_sign() == "hart");
    CHECK_EQ(player1.stacksize(),11);
    CHECK_EQ(player2.stacksize(),8);
    CHECK_NOTHROW(my_game.playAll());
    CHECK_EQ(player1.stacksize(),0);
    CHECK_EQ(player2.stacksize(),0);
}


TEST_CASE("play all the turns")
{
    for (int i=0;i<26;i++) {
        my_game.playTurn(); }/// do all the turns cards must be 0
    CHECK_EQ(player1.cardesTaken(),20);
    CHECK_EQ(player2.cardesTaken(),32);
    CHECK_EQ(player1.stacksize(),0);
    CHECK_EQ(player2.stacksize(),0);

}

TEST_CASE("test the prints of game"){
    my_game.playAll();
    CHECK_NOTHROW(my_game.printLastTurn());
    CHECK_NOTHROW(my_game.printLog());
    CHECK_NOTHROW(my_game.printStats());
    CHECK_NOTHROW(my_game.printWiner());

}

TEST_CASE("check get and set function"){
    CHECK_NOTHROW(player1.setName("noam"));
    CHECK_NOTHROW(player1.getName());
    CHECK_NOTHROW(card.get_number());
    CHECK_EQ(player1.stacksize(),26);
}
