#include "Settings.h"

//DOODLER TEXTURES FILES
const char* DOODLER_RIGHT_FILE_PATH = "textures/doomerDoodleRight.png";
const char* DOODLER_LEFT_FILE_PATH = "textures/doomerDoodleLeft.png";

//PLATFORMS TEXTURES FILES
const char* PLATFORM_FILE_PATH = "textures/vodkaPlatform.png";
const char* FAST_PLATFORM_FILE_PATH = "textures/brownBeerPlatform.png";
const char* TELEPORT_PLATFORM_FILE_PATH = "textures/greenBeerPlatform.png";

//BACKGROUND TEXTURE FILE
const char* BACKGROUND_FILE_PATH = "textures/background.png";

//MENU TEXTURES FILES
const char* MENU_BACKGROUND_FILE_PATH = "textures/balkon.png";
const char* PLAY_BUTTON_FILE_PATH = "textures/playButton.png";
const char* GAME_OVER_FILE_PATH = "textures/gameOver.png";
const char* SCORE_TEXT_FILE_PATH = "textures/score.png";
const char* BEST_SCORE_TEXT_FILE_PATH = "textures/bestScore.png";
const char* SMOKING_DOODLER_TILESET_FILE_PATH = "textures/smokingDoodlerTileset.png";

//FONTS FILE
const char* FONT_FILE_PATH = "fonts/Ustroke-Regular.ttf";

//BEST SCORE FILE
const char* BEST_SCORE_FILE_PATH = "bestScore.txt";

//AUDIO FILES
const char* PLATFORM_SAMPLE_FILE_PATH = "audio/platformSound.wav";
const char* FAST_PLATFORM_SAMPLE_FILE_PATH = "audio/fastPlatformSound.wav";
const char* TELEPORT_PLATFORM_SAMPLE_FILE_PATH = "audio/teleportPlatformSound.wav";

//DOODLER PHISICS
const float START_VERTICAL_SPEED = -4.5;
const float VERTICAL_ACCELERATION = 0.03;
const float HORIZONTAL_SPEED = 1.0;

//WINDOW CHARACTERISTICS
const float WINDOW_HEIGHT = 960.0;
const float WINDOW_WIDTH = 640.0;

//DOODLER TEXTURE CHARACTERISTICS
const float DOODLER_UPPER_BOUND = 30.0;
const float DOODLER_LOWER_BOUND = 39.0;
const float DOODLER_RIGHT_BOUND = 26.0;
const float DOODLER_LEFT_BOUND = 24.0;

//BASIC PLATFORM TEXTURE CHARACTERISTICS
const float PLATFORM_UPPER_BOUND = 5.0;
const float PLATFORM_LOWER_BOUND = 11.0;
const float PLATFORM_RIGHT_BOUND = 33.0;
const float PLATFORM_LEFT_BOUND = 38.0;

//FAST PLATFORM TEXTURE CHARACTERISTICS
const float FAST_PLATFORM_UPPER_BOUND = 6.5;
const float FAST_PLATFORM_LOWER_BOUND = 5.5;
const float FAST_PLATFORM_RIGHT_BOUND = 39.0;
const float FAST_PLATFORM_LEFT_BOUND = 41.0;

//FAST PLATFORM PHISICS
const float FAST_PLATFORM_SPEED = 0.5;

//TELEPORT PLATFORM TEXTURE CHARACTERISTICS
const float TELEPORT_PLATFORM_UPPER_BOUND = 7.5;
const float TELEPORT_PLATFORM_LOWER_BOUND = 5.5;
const float TELEPORT_PLATFORM_RIGHT_BOUND = 39.0;
const float TELEPORT_PLATFORM_LEFT_BOUND = 41.0;

//TELEPORT PLATFORM PHISICS
const short FRAMES_FOR_TELEPORTING = 50;


//COLLISION PARAMETERES
const float EPSILON = 5.0;

//RANDOM INITIAL PARAMETERS
const float START_PLATFORM_OFFSET = 30.0;
const float DISTANCE_BETWEEN_PLATFORMS = 100.0;
const float LAYER_LEFT_BOUND = 50.0;
const float LAYER_RIGHT_BOUND = 590.0;

//VIEW PARAMETERES
const float VIEW_UPPER_BOUND = 350.0;

//GAME LEVELS PARAMETERS
const float LEVELS_CHANGE_SPEED = 15000.0;
const float MAX_LEVEL_SCORE = 30000.0;

//MENU PARAMETERS
const float PLAY_BOTTON_UPPER_BOUND = 50.0;
const float PLAY_BOTTON_LOWER_BOUND = 50.0;
const float PLAY_BOTTON_LEFT_BOUND = 147.0;
const float PLAY_BOTTON_RIGHT_BOUND = 150.0;
