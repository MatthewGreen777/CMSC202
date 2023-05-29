#include <iostream>
#include <string>
using namespace std;

#ifndef MEDIA_H
#define MEDIA_H

class Media{
 public:
  //Name: Media - Default Constructor
  //Precondition: None
  //Postcondition: Creates a default media
  Media();
  //Name: Media - Overloaded Constructor
  //Precondition: Requires title, artist, type, year and rank
  //Postcondition: Creates a media entry based on passed parameters
  Media(string title, string artist, string type, int year, int rank );

  //Name: Mutators and Accessors
  //Precondition: None
  //Postcondition: Sets and Gets private member variables
  string GetTitle()const; // return title
  string GetArtist()const; // return artist
  string GetType()const; //return type
  int GetYear()const; // return year
  int GetRank()const; // return rank (1-100 from that year)
  void SetTitle(string title);
  void SetArtist(string artist);
  void SetType(string type);
  void SetYear(int year);
  void SetRank(int rank);
  //Name: Overloaded << operator
  //Precondition: media available
  //Postcondition: Returns output stream including title by artist from year
  friend ostream& operator<<(ostream& out, Media& m);
  //Name: Overloaded Relational Operator (<)
  //Precondition: Two media objects required
  //Postcondition: if passed media's year is less than first, return true else false
  bool operator<(const Media& m);
private:
  string m_title; //Title of media
  string m_artist; //Artist of media
  string m_type; //Type of media (music or podcast)
  int m_year; //Year of release
  int m_rank; //Rank 1-100 from that year
};

#endif
