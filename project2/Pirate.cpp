/********************************************************************
 * File: Pirate.cpp
 * Project: CMSC Project 2, Fall 2020
 * Author: Matthew Green
 * Date: 08/10/2020
 * Section: Lecture Section 30, Discussion section 33
 * E-mail: mgreen11@gl.umbc.edu
 * 
 * Description: Defines and implements the methods and constructer
 * from the Pirate.h header file
 *********************************************************************/

#include "Pirate.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

// constuctor
// isn't used in the actual program
Pirate::Pirate() {
    cout << "Pirate created" << endl;
}

// overloaded constructor
Pirate::Pirate(string name, int rating, string origin, string desc) {
    // sets the private variables from the header file equal to what the parameters are set to
    m_pirateName = name;
    m_pirateRating = rating;
    m_pirateOrigin = origin;
    m_pirateDesc = desc;
    m_pirateCargo = 0;
}
// accessor for GetName()
string Pirate::GetName() {
    return m_pirateName;
}
// accessor for GetRating()
int Pirate::GetRating() {
    return m_pirateRating;
}
// modifier for SetRating
// isn't used in the acutal program
void Pirate::SetRating(int rating) {
    if (rating > 0) {
        rating = m_pirateRating;
    } else {
        // if a rating in not defined, it defaults to 50
        m_pirateRating = 50;
    }
}
// accessor for GetOrigin()
string Pirate::GetOrigin() {
    return (m_pirateOrigin);
}
// accessor for GetSec()
string Pirate::GetDesc() {
    return (m_pirateDesc);
}
// modifier for SetCurShip()
void Pirate::SetCurShip(Ship curShip) {
    m_curShip = curShip;
}
// method to calculate how much treasure is gained
void Pirate::CalcTreasure(Ship enemyShip) {
    int treasureGained = 0; // declares an int to be used to add the treasure gained from winning a battle
    // calculates the treasure gained from the battle using the formula we were given
    treasureGained = (enemyShip.m_cannon + enemyShip.m_curToughness + enemyShip.m_speed) / 3;
    // adds the treasure ganed to the total cargo
    m_pirateCargo = treasureGained + m_pirateCargo;
}
// method to tell how the battles are conducted
void Pirate::Battle(Pirate enemyPirate, Ship enemyShip) {
    int shotHit = 0; // declares an int to be used to know how many shot hit the ship
    int random = 0; // declares an int to be used to calculate if the shot hit or missed
    // if statement to make sure that your ship has a toughness greater than 0
    if (m_curShip.m_curToughness > 0) {
        cout << "A naval battle of the ages comences between " << GetName() << " and " << enemyPirate.GetName() << endl;
        // while loop to keep the battle going until one of the ship toughness has gone below 1
        while ((m_curShip.m_curToughness >= 1) && (enemyShip.m_curToughness >= 1)) {
            // player fires first
            cout << GetName() << " fires " << m_curShip.m_cannon << " cannons!" << endl;
            // for loop to determine how many shots to calculate
            for (int i = 0; i < m_curShip.m_cannon; i++) {
                // sets random equal to some value between 1 and 100
                random = rand() % 100 + 1;
                // increases the amount of shot hit if random is lower than the pirate rating
                if (random < GetRating()) {
                    shotHit += 1;
                }
            }
            cout << shotHit << " shots hit!" << endl;
            // recalculates the enemy ship toughness to how many shot hit them
            enemyShip.m_curToughness = enemyShip.m_curToughness- shotHit;
            // reset the shot hit value
            shotHit = 0;
            cout << enemyPirate.GetName() << " fires " << enemyShip.m_cannon << " back!" << endl;
            for (int i = 0; i < enemyShip.m_cannon; i++) {
                random = rand() % 100 + 1;
                if (random > GetRating()) {
                    shotHit += 1;
                }
            }
            cout << shotHit << " shots hit!" << endl;
            // recalculates the toughness of your ship
            m_curShip.m_curToughness = m_curShip.m_curToughness - shotHit;
            shotHit = 0;
        }
        // you win if the enemy toughness goes below 1 and yours is above 1
        if ((m_curShip.m_curToughness >= 1) && (enemyShip.m_curToughness < 1)) {
            cout << "You Won!" << endl;
            // calls the CalcTreasure function for winning the battle
            CalcTreasure(enemyShip);
            // you lose if the enemy toughness is above 1 and yours below 1
        } else if ((m_curShip.m_curToughness < 1) && (enemyShip.m_curToughness >= 1)) {
            cout << "You Lost!" << endl;
            // sets your toughness to 0 incase your toughness went below 0 during the battle
            m_curShip.m_curToughness = 0;
            // recalculates your cargo due to losing the battle
            m_pirateCargo = m_pirateCargo / 2;
            // battle end in a draw if both ships toughness goes below 1 on the same turn
        } else {
            cout << "The battle ended in a stalemate" << endl;
            m_curShip.m_curToughness = 0;
        }
        // warns the player that they can't battle if their toughness is below 1
    } else {
        cout << "The seas are a dangerous place, repair your ship before trying to traverse" << endl;
    }
    // increase the days spent as a pirate
    m_pirateDays += 1;
}
// method that details how to repair the ship
void Pirate::RepairShip() {
    int days = 0; // declares int to keep track of how many days it took to repair the ship
    // message if user tries to repair ship when ship toughness is at max
    if (m_curShip.m_curToughness == m_curShip.m_toughness) {
        cout << m_curShip.m_type << " is already fully repaired" << endl;
    } else if (m_curShip.m_curToughness < m_curShip.m_toughness) {
        // while loop to increase how ship current toughness until equal to max toughness
        while (m_curShip.m_curToughness != m_curShip.m_toughness) {
            // increases the ship current toughness by 1
            m_curShip.m_curToughness += 1;
            // increase the days spent as a pires
            m_pirateDays += 1;
            // increases the value that keeps track of how many days it took to repair the ship
            days += 1;
        }
        cout << "It took " << days << " to repair your " << m_curShip.m_type << endl;
        // sets toughness to ship max toughness if current toughness was over the max toughness
    } else {
        cout << m_curShip.m_type << " toughness was returned to max" << endl;
        m_curShip.m_curToughness = m_curShip.m_toughness;
    }
}
// method that details how fleeing from enemy pirates works
void Pirate::Flee(Pirate enemyPirate, Ship enemyShip) {
    cout << "You attempted to escape from " << enemyPirate.GetName() << endl;
    // you are able to escape from enemy ship if your speed is greater than their speed
    if (m_curShip.m_speed > enemyShip.m_speed) {
        cout << "You were able to escape from " << enemyPirate.GetName() << endl;
        m_pirateDays += 1;
        // enter you into battle if your slower than the enemy ship
    } else {
        cout << "You were not able to escape from " << enemyPirate.GetName() << endl;
        Battle(enemyPirate, enemyShip);
    }
}
// method that displays all the stats and background of the player pirate
void Pirate::DisplayScore() {
    cout << "Name: " << GetName() << endl;
    cout << "Rating: " << GetRating() << endl;
    cout << "Country: " << GetOrigin() << endl;
    cout << "Description: " << GetDesc() << endl;
    cout << "Days Sailing: " << m_pirateDays << endl;
    cout << "Cargo Captured: " << m_pirateCargo << endl;
    cout << "Cargo Per Day: " << setprecision(3) << (double)m_pirateCargo/m_pirateDays << endl;
    cout << "Ship Type: " << m_curShip.m_type << endl;
    cout << "Ship Cannons: " << m_curShip.m_cannon << endl;
    cout << "Ship Current Toughness: " << m_curShip.m_curToughness << endl;
    cout << "Ship Max Toughness: " << m_curShip.m_toughness << endl;
    cout << "Ship Speed: " << m_curShip.m_speed << endl;
}