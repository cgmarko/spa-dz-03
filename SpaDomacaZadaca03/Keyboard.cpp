#include "Keyboard.h"
void Keyboard::resolveKeyboard(sf::Event event, Image &image, Photon &photon, Star &star, Map &gravityField, Wall &wall, Void &darkVoid)
{
	if (event.type = sf::Event::KeyPressed)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Up:
			if (!star.getMoving() && star.getCenterY() > 1 && !gravityField.getWall(star.getCenterX(), star.getCenterY() - 1) && !star.getShooting())
			{
				star.setMovementBuffer(100);
				star.setStartedMoving(image.getTime());
				star.setMoving(true);
				star.setCenterY(star.getCenterY() - 1);
			}
			break;
		case sf::Keyboard::Down:
			if (!star.getMoving() && star.getCenterY() != gravityField.getSizeY() && !gravityField.getWall(star.getCenterX(), star.getCenterY() + 1) && !star.getShooting())
			{
				star.setMovementBuffer(100);
				star.setStartedMoving(image.getTime());
				star.setMoving(true);
				star.setCenterY(star.getCenterY() + 1);
			}
			break;
		case sf::Keyboard::Left:
			if (!star.getMoving() && star.getCenterX() > 1 && !gravityField.getWall(star.getCenterX() - 1, star.getCenterY()) && !star.getShooting())
			{
				star.setMovementBuffer(100);
				star.setStartedMoving(image.getTime());
				star.setMoving(true);
				star.setCenterX(star.getCenterX() - 1);
			}
			break;
			
		case sf::Keyboard::Right:
			if (!star.getMoving() && star.getCenterX() != gravityField.getSizeX() && !gravityField.getWall(star.getCenterX() + 1, star.getCenterY()) && !star.getShooting())
			{
				star.setMovementBuffer(100);
				star.setStartedMoving(image.getTime());
				star.setMoving(true);
				star.setCenterX(star.getCenterX() + 1);
			}
			break;
		case sf::Keyboard::Space:
			if (photon.getPhotonBuffer() < 10)
			{
				if (!star.getShooting())
				{
					star.setShooting(true);
				}
				star.setLastCharge(image.getTime());
				for (int i = 0; i < 5; i++)
				{
					photon.increasePhotonBuffer();
				}
				
			}
			
			break;
		case sf::Keyboard::W:
			if (gravityField.getBlackHole().second > 1 && !gravityField.getWall(gravityField.getBlackHole().first, gravityField.getBlackHole().second - 1))
			{
				gravityField.setBlackHole(gravityField.getBlackHole().first, gravityField.getBlackHole().second - 1);
				darkVoid.setCenterY(gravityField.getBlackHole().second);
				gravityField.resetMap();
			}
			break;
		case sf::Keyboard::S:
			if (gravityField.getBlackHole().second != gravityField.getSizeY() && !gravityField.getWall(gravityField.getBlackHole().first, gravityField.getBlackHole().second + 1))
			{
				gravityField.setBlackHole(gravityField.getBlackHole().first, gravityField.getBlackHole().second + 1);
				darkVoid.setCenterY(gravityField.getBlackHole().second);
				gravityField.resetMap();
				
			}
			break;
		case sf::Keyboard::A:
			if (gravityField.getBlackHole().first > 1 && !gravityField.getWall(gravityField.getBlackHole().first - 1, gravityField.getBlackHole().second))
			{
				gravityField.setBlackHole(gravityField.getBlackHole().first - 1, gravityField.getBlackHole().second);
				darkVoid.setCenterX(gravityField.getBlackHole().first);
				gravityField.resetMap();
			}
			break;

		case sf::Keyboard::D:
			if (gravityField.getBlackHole().first != gravityField.getSizeX() && !gravityField.getWall(gravityField.getBlackHole().first + 1, gravityField.getBlackHole().second))
			{
				gravityField.setBlackHole(gravityField.getBlackHole().first + 1, gravityField.getBlackHole().second);
				darkVoid.setCenterX(gravityField.getBlackHole().first);
				gravityField.resetMap();
			}
			break;
		default:
			break;
		}
	}
}
