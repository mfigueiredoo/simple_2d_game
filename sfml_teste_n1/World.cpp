#include "World.h"


World::World()
{
	this->initVariables();
}

World::World(sf::Texture* txt_background, sf::Texture *txt_tiles, std::string maps_pathName, float _tileSize, sf::Vector2f _screenSize, bool _isGridVisible)
{
	this->initVariables();
	this->mapManager = FileManager(maps_pathName);

	this->textureBackground = txt_background;
	this->textureTiles = txt_tiles;
	this->tileSize = _tileSize;

	this->gridLength = this->loadMapData();

	this->isGridVisible = _isGridVisible;

	this->background = Background(_screenSize);
	this->background.sprite.setTexture(this->textureBackground);

	this->initGrid();
	
	
}

World::~World()
{
}

void World::initVariables()
{
	bool isGridVisible = false;

	this->tileSize = 0;
	this->gridLength = sf::Vector2i();
	this->gridLineColor = sf::Color(0, 0, 0, 255);
	this->verticalLines = std::vector<sf::VertexArray>();
	this->horizontalLines = std::vector<sf::VertexArray>();

	this->tiles = std::vector<WorldTile>();
	this->mapManager = FileManager();
	this->background = Background();
	this->isMapLoaded = false;

	this->textureBackground = nullptr;
	this->textureTiles = nullptr;
}

void World::initGrid()
{
	int screenTop = 0;
	int screenBottom = this->gridLength.y * this->tileSize;
	int screenLeft = 0;
	int screenRight = this->gridLength.x * this->tileSize;

	// Vertical Lines
	for (int i = 0; i < this->gridLength.x; i++)
	{
		sf::VertexArray vLine(sf::LinesStrip, 0);

		sf::Vertex v_1(sf::Vector2f((float)(i * this->tileSize), (float)(screenTop)), this->gridLineColor);
		sf::Vertex v_2(sf::Vector2f((float)(i * this->tileSize), (float)(screenBottom)), this->gridLineColor);

		vLine.append(v_1);
		vLine.append(v_2);

		this->verticalLines.push_back(vLine);

	}

	// Horizontal Lines
	for (int i = 0; i < this->gridLength.y; i++)
	{
		sf::VertexArray hLine(sf::LinesStrip, 0);

		sf::Vertex v_1(sf::Vector2f((float)(screenLeft), (float)(i * this->tileSize)), this->gridLineColor);
		sf::Vertex v_2(sf::Vector2f((float)(screenRight), (float)(i * this->tileSize)), this->gridLineColor);

		hLine.append(v_1);
		hLine.append(v_2);

		this->horizontalLines.push_back(hLine);

	}

}

sf::Vector2i World::loadMapData()
{
	std::string file_name = this->mapManager.fileName;

	std::ifstream file(file_name);

	int x = 0;
	int y = 0;

	if (file.is_open()) {
		if (this->mapManager.fileIsEmpty(file)) {
			std::cout << "[WARNIG] - File \"" << file_name << "\" is EMPTY. Is not possible loading maps.\n" << std::endl;
			file.close();
		}
		else {

			std::string fileLine;
			
			while (std::getline(file, fileLine))
			{
				for (x = 0; x < fileLine.size(); x++)
				{
					sf::Vector3i vertexData(x, y, (int)(fileLine[x]));
					this->tileData.push_back(vertexData);
				}
				y++;
			}

			this->isMapLoaded = true;
			this->setupMap();

			file.close();
		}
	}
	else {
		std::cout << "[WARNING] - File \"" << file_name << "\" is NOT OPEN. Is not possible loading maps.\n" << std::endl;
	}

	return sf::Vector2i(x, y);

}

void World::setupMap()
{		
	if (this->isMapLoaded)
	{
		for (int i = 0; i < this->tileData.size(); i++)
		{
			WorldTile t = WorldTile(sf::Vector2f(this->tileData[i].x * this->tileSize, this->tileData[i].y * this->tileSize), this->tileSize, tileData[i].z);
			t.sprite.setTexture(this->textureTiles);
			this->addTile(t);
		}
	}
}

void World::addTile(WorldTile tile)
{
	this->tiles.push_back(tile);
}

void World::reset()
{
	this->tiles = std::vector<WorldTile>();
	this->tileData = std::vector<sf::Vector3i>();
	this->gridLength = this->loadMapData();
}

void World::update()
{
	this->background.update();

	for (size_t i = 0; i < this->tiles.size(); i++)
	{
		this->tiles[i].update();
	}

	for (size_t i = 0; i < this->decorations.size(); i++)
	{
		this->decorations[i].update();
	}

}

void World::render(sf::RenderWindow* win)
{
	this->background.render(win);

	for (size_t i = 0; i < this->decorations.size(); i++)
	{
		this->decorations[i].render(win);
	}

	for (size_t i = 0; i < this->tiles.size(); i++)
	{
		this->tiles[i].render(win);
	}

	if (!this->isGridVisible) { return; }

	// Grid Vertical lines
	for (size_t i = 0; i < verticalLines.size(); i++)
	{
		win->draw(verticalLines[i]);
	}

	// Grid Horizontal lines
	for (size_t i = 0; i < horizontalLines.size(); i++)
	{
		win->draw(horizontalLines[i]);
	}

}
