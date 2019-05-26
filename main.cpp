#include "Header.h"


sf::RenderWindow window(sf::VideoMode(640, 480), L"��������� �����", sf::Style::Titlebar | sf::Style::Close);

int main()
{
	sf::Image icon;
	sf::Font font;
	if ((!icon.loadFromFile("images/fone2.png")) 
		|| (!icon.loadFromFile("images/rules1.png")) 
		|| (!icon.loadFromFile("images/rules2.png")) 
		|| (!icon.loadFromFile("images/rules3.png"))
		|| (!icon.loadFromFile("images/Frame.png"))
		|| (!icon.loadFromFile("images/icon.png"))
		|| (!font.loadFromFile("font.otf")))
	{ return 1; }
	else
		window.setIcon(16, 16, icon.getPixelsPtr());
	window.setFramerateLimit(90);
	Game(window);
	return 0;
}