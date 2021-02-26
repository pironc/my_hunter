# my_hunter
replica of the famous NES "Duck Hunt" game in CSFML  
  
I needed to make a "duck-hunt" style game and decided to  
create an almost 1:1 replica of the Nintendo NES Duck-Hunt game.  
  
In order to play, you will :
  
* Install the CSFML Library  
```
./build_csfml.h
```  
  
* Start the game
```
make; ./my_hunter
```  
  
For any informations (hotkeys, how the game works, ...) please use  
  
```
./my_hunter -h
```  
  
* Screenshots :  
![my_hunter_menu](https://raw.github.com/pironc/my_hunter/master/screenshots/my_hunter_menu.png "my_hunter game menu")

The biggest mistake I did in this project was sending and dereferencing  
pointers, which does not need any referencing/dereferencing as they  
already are pointers and can be modified without returning the main strucutre.