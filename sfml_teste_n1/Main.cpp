#include "Definitions.h"

int main()
{
    init();

    // Init Fonts
    sf::Font *defaultFont = new sf::Font();
    (*defaultFont).loadFromFile(FONTS_PATH + std::string("pixelmix.ttf"));

    // Init Textures
    sf::Texture* texturePlayer = new sf::Texture();
    if ( !(*texturePlayer).loadFromFile( TEXTURES_PATH + std::string("playerSprites.png")) ) { std::cout << "[ERROR]- Main.cpp can not load texture file \"playerSprites.png\" " << std::endl; }
    (*texturePlayer).setSmooth(false);

    sf::Texture* textureWorldTiles = new sf::Texture();
    if ( !(*textureWorldTiles).loadFromFile(TEXTURES_PATH + std::string("worldTileSprites.png")) ) { std::cout << "[ERROR]- Main.cpp can not load texture file \"worldTileSprites.png\" " << std::endl; }
    (*textureWorldTiles).setSmooth(false);

    sf::Texture* textureWorldDecorations = new sf::Texture();
    if ( !(*textureWorldDecorations).loadFromFile(TEXTURES_PATH + std::string("worldDecorationSprites.png")) ) { std::cout << "[ERROR]- Main.cpp can not load texture file \"worldDecorationSprites.png\" " << std::endl; }
    (*textureWorldDecorations).setSmooth(false);

    sf::Texture* textureBackground = new sf::Texture();
    if ( !(*textureBackground).loadFromFile(TEXTURES_PATH + std::string("backgroundSprites.png")) ) { std::cout << "[ERROR]- Main.cpp can not load texture file \"backgroundSprites.png\" " << std::endl; }
    (*textureBackground).setSmooth(false);

    sf::Texture* textureMenu = new sf::Texture();
    if (!(*textureMenu).loadFromFile(TEXTURES_PATH + std::string("menuBackgroundSprites.png") )) { std::cout << "[ERROR]- Main.cpp can not load texture file \"menuBackgroundSprites.png\" " << std::endl; }
    (*textureMenu).setSmooth(false);

    sf::Texture* textureIntro = new sf::Texture();
    if (!(*textureIntro).loadFromFile(TEXTURES_PATH + std::string("intro.png") )) { std::cout << "[ERROR]- Main.cpp can not load texture file \"intro.png\" " << std::endl; }
    (*textureIntro).setSmooth(false);

    // Init GameObjects
    gameEngine.player = Player(sf::Vector2f(_PLAYERSIZE, _PLAYERSIZE), sf::Vector2f( (300.f) + 30.f, 0.f));
    gameEngine.player.sprite.setTexture(texturePlayer);
    gameEngine.player.sprite.setOrigin(sf::Vector2f(gameEngine.player.initialSize.x/2, gameEngine.player.initialSize.y/2));
    gameEngine.player.sprite.setPosition(gameEngine.player.initialPosition);

    gameEngine.world = World(textureBackground, textureWorldTiles, MAPS_PATH, _TILESIZE, sf::Vector2f(_WINDOW_WIDTH, _WINDOW_HEIGHT), false);

    float x = _WINDOW_WIDTH * 0.25;
    float y = _WINDOW_HEIGHT * 0.50;

    sf::Vector2f buttonSize = sf::Vector2f(256.f, 0.f);

    gameEngine.mainMenu = Menu(textureMenu, defaultFont, sf::Vector2f((float)_WINDOW_WIDTH, (float)_WINDOW_HEIGHT), std::string("Main Menu"));
    
    Button play_btn = Button(gameEngine.mainMenu.font, "Play", "play_btn", buttonSize, sf::Vector2f(x, y + gameEngine.mainMenu.verticalControlsSpacing * gameEngine.mainMenu.controls.getButtonsLength()), 24.f, sf::Vector2f(36.f, 12.f));
    gameEngine.mainMenu.controls.buttons.push_back(play_btn);
    Button config_btn = Button(gameEngine.mainMenu.font, "Configurations", "config_btn", buttonSize, sf::Vector2f(x, y + gameEngine.mainMenu.verticalControlsSpacing * gameEngine.mainMenu.controls.getButtonsLength()), 24.f, sf::Vector2f(36.f, 12.f));
    gameEngine.mainMenu.controls.buttons.push_back(config_btn);
    Button exit_btn = Button(gameEngine.mainMenu.font, "Exit", "exit_btn", buttonSize, sf::Vector2f(x, y + gameEngine.mainMenu.verticalControlsSpacing * gameEngine.mainMenu.controls.getButtonsLength()), 24.f, sf::Vector2f(36.f, 12.f));
    gameEngine.mainMenu.controls.buttons.push_back(exit_btn);

    gameEngine.mainMenu.isVisible = true;

    gameEngine.pauseMenu = Menu(textureMenu, defaultFont, sf::Vector2f((float)_WINDOW_WIDTH, (float)_WINDOW_HEIGHT), std::string("Paused"));
    
    Button resume_btn = Button(gameEngine.pauseMenu.font, "Resume", "resume_btn", buttonSize, sf::Vector2f(x, y + gameEngine.pauseMenu.verticalControlsSpacing * gameEngine.pauseMenu.controls.getButtonsLength()), 24.f, sf::Vector2f(36.f, 12.f));
    gameEngine.pauseMenu.controls.buttons.push_back(resume_btn);
    Button restart_btn = Button(gameEngine.pauseMenu.font, "Restart", "restart_btn", buttonSize, sf::Vector2f(x, y + gameEngine.pauseMenu.verticalControlsSpacing * gameEngine.pauseMenu.controls.getButtonsLength()), 24.f, sf::Vector2f(36.f, 12.f));
    gameEngine.pauseMenu.controls.buttons.push_back(restart_btn);
    Button gotoMain_btn = Button(gameEngine.pauseMenu.font, "Go to Main Menu", "mainMenu_btn", buttonSize, sf::Vector2f(x, y + gameEngine.pauseMenu.verticalControlsSpacing * gameEngine.pauseMenu.controls.getButtonsLength()), 24.f, sf::Vector2f(36.f, 12.f));
    gameEngine.pauseMenu.controls.buttons.push_back(gotoMain_btn);

    gameEngine.configMenu = Menu(textureMenu, defaultFont, sf::Vector2f((float)_WINDOW_WIDTH, (float)_WINDOW_HEIGHT), std::string("Configurations"));


    Button tilesize_btn = Button(gameEngine.configMenu.font, "Tile Size", "defaultName", buttonSize, sf::Vector2f(x, y + gameEngine.configMenu.verticalControlsSpacing * gameEngine.configMenu.controls.getButtonsLength()), 24.f, sf::Vector2f(36.f, 12.f));
    gameEngine.configMenu.controls.buttons.push_back(tilesize_btn);

    Label resolution_lbl = Label(gameEngine.configMenu.font, "Resolution:", buttonSize, sf::Vector2f(x, y + gameEngine.configMenu.verticalControlsSpacing * gameEngine.configMenu.controls.getButtonsLength()), 24.f, sf::Vector2f(36.f, 12.f));
    gameEngine.configMenu.controls.labels.push_back(resolution_lbl);


    /*Button resolution_btn = Button(gameEngine.configMenu.font, "Resolution", "defaultName", buttonSize, sf::Vector2f(x, y + gameEngine.configMenu.verticalControlsSpacing * gameEngine.configMenu.controls.getButtonsLength()), 24.f, sf::Vector2f(36.f, 12.f));
    gameEngine.configMenu.controls.buttons.push_back(resolution_btn);*/
    Button back_btn = Button(gameEngine.configMenu.font, "Back", "back_btn", buttonSize, sf::Vector2f(x, y + gameEngine.configMenu.verticalControlsSpacing * (gameEngine.configMenu.controls.getButtonsLength() + 1)), 24.f, sf::Vector2f(36.f, 12.f));
    gameEngine.configMenu.controls.buttons.push_back(back_btn);

    ComboBox resolution_cbBox = ComboBox(defaultFont, sf::Vector2f(256.f, 0.f), sf::Vector2f(x + resolution_lbl.background.getGlobalBounds().width, y + gameEngine.configMenu.verticalControlsSpacing * 1), 24.f, sf::Vector2f(36.f, 12.f));
    resolution_cbBox.addItem(ItemComboBox(defaultFont, "1920 x 1080", resolution_cbBox.items.size()));
    resolution_cbBox.addItem(ItemComboBox(defaultFont, "1440 x 720", resolution_cbBox.items.size()));
    resolution_cbBox.addItem(ItemComboBox(defaultFont, "800 x 600", resolution_cbBox.items.size()));
    gameEngine.configMenu.controls.comboboxes.push_back(resolution_cbBox);


    gameEngine.intro = Intro(sf::Vector2f((float)_WINDOW_WIDTH, (float)_WINDOW_HEIGHT));
    gameEngine.intro.banner.setTexture(textureIntro);
    gameEngine.intro.banner.setTextureRect(sf::IntRect(0, 0, _WINDOW_WIDTH, _WINDOW_HEIGHT));


    // Set MainMenu Event Handlers
    for (size_t i = 0; i < gameEngine.mainMenu.controls.buttons.size(); i++)
    {
        if (gameEngine.mainMenu.controls.buttons[i].name != "defaultName")
        {
            if (gameEngine.mainMenu.controls.buttons[i].name == "play_btn") {
                gameEngine.mainMenu.controls.buttons[i].click = &playClickHandler;
            }

            if (gameEngine.mainMenu.controls.buttons[i].name == "config_btn") {
                gameEngine.mainMenu.controls.buttons[i].click = &configClickHandler;
            }

            if (gameEngine.mainMenu.controls.buttons[i].name == "exit_btn") {
                gameEngine.mainMenu.controls.buttons[i].click = &exitClickHanlder;
            }
        }
        else {
            gameEngine.mainMenu.controls.buttons[i].click = &defaultClickHandler;
        }
    }

    // Set PauseMenu Event Handlers
    for (size_t i = 0; i < gameEngine.pauseMenu.controls.buttons.size(); i++)
    {
        if (gameEngine.pauseMenu.controls.buttons[i].name != "defaultName")
        {
            if (gameEngine.pauseMenu.controls.buttons[i].name == "resume_btn") {
                gameEngine.pauseMenu.controls.buttons[i].click = &resumeClickHandler;
            }

            if (gameEngine.pauseMenu.controls.buttons[i].name == "restart_btn") {
                gameEngine.pauseMenu.controls.buttons[i].click = &restartClickHandler;
            }

            if (gameEngine.pauseMenu.controls.buttons[i].name == "mainMenu_btn") {
                gameEngine.pauseMenu.controls.buttons[i].click = &gotoMainMenuClickHandler;
            }
        }
        else {
            gameEngine.pauseMenu.controls.buttons[i].click = &defaultClickHandler;
        }
    }

    // Set ConfigMenu Event Handlers
    for (size_t i = 0; i < gameEngine.configMenu.controls.buttons.size(); i++)
    {
        if (gameEngine.configMenu.controls.buttons[i].name != "defaultName") {
            if (gameEngine.configMenu.controls.buttons[i].name == "back_btn") {
                gameEngine.configMenu.controls.buttons[i].click = &backClickHandler;
            }
        }
        else {
            gameEngine.configMenu.controls.buttons[i].click = &defaultClickHandler;
        }
    }

    WorldDecoration decor = WorldDecoration(textureWorldDecorations);
    gameEngine.world.decorations.push_back(decor);

    // Clock definition for deltaTime
    sf::Clock clock;
    clock.restart();


    // Game loop
    while (gameEngine.window->isOpen())
    {

        float deltaTime = clock.restart().asSeconds();

        gameEngine.pollEvents();
        gameEngine.window->clear(gameEngine.clearColor);   

        gameEngine.intro.update(deltaTime);
        gameEngine.mainMenu.update();
        gameEngine.pauseMenu.update();
        gameEngine.configMenu.update();

        
        // UPDATE game objects
        if (!gameEngine.isPaused) {
            gameEngine.world.update();
            gameEngine.player.update(gameEngine.keys, gameEngine.isMenuVisible(), deltaTime);
        }
        
        gameEngine.update();


        //RENDER game objects
        gameEngine.world.render(gameEngine.window);
        gameEngine.player.render(gameEngine.window);

        gameEngine.mainMenu.render(gameEngine.window);
        gameEngine.pauseMenu.render(gameEngine.window);
        gameEngine.configMenu.render(gameEngine.window);

        gameEngine.intro.render(gameEngine.window);

        gameEngine.window->display();

    }

    return 0;
}