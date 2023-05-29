/********************************************************
** File: Media.cpp
** Project: CMSC 202 Project 5
** Author: Matthew Green and ???
** Date: 3/12/2020
** Email: mgreen11@umbc.edu
**
** Description: Defines all the function from the .h file
** to create the media. 
**********************************************************/
#include "Media.h"
using namespace std;

// Default constructor, not used
Media::Media() {

}

// Overloaded constructor 
Media::Media(string title, string artist, string type, int year, int rank) {
    SetTitle(title);
    SetArtist(artist);
    SetType(type);
    SetYear(year);
    SetRank(rank);
}

// Accessors
string Media::GetArtist() const {
    return m_artist;
}

string Media::GetTitle() const {
    return m_title;
}

string Media::GetType() const {
    return m_type;
}

int Media::GetYear() const {
    return m_year;
}

int Media::GetRank() const {
    return m_rank;
}

// Mutators
void Media::SetArtist(string artist) {
    m_artist = artist;
}

void Media::SetTitle(string title) {
    m_title = title;
}

void Media::SetType(string type) {
    m_type = type;
}

void Media::SetYear(int year) {
    m_year = year;
}

void Media::SetRank(int rank) {
    m_rank = rank;
}

// overloaded operator
ostream& operator<<(ostream& out, Media& m) {
    out << m.GetTitle() << " by " << m.GetArtist() << " from " << m.GetYear();
    return out;
}

// overloaded operator
bool Media::operator<(const Media& m) {
    if (m.GetYear() < m.GetYear()) {
        return true;
    } else {
        return false;
    }
}