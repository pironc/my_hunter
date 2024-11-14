# my_hunter
### Replica of the famous NES "Duck Hunt" game in CSFML  
  
I needed to make a "duck-hunt" style game and decided to  
create an almost 1:1 replica of the Nintendo NES Duck-Hunt game.  

### In order to compile and run the project, you will need to install the CSFML :
  
  
  For **Ubuntu** (might also work w/ other distros), use the following command : 
  
  ```
  sudo apt-get install libcsfml-dev
  ```  
  The **build_csfml** executable should work with Fedora.  

  - [x] For **MacOS ARM**, the library and header files are already included in the repository and wil automatically be compiled with it.  
If it is not compiling, download the sources, build it and link it to the project in the Makefile.
  
#### Install the CSFML Library  
```
./build_csfml.h
```  

#### Start the game
```
make; ./my_hunter
```  
  
#### For any informations (hotkeys, how the game works, ...) use  
  
```
./my_hunter -h
```  
  
### Screenshots :

![my_hunter_menu](https://github.com/pironc/my_hunter/blob/main/screenshots/my_hunter_menu_lowres.png "my_hunter game menu")  
![my_hunter_menu](https://github.com/pironc/my_hunter/blob/main/screenshots/my_hunter_game_lowres.png "my_hunter game menu")

The "biggest mistake" I did in this project was sending and dereferencing  
pointers, which does not need any referencing/dereferencing as they  
already are pointers and can be modified without returning the main strucutre.
