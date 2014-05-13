#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H
class Song;
class MusicPlayer{
  public:
    MusicPlayer();
    void loop();
    void setup(int pin);
    void setSong(Song* song);
    Song* getSong();
  protected:
    Song* song;
    int pin;
};

class Song{
  public:
    Song(int notes_amount, int* tones, int* note_durations);
  protected:
    int* tones;
    int* note_durations;
    int notes_amount;
};
#endif
