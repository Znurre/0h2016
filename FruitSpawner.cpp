#include <QDebug>

#include "Fruit.h"
#include "FruitSpawner.h"

FruitSpawner::FruitSpawner(PositionProvider &positionProvider, StateHandler &stateHandler, Bucket &bucket)
	: m_positionProvider(positionProvider)
	, m_stateHandler(stateHandler)
	, m_bucket(bucket)
	, m_delay(1000)
	, m_timer(0)
{

}

void FruitSpawner::draw(QPainter &painter)
{
	for (Fruit *fruit : m_fruits)
	{
		fruit->draw(painter);
	}
}

bool FruitSpawner::update(long delta)
{
	QSet<Fruit *> toRemove;

	for (Fruit *fruit : m_fruits)
	{
		if (!fruit->update(delta))
		{
			toRemove << fruit;

			delete fruit;
		}
	}

	m_fruits.subtract(toRemove);

	if ((m_timer += delta) >= m_delay)
	{
		const int index = qrand() % 5;

		m_fruits << new Fruit(m_positionProvider, m_stateHandler, m_bucket, index);

		m_timer = 0;
		m_delay -= 5;
	}

	return true;
}
