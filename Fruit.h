#ifndef FRUIT_H
#define FRUIT_H

#include "IDrawable.h"

class PositionProvider;
class StateHandler;
class Bucket;

class Fruit : public IDrawable
{
	public:
		Fruit(PositionProvider &positionProvider, StateHandler &stateHandler, Bucket &bucket, int index);

		void draw(QPainter &painter) override;
		bool update(long delta) override;

	private:
		PositionProvider &m_positionProvider;
		StateHandler &m_stateHandler;
		Bucket &m_bucket;

		int m_index;

		float m_y;
};

#endif // FRUIT_H
