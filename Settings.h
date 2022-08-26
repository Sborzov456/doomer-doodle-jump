#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cmath>
#include <string>

//TEXTURES FILES
extern const char* DOODLER_RIGHT_FILE_PATH;
extern const char* DOODLER_LEFT_FILE_PATH;
extern const char* PLATFORM_FILE_PATH;
extern const char* FAST_PLATFORM_FILE_PATH;
extern const char* TELEPORT_PLATFORM_FILE_PATH;
extern const char* BACKGROUND_FILE_PATH;
extern const char* MENU_BACKGROUND_FILE_PATH;
extern const char* PLAY_BUTTON_FILE_PATH;
extern const char* GAME_OVER_FILE_PATH;
extern const char* SCORE_TEXT_FILE_PATH;
extern const char* BEST_SCORE_TEXT_FILE_PATH;
extern const char* SMOKING_DOODLER_TILESET_FILE_PATH;

//FONTS FILE
extern const char* FONT_FILE_PATH;

//BEST SCORE FILE
extern const char* BEST_SCORE_FILE_PATH;

//AUDIO FILES
extern const char* PLATFORM_SAMPLE_FILE_PATH;
extern const char* FAST_PLATFORM_SAMPLE_FILE_PATH;
extern const char* TELEPORT_PLATFORM_SAMPLE_FILE_PATH;


//DOODLER JUMP PHISICS
extern const float START_VERTICAL_SPEED;
extern const float VERTICAL_ACCELERATION;
extern const float HORIZONTAL_SPEED;


//WINDOW CHARACTERISTICS
extern const float WINDOW_HEIGHT;
extern const float WINDOW_WIDTH;

//DOODLER TEXTURE CHARACTERISTICS
extern const float DOODLER_UPPER_BOUND;
extern const float DOODLER_LOWER_BOUND;
extern const float DOODLER_RIGHT_BOUND;
extern const float DOODLER_LEFT_BOUND;

//BASIC PLATFORM TEXTURE CHARACTERISTICS
extern const float PLATFORM_UPPER_BOUND;
extern const float PLATFORM_LOWER_BOUND;
extern const float PLATFORM_RIGHT_BOUND;
extern const float PLATFORM_LEFT_BOUND;

//FAST PLATFORM TEXTURE CHARACTERISTICS
extern const float FAST_PLATFORM_UPPER_BOUND;
extern const float FAST_PLATFORM_LOWER_BOUND;
extern const float FAST_PLATFORM_RIGHT_BOUND;
extern const float FAST_PLATFORM_LEFT_BOUND;

//FAST PLATFORM PHISICS
extern const float FAST_PLATFORM_SPEED;

//TELEPORT PLATFORM TEXTURE CHARACTERISTICS
extern const float TELEPORT_PLATFORM_UPPER_BOUND;
extern const float TELEPORT_PLATFORM_LOWER_BOUND;
extern const float TELEPORT_PLATFORM_RIGHT_BOUND;
extern const float TELEPORT_PLATFORM_LEFT_BOUND;

//TELEPORT PLATFORM PHISICS
extern const short FRAMES_FOR_TELEPORTING;

//COLLISION PARAMETERES
extern const float EPSILON;

//RANDOM INITIAL PARAMETERS
extern const float START_PLATFORM_OFFSET;
extern const float DISTANCE_BETWEEN_PLATFORMS;
extern const float LAYER_LEFT_BOUND;
extern const float LAYER_RIGHT_BOUND;

//VIEW PARAMETERES
extern const float VIEW_UPPER_BOUND;

//GAME LEVELS PARAMETERS
extern const float LEVELS_CHANGE_SPEED;
extern const float MAX_LEVEL_SCORE;

//MENU PARAMETERS
extern const float PLAY_BOTTON_UPPER_BOUND;
extern const float PLAY_BOTTON_LOWER_BOUND;
extern const float PLAY_BOTTON_LEFT_BOUND;
extern const float PLAY_BOTTON_RIGHT_BOUND;