# wave-player
This is simple wave player for winapi aplications, with example
aplication

!!Remember!!
Now this project can only play 44100 kbits/s 16 bit 2 channel files

How to use

1. Download the wave_player both *.cpp & *.h
2. Include to your project
3. Init wavePlayer

    wavePlayer = new WavePlayer(hwndDlg);
    
    
4. Use Play method with given file path to play choosen file
   or stop to stop playing
   
          wavePlayer->Play(path);
          
          wavePlayer->Stop();
          
          
