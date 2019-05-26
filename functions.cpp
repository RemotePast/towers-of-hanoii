#include "Header.h"
#include <vector>
#include <sstream>

int n;

void draw_field(sf::RenderWindow& window)
{
	sf::Texture fone;
	sf::Sprite sprite;
	fone.loadFromFile("images/fone2.png");
	sprite.setTexture(fone);
	sf::RectangleShape desk(sf::Vector2f(600, 30));
	sf::RectangleShape stick1(sf::Vector2f(5, 300));
	sf::RectangleShape stick2(sf::Vector2f(5, 300));
	sf::RectangleShape stick3(sf::Vector2f(5, 300));
	desk.setFillColor(sf::Color(47, 3, 3));
	desk.setPosition(20, 440);
	stick1.setFillColor(sf::Color::Black);
	stick2.setFillColor(sf::Color::Black);
	stick3.setFillColor(sf::Color::Black);
	stick1.setPosition(120, 140);
	stick2.setPosition(320, 140);
	stick3.setPosition(520, 140);
	window.draw(sprite);
	window.draw(desk);
	window.draw(stick1);
	window.draw(stick2);
	window.draw(stick3);
}

void begin(sf::RenderWindow& window)
{
	sf::Texture title;
	sf::Sprite sprite;
	title.loadFromFile("images/Frame.png");
	sprite.setTexture(title);
	sf::Clock clock;
	float time = 0;
	while (window.isOpen() && (time <= 3)) // показываем начальный экран в течении 3 секунд
	{
		time = clock.getElapsedTime().asSeconds(); // берем прошедшее время в микросекундах
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		window.draw(sprite);
		window.display();
		window.clear();
	}
}

void info(sf::RenderWindow& window)
{
	sf::Font font;
	font.loadFromFile("font.otf");
	sf::Text next(L"Дальше", font, 40);
	sf::Text goback(L"Вернуться в меню", font, 50);
	next.setFillColor(sf::Color::White);
	next.setPosition(260, 433);
	goback.setFillColor(sf::Color::White);
	goback.setPosition(135, 400);
	sf::Texture pages[3];
	sf::Sprite sprite;
	pages[0].loadFromFile("images/rules1.png");
	pages[1].loadFromFile("images/rules2.png");
	pages[2].loadFromFile("images/rules3.png");
	sprite.setTexture(pages[0]);
	int ind = 0;
	while (window.isOpen() && (ind <= 2))
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if ((next.getGlobalBounds().contains(float(sf::Mouse::getPosition(window).x), float(sf::Mouse::getPosition(window).y))))
			{
				if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
					next.setFillColor(sf::Color(47, 3, 3));
				else
				{
					if (ind < 2)
						sprite.setTexture(pages[++ind]);  // переключаем страницу
					sf::sleep(sf::seconds(0.3f));
				}
			}
			else if ((goback.getGlobalBounds().contains(float(sf::Mouse::getPosition(window).x), float(sf::Mouse::getPosition(window).y))) && (ind == 2))
			{
				if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
					goback.setFillColor(sf::Color::Red);
				else
				{
					sf::sleep(sf::seconds(0.3f));
					return; 
				}
			}
			else
			{
				next.setFillColor(sf::Color::White);
				goback.setFillColor(sf::Color::White);
			}
			window.clear();
			window.draw(sprite);
			if (ind < 2)
				window.draw(next);
			else if (ind == 2)
				window.draw(goback);
			window.display();
		}
	}
}


bool menu(sf::RenderWindow & window)
{
	sf::Texture fone;
	sf::Sprite sprite;
	fone.loadFromFile("images/fone2.png");
	sprite.setTexture(fone);
	sf::Font font;
	font.loadFromFile("font.otf");
	sf::Text newgame(L"Новая Игра", font, 80);
	sf::Text rules(L"Правила игры", font, 80);
	sf::Text exit(L"Выход", font, 80);
	newgame.setPosition(135, 60);
	rules.setPosition(90, 180);
	exit.setPosition(215, 300);
	newgame.setFillColor(sf::Color::White);
	rules.setFillColor(sf::Color::Black);
	exit.setFillColor(sf::Color::White);
	bool isMenu = 1;
	int menuNum = 0;
	while (window.isOpen())
	{
		sf::Event event;
		while ((window.pollEvent(event)) && (isMenu))
		{
			menuNum = 0; // хранит выбор раздела меню пользователем
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (newgame.getGlobalBounds().contains(float(sf::Mouse::getPosition(window).x), float(sf::Mouse::getPosition(window).y)))
			{
				newgame.setFillColor(sf::Color(47, 3, 3));
				menuNum = 1;
			}
			else if (rules.getGlobalBounds().contains(float(sf::Mouse::getPosition(window).x), float(sf::Mouse::getPosition(window).y)))
			{
				rules.setFillColor(sf::Color(47, 3, 3));
				menuNum = 2;
			}
			else if (exit.getGlobalBounds().contains(float(sf::Mouse::getPosition(window).x), float(sf::Mouse::getPosition(window).y)))
			{
				exit.setFillColor(sf::Color(47, 3, 3));
				menuNum = 3;
			}
			else
			{
				newgame.setFillColor(sf::Color::White);
				rules.setFillColor(sf::Color::Black);
				exit.setFillColor(sf::Color::White);
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (menuNum == 1) // переходим к выбору количества дисков
				{
					isMenu = false;
					return false;
				}
				else if (menuNum == 2)  // переход к правилам игры
				{
					return true;
				}
				else if (menuNum == 3) // если закрыли окно игры
				{
					isMenu = false;
					window.close();
				}

			}
		}
		window.clear();
		window.draw(sprite);
		window.draw(newgame);
		window.draw(rules);
		window.draw(exit);
		window.display();
	}
}

void setup(sf::RenderWindow & window)
{
	sf::Texture fone;
	sf::Sprite sprite;
	fone.loadFromFile("images/fone2.png");
	sprite.setTexture(fone);
	sf::Font font;
	font.loadFromFile("font.otf");
	sf::Text question(L"Количество дисков:", font, 75);
	sf::Text three("3", font, 80);
	sf::Text four("4", font, 80);
	sf::Text five("5", font, 80);
	sf::Text six("6", font, 80);
	sf::Text seven("7", font, 80);
    sf::Text eight("8", font, 80);
	question.setPosition(25, 130);
	three.setPosition(60, 220);
	four.setPosition(160, 220);
	five.setPosition(260, 220);
	six.setPosition(360, 220);
	seven.setPosition(460, 220);
    eight.setPosition(560, 220);
	question.setFillColor(sf::Color::Black);
	three.setFillColor(sf::Color::White);
	four.setFillColor(sf::Color::White);
	five.setFillColor(sf::Color::White);
	six.setFillColor(sf::Color::White);
	seven.setFillColor(sf::Color::White);
    eight.setFillColor(sf::Color::White);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (three.getGlobalBounds().contains(float(sf::Mouse::getPosition(window).x), float(sf::Mouse::getPosition(window).y)))
			{
				three.setFillColor(sf::Color(47, 3, 3));
				n = std::stoi(static_cast<std::string>(three.getString()));
                // считываю количество, которое выбрал пользователь
			}
			else if (four.getGlobalBounds().contains(float(sf::Mouse::getPosition(window).x), float(sf::Mouse::getPosition(window).y)))
			{
				four.setFillColor(sf::Color(47, 3, 3));
				n = std::stoi(static_cast<std::string>(four.getString()));
			}
			else if (five.getGlobalBounds().contains(float(sf::Mouse::getPosition(window).x), float(sf::Mouse::getPosition(window).y)))
			{
				five.setFillColor(sf::Color(47, 3, 3));
				n = std::stoi(static_cast<std::string>(five.getString()));
			}
			else if (six.getGlobalBounds().contains(float(sf::Mouse::getPosition(window).x), float(sf::Mouse::getPosition(window).y)))
			{
				six.setFillColor(sf::Color(47, 3, 3));
				n = std::stoi(static_cast<std::string>(six.getString()));
			}
			else if (seven.getGlobalBounds().contains(float(sf::Mouse::getPosition(window).x), float(sf::Mouse::getPosition(window).y)))
			{
				seven.setFillColor(sf::Color(47, 3, 3));
				n = std::stoi(static_cast<std::string>(seven.getString()));
			}
            else if (eight.getGlobalBounds().contains(float(sf::Mouse::getPosition(window).x), float(sf::Mouse::getPosition(window).y)))
            {
                eight.setFillColor(sf::Color(47, 3, 3));
                n = std::stoi(static_cast<std::string>(eight.getString()));
            }
			else
			{
				n = 0;
				three.setFillColor(sf::Color::White);
				four.setFillColor(sf::Color::White);
				five.setFillColor(sf::Color::White);
				six.setFillColor(sf::Color::White);
				seven.setFillColor(sf::Color::White);
                eight.setFillColor(sf::Color::White);
			}
			if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (n != 0))
			{
				return;
			}
		}
		window.clear();
		window.draw(sprite);
		window.draw(question);
		window.draw(three);
		window.draw(four);
		window.draw(five);
		window.draw(six);
		window.draw(seven);
        window.draw(eight);
		window.display();
	}
}

int game_loop(sf::RenderWindow & window)
{
	Disk* disks = new Disk[n]; // массив дисков
	std::vector<Disk> first_stick; // диски на первом стержне 
	std::vector<Disk> second_stick; // диски на втором стержне
	std::vector<Disk> third_stick; // диски на третьем стержне
	sf::Font font;
	font.loadFromFile("font.otf");
	sf::Text stick1("1", font, 70);
	sf::Text stick2("2", font, 60);
	sf::Text stick3("3", font, 60);
	sf::Texture texture1;
	sf::Texture texture2;
	sf::Texture texture3;
	texture1.loadFromFile("images/escapebl.png");
	texture2.loadFromFile("images/escapegr.png");
	texture3.loadFromFile("images/escapere.png");
	sf::Sprite arrowBackwards;
	arrowBackwards.setTexture(texture1);
	arrowBackwards.setPosition(280, 10);
	stick1.setPosition(120, 62);
	stick2.setPosition(310, 65);
	stick3.setPosition(510, 60);
	stick1.setFillColor(sf::Color::Black);
	stick2.setFillColor(sf::Color::Black);
	stick3.setFillColor(sf::Color::Black);
	sf::Text text(L"Сделано\nПерестановок: ", font, 30);
	sf::Text swapsText("", font, 60);
	sf::Text arrow11("3", font, 50);
	sf::Text arrow12("2", font, 55);
	sf::Text arrow21("1", font, 60);
	sf::Text arrow22("3", font, 50);
	sf::Text arrow31("2", font, 55);
	sf::Text arrow32("1", font, 60);
	sf::Text goback(L"Вернуться в меню", font, 30);
	goback.setPosition(400, 5);
	goback.setFillColor(sf::Color::White);
	text.setPosition(15, 0);
	swapsText.setPosition(190, 13);
	text.setFillColor(sf::Color::Black);
	swapsText.setFillColor(sf::Color::Black);
	arrow11.setPosition(90, 410);
	arrow12.setPosition(135, 408);
	arrow21.setPosition(290, 403);
	arrow22.setPosition(335, 410);
	arrow31.setPosition(490, 408);
	arrow32.setPosition(535, 403);
    struct LastSwap
    {
        int number = 0;	// номер хода
        Location from = first; // откуда переставляли
        Location  to = first; // куда переставили
        bool available = false; // можно ли отменить ход
    };
	for (int i = 0; i < n; i++)
	{
		first_stick.push_back(disks[i]);
		first_stick.back().get_disk().setFillColor(sf::Color((120 + i * 15), (50 + i * 15), (0 + i * 15)));
		first_stick.back().set_number(i);
		first_stick[i].set_position();
		first_stick[i].set_size(i);
		if (i == (n - 1))
			first_stick[i].set_state(true);
	}
    LastSwap lastSwap;
	while (window.isOpen())
	{
		sf::Event event;
		std::ostringstream gameSwapsString;
        gameSwapsString << lastSwap.number;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				return 0;
			}
			if (first_stick.empty() && second_stick.empty())
			{
				return lastSwap.number;
			}
			if (goback.getGlobalBounds().contains(float(sf::Mouse::getPosition(window).x), float(sf::Mouse::getPosition(window).y)))
			{
				  if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
					  goback.setFillColor(sf::Color(47, 3, 3));
                  else { return -1; } // вернуться в главное меню
			}
			else
				goback.setFillColor(sf::Color::White);

			if ((arrow11.getGlobalBounds().contains(float(sf::Mouse::getPosition(window).x), float(sf::Mouse::getPosition(window).y)))
				&& (!first_stick.empty()) && ((third_stick.empty()) || (third_stick.back().get_width() > first_stick.back().get_width())))
			{
				if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
					arrow11.setFillColor(sf::Color::Green);
				else
				{
                    lastSwap.number++;
                    lastSwap.available = true;
                    lastSwap.from = first;
                    lastSwap.to = third;
					if (!third_stick.empty())
						third_stick.back().set_state(false);
					third_stick.push_back(first_stick.back());
					first_stick.pop_back();
					third_stick.back().set_location(third);
					third_stick.back().set_position(1, third_stick.size() - 1);
					if (!first_stick.empty())
						first_stick.back().set_state(true);
				}
			}
			else if ((arrow12.getGlobalBounds().contains(float(sf::Mouse::getPosition(window).x), float(sf::Mouse::getPosition(window).y)))
				&& (!first_stick.empty()) && ((second_stick.empty()) || (second_stick.back().get_width() > first_stick.back().get_width())))
			{
				if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
					arrow12.setFillColor(sf::Color::Green);
				else
				{
                    lastSwap.number++;
                    lastSwap.available = true;
                    lastSwap.from = first;
                    lastSwap.to = second;
					if (!second_stick.empty())
						second_stick.back().set_state(false);
					second_stick.push_back(first_stick.back());
					first_stick.pop_back();
					second_stick.back().set_location(second);
					second_stick.back().set_position(1, second_stick.size() - 1);
					if (!first_stick.empty())
						first_stick.back().set_state(true);
				}
			}

			else if ((arrow21.getGlobalBounds().contains(float(sf::Mouse::getPosition(window).x), float(sf::Mouse::getPosition(window).y)))
				&& (!second_stick.empty()) && ((first_stick.empty()) || (first_stick.back().get_width() > second_stick.back().get_width())))
			{
				if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
					arrow21.setFillColor(sf::Color::Green);
				else {
                    lastSwap.number++;
                    lastSwap.available = true;
                    lastSwap.from = second;
                    lastSwap.to = first;
					if (!first_stick.empty())
						first_stick.back().set_state(false);
					first_stick.push_back(second_stick.back());
					second_stick.pop_back();
					first_stick.back().set_location(first);
					first_stick.back().set_position(2, first_stick.size() - 1);
					if (!second_stick.empty())
						second_stick.back().set_state(true);
				}
			}

			else if ((arrow22.getGlobalBounds().contains(float(sf::Mouse::getPosition(window).x), float(sf::Mouse::getPosition(window).y)))
				&& (!second_stick.empty()) && ((third_stick.empty()) || (third_stick.back().get_width() > second_stick.back().get_width())))
			{
				if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
					arrow22.setFillColor(sf::Color::Green);
				else {
                    lastSwap.number++;
                    lastSwap.available = true;
                    lastSwap.from = second;
                    lastSwap.to = third;
					if (!third_stick.empty())
						third_stick.back().set_state(false);
					third_stick.push_back(second_stick.back());
					second_stick.pop_back();
					third_stick.back().set_location(third);
					third_stick.back().set_position(1, third_stick.size() - 1);
					if (!second_stick.empty())
						second_stick.back().set_state(true);
				}
			}

			else if ((arrow31.getGlobalBounds().contains(float(sf::Mouse::getPosition(window).x), float(sf::Mouse::getPosition(window).y)))
				&& (!third_stick.empty()) && ((second_stick.empty()) || (second_stick.back().get_width() > third_stick.back().get_width())))
			{
				if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
					arrow31.setFillColor(sf::Color::Green);
				else {
                    lastSwap.number++;
                    lastSwap.available = true;
                    lastSwap.from = third;
                    lastSwap.to = second;
					if (!second_stick.empty())
						second_stick.back().set_state(false);
					second_stick.push_back(third_stick.back());
					third_stick.pop_back();
					second_stick.back().set_location(second);
					second_stick.back().set_position(2, second_stick.size() - 1);
					if (!third_stick.empty())
						third_stick.back().set_state(true);
				}
			}

			else if ((arrow32.getGlobalBounds().contains(float(sf::Mouse::getPosition(window).x), float(sf::Mouse::getPosition(window).y)))
				&& (!third_stick.empty()) && ((first_stick.empty()) || (first_stick.back().get_width() > third_stick.back().get_width())))
			{
				if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
					arrow32.setFillColor(sf::Color::Green);
				else
				{
                    lastSwap.number++;
                    lastSwap.available = true;
                    lastSwap.from = third;
                    lastSwap.to = first;
					if (!first_stick.empty())
						first_stick.back().set_state(false);
					first_stick.push_back(third_stick.back());
					third_stick.pop_back();
					first_stick.back().set_location(first);
					first_stick.back().set_position(2, first_stick.size() - 1);
					if (!first_stick.empty())
						first_stick.back().set_state(true);
				}
			}
			else if (arrow11.getGlobalBounds().contains(float(sf::Mouse::getPosition(window).x), float(sf::Mouse::getPosition(window).y)))
				arrow11.setFillColor(sf::Color::Red);
			else if (arrow12.getGlobalBounds().contains(float(sf::Mouse::getPosition(window).x), float(sf::Mouse::getPosition(window).y)))
				arrow12.setFillColor(sf::Color::Red);
			else if (arrow21.getGlobalBounds().contains(float(sf::Mouse::getPosition(window).x), float(sf::Mouse::getPosition(window).y)))
				arrow21.setFillColor(sf::Color::Red);
			else if (arrow22.getGlobalBounds().contains(float(sf::Mouse::getPosition(window).x), float(sf::Mouse::getPosition(window).y)))
				arrow22.setFillColor(sf::Color::Red);
			else if (arrow31.getGlobalBounds().contains(float(sf::Mouse::getPosition(window).x), float(sf::Mouse::getPosition(window).y)))
				arrow31.setFillColor(sf::Color::Red);
			else if (arrow32.getGlobalBounds().contains(float(sf::Mouse::getPosition(window).x), float(sf::Mouse::getPosition(window).y)))
				arrow32.setFillColor(sf::Color::Red);
			else
			{
				arrow11.setFillColor(sf::Color::White);
				arrow12.setFillColor(sf::Color::White);
				arrow21.setFillColor(sf::Color::White);
				arrow22.setFillColor(sf::Color::White);
				arrow31.setFillColor(sf::Color::White);
				arrow32.setFillColor(sf::Color::White);
			}
            if (arrowBackwards.getGlobalBounds().contains(float(sf::Mouse::getPosition(window).x), float(sf::Mouse::getPosition(window).y)))
            {
                if ((!lastSwap.available) && (!sf::Mouse::isButtonPressed(sf::Mouse::Left)))
                    arrowBackwards.setTexture(texture3);
                else if (lastSwap.available)
                {
                    if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        arrowBackwards.setTexture(texture2);
                    else 
                    {
                        arrowBackwards.setTexture(texture1);
                        lastSwap.available = false;
                        lastSwap.number--;
                        if (lastSwap.to == first)
                        {
                            if (lastSwap.from == second)
                            {
                                if (!second_stick.empty())
                                    second_stick.back().set_state(false);
                                second_stick.push_back(first_stick.back());
                                first_stick.pop_back();
                                second_stick.back().set_location(second);
                                second_stick.back().set_position(2, second_stick.size() - 1);
                                if (!first_stick.empty())
                                    first_stick.back().set_state(true);
                            }
                            else   //== third
                            {
                                if (!third_stick.empty())
                                    third_stick.back().set_state(false);
                                third_stick.push_back(first_stick.back());
                                first_stick.pop_back();
                                third_stick.back().set_location(third);
                                third_stick.back().set_position(1, third_stick.size() - 1);
                                if (!first_stick.empty())
                                    first_stick.back().set_state(true);
                            }
                        }
                        else if (lastSwap.to == second)
                        {
                            if (lastSwap.from == first)
                            {
                                if (!first_stick.empty())
                                    first_stick.back().set_state(false);
                                first_stick.push_back(second_stick.back());
                                second_stick.pop_back();
                                first_stick.back().set_location(first);
                                first_stick.back().set_position(2, first_stick.size() - 1);
                                if (!second_stick.empty())
                                    second_stick.back().set_state(true);
                            }
                            else //== third
                            {
                                if (!third_stick.empty())
                                    third_stick.back().set_state(false);
                                third_stick.push_back(second_stick.back());
                                second_stick.pop_back();
                                third_stick.back().set_location(third);
                                third_stick.back().set_position(1, third_stick.size() - 1);
                                if (!second_stick.empty())
                                    second_stick.back().set_state(true);
                            }
                        }
                        else //third
                        {
                            if (lastSwap.from == first)
                            {
                                if (!first_stick.empty())
                                    first_stick.back().set_state(false);
                                first_stick.push_back(third_stick.back());
                                third_stick.pop_back();
                                first_stick.back().set_location(first);
                                first_stick.back().set_position(2, first_stick.size() - 1);
                                if (!third_stick.empty())
                                    third_stick.back().set_state(true);
                            }
                            else   //== second
                            {
                                if (!second_stick.empty())
                                    second_stick.back().set_state(false);
                                second_stick.push_back(third_stick.back());
                                third_stick.pop_back();
                                second_stick.back().set_location(second);
                                second_stick.back().set_position(2, second_stick.size() - 1);
                                if (!third_stick.empty())
                                    third_stick.back().set_state(true);
                            }
                        }
                    }
                }
			}
            else
                arrowBackwards.setTexture(texture1);
		}
		window.clear();
		draw_field(window);
		for (auto element : first_stick) // пройтись по всем дискам, лежащим на первом стержне
			window.draw(element.get_disk()); 
		for (auto element : second_stick)
			window.draw(element.get_disk());
		for (auto element : third_stick)
			window.draw(element.get_disk());
		window.draw(arrow11);
		window.draw(arrow12);
		window.draw(arrow21);
		window.draw(arrow22);
		window.draw(arrow31);
		window.draw(arrow32);
		window.draw(stick1);
		window.draw(stick2);
		window.draw(stick3);
		swapsText.setString(gameSwapsString.str()); 
		window.draw(text);
		window.draw(swapsText);
		window.draw(goback);
		window.draw(arrowBackwards);
		window.display();
	}
}


void gameover(sf::RenderWindow & window, int swaps)
{
	if (swaps == -1) // выйти в главное меню
		return;
	sf::Texture fone;
	sf::Sprite sprite;
	fone.loadFromFile("images/fone2.png");
	sprite.setTexture(fone);
	sf::Font font;
	font.loadFromFile("font.otf");
	sf::Text congrats(L"ТЫ МОЛОДЕЦ :)", font, 80);
	sf::Text goback(L"Вернуться в меню", font, 50);
	sf::Text minSwapsString(L"Минимальное количество перестановок: ", font, 30);
	sf::Text numberMinSwaps(std::to_string(int(std::pow(2,n)) - 1), font, 50);  // минимальное кол-во перестановок
	sf::Text playerSwapsString(L"Ты сделал всего перестановок: ", font, 30);
	sf::Text numberPlayerSwaps(std::to_string(swaps), font, 50);
	congrats.setPosition(85, 60);
	goback.setPosition(250, 400);
	minSwapsString.setPosition(40, 190);
	playerSwapsString.setPosition(110, 250);
	numberMinSwaps.setPosition(560, 170);
	numberPlayerSwaps.setPosition(485, 230);
	minSwapsString.setFillColor(sf::Color::Black);
	numberMinSwaps.setFillColor(sf::Color::Black);
	numberPlayerSwaps.setFillColor(sf::Color::Black);
	playerSwapsString.setFillColor(sf::Color::Black);
	congrats.setFillColor(sf::Color::White);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if ((goback.getGlobalBounds().contains(float(sf::Mouse::getPosition(window).x), float(sf::Mouse::getPosition(window).y))))
			{
				if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
					goback.setFillColor(sf::Color(47, 3, 3));
				else
					return;
			}
			else { goback.setFillColor(sf::Color::White); }
		}
		window.clear();
		window.draw(sprite);
		window.draw(congrats);
		window.draw(goback);
		window.draw(minSwapsString);
		window.draw(playerSwapsString);
		window.draw(numberMinSwaps);
		window.draw(numberPlayerSwaps);
		window.display();
	}
}

void Game(sf::RenderWindow & window)
{
	begin(window);
	while (window.isOpen())
	{
		while (menu(window))
			info(window);
		setup(window);
		sf::sleep(sf::seconds(0.5));
		gameover(window, (game_loop(window)));
	}
}