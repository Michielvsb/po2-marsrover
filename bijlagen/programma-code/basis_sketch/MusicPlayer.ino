MusicPlayer::MusicPlayer(){
}
void MusicPlayer::setup(int pin){
  this->pin = pin;
  pinMode(this->pin, OUTPUT);
}
void MusicPlayer::loop(){
  
}
void MusicPlayer::setSong(Song *s){
  this->song = s;
}
Song* MusicPlayer::getSong(){
  return this->song;
}
Song::Song(int notes_amount, int* tones, int* note_durations){
  this->notes_amount = notes_amount;
  this->tones = tones;
  this->note_durations = note_durations;
}
