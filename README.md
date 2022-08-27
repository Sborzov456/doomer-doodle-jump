# Doomer Doodle Jump :night_with_stars:
## :pushpin: Short Description
  An object-oriented project, which is a _doomer-themed_ version of the popular **Doodle Jump** game.
  
  The meaning of the game is to _score points by passing the distance by jumping on the platforms_.<br>
  _**You can control the character with the arrows on keyboard.**_
  
  :computer: **Code - [Alexander Borzov](https://github.com/Sborzov456)** <br>
  :paintbrush: **Design - [Victoria Koroleva](https://vk.com/vwika_artt)**
## :pushpin: Demo
  
  ![Demo](https://github.com/Sborzov456/doomer-doodle-jump/blob/master/demo/demo.gif)
  
  ***This illustration is the original size of the game window.***
## :pushpin: Renovations
  - [x] **Different design.** As you can see in the demo, the platforms are beer and vodka bottles, and the character is drawn in doomer style. Also, the background is         a night city, not a notebook sheet, as in the original.
  - [x] **New platform type.** These are _teleport platforms_. They are very similar to the tan platforms in the original, but they have a different animation of                 movement: _they disappear and appear in different place_, which makes it impossible for the player to track their movement. In this project, they have a               _green bottle design_.
## :pushpin: Development Tools

  - [x] **Programming language: C++20**
  - [x] **Audio and graphics lib: SFML 2.5.1**
  - [x] **STL: `std::vector<T>` used to store platforms**
  - [x] **Random number generator: `std::mt19973`**
  - [x] **Texture Creation Software: Clip Studio Paint**
  
## :pushpin: Settings

  All settings are stored in the **Settings.cpp** file. <br>
  I recommend you do not change the _texture size settings_, but you can change the following settings:
  * `const float START_VERTICAL_SPEED`: the initial jump speed of the character, the higher it is, the higher the character will jump;
  * `const float VERTICAL_ACCELERATION`: free fall acceleration, the higher it is, the faster the character will lose initial speed;
  * `const float HORIZONTAL_SPEED`: the speed at which the character moves horizontally when the arrows on the keyboard are pressed;
  * `const float FAST_PLATFORM_SPEED`: the speed at which "fast platforms" move horizontally;
  * `const short FRAMES_FOR_TELEPORTING`: the number of frames for which the teleportation platform teleports. The higher it is, the slower the platform teleports.                                               **Recommendation: do not set above 120**;
  * `const float DISTANCE_BETWEEN_PLATFORMS`: distance between platforms during their initialization, the smaller it is, the more platforms will be initialized;
  * `const float LEVELS_CHANGE_SPEED`: the rate at which the difficulty of the game will increase;
  * `const float MAX_LEVEL_SCORE`: score limit at which the difficulty of the game will stop increasing;

## :pushpin: Run Without Сompilation
  1. **Follow the link below to [Google Disk](https://drive.google.com/drive/folders/15RAKZuXRAXLoUJRMtCb7S19sK4udE6dN?usp=sharing);**
  2. **Download the _DoomerDoodle.rar_ file from there;**
  3. **Unzip the archive (Password: 123);**
  4. **Run DoomerDoodleJump.exe;**
  
  :warning: **If the operating system will warn about malware - ignore it, the warning is erroneous.**
