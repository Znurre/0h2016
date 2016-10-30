#ifndef POSITIONPROVIDER_H
#define POSITIONPROVIDER_H

class Window;

class PositionProvider
{
	public:
		PositionProvider(Window &window);

		int getBucketWidth() const;
		int getPosition(int index) const;
		int getBottom() const;
		int getBounds() const;

	private:
		Window &m_window;
};

#endif // POSITIONPROVIDER_H
