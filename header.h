#pragma once
#include <SFML/Graphics.hpp>


void begin(sf::RenderWindow&); // начальный экран
void info(sf::RenderWindow&); // раздел "правила игры"
bool menu(sf::RenderWindow&); // главное меню
void setup(sf::RenderWindow&);  // выбор количества дисков
int game_loop(sf::RenderWindow&); // игровой цикл
void draw_field(sf::RenderWindow&); // отрисовка поля
void gameover(sf::RenderWindow&, int); // окончание игры
void Game(sf::RenderWindow&); // сама игра

enum Location { first = 1, second, third };

class Disk
{
public:
	float init_x = 47.f;
	float init_y = 420.f;

	bool get_state() { return this->m_state; }

	void set_state(bool state) { this->m_state = state; }

	void set_number(int number) { this->m_number = number; }

	void set_position(int direction = 0, int index = 0) //0 - на месте, 1 - вправо, 2 - влево
	{
		float shift_x = 200.f;
		if (direction == 0)
		{
			this->m_posx = init_x + 10.f * this->m_number;
			this->m_posy = init_y - 21.f * this->m_number;
		}
		if (direction == 1)
		{
			if (this->get_location() == second)
			{
				this->m_posx = 320.f - (m_width / 2) + 2.5f;
				this->m_posy = init_y - 21.f * index;
			}
			else if (this->get_location() == third)
			{
				this->m_posx = 520.f - (m_width / 2) + 2.5f;
				this->m_posy = init_y - 21.f * index;
			}
		}
		if (direction == 2)
		{
			if (this->get_location() == second)
			{
				this->m_posx = 320.f - (m_width / 2) + 2.5f;
				this->m_posy = init_y - 21.f * index;
			}
			else if (this->get_location() == first)
			{
				this->m_posx = 120.f - (m_width / 2) + 2.5f;
				this->m_posy = init_y - 21.f * index;
			}
		}
	}

	int get_location() { return this->m_location; }

	void set_location(int location) { this->m_location = static_cast<Location>(location); }

	float get_width() { return this->m_width; }

	void set_size(int number)
	{
		this->m_width -= number * 20;
	}

	sf::RectangleShape& get_disk()
	{
		this->m_rectangle.setSize(sf::Vector2f(this->m_width, this->m_height));
		this->m_rectangle.setPosition(this->m_posx, this->m_posy);
		this->m_rectangle.setOutlineColor(sf::Color::Black);
		this->m_rectangle.setOutlineThickness(1.0);
		return (this->m_rectangle);
	}

private:
	float m_width = 150.0;
	float m_height = 20.0;
	int m_number = -1;
	float m_posx = -1, m_posy = -1;
	bool m_state = false; //диск по умолчанию закрыт, нельзя подвинуть
	Location m_location = first; //на каком шесте находится сейчас, по умолчанию на первом
	sf::RectangleShape m_rectangle;
};

