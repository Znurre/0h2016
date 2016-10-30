#ifndef FRUITSPAWNER_H
#define FRUITSPAWNER_H

#include <QSet>

#include "IDrawable.h"

class Fruit;
class PositionProvider;
class StateHandler;
class Bucket;

class FruitSpawner : public IDrawable
{
	public:
		FruitSpawner(PositionProvider &positionProvider, StateHandler &stateHandler, Bucket &bucket);

		void draw(QPainter &painter) override;
		bool update(long delta) override;

	private:
		PositionProvider &m_positionProvider;
		StateHandler &m_stateHandler;
		Bucket &m_bucket;

		QSet<Fruit *> m_fruits;

		long m_delay;
		long m_timer;
};

#endif // FRUITSPAWNER_H
