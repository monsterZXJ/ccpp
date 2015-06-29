

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace std;

class Bullet;
class Flight;

vector<Bullet *> bullets;
vector<Flight *> badpeople;


class Bullet
{
public:
	Bullet(sf::RenderWindow *w, double x, double y)
	{
		window = w;
		if (!texture.loadFromFile("C:\\Users\\ZXJ\\Documents\\visual studio 2013\\Projects\\game\\game\\data\\picture\\1.png"))
		{
			return;
		}
		sprite.setTexture(texture);
		sprite.setPosition(x, y);
		sprite.setScale(0.5, 0.5);

	}
	void show()
	{
		window->draw(sprite);
	}
	void move()
	{
		sprite.move(0.0, -1.0);
	}
	bool outside()
	{
		return sprite.getPosition().y < 0;
	}
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::RenderWindow *window;
};

class Flight
{
public:
	Flight(char* path,sf::RenderWindow* w)
	{
		window = w;
		sf::Texture *texture = new sf::Texture;
		if (!texture->loadFromFile(path))
		{
			return ;
		}

		flight.setTexture(*texture);
		flight.setPosition(130,530);
		flight.setScale(0.5, 0.5);

		width = flight.getTextureRect().width*flight.getScale().x;
		height = flight.getTextureRect().height*flight.getScale().y;
	}
	void move(double x, double y)
	{
		double a = flight.getPosition().x;
		double dx;


		if (x <= 0)
		{
			if (a + x > 0)
			{
				dx = x;
			}
			else if (a + x < 0 && a>0)
			{
				dx = -a;
			}
			else {
				dx = 0;
			}
		}
		else
		{
			if (a + width + x < window->getSize().x)
			{
				dx = x;
			}
			else if (a + width + x > window->getSize().x&&a + width + x != window->getSize().x)
			{
				dx = window->getSize().x - width - a;
			}
			else
			{
				dx = 0;
			}
		}
		flight.move(dx, y);

	}
	void show()
	{
		window->draw(flight);
	}
	void launch()
	{
		Bullet *bullet = new Bullet(window, flight.getPosition().x+width/2,flight.getPosition().y);
		bullets.push_back(bullet);
	}

private:
	sf::Sprite flight;
	sf::RenderWindow *window;
	double width, height;
};
/*
class emenyflight :public Flight
{
public:
	void setposition(double x, double y)
	{
		
	}
private:
	sf::Sprite hero;
	double x, y;
};
*/

int main()
{

	sf::RenderWindow window(sf::VideoMode(300, 600), "SFML works");



	/* Play Music */
	sf::Music music;
	if (!music.openFromFile("D:\\lalala\\Fighters\\resources\\sound\\game_music.ogg"))
	{
		
	}
	music.setLoop(true);
	music.play();

	/* Display Backgroud */
	sf::Sprite sprite;
	sf::Texture texture;

	if (!texture.loadFromFile("C:\\Users\\ZXJ\\Documents\\visual studio 2013\\Projects\\game\\game\\data\\picture\\background1.png"))
	{
		return 0;
	}
	sprite.setTexture(texture);
	
	//flight
	Flight flight("C:\\Users\\ZXJ\\Documents\\visual studio 2013\\Projects\\game\\game\\data\\picture\\feiji.png", &window);

	sf::Clock clock;
	sf::Time elapsed;
	sf::Clock enemyclock;
	sf::Time enemyelapsed;

	sf::Event event;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				flight.move(-5.0,0.0);
			if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				flight.move(5.0, 0.0);
			if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				flight.move(0.0,-7.0);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				flight.move(0.0,7.0);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				flight.launch();
		}
		
		enemyelapsed = enemyclock.getElapsedTime();
		if (enemyelapsed > sf::seconds(1))
		{
			Flight *enemy = new Flight("C:\\Users\\ZXJ\\Documents\\visual studio 2013\\Projects\\game\\game\\data\\picture\\dj.png", &window);
			badpeople.push_back(enemy);
		}


		// Clear screen
		window.clear();

		
		// Draw the sprite
		window.draw(sprite);
		flight.show();
		
		elapsed = clock.getElapsedTime();
		for (int i = 0; i < bullets.size();i++)
		{
			if (elapsed > sf::milliseconds(5)){
				clock.restart();
				bullets[i]->move();
			}
			bullets[i]->show();
			if (bullets[i]->outside())
			{
				delete bullets[i];
				bullets.erase(bullets.begin() + i);
			}
		}

		for (int j = 0; j < badpeople.size(); j++)
		{
			badpeople[j]->show();
		}
		// Update the window
		window.display();
		// Play the music
	}


	return 0;
}
	/*



#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	// Load a sprite to display
	sf::Texture texture;
	if (!texture.loadFromFile("C:\\Users\\ZXJ\\Documents\\visual studio 2013\\Projects\\game\\game\\data\\picture\\background.jpg"))
		return EXIT_FAILURE;
	sf::Sprite sprite(texture);
	// Create a graphical text to display

	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// Clear screen
		window.clear();
		// Draw the sprite
		window.draw(sprite);
		// Update the window
		window.display();
	}
	return EXIT_SUCCESS;
}
*/