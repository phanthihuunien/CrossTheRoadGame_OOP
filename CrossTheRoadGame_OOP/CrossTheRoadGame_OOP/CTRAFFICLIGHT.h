#pragma once
class CTRAFFICLIGHT
{
private:
	bool green = true;
public:
	CTRAFFICLIGHT() {}
	bool getLight()
	{
		return green;
	}
	void setLight(bool x)
	{
		green = x;
	}
};

