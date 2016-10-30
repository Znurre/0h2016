#include "PositionProvider.h"
#include "Window.h"

const int PADDING = 100;

PositionProvider::PositionProvider(Window &window)
	: m_window(window)
{

}

int PositionProvider::getBucketWidth() const
{
	const int w = m_window.width();
	const int s = (w - PADDING * 2) / 5;

	return s;
}

int PositionProvider::getPosition(int index) const
{
	return PADDING + getBucketWidth() * index;
}

int PositionProvider::getBottom() const
{
	return m_window.height() - 20;
}

int PositionProvider::getBounds() const
{
	return m_window.height();
}
