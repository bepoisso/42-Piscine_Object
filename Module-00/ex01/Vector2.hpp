#pragma once

class Vector2 {

private:
	float x;
	float y;
	
public:
	Vector2(float x = 0, float y = 0);
	~Vector2();
	float getX() const;
	float getY() const;
	void setX(float newX);
	void setY(float newY);
};
