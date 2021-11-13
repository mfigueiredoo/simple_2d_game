#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <cstring>

#include "WorldTile.h"
#include "WorldDecoration.h"
#include "MapManager.h"
#include "Background.h"

#ifndef WORLD_H
#define WORLD_H

class World
{

private:

public:

	bool isGridVisible;
	bool isMapLoaded;
	

	float tileSize;

	sf::Vector2i gridLength;
	sf::Color gridLineColor;
	std::vector<sf::VertexArray> verticalLines;
	std::vector<sf::VertexArray> horizontalLines;

	std::vector<WorldTile> tiles;
	std::vector<sf::Vector3i> tileData;

	std::vector<WorldDecoration> decorations;
	std::vector<sf::Vector3i> decorationsData;

	MapManager mapManager;
	Background background;

	sf::Texture* textureTiles;
	sf::Texture* textureBackground;

	World();
	World(sf::Texture* txt_background, sf::Texture* txt, std::string MAPS_path, float tileSize, sf::Vector2f screenSize, bool isGridVisible = false);
	~World();

	void initVariables();
	void initGrid();

	sf::Vector2i loadMapData();
	void setupMap();

	void addTile(WorldTile Tile);

	void reset();

	void update();
	void render(sf::RenderWindow* win);
};

#endif

