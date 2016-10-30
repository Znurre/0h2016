#include <QDebug>

#include "Fruit.h"
#include "PositionProvider.h"
#include "StateHandler.h"
#include "Bucket.h"

Fruit::Fruit(PositionProvider &positionProvider, StateHandler &stateHandler, Bucket &bucket, int index)
	: m_positionProvider(positionProvider)
	, m_stateHandler(stateHandler)
	, m_bucket(bucket)
	, m_index(index)
	, m_y(-10)
{

}

void Fruit::draw(QPainter &painter)
{
	const int x = m_positionProvider.getPosition(m_index);
	const int w = m_positionProvider.getBucketWidth();

	const QRect rect(x - 5 + w / 2, m_y, 10, 10);

	painter.fillRect(rect, Qt::red);
}

bool Fruit::update(long delta)
{
	const int bottom = m_positionProvider.getBottom();
	const int bounds = m_positionProvider.getBounds();

	m_y += (delta * 0.1f);

	if (m_y >= bottom)
	{
		if (m_bucket.index() == m_index)
		{
			return false;
		}
	}

	if (m_y > bounds)
	{
		m_stateHandler.changeState(StateHandler::GameOver);

		return false;
	}

	return true;
}
