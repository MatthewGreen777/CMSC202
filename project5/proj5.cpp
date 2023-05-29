#include <iostream>
#include "MediaPlayer.h"
#include "Media.h"

int main (int argc, char* argv[]) {
  string mediaFile;
  cout << "Welcome to UMBC Media Player"<<endl;
  if(argc > 1){
    mediaFile = argv[1];
  } else{
    cout << "One media files required - try again" << endl;
    cout << "./proj5 proj5_media.txt" << endl;
    return 0;
  }
  MediaPlayer* myMedia = new MediaPlayer(mediaFile);
  myMedia->MainMenu();
  delete myMedia;
  return 0;
}
