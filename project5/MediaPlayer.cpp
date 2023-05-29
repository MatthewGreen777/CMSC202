/********************************************************
** File: MediaPlayer.cpp
** Project: CMSC 202 Project 5
** Author: Matthew Green and ???
** Date: 03/12/2020
** Email: mgreen11@umbc.edu
**
** Description: Defines all the function in the .h file
** to create the media player
**********************************************************/
#include "MediaPlayer.h"
using namespace std;

// Default constructor, not used
MediaPlayer::MediaPlayer() {
    string filename = " "; // decalred string
    cout << "Please enter the name of file (include file extention)" << endl;
    cin >> filename; // user enter file name
    if (cin.fail()) {
        cin.clear();
        cin.ignore(256, '\n');
        filename = " ";
    }
    LoadCatalog(filename); // reads in data from file
    cout << "Welcome to UMBC Media Player" << endl;
    cout << m_mediaCatalog.size() << " media files loaded" << endl;
}

// Overloaded constructor
MediaPlayer::MediaPlayer(string filename) {
    LoadCatalog(filename); // reads in everthing from file
    cout << "Welcome to UMBC Media Player" << endl;
    cout << m_mediaCatalog.size() << " media files loaded" << endl;
}

// Destructor
MediaPlayer::~MediaPlayer() {
    // loop to deleate everything in vector
    for (unsigned int i = 0; i < m_mediaCatalog.size(); i++) {
        delete m_mediaCatalog.at(i);
    }
    // loop to delete everything in vector
    for (int i = 0; i < m_playList.Size(); i++) {
        delete m_playList.At(i);
    }
}

// loads evertyhing from file
void MediaPlayer::LoadCatalog(string filename) {
    // declare 5 strings to hold media data
    string title  = " ";
    string artist = " ";
    string type = " ";
    string year = " ";
    string rank = " ";
    ifstream open(filename); // opens the file
    // while loop to read file
    while(getline(open, title, ';')) {
        // set the data in the strings
        getline(open, artist, ';');
        getline(open, type, ';');
        getline(open, year, ';');
        getline(open, rank, '\n');
        // create new media with data obtained from file
        Media *media = new Media(title, artist, type, stoi(year), stoi(rank));
        m_mediaCatalog.push_back(media); // add element to vector
    }
    open.close(); // closes the file
}

// imports the data from a file to a playlist
void MediaPlayer::ImportPlaylist() {
    ClearPlaylist();
    string filename = " "; // declare string to hold filename
    // declare 5 strings to hold media data
    string title  = " ";
    string artist = " ";
    string type = " ";
    string year = " ";
    string rank = " ";
    cout << "What is the name of the playlist you wish to import? (add file extention)" << endl;
    cin >> filename;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(256, '\n');
        filename = " ";
    }
    ifstream open(filename); // open file to be read
    // loop to read through file
    while (getline(open, title, ';')) { 
        // set the data in the strings
        getline(open, artist, ';');
        getline(open, type, ';');
        getline(open, year, ';');
        getline(open, rank, '\n');
        // create new media with data obtained from file
        Media *media = new Media(title, artist, type, stoi(year), stoi(rank));
        if (m_playList.IsFull()) {
            delete media;
        } else {
            m_playList.Enqueue(media); // add media to queue
        }
    }
    if (m_playList.Size() <= 0) { // no playlist is created if no data was added
        cout << "There was no data to import" << endl;
    } else { // add playlist if there was any data
        m_playLists.push_back(m_playList);
        m_playlistNames.push_back(filename);
        cout << "Playlist imported with " << m_playList.Size() << " media files" << endl;;
    }
}

// Exports the data from a playlist to a file
void MediaPlayer::ExportPlaylist() {
    int numberPlayList = 0; // declare int to choose which playlist to export
    if (m_playlistNames.size() <= 0) { // checks if there are any playlists
        cout << "There are no playlists to export" << endl;
    } else {
        cout << "Which playlist do you want to export?" << endl;
        // loop to name all playlist that exists
        for (unsigned int i = 0; i < m_playlistNames.size(); i++) {
            cout << (i+1) << ". " << m_playlistNames.at(i) << endl;
        }
        // loop for user to choose a valid choice
        while ((numberPlayList <= 0) || ((unsigned int) numberPlayList > m_playlistNames.size())) {
            cin >> numberPlayList;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Enter a valid choice" << endl;
                numberPlayList = 0;
            }
        }
        numberPlayList--; // decrement one
        ofstream write(m_playlistNames.at(numberPlayList)); // open file
        // loop to write data to file
        for (int i = 0; i < m_playLists.at(numberPlayList).Size(); i++) {
            write << m_playLists.at(numberPlayList).At(i)->GetTitle() << ";";
            write << m_playLists.at(numberPlayList).At(i)->GetArtist() << ";";
            write << m_playLists.at(numberPlayList).At(i)->GetType()  << ";";
            write << m_playLists.at(numberPlayList).At(i)->GetYear() << ";";
            write << m_playLists.at(numberPlayList).At(i)->GetRank() << "\n";
        }
        cout << "Playlist Exported" << endl;
        write.close(); // closes the file
    }
}

// define what the menu is and the action for each menu choice
void MediaPlayer::MainMenu() {
    int choice = 0; // declare integer to decide choice
    // loops until user decide to quit
    while (choice != 8) {
        cout << "What would you like to do" << endl;
        cout << "1. Display Media by Type and Year" << endl;
        cout << "2. Create New Playlist" << endl;
        cout << "3. Add Media to Playlist" << endl;
        cout << "4. Display Existing Playlist" << endl;
        cout << "5. Import Playlist" << endl;
        cout << "6. Export Playlist" << endl;
        cout << "7. Sort Playlist by Year" << endl;
        cout << "8. Quit" << endl;
        cin >> choice; // user choices their choice
        // ignore input if not int
        if (cin.fail()) {
            cin.clear();
            cin.ignore(256, '\n');
            choice = 0;
        }
        // switch statement to determine action based on choice
        switch (choice) {
            case 1:
                DisplayMedia(); // displays the media
                break;
            case 2:
                CreatePlaylist(); // create new playlist
                break;
            case 3:
                AddMedia(); // add media to playlist
                break;
            case 4:
                DisplayPlaylist(); // display playlist
                break;
            case 5:
                ImportPlaylist(); // import playlist
                break;
            case 6:
                ExportPlaylist(); // export playlist
                break;
            case 7:
                SortPlaylist(); // sort playlist
                break;
            case 8:
                cout << "Thank you for using the UMBC Media Player" << endl; // quits using media player
                break;
            default:
                cout << "Please enter one of the choices" << endl; // promts user to choice on of the choices
                break;
        }
    }
}

// user creates new playlist
void MediaPlayer::CreatePlaylist() {
    ClearPlaylist(); // clears the data
    string playlistName = " "; // declare string to hold name
    cout << "What would you like to name the playlist?" << endl;
    cin >> playlistName;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(256, '\n');
        playlistName = " ";
    }
    playlistName = playlistName + ".txt"; // adds file extention to name
    m_playLists.push_back(m_playList); // add playlist to playlist vector
    m_playlistNames.push_back((playlistName)); // add playlist name to name vector
}

// display all media from certain year
int MediaPlayer::DisplayMedia() {    
    // declare a string and 2 int for user to track user choice
    string choice = " ";
    int year = 0;
    int found = 0;
    // loop until user chooses one option
    while ((choice != "music") && (choice != "podcast")) { 
        cout << "Which type of media do you want to display?" << endl;
        cout << "music" << endl;
        cout << "podcast" << endl;
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(256, '\n');
            choice = " ";
        }
    }
    // loop until user chooses one of the options
    while ((year <1958) || (year > 2020)) {
        cout << "Which year would you like to display? (1958-2020)" << endl;
        cin >> year;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(256, '\n');
            year = 0;
        }
    }
    cout << "*****" << year << "*****" << endl;
    // loop print out data from choses year
    for (unsigned int i = 0; i < m_mediaCatalog.size(); i++) {
        if ((m_mediaCatalog.at(i)->GetType() == choice) &&(m_mediaCatalog.at(i)->GetYear() == year)) {
            cout << (i+1) << ". " << m_mediaCatalog.at(i)->GetTitle() << " by " << m_mediaCatalog.at(i)->GetArtist() << endl;
            found++; // increase found value
        }
    }
    cout << found << " media found" << endl;
    return found; // return value of found
}

// add media to playlist
void MediaPlayer::AddMedia() {
    int playlistNumber = 0; // declare int to chooses playlist
    int mediaNumber = 0; // declare int to choose media number
    if (m_playlistNames.size() <= 0) { // checks if there is any playlists
        cout << "There are no playlists to add media too" << endl;
    } else {
        cout << "Which playlist would you like to add media to?" << endl;
        // loops to list every playlist
        for (unsigned int i = 0; i < m_playlistNames.size(); i++) {
            cout << (i+1) << ". " << m_playlistNames.at(i) << endl;
        }
        // loop until user chooses one of the playlist
        while ((playlistNumber <= 0) || ((unsigned int) playlistNumber > m_playlistNames.size())) {
            cin >> playlistNumber;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(256, '\n');
                playlistNumber = 0;
            }
        }
        playlistNumber--; // decrement value
        if (m_playLists.at(playlistNumber).IsFull()) { // checks if playlist is full
            cout << "Playlist is full, no more room to add media" << endl;
        } else {
            DisplayPlaylist(playlistNumber); // display everything in the playlist
            cout << "Choose the type of media you would like to add to the playlist" << endl;
            if (DisplayMedia() <= 0) { // checks if any media found to add to playlist
                cout << "No media to add" << endl;
            } else {
                cout << "Enter the number of the media you would like to add:" << endl;
                // loop until user chooses valid playlist
                while ((mediaNumber <= 0) || ((unsigned int) mediaNumber > m_mediaCatalog.size())) {
                    cin >> mediaNumber;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(256, '\n');
                        playlistNumber = 0;
                        cout << "Enter a valid number" << endl;
                    }
                }
                mediaNumber--; // decrement value
                m_playLists.at(playlistNumber).Enqueue(m_mediaCatalog.at(mediaNumber)); // add media to playlist
            }
        }
    }
}

// display data in playlist
void MediaPlayer::DisplayPlaylist() {
    int playlistNumber = 0; // declare int to choose which playlist
    if (m_playlistNames.size() <= 0) { // checks if any playlist exists
        cout << "There are no playlist to display" << endl;
    } else {
        cout << "Which playlist to you want to display?" << endl;
        // loop to show every playlist that exists
        for (unsigned int i = 0; i < m_playlistNames.size(); i++) {
            cout << (i+1) << ". " << m_playlistNames.at(i) << endl;
        }
        // loop until user chooses a valid playlist
        while ((playlistNumber <= 0) || ((unsigned int) playlistNumber > m_playlistNames.size())) {
            cin >> playlistNumber;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(256, '\n');
                playlistNumber = 0;
            }
        }
        playlistNumber--; // decrement value
        if (m_playLists.at(playlistNumber).IsEmpty()) {
            cout << "The playlist is currently empty" << endl;
        } else {
            // loop to display all the data in playlist chosen
            for (int i = 0; i < m_playLists.at(playlistNumber).Size(); i++) {
                cout << *m_playLists.at(playlistNumber).At(i) << endl; // uses friend function
            }
        }
    }
}

// overloaded function to display data in playlist
void MediaPlayer::DisplayPlaylist(int playlistNumber) {
    if (m_playLists.at(playlistNumber).IsEmpty()) { // checks if playlist is empty
        cout << "The playlist is currently empty" << endl;
    } else {
        // loop to display all the data in the playlist
        for (int i = 0; i < m_playLists.at(playlistNumber).Size(); i++) {
            cout << *m_playLists.at(playlistNumber).At(i) << endl; // uses friend function
        }
    }
}

// sort playlist 
void MediaPlayer::SortPlaylist() {
    int playlistNumber = 0; // declare int to choose which playlist
    if (m_playlistNames.size() <= 0) { // checks if any playlist exist
        cout << "There are no playlists" << endl;
    } else {
        cout << "Which playlist would you like to sort?" << endl;
        // loop to show all playlists
        for (unsigned int i = 0; i < m_playlistNames.size(); i++) {
            cout << (i+1) << ". " << m_playlistNames.at(i) << endl;
        }
        // loop until user chooses a valid playlist
        while ((playlistNumber <= 0) || ((unsigned int) playlistNumber > m_playlistNames.size())) {
            cin >> playlistNumber;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(256, '\n');
                playlistNumber = 0;
            }
        }
        playlistNumber--; // decrement value
        if (m_playLists.at(playlistNumber).IsEmpty()) { // checks if playlist is empty
            cout << "The playlist is currently empty" << endl;
        } else {
            m_playLists.at(playlistNumber).Sort(); // sort playlist
            cout << "Sorted playlist by year" << endl;
        }
    }
}

// clear m_playlist of data so no memory leaks happen
void MediaPlayer::ClearPlaylist() {
    // loop to deleate everything in list
    for (int i = 0; i < m_playList.Size(); i++) {
        delete m_playList.At(i);
        m_playList.At(i) = nullptr;
    }
}