# my_hunter
replica of the famous NES "Duck Hunt" game in CSFML  
  
I needed to make a "duck-hunt" style game and decided to  
create an almost 1:1 replica of the Nintendo NES Duck-Hunt game.  
  
In order to play, you will :
  
  
  !!!  
  FOR UBUNTU (might also work w/ other distros),  
  PLEASE REFER TO https://gist.github.com/paullaffitte/c3f028dc64a55e920fa8afabff70673e  
  The original build_csfml works with Fedora
  !!!  
  
  
* Install the CSFML Library  
```
./build_csfml.h
```  
  
* Start the game
```
make; ./my_hunter
```  
  
For any informations (hotkeys, how the game works, ...) use  
  
```
./my_hunter -h
```  
  
* Screenshots :

![my_hunter_menu](https://github.com/pironc/my_hunter/blob/main/screenshots/my_hunter_menu_lowres.png "my_hunter game menu")  
![my_hunter_menu](https://github.com/pironc/my_hunter/blob/main/screenshots/my_hunter_game_lowres.png "my_hunter game menu")

The "biggest mistake" I did in this project was sending and dereferencing  
pointers, which does not need any referencing/dereferencing as they  
already are pointers and can be modified without returning the main strucutre.
