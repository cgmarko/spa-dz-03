#include "Keyboard.h"
void Keyboard::resolveKeyboard(sf::Event event, Image &image, Photon &photon, Star &star, Map &gravityField, Wall &wall, Void &darkVoid, Menu &menu, Music &music)
{
		switch (event.key.code)
		{
		case sf::Keyboard::Up:
			if (menu.getCurrentSelect().first <3)
			{
				menu.up();
				return;
			}

			if (menu.getCurrentSelect().first == 3 )
			{
				if (wall.getBeginY() > 1 && wall.getSetBegin())
				{
					wall.setBeginY(wall.getBeginY() - 1);
				}
				else if (wall.getEndY() - wall.getBeginY() > 0 && !wall.getSetBegin())
				{
					wall.setEndY(wall.getEndY() - 1);
				}
			}


			if (!star.getMoving() && star.getCenterY() > 1 && !gravityField.getWall(star.getCenterX(), star.getCenterY() - 1) && !star.getShooting() && menu.getCurrentSelect().first == 4)
			{
				star.setMovementBuffer(100);
				star.setStartedMoving(image.getTime());
				star.setMoving(true);
				star.setCenterY(star.getCenterY() - 1);
			}
			break;
		case sf::Keyboard::Down:
			if (menu.getCurrentSelect().first < 3)
			{
				menu.down();
				return;
			}

			if (menu.getCurrentSelect().first == 3)
			{
				if (wall.getEndY() - wall.getBeginY() > 0 && wall.getSetBegin())
				{
					wall.setBeginY(wall.getBeginY() + 1);
				}
				else if (wall.getEndY() < gravityField.getSizeY() && !wall.getSetBegin())
				{
					wall.setEndY(wall.getEndY() + 1);
				}
			}

	
			if (!star.getMoving() && star.getCenterY() != gravityField.getSizeY() && !gravityField.getWall(star.getCenterX(), star.getCenterY() + 1) && !star.getShooting() && menu.getCurrentSelect().first == 4)
			{
				star.setMovementBuffer(100);
				star.setStartedMoving(image.getTime());
				star.setMoving(true);
				star.setCenterY(star.getCenterY() + 1);
			}
			break;
		case sf::Keyboard::Left:
	
			if (menu.getCurrentSelect().first == 3)
			{
				if ( wall.getBeginX() > 1 && wall.getSetBegin())
				{
					wall.setBeginX(wall.getBeginX() - 1);
				}
				else if (wall.getEndX() - wall.getBeginX() >  0 && !wall.getSetBegin())
				{
					wall.setEndX(wall.getEndX() - 1);
				}
			}







			if (!star.getMoving() && star.getCenterX() > 1 && !gravityField.getWall(star.getCenterX() - 1, star.getCenterY()) && !star.getShooting() && menu.getCurrentSelect().first == 4)
			{
				star.setMovementBuffer(100);
				star.setStartedMoving(image.getTime());
				star.setMoving(true);
				star.setCenterX(star.getCenterX() - 1);
			}
			break;
			
		case sf::Keyboard::Right:

			if (menu.getCurrentSelect().first == 3)
			{
				if ((wall.getEndX() - wall.getBeginX()) > 0 && wall.getSetBegin())
				{
					wall.setBeginX(wall.getBeginX() + 1);
				}
				else if (wall.getEndX()  < gravityField.getSizeX() && !wall.getSetBegin())
				{
					wall.setEndX(wall.getEndX() + 1);
				}
			}


		
			if (!star.getMoving() && star.getCenterX() != gravityField.getSizeX() && !gravityField.getWall(star.getCenterX() + 1, star.getCenterY()) && !star.getShooting() && menu.getCurrentSelect().first == 4)
			{
				star.setMovementBuffer(100);
				star.setStartedMoving(image.getTime());
				star.setMoving(true);
				star.setCenterX(star.getCenterX() + 1);
			}
			break;
		case sf::Keyboard::Space:
			if (menu.getCurrentSelect().first == 3)
			{
				wall.setSetBegin();
			}
			if (photon.getPhotonBuffer() < 10 && menu.getCurrentSelect().first == 4)
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
			if (gravityField.getBlackHole().second > 1 && !gravityField.getWall(gravityField.getBlackHole().first, gravityField.getBlackHole().second - 1) && darkVoid.getMovementBuffer() <= 0 && menu.getCurrentSelect().first == 4)
			{
				darkVoid.setMovementBuffer(100);
				gravityField.setBlackHole(gravityField.getBlackHole().first, gravityField.getBlackHole().second - 1);
				gravityField.resetMap();
			}
			break;
		case sf::Keyboard::S:
			if (gravityField.getBlackHole().second != gravityField.getSizeY() && !gravityField.getWall(gravityField.getBlackHole().first, gravityField.getBlackHole().second + 1) && darkVoid.getMovementBuffer() <= 0 && menu.getCurrentSelect().first == 4)
			{
				darkVoid.setMovementBuffer(100);
				gravityField.setBlackHole(gravityField.getBlackHole().first, gravityField.getBlackHole().second + 1);
				gravityField.resetMap();
				
			}
			break;
		case sf::Keyboard::A:
			if (gravityField.getBlackHole().first > 1 && !gravityField.getWall(gravityField.getBlackHole().first - 1, gravityField.getBlackHole().second) && darkVoid.getMovementBuffer() <= 0 && menu.getCurrentSelect().first == 4)
			{
				darkVoid.setMovementBuffer(100);
				gravityField.setBlackHole(gravityField.getBlackHole().first - 1, gravityField.getBlackHole().second);
				gravityField.resetMap();
			}
			break;

		case sf::Keyboard::D:
			if (gravityField.getBlackHole().first != gravityField.getSizeX() && !gravityField.getWall(gravityField.getBlackHole().first + 1, gravityField.getBlackHole().second) && darkVoid.getMovementBuffer() <= 0 && menu.getCurrentSelect().first == 4)
			{
				darkVoid.setMovementBuffer(100);
				gravityField.setBlackHole(gravityField.getBlackHole().first + 1, gravityField.getBlackHole().second);
				gravityField.resetMap();
			}
			break;
		case sf::Keyboard::Enter:
			switch (menu.getCurrentSelect().first)
			{
			case 0:
				menu.setCurrentSelect(3);
				menu.setGameStarted();
				break;
			case 1:
				music.volumeUp();
				menu.setCurrentSelect(4);
				break;
			case 2:
				image.closeWindow();
				break;
			case 3:
				menu.setCurrentSelect(4);
				music.volumeUp();
				break;
			default:
				break;
			}
			break;
		case sf::Keyboard::Escape:
			if (menu.getCurrentSelect().first == 4)
			{
				music.volumeDown();
				menu.setCurrentSelect(1);
			}
			break;
		default:
			break;
		}
		
}
