#include "HelperFunctions.h"
#include <math.h>

float distance(sf::Vector2<float> a, sf::Vector2<float> b)
{
	sf::Vector2<float> diff = a - b;
	return sqrt((diff.x)*(diff.x)/* + (diff.y)*(diff.y)*/);
}